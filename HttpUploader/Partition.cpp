// Partition.cpp : Implementation of CPartition

#include "stdafx.h"
#include "Partition.h"
#include "Utility.h"
#include "JsArrayObject.h"
#include "ult/file-dir.h"
#include "ult/string-operate.h"
#include <boost/filesystem.hpp>
#include <ShlGuid.h>

// CPartition

CPartition::CPartition( void ) :
    allow_select_multi_file_(false)  {

}

STDMETHODIMP CPartition::SetSite( IUnknown* punksite ) {
  if (punksite != NULL) {
    CComQIPtr<IServiceProvider> sp = punksite;
    /*HRESULT hr = sp->QueryService(IID_IWebBrowserApp,
    IID_IWebBrowser2, (void**)&pwebbrowser_);*/
    CComQIPtr<IOleWindow> pwindow;
    sp->QueryService(SID_SShellBrowser, IID_IOleWindow,
      (void**)&pwindow);
    pwindow->GetWindow(&hwnd_browser_);
  } else {
    //release pointer
  }
  return IObjectWithSiteImpl<CPartition>::SetSite(punksite);
}

bool CPartition::GetOpenFiles(HWND hwnd, std::wstring file_filter, bool multi_select, std::vector<std::wstring>* pvec) {
  OPENFILENAME ofn;
  const size_t buf_len = 8192;
  wchar_t* files = new wchar_t[buf_len];
  memset(&ofn, 0, sizeof (ofn));
  ofn.lStructSize = sizeof (ofn);
  ofn.hwndOwner = hwnd;
  ofn.lpstrFile = files;
  ofn.lpstrFile[0] = L'\0';
  ofn.nMaxFile = buf_len;
  ofn.lpstrFilter = file_filter.empty() ? NULL : file_filter.c_str();
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = NULL;
  ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
  if (multi_select) {
    ofn.Flags |= OFN_ALLOWMULTISELECT;
  }
  bool result = false;
  do {
    if (FALSE == ::GetOpenFileName(&ofn)) {
      break;
    }
    if (!multi_select) {
      pvec->push_back(files);
      break;
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
    result = true;
  } while (false);
  
  delete[] files;
  return result;
}

bool CPartition::GetOpenDir( HWND hwnd, std::wstring* dir ) {
  wchar_t buf[MAX_PATH];
  BROWSEINFO bi;
  memset(&bi, 0, sizeof (bi));
  bi.hwndOwner = hwnd;
  bi.pszDisplayName = buf;
  bi.ulFlags = BIF_NEWDIALOGSTYLE;
  PIDLIST_ABSOLUTE pa = SHBrowseForFolder(&bi);
  if (pa == NULL) {
    return false;
  }
  SHGetPathFromIDList(pa, buf);
  CoTaskMemFree(pa);
  *dir = buf;
  return true;
}

std::wstring CPartition::NormalFileFilter( const std::wstring& filter ) {
  if (filter.empty()) {
    return L"";
  }
  std::vector<std::wstring> vec;
  ult::SplitString(filter, L",", &vec);
  std::wstring result(L"Allowed Files(");
  if (vec.size() == 0) {
    result += L"*.*)";
    ult::StringAddNull(&result);
    result += L"*.*";
  } else {
    BOOST_FOREACH(std::wstring item, vec) {
      result += L"*." + item + L" ";
    }
    result.pop_back();
    result += L")";
    ult::StringAddNull(&result);
    BOOST_FOREACH(std::wstring item, vec) {
      result += L"*." + item + L";";
    }
    result.pop_back();
  }
  ult::StringAddNull(&result);
  ult::StringAddNull(&result);
  return result;
}

STDMETHODIMP CPartition::ShowDialog(BYTE* result) {
  // TODO: Add your implementation code here
  std::wstring real_filter = NormalFileFilter(file_filter_);
  std::vector<std::wstring> vec;
  if (!GetOpenFiles(hwnd_browser_, real_filter, allow_select_multi_file_, &vec)) {
    *result = 0;
    return S_OK;
  }
  selected_file_ = vec;
  *result = 1;
  return S_OK;
}

STDMETHODIMP CPartition::get_FileFilter(BSTR* pVal) {
  // TODO: Add your implementation code here
  //复制一份返回
  *pVal = ::SysAllocStringLen(file_filter_.c_str(), file_filter_.length());
  return S_OK;
}

STDMETHODIMP CPartition::put_FileFilter(BSTR newVal) {
  // TODO: Add your implementation code here
  file_filter_.assign(newVal, ::SysStringLen(newVal));
  return S_OK;
}

STDMETHODIMP CPartition::get_AllowMultiSelect(BYTE* pVal) {
  // TODO: Add your implementation code here
  *pVal = allow_select_multi_file_ ? 1 : 0;
  return S_OK;
}

STDMETHODIMP CPartition::put_AllowMultiSelect(BYTE newVal) {
  // TODO: Add your implementation code here
  allow_select_multi_file_ = (newVal == 0) ? false : true;
  return S_OK;
}

STDMETHODIMP CPartition::ShowFolder(BYTE* result) {
  // TODO: Add your implementation code here
  std::wstring select_dir;
  if (!GetOpenDir(hwnd_browser_, &select_dir)) {
    *result = 0;
    return S_OK;
  }
  std::vector<std::wstring> vec;
  if (!ult::GetFilesInDir(select_dir, &vec)) {
    *result = 0;
    return S_OK;
  }
  selected_file_ = vec;
  *result = 1;
  return S_OK;
}

STDMETHODIMP CPartition::GetSelectedFiles(IDispatch** result) {
  // TODO: Add your implementation code here
  JsArrayObject* p = new JsArrayObject;
  BOOST_FOREACH(std::wstring i, selected_file_) {
    p->PushBack(CComVariant(i.c_str()));
  }
  *result = p;
  return S_OK;
}

STDMETHODIMP CPartition::GetClipboardFiles(IDispatch** result) {
  // TODO: Add your implementation code here
  std::vector<std::wstring> files;
  if (TRUE == ::IsClipboardFormatAvailable(CF_HDROP) && TRUE == ::OpenClipboard(NULL)) {
    HANDLE h = ::GetClipboardData(CF_HDROP);
    if (h != NULL) {
      wchar_t buf[MAX_PATH];
      HDROP hdrop = (HDROP)GlobalLock(h);
      UINT file_count = ::DragQueryFile(hdrop, (UINT)-1, buf, MAX_PATH);
      for (UINT i = 0; i < file_count; ++i) {
        ::DragQueryFile(hdrop, i, buf, MAX_PATH);
        if (boost::filesystem::is_regular_file(buf)) {
          files.push_back(buf);
        }
      }
      GlobalUnlock(h);
    }
    CloseClipboard();
  }
  JsArrayObject* p = new JsArrayObject;
  BOOST_FOREACH(std::wstring i, files) {
    p->PushBack(CComVariant(i.c_str()));
  }
  *result = p;
  return S_OK;
}

STDMETHODIMP CPartition::GetFileSize(BSTR file, DOUBLE* result) {
  // TODO: Add your implementation code here
  *result = 0;
  std::wstring filew(file, ::SysStringLen(file));
  if (boost::filesystem::exists(filew)) {
    *result = (DOUBLE)boost::filesystem::file_size(filew);
  }
  return S_OK;
}

STDMETHODIMP CPartition::ClearSelectedFiles(BYTE* result) {
  // TODO: Add your implementation code here
  selected_file_.clear();
  *result = (BYTE)-1;
  return S_OK;
}

HRESULT CPartition::FinalConstruct(void) {
  return S_OK;
}

void CPartition::FinalRelease( void ) {

}
