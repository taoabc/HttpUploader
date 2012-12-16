// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"
#include "Utility.h"
#include "ult/md5.h"
#include "ult/number.h"
#include "ult/file-io.h"
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <ShlGuid.h>
#include <cassert>
// CUploader

CUploader::CUploader( void ) :
    posted_length_(0),
    range_size_(131072),
    file_size_limit_(2147483648),
    file_size_(0) {
}

CUploader::~CUploader( void ) {

}

STDMETHODIMP CUploader::SetSite( IUnknown* punksite ) {
  if (punksite != NULL) {
  } else {
    //release pointer
  }
  return IObjectWithSiteImpl<CUploader>::SetSite(punksite);
}

STDMETHODIMP CUploader::get_MD5(BSTR* pVal) {
  // TODO: Add your implementation code here
  //alloc string to return
  *pVal = ::SysAllocStringLen(md5_.c_str(), md5_.length());
  return S_OK;
}

STDMETHODIMP CUploader::get_PostedLength(DOUBLE* pVal) {
  // TODO: Add your implementation code here
  *pVal = (DOUBLE)posted_length_;
  return S_OK;
}

STDMETHODIMP CUploader::get_PostUrl(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = ::SysAllocStringLen(post_url_.c_str(), post_url_.length());
  return S_OK;
}

STDMETHODIMP CUploader::put_PostUrl(BSTR newVal) {
  // TODO: Add your implementation code here
  post_url_.assign(newVal, ::SysStringLen(newVal));
  return S_OK;
}

STDMETHODIMP CUploader::get_EncodeType(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = ::SysAllocStringLen(encode_type_.c_str(), encode_type_.length());
  return S_OK;
}

STDMETHODIMP CUploader::put_EncodeType(BSTR newVal) {
  // TODO: Add your implementation code here
  encode_type_.assign(newVal, ::SysStringLen(newVal));
  return S_OK;
}

STDMETHODIMP CUploader::get_OnPost(IDispatch** pVal) {
  // TODO: Add your implementation code here
  on_post_.CopyTo(pVal);
  return S_OK;
}

STDMETHODIMP CUploader::put_OnPost(IDispatch* newVal) {
  // TODO: Add your implementation code here
  on_post_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_OnStateChanged(IDispatch** pVal) {
  // TODO: Add your implementation code here
  on_state_changed_.CopyTo(pVal);
  return S_OK;
}

STDMETHODIMP CUploader::put_OnStateChanged(IDispatch* newVal) {
  // TODO: Add your implementation code here
  on_state_changed_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_LocalFile(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = ::SysAllocStringLen(local_file_.c_str(), local_file_.length());
  return S_OK;
}

STDMETHODIMP CUploader::put_LocalFile(BSTR newVal) {
  // TODO: Add your implementation code here
  local_file_.assign(newVal, ::SysStringLen(newVal));
  file_size_ = boost::filesystem::file_size(local_file_);
  return S_OK;
}

STDMETHODIMP CUploader::get_FileSizeLimit(DOUBLE* pVal) {
  // TODO: Add your implementation code here
  *pVal = (DOUBLE)file_size_limit_;
  return S_OK;
}

STDMETHODIMP CUploader::put_FileSizeLimit(DOUBLE newVal) {
  // TODO: Add your implementation code here
  file_size_limit_ = (ULONGLONG)newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_RangeSize(DOUBLE* pVal) {
  // TODO: Add your implementation code here
  *pVal = (DOUBLE)range_size_;
  return S_OK;
}

STDMETHODIMP CUploader::put_RangeSize(DOUBLE newVal) {
  // TODO: Add your implementation code here
  range_size_ = (ULONGLONG)newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_CompanyLicensed(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = SysAllocStringLen(company_lisensed_.c_str(), company_lisensed_.length());
  return S_OK;
}

STDMETHODIMP CUploader::put_CompanyLicensed(BSTR newVal) {
  // TODO: Add your implementation code here
  company_lisensed_.assign(newVal, ::SysStringLen(newVal));
  return S_OK;
}

STDMETHODIMP CUploader::get_FileID(ULONG* pVal) {
  // TODO: Add your implementation code here
  *pVal = file_id_;
  return S_OK;
}

STDMETHODIMP CUploader::put_FileID(ULONG newVal) {
  // TODO: Add your implementation code here
  file_id_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_Object(IDispatch** pVal) {
  // TODO: Add your implementation code here
  *pVal = object_;
  return S_OK;
}

STDMETHODIMP CUploader::put_Object(IDispatch* newVal) {
  // TODO: Add your implementation code here
  object_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::ClearFields( BYTE* result )
{
  // TODO: Add your implementation code here
  post_fields_.clear();
  *result = (BYTE)-1;
  return S_OK;
}

STDMETHODIMP CUploader::AddField(BSTR key, BSTR value, BYTE* result) {
  // TODO: Add your implementation code here
  PostField field;
  field.key.assign(key, ::SysStringLen(key));
  field.value.assign(value, ::SysStringLen(value));
  post_fields_.push_back(field);
  *result = (BYTE)-1;
  return S_OK;
}

STDMETHODIMP CUploader::Post(BYTE* result) {
  // TODO: Add your implementation code here
  *result = 0;
  if (local_file_.empty()) {
    SetError(err::kLocalFileEmpty);
  } else if(post_url_.empty()) {
    SetError(err::kPostUrlEmpty);
  } else if (file_size_ > file_size_limit_) {
    SetError(err::kFileSizeExceed);
  } else {
    boost::thread t(std::bind(&CUploader::DoPost, this, 0));
    thread_vec_.push_back(std::move(t));
    *result = (BYTE)-1;
  }
  return S_OK;
}

STDMETHODIMP CUploader::CheckFile(BYTE* result) {
  // TODO: Add your implementation code here
  if (local_file_.empty()) {
    *result = 0;
  } else {
    boost::thread t(std::bind(&CUploader::CalcMd5Thread, this, local_file_));
    thread_vec_.push_back(std::move(t));
    *result = (BYTE)-1;
  }
  return S_OK;
}

STDMETHODIMP CUploader::Stop(BYTE* result) {
  // TODO: Add your implementation code here
  stop_ = true;
  *result = (BYTE)-1;
  return S_OK;
}

void CUploader::CalcMd5Thread( const std::wstring& file ) {
  //文件大小为0，返回
  if (0 == boost::filesystem::file_size(file)) {
    SetError(err::kMd5FileSizeZero);
    return;
  }
  std::function<void (ULONGLONG, ULONGLONG)> OnWorking = [this](ULONGLONG completed, ULONGLONG total){
    boost::this_thread::interruption_point();
    md5_percent_ = (USHORT)ult::UIntMultDiv(100, completed, total);
    msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateMd5Working);
  };
  md5_percent_ = 0;
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateMd5Working);
  //同步计算
  std::wstring md5 = ult::MD5File(file, OnWorking);
  if (md5.empty()) {
    SetError(err::kMd5FileOpenError);
    return;
  }
  //计算完成，更改共享变量
  mutex_calcmd5_.lock();
  md5_ = md5;
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateMd5Complete);
  mutex_calcmd5_.unlock();
}

STDMETHODIMP CUploader::get_Md5Percent(USHORT* pVal) {
  // TODO: Add your implementation code here
  *pVal = md5_percent_;
  return S_OK;
}

void CUploader::SetState( LONG state ) {
  if (on_state_changed_ != NULL) {
    VARIANT param[2];
    param[0].lVal = state;
    param[0].vt = VT_I4;
    param[1].pdispVal = object_;
    param[1].vt = VT_DISPATCH;
    CComVariant result;
    ult::InvokeMethod(on_state_changed_, param, 2, &result);
  }
}

/*
** 上传主函数
** todo
**   将其功能分开来写
*/
void CUploader::DoPost( ULONGLONG start_pos ) {
  HRESULT hr;
  WinhttpUploader uploader;
  BOOST_FOREACH(PostField field, post_fields_) {
    std::string uvalue = ult::UnicodeToUtf8(field.value);
    uploader.AddField(field.key, uvalue.c_str(), uvalue.length());
  }
  ULONGLONG filesize = file_size_;
  boost::filesystem::path file(local_file_);
  if (!boost::filesystem::exists(local_file_)) {
    SetError(err::kLocalFileAbsent);
    return;
  }
  std::wstring name = file.filename().wstring();
  posted_length_ = start_pos;
  if (posted_length_ >= filesize) {
    error_msg_ = L"续传位置超过或等于文件大小";
    msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateError);
    return;
  }
  ULONGLONG sendsize = filesize - posted_length_;
  int ret = uploader.BeginPost(post_url_, name, sendsize);
  if (ret != ult::HttpStatus::kSuccess) {
    error_msg_ = L"连接服务器错误";
    SetError(err::kConnectError);
    return;
  }
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateConnected);
  DWORD write, readed;
  stop_ = false;
  begin_post_time_ = ::GetTickCount();
  begin_post_cursor_ = posted_length_;
  msgwnd_.SetPostTimer();
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateUploading);
  USHORT percent = (USHORT)ult::UIntMultDiv(100, posted_length_, filesize);
  OnPostParam onpost_param;
  onpost_param.left_time = 0;
  onpost_param.percent = percent;
  onpost_param.posted = posted_length_;
  onpost_param.speed = 0;
  msgwnd_.SendMessage(UM_ON_POST, (WPARAM)&onpost_param);
  ULONGLONG new_pos;
  DWORD buf_len = (DWORD)range_size_; // set buffer
  ult::File f;
  if (!f.Open(local_file_)) {
    error_msg_ = L"无法打开指定文件";
    SetError(err::kFileOpenError);
    return;
  }
  f.Seek(posted_length_, &new_pos);
  bool isok = true;
  LONG last_state = 0;
  char* buffer = new char[buf_len];
  while (posted_length_ < filesize) {
    boost::this_thread::interruption_point();
    if (stop_) {
      isok = false;
      error_msg_ = L"上传被手动停止";
      last_state = state::kStateStop;
      break;
    }
    write = (DWORD)min(filesize-posted_length_, buf_len);
    f.Read(buffer, write, &readed);
    if (readed != write) {
      isok = false;
      error_msg_ = L"读取文件错误";
      error_code_ = err::kFileReadError;
      last_state = state::kStateError;
      break;
    }
    hr = uploader.WriteData(buffer, readed);
    if (FAILED(hr)) {
      isok = false;
      error_msg_ = L"POST过程中发生错误";
      error_code_ = err::kSendDataError;
      last_state = state::kStateError;
      break;
    }
    posted_length_ += write;
  }
  delete[] buffer;
  msgwnd_.KillPostTimer();
  if (!isok) {
    msgwnd_.SendMessage(UM_STATE_CHANGE, last_state);
    return;
  }
  hr = uploader.EndPost();
  http_status_ = uploader.GetStatus();
  if (FAILED(hr)) {
    error_msg_ = L"结束传输过程中发生错误";
    SetError(err::kSendDataError);
    return;
  }
  recv_string_ = ult::Utf8ToUnicode(uploader.GetRecvString());
  onpost_param.left_time = 0;
  onpost_param.percent = 100;
  onpost_param.posted = filesize;
  onpost_param.speed = 0;
  msgwnd_.SendMessage(UM_ON_POST, (WPARAM)&onpost_param);
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateUploadComplete);
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateLeisure);
}

void CUploader::OnPostTimer( void ) {
  static ULONGLONG old_posted = posted_length_;
  static DWORD oldtk = ::GetTickCount();
  DWORD newtk = ::GetTickCount();
  //如果过小，不计算速度
  if (newtk - oldtk < 800) {
    return;
  }
  ULONGLONG new_posted = posted_length_;
  ULONGLONG speed = (ULONGLONG)(new_posted - old_posted) * 1000 / (newtk - oldtk);
  USHORT percent = (USHORT)ult::UIntMultDiv(new_posted, 100, file_size_);
  DWORD left_time = 0;
  DWORD used_time = ::GetTickCount() - begin_post_time_;
  ULONGLONG sended = new_posted - begin_post_cursor_;
  ULONGLONG avg_speed = (sended / used_time) * 1000;
  left_time = (DWORD)((file_size_ - new_posted) / avg_speed);
  if (on_post_ != NULL) {
    OnPostCallback(speed, new_posted, percent, left_time);
  }
  oldtk = newtk;
  old_posted = new_posted;
}

STDMETHODIMP CUploader::get_ErrorCode(LONG* pVal) {
  // TODO: Add your implementation code here
  *pVal = error_code_;
  return S_OK;
}

STDMETHODIMP CUploader::get_FileSize(DOUBLE* pVal) {
  // TODO: Add your implementation code here
  *pVal = (DOUBLE)file_size_;
  return S_OK;
}

STDMETHODIMP CUploader::get_ErrorMsg(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = ::SysAllocStringLen(error_msg_.c_str(), error_msg_.length());
  return S_OK;
}

STDMETHODIMP CUploader::PostFromPosition(DOUBLE position, BYTE* result) {
  // TODO: Add your implementation code here
  if (local_file_.empty() || post_url_.empty()) {
    *result = 0;
  } else {
    boost::thread t(std::bind(&CUploader::DoPost, this, (ULONGLONG)position));
    t.detach();
    *result = (BYTE)-1;
  }
  return S_OK;
}

void CUploader::SetError( LONG error_code ) {
  error_code_ = error_code;
  msgwnd_.SendMessage(UM_STATE_CHANGE, state::kStateError);
}

void CUploader::OnPostCallback( ULONGLONG speed, ULONGLONG posted, USHORT percent, DWORD left_time ) {
  assert(on_post_ != NULL);
  VARIANT param[5];
  param[0].ullVal = left_time;
  param[0].vt = VT_UI4;
  param[1].uiVal = percent;
  param[1].vt = VT_UI2;
  param[2].dblVal = (DOUBLE)posted;
  param[2].vt = VT_R8;
  param[3].dblVal = (DOUBLE)speed;
  param[3].vt = VT_R8;
  param[4].pdispVal = object_;
  param[4].vt = VT_DISPATCH;
  CComVariant result;
  ult::InvokeMethod(on_post_, param, 5, &result);
}

STDMETHODIMP CUploader::get_HttpStatus(DOUBLE* pVal) {
  // TODO: Add your implementation code here
  *pVal = http_status_;
  return S_OK;
}

STDMETHODIMP CUploader::get_ReturnedString(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = ::SysAllocStringLen(recv_string_.c_str(), recv_string_.length());
  return S_OK;
}

void CUploader::FinalRelease( void ) {
  msgwnd_.KillPostTimer();
  for (auto iter = thread_vec_.begin(); iter != thread_vec_.end(); ++iter) {
    iter->interrupt();
    iter->timed_join(boost::posix_time::milliseconds(1000));
  }
  thread_vec_.clear();
  on_post_.Release();
  on_state_changed_.Release();
  msgwnd_.DestroyWindow();
}

HRESULT CUploader::FinalConstruct( void ) {
  msgwnd_.Create(HWND_MESSAGE);
  msgwnd_.SetWindowLongPtr(GWLP_USERDATA, (LONG_PTR)this);
  return S_OK;
}