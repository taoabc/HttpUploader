// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"
#include "Utility.h"
#include "ult/md5.h"
#include "ult/number.h"

#include <ShlGuid.h>
// CUploader

CUploader::CUploader( void ) :
    posted_length_(0) {
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

STDMETHODIMP CUploader::put_MD5(BSTR newVal) {
  // TODO: Add your implementation code here
  md5_.assign(newVal, ::SysStringLen(newVal));
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

STDMETHODIMP CUploader::ClearFields(LONG* result) {
  // TODO: Add your implementation code here

  return S_OK;
}

STDMETHODIMP CUploader::AddField(BSTR key, BSTR value) {
  // TODO: Add your implementation code here

  return S_OK;
}

STDMETHODIMP CUploader::Post(LONG* result) {
  // TODO: Add your implementation code here
  if (local_file_.empty() || post_url_.empty()) {
    *result = 0;
  } else {
    boost::thread t(std::bind(&CUploader::DoPost, this));
    t.detach();
    *result = 1;
  }
  return S_OK;
}

STDMETHODIMP CUploader::CheckFile(LONG* result) {
  // TODO: Add your implementation code here
  if (local_file_.empty()) {
    *result = 0;
  } else {
    boost::thread t(std::bind(&CUploader::CalcMd5, this, local_file_));
    t.detach();
    *result = 1;
  }
  return S_OK;
}

STDMETHODIMP CUploader::Stop(LONG* result) {
  // TODO: Add your implementation code here

  return S_OK;
}

void CUploader::CalcMd5( const std::wstring& file ) {
  std::function<void(ULONGLONG, ULONGLONG)> OnWorking = [this](ULONGLONG completed, ULONGLONG total){
    //更改共享变量，上锁
    mutex_calcmd5_.lock();
    md5_percent_ = (USHORT)ult::UIntMultDiv(100, completed, total);
    msgwnd_.PostMessage(UM_CALCMD5);
    mutex_calcmd5_.unlock();
  };
  mutex_calcmd5_.lock();
  md5_percent_ = 0;
  msgwnd_.PostMessage(UM_CALCMD5);
  mutex_calcmd5_.unlock();
  //同步计算
  std::wstring md5 = ult::MD5File(file, OnWorking);
  //计算完成，更改共享变量
  mutex_calcmd5_.lock();
  md5_ = md5;
  msgwnd_.PostMessage(UM_CALCMD5_COMPLETE);
  mutex_calcmd5_.unlock();
}

STDMETHODIMP CUploader::get_Md5Percent(USHORT* pVal) {
  // TODO: Add your implementation code here
  *pVal = md5_percent_;
  return S_OK;
}

STDMETHODIMP CUploader::put_Md5Percent(USHORT newVal) {
  // TODO: Add your implementation code here
  md5_percent_ = newVal;
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

}
