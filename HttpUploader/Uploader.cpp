// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"
#include "Utility.h"
#include "ult/md5.h"
#include "ult/number.h"
#include "ult/file-io.h"
#include <boost/filesystem.hpp>
#include <ShlGuid.h>
// CUploader

CUploader::CUploader( void ) :
    posted_length_(0),
    range_size_(131072) {
  msgwnd_.Create(HWND_MESSAGE);
  msgwnd_.SetWindowLongPtr(GWLP_USERDATA, (LONG_PTR)this);
}

STDMETHODIMP CUploader::SetSite( IUnknown* punksite ) {
  if (punksite != NULL) {
    CComQIPtr<IServiceProvider> sp = punksite;
    HRESULT hr = sp->QueryService(IID_IWebBrowserApp,
      IID_IWebBrowser2, (void**)&pwebbrowser_);
    hr = pwebbrowser_->get_Document((IDispatch**)&phtmldoc_);
    CComQIPtr<IOleWindow> pwindow;
    sp->QueryService(SID_SShellBrowser, IID_IOleWindow,
      (void**)&pwindow);
    pwindow->GetWindow(&hwnd_browser_);
  } else {
    //release pointer
    pwebbrowser_.Release();
    phtmldoc_.Release();
  }
  return IObjectWithSiteImpl<CUploader>::SetSite(punksite);
}

STDMETHODIMP CUploader::get_MD5(BSTR* pVal) {
  // TODO: Add your implementation code here
  //alloc string to return
  *pVal = ::SysAllocStringLen(md5_.c_str(), md5_.length());
  return S_OK;
}

STDMETHODIMP CUploader::get_PostedLength(ULONGLONG* pVal) {
  // TODO: Add your implementation code here
  *pVal = posted_length_;
  return S_OK;
}

STDMETHODIMP CUploader::put_PostedLength(ULONGLONG newVal) {
  // TODO: Add your implementation code here
  posted_length_ = newVal;
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

STDMETHODIMP CUploader::get_FileSizeLimit(ULONGLONG* pVal) {
  // TODO: Add your implementation code here
  *pVal = file_size_limit_;
  return S_OK;
}

STDMETHODIMP CUploader::put_FileSizeLimit(ULONGLONG newVal) {
  // TODO: Add your implementation code here
  file_size_limit_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_RangeSize(ULONGLONG* pVal) {
  // TODO: Add your implementation code here
  *pVal = range_size_;
  return S_OK;
}

STDMETHODIMP CUploader::put_RangeSize(ULONGLONG newVal) {
  // TODO: Add your implementation code here
  range_size_ = newVal;
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
  object_.CopyTo(pVal);
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
  if (local_file_.empty() || post_url_.empty()) {
    *result = 0;
  } else {
    boost::thread t(std::bind(&CUploader::DoPost, this));
    t.detach();
    *result = (BYTE)-1;
  }
  return S_OK;
}

STDMETHODIMP CUploader::CheckFile(BYTE* result) {
  // TODO: Add your implementation code here
  if (local_file_.empty()) {
    *result = 0;
  } else {
    boost::thread t(std::bind(&CUploader::CalcMd5, this, local_file_));
    t.detach();
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

void CUploader::CalcMd5( const std::wstring& file ) {
  std::function<void(ULONGLONG, ULONGLONG)> OnWorking = [this](ULONGLONG completed, ULONGLONG total){
    //更改共享变量，上锁
    mutex_calcmd5_.lock();
    md5_percent_ = (USHORT)ult::UIntMultDiv(100, completed, total);
    msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateMd5Working);
    mutex_calcmd5_.unlock();
  };
  mutex_calcmd5_.lock();
  md5_percent_ = 0;
  msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateMd5Working);
  mutex_calcmd5_.unlock();
  //同步计算
  std::wstring md5 = ult::MD5File(file, OnWorking);
  //计算完成，更改共享变量
  mutex_calcmd5_.lock();
  md5_ = md5;
  msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateMd5Complete);
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

void CUploader::DoPost( void ) {
  HRESULT hr;
  WinhttpUploader uploader;
  BOOST_FOREACH(PostField field, post_fields_) {
    std::string uvalue = ult::UnicodeToUtf8(field.value);
    uploader.AddField(field.key, uvalue.c_str(), uvalue.length());
  }
  ult::File f;
  if (!f.Open(local_file_)) {
    msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateError);
    return;
  }
  boost::filesystem::path file(local_file_);
  std::wstring name = file.filename().wstring();
  ULONGLONG filesize = f.GetSize();
  if (posted_length_ >= filesize) {
    msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateError);
    return;
  }
  ULONGLONG sendsize = filesize - posted_length_;
  if (sendsize > 0xfffff000) {
    msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateError);
    return;
  }
  int ret = uploader.BeginPost(post_url_, name, sendsize);
  if (ret != ult::HttpStatus::kSuccess) {
    msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateError);
    return;
  }
  msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateConnected);
  DWORD write, readed;
  stop_ = false;
  begin_post_time_ = ::GetTickCount();
  begin_post_cursor_ = posted_length_;
  msgwnd_.SetPostTimer();
  msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateUploading);
  ULONGLONG new_pos;
  DWORD buf_len = (DWORD)range_size_; // set buffer 128K
  char* buffer = new char[buf_len];
  f.Seek(posted_length_, &new_pos);
  bool isok = true;
  LONG last_state = 0;
  while (posted_length_ < filesize) {
    if (stop_) {
      isok = false;
      last_state = state::kStateStop;
      break;
    }
    write = (DWORD)min(filesize-posted_length_, buf_len);
    f.Read(buffer, write, &readed);
    if (readed != write) {
      isok = false;
      last_state = state::kStateError;
      break;
    }
    hr = uploader.WriteData(buffer, readed);
    if (FAILED(hr)) {
      isok = false;
      last_state = state::kStateError;
      break;
    }
    posted_length_ += write;
  }
  delete[] buffer;
  msgwnd_.KillPostTimer();
  if (!isok) {
    msgwnd_.PostMessageW(UM_STATE_CHANGE, last_state);
    return;
  }
  hr = uploader.EndPost();
  if (FAILED(hr)) {
    msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateError);
    return;
  }
  msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateUploadComplete);
  msgwnd_.PostMessage(UM_STATE_CHANGE, state::kStateLeisure);
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
    VARIANT param[5];
    param[0].ullVal = left_time;
    param[0].vt = VT_UI4;
    param[1].uiVal = percent;
    param[1].vt = VT_UI2;
    param[2].ullVal = new_posted;
    param[2].vt = VT_UI8;
    param[3].ullVal = speed;
    param[3].vt = VT_UI8;
    param[4].pdispVal = object_;
    param[4].vt = VT_DISPATCH;
    CComVariant result;
    ult::InvokeMethod(on_post_, param, 5, &result);
  }
  oldtk = newtk;
  old_posted = new_posted;
}

STDMETHODIMP CUploader::get_ErrorCode(LONG* pVal) {
  // TODO: Add your implementation code here
  *pVal = error_code_;
  return S_OK;
}