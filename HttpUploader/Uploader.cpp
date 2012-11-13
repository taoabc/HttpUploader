// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"
#include "JsArrayObject.h"
#include "ult/file-dir.h"
#include "ult/md5.h"

#include <atlsafe.h>
#include <commdlg.h>
#include <ShlGuid.h>

// CUploader

STDMETHODIMP CUploader::SetSite(IUnknown* punksite) {
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


STDMETHODIMP CUploader::Test(LONG* result) {
  // TODO: Add your implementation code here
  /*CComQIPtr<IDispatch> pscript;
  phtmldoc_->get_Script(&pscript);
  CComBSTR func_name(L"JsTest");
  DISPID dispid;
  HRESULT hr = pscript->GetIDsOfNames(IID_NULL, &func_name, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
  if (SUCCEEDED(hr)) {
    DISPPARAMS dispparams;
    memset(&dispparams, 0, sizeof (dispparams));
    dispparams.cArgs = 3;
    CComVariant va_param[3] = {23, L"asdf", L";lkj"};
    dispparams.rgvarg = va_param;
    dispparams.cNamedArgs = 0;
    CComVariant va_result;
    UINT arrerr = -1;
    hr = pscript->Invoke(dispid, IID_NULL, 0, DISPATCH_METHOD, &dispparams, &va_result, NULL, &arrerr);
  }
  *result = 555;*/
  /*if (ontest_ != NULL) {
    DISPPARAMS dispparams;
    memset(&dispparams, 0, sizeof (dispparams));
    CComVariant va_result;
    ontest_->Invoke(0, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &dispparams, &va_result, NULL, NULL);
  }*/
  OnPost(1, 23, 235235, 45, 2636);
  return S_OK;
}

STDMETHODIMP CUploader::ShowDialog(void) {
  // TODO: Add your implementation code here
  std::vector<std::wstring> vec;
  GetOpenFiles(hwnd_browser_, &vec);
  std::wstring dir;
  std::wstring name;
  selected_file_name_.RemoveAll();
  selected_file_path_.RemoveAll();
  for (std::wstring i : vec) {
    ult::ToUpperpathAndFilename(i, L"\\", &dir, &name);
    selected_file_path_.Add(i.c_str());
    selected_file_name_.Add(name.c_str());
  }
  return S_OK;
}

STDMETHODIMP CUploader::get_UrlPost(BSTR* pVal) {
  // TODO: Add your implementation code here
  *pVal = post_url_;
  return S_OK;
}

STDMETHODIMP CUploader::put_UrlPost(BSTR newVal) {
  // TODO: Add your implementation code here
  post_url_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::GetSelectedFiles(IDispatch** result) {
  // TODO: Add your implementation code here
  JsArrayObject<BSTR, VT_BSTR>* p = new JsArrayObject<BSTR, VT_BSTR>;
  for (size_t i = 0; i < selected_file_path_.GetCount(); ++i) {
    p->PushBack(selected_file_path_.GetAt(i));
  }
  *result = p;
  return S_OK;
}

bool CUploader::GetOpenFiles(HWND hwnd, std::vector<std::wstring>* pvec) {
  OPENFILENAME ofn;
  const size_t buf_len = 8192;
  wchar_t* files = new wchar_t[buf_len];
  memset(&ofn, 0, sizeof (ofn));
  ofn.lStructSize = sizeof (ofn);
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = files;
  ofn.lpstrFile[0] = L'\0';
  ofn.nMaxFile = buf_len;
  ofn.lpstrFilter = L"All\0*.*\0";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = NULL;
  ofn.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
  if (FALSE == GetOpenFileName(&ofn)) {
    delete[] files;
    return false;
  }
  wchar_t* p = files;
  std::wstring dir(p);
  p += wcslen(p) + 1;
  if (*p == NULL) {
    pvec->push_back(dir);
  }
  while (*p != NULL) {
    std::wstring file_path(dir);
    ult::AppendPath(&file_path, p);
    pvec->push_back(file_path);
    p += wcslen(p) + 1;
  }
  delete[] files;
  return true;
}

STDMETHODIMP CUploader::get_OnTest(IDispatch** pVal) {
  // TODO: Add your implementation code here
  *pVal = ontest_;
  return S_OK;
}

STDMETHODIMP CUploader::put_OnTest(IDispatch* newVal) {
  // TODO: Add your implementation code here
  ontest_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_OnPost(IDispatch** pVal) {
  // TODO: Add your implementation code here
  *pVal = on_post_;
  return S_OK;
}

STDMETHODIMP CUploader::put_OnPost(IDispatch* newVal) {
  // TODO: Add your implementation code here
  on_post_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::get_OnStateChanged(IDispatch** pVal) {
  // TODO: Add your implementation code here
  *pVal = on_state_changed_;
  return S_OK;
}

STDMETHODIMP CUploader::put_OnStateChanged(IDispatch* newVal) {
  // TODO: Add your implementation code here
  on_state_changed_ = newVal;
  return S_OK;
}

STDMETHODIMP CUploader::Post(void) {
  // TODO: Add your implementation code here

  return S_OK;
}

STDMETHODIMP CUploader::Stop(void) {
  // TODO: Add your implementation code here

  return S_OK;
}

HRESULT CUploader::InvokeMethod(IDispatch* disp, VARIANT* param, UINT args, VARIANT* result) {
  return InvokeMethod(disp, 0, param, args, result);
}

HRESULT CUploader::InvokeMethod(IDispatch* disp, DISPID dispid, VARIANT* param, UINT args, VARIANT* result) {
  DISPPARAMS ps;
  ps.cArgs = args;
  ps.rgvarg = param;
  ps.cNamedArgs = 0;
  ps.rgdispidNamedArgs = NULL;

  return disp->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &ps, result, NULL, NULL);
}

DISPID CUploader::FindId(IDispatch* disp, LPOLESTR name) {
  DISPID id = 0;
  if(FAILED(disp->GetIDsOfNames(IID_NULL, &name, 1, LOCALE_SYSTEM_DEFAULT, &id))) {
    id = -1;
  }
  return id;
}

HRESULT CUploader::OnPost(int id, ULONGLONG speed, ULONGLONG posted, USHORT percent, UINT lefttime) {
  if (on_post_ != NULL) {
    CComVariant param[5];
    param[0] = lefttime;
    param[1] = percent;
    param[2] = posted;
    param[3] = speed;
    param[4] = id;
    CComVariant result;
    InvokeMethod(on_post_, param, 5, &result);
  }
  return S_OK;
}

HRESULT CUploader::OnStateChanged(int id, int state) {
  if (on_state_changed_ != NULL) {
    CComVariant param[2];
    param[0] = state;
    param[1] = id;
    CComVariant result;
    InvokeMethod(on_state_changed_, param, 2, &result);
  }
  return S_OK;
}

unsigned __stdcall CUploader::AsyncCalcMd5Thread(void* pparam) {
  //get and delete parameter
  CalcMd5Param* param = (CalcMd5Param*)pparam;
  const std::wstring file = param->file;
  CComQIPtr<IDispatch> disp = param->disp;
  delete param;
  std::wstring md5 = ult::MD5File(file);

  return 0;
}

STDMETHODIMP CUploader::CalcMd5(BSTR file_name, BSTR* result) {
  // TODO: Add your implementation code here
  std::wstring filename(file_name, ::SysStringLen(file_name));
  std::wstring md5 = ult::MD5File(filename);
  *result = ::SysAllocStringLen(md5.c_str(), md5.length());
  return S_OK;
}

STDMETHODIMP CUploader::AsyncCalcMd5(BSTR file, IDispatch* callback, LONG* result) {
  // TODO: Add your implementation code here
  CalcMd5Param* param = new CalcMd5Param;
  param->file.assign(file, ::SysStringLen(file));
  param->disp = callback;
  CloseHandle((HANDLE)_beginthreadex(NULL, 0, AsyncCalcMd5Thread, param, 0, NULL));
  return S_OK;
}