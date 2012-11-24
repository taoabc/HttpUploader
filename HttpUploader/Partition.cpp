// Partition.cpp : Implementation of CPartition

#include "stdafx.h"
#include "Partition.h"

#include <ShlGuid.h>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>

// CPartition

CPartition::CPartition( void ) {

}

STDMETHODIMP CPartition::SetSite( IUnknown* punksite ) {
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
  return IObjectWithSiteImpl<CPartition>::SetSite(punksite);
}

STDMETHODIMP CPartition::ShowDialog(BYTE* result) {
  // TODO: Add your implementation code here
  std::vector<std::wstring> vec;
  GetOpenFiles(hwnd_browser_, &vec);
  std::wstring dir;
  std::wstring name;
  selected_file_.clear();
  BOOST_FOREACH(std::wstring i, vec) {
    selected_file_.push_back(i);
  }
  return S_OK;
}

bool CPartition::GetOpenFiles( HWND hwnd, std::vector<std::wstring>* pvec ) {
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
    boost::filesystem::path file_path(dir);
    file_path /= p;
    pvec->push_back(file_path.wstring());
    p += wcslen(p) + 1;
  }
  delete[] files;
  return true;
}

HRESULT CPartition::InvokeMethod( IDispatch* disp, VARIANT* param, UINT args, VARIANT* result ) {
  return InvokeMethod(disp, 0, param, args, result);
}

HRESULT CPartition::InvokeMethod( IDispatch* disp, DISPID dispid, VARIANT* param, UINT args, VARIANT* result ) {
  DISPPARAMS ps;
  ps.cArgs = args;
  ps.rgvarg = param;
  ps.cNamedArgs = 0;
  ps.rgdispidNamedArgs = NULL;

  return disp->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &ps, result, NULL, NULL);
}

DISPID CPartition::FindId( IDispatch* disp, LPOLESTR name ) {
  DISPID id = 0;
  if(FAILED(disp->GetIDsOfNames(IID_NULL, &name, 1, LOCALE_SYSTEM_DEFAULT, &id))) {
    id = -1;
  }
  return id;
}


STDMETHODIMP CPartition::get_FileFilter(BSTR* pVal)
{
  // TODO: Add your implementation code here

  return S_OK;
}


STDMETHODIMP CPartition::put_FileFilter(BSTR newVal)
{
  // TODO: Add your implementation code here

  return S_OK;
}
