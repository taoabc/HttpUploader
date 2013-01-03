#include "stdafx.h"
#include "WinhttpUploader.h"

#include "ult/string-operate.h"
#include "ult/file-dir.h"
#include "Utility.h"

const std::string WinhttpUploader::kLineEnd_ = "\r\n";
const std::wstring WinhttpUploader::kLineEndW_ = L"\r\n";

WinhttpUploader::WinhttpUploader(void) {
  InitBoundary();
}

WinhttpUploader::~WinhttpUploader(void) {
}

void WinhttpUploader::InitBoundary(void) {
  //init boundary
  wboundary_ = L"----------";
  wboundary_ += ult::GetRandomString(30);
  aboundary_ = ult::UnicodeToAnsi(wboundary_);
}

void WinhttpUploader::Reset(void) {
  this->Close();
  connection_.Close();
  session_.Close();
  InitBoundary();
  sendfield_.clear();
}

int WinhttpUploader::InitRequest(const std::wstring& url) {
  HRESULT hr = session_.Initialize(true);
  if (FAILED(hr)) {
    return ult::HttpStatus::kUnknownError;
  }
  URL_COMPONENTS uc;
  ult::UltWinHttpCrackUrl(url.c_str(), &uc);
  std::wstring host_name(uc.lpszHostName, uc.dwHostNameLength);
  hr = connection_.Initialize(session_.GetHandle(), host_name.c_str(), uc.nPort);
  if (FAILED(hr)) {
    return ult::HttpStatus::kConnectError;
  }
  hr = Initialize(connection_.GetHandle(), L"POST", uc.lpszUrlPath, uc.nScheme);
  if (FAILED(hr)) {
    return ult::HttpStatus::kOpenRequestError;
  }
  return ult::HttpStatus::kSuccess;
}

void WinhttpUploader::AddField(const std::wstring& field, const char* data, DWORD len) {
  if (len == 0) {
    return;
  }
  sendfield_ += "--" + aboundary_ + kLineEnd_ + "Content-Disposition: form-data; name=\"";
  sendfield_ += ult::UnicodeToAnsi(field) + "\"" + kLineEnd_ + kLineEnd_;
  sendfield_.append(data, len);
  sendfield_ += kLineEnd_;
}

void WinhttpUploader::ClearField( void ) {
  sendfield_.clear();
}

HRESULT WinhttpUploader::PostFile(const void* data, DWORD len, ULONGLONG begine_pos) {
  Reset();
  RETURN_IF_FAILED(InitRequest(url_));
  BOOST_FOREACH(PostField field, post_fields_) {
    std::string uvalue = ult::UnicodeToUtf8(field.value);
    AddField(field.key, uvalue.c_str(), uvalue.length());
  }
  header_ = L"Content-Type: multipart/form-data; boundary=" + wboundary_ + kLineEndW_;
  postbegin_ = "--" + aboundary_ + kLineEnd_ + "Content-Disposition: form-data; name=\"file\"; filename=\"";
  postbegin_ += ufilename_ + "\"" + kLineEnd_ + "Content-Type: application/octet-stream" + kLineEnd_ + kLineEnd_;
  postend_ = kLineEnd_ + "--" + aboundary_ + "--" + kLineEnd_;

  std::string begin_pos_str = std::to_string(begine_pos);
  std::string sendfiled = AddTempFiled(L"start", begin_pos_str.c_str(), begin_pos_str.length());
  DWORD total_size = len + sendfiled.length() + postbegin_.length() + postend_.length();
  RETURN_IF_FAILED(SendRequest(header_.c_str(), -1L, NULL, 0, total_size));
  RETURN_IF_FAILED(WriteData(sendfiled.c_str(), sendfiled.length()));
  RETURN_IF_FAILED(WriteData(postbegin_.c_str(), postbegin_.length()));
  RETURN_IF_FAILED(WriteData(data, len));
  RETURN_IF_FAILED(WriteData(postend_.c_str(), postend_.length()));
  string_rcv_.clear();
  return RecieveResponse(&status_);
}

DWORD WinhttpUploader::GetStatus( void ) const {
  return status_;
}

HRESULT WinhttpUploader::OnReadComplete( const void* info, DWORD length ) {
  string_rcv_.append((const char*)info, length);
  return S_OK;
}

std::string WinhttpUploader::GetRecvString( void ) const {
  return string_rcv_;
}

HRESULT WinhttpUploader::PreparePost( const std::wstring& url, const std::wstring& filename,
                                      const std::vector<PostField>& post_fields) {
  url_ = url;
  ufilename_ = ult::UnicodeToUtf8(filename);
  post_fields_ = post_fields;
  return S_OK;
}

std::string WinhttpUploader::AddTempFiled( const std::wstring& field, const char* data, DWORD len ) {
  std::string sendfield = sendfield_ + "--" + aboundary_ + kLineEnd_ + "Content-Disposition: form-data; name=\"";
  sendfield += ult::UnicodeToUtf8(field) + "\"" + kLineEnd_ + kLineEnd_;
  sendfield.append(data, len);
  sendfield += kLineEnd_;
  return sendfield;
}
