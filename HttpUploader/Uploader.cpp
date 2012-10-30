// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"


// CUploader

STDMETHODIMP CUploader::SetSite(IUnknown* punksite) {
  if (punksite != NULL) {
    CComQIPtr<IServiceProvider> sp = punksite;
    HRESULT hr = sp->QueryService(IID_IWebBrowserApp,
        IID_IWebBrowser2, (void**)&pwebbrowser_);
  } else {
    //release pointer
    pwebbrowser_.Release();
  }
  return IObjectWithSiteImpl<CUploader>::SetSite(punksite);
}


STDMETHODIMP CUploader::Test(LONG* result)
{
  // TODO: Add your implementation code here
  *result = 3;
  return S_OK;
}