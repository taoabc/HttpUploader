// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"
#include "JsArrayObject.h"
#include "ult/file-dir.h"

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
  CComQIPtr<IDispatch> pscript;
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
  *result = 555;
  return S_OK;
}

STDMETHODIMP CUploader::ShowDialog(void) {
  // TODO: Add your implementation code here
  std::vector<std::wstring> vec;
  GetOpenFiles(hwnd_browser_, &vec);
  std::wstring name;
  for (std::wstring i : vec) {
    ult::ToUpperpathAndFilename(i, L"\\", NULL, &name);
    selected_file_path_.Add(i.c_str());
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
  for (size_t i = 0; i < selected_file_name_.GetCount(); ++i) {
    p->PushBack(selected_file_name_.GetAt(i));
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
  if (p == NULL) {
    pvec->push_back(dir);
  }
  while (*p != NULL) {
    std::wstring file_path(dir);
    file_path += p;
    pvec->push_back(file_path);
    p += wcslen(p) + 1;
  }
  delete[] files;
  return true;
}