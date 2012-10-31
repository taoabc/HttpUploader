// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"


// CUploader

STDMETHODIMP CUploader::SetSite(IUnknown* punksite) {
  if (punksite != NULL) {
    CComQIPtr<IServiceProvider> sp = punksite;
    HRESULT hr = sp->QueryService(IID_IWebBrowserApp,
        IID_IWebBrowser2, (void**)&pwebbrowser_);
    hr = pwebbrowser_->get_Document((IDispatch**)&phtmldoc_);
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
  *result = 3;
  return S_OK;
}

STDMETHODIMP CUploader::ShowDialog(void) {
  // TODO: Add your implementation code here

  return S_OK;
}
