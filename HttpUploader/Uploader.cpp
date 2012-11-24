// Uploader.cpp : Implementation of CUploader

#include "stdafx.h"
#include "Uploader.h"

#include <boost/thread/thread.hpp>

#include <ShlGuid.h>
// CUploader

CUploader::CUploader( void ) {

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
