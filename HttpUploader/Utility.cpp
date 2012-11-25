#include "StdAfx.h"
#include "Utility.h"
#include "ult/file-dir.h"
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>

namespace ult {

void StringAddNull( std::wstring* toadd ) {
  toadd->append(L"\0", 1);
}

HRESULT InvokeMethod( IDispatch* disp, VARIANT* param, UINT args, VARIANT* result ) {
  return ult::InvokeMethod(disp, 0, param, args, result);
}

HRESULT InvokeMethod( IDispatch* disp, DISPID dispid, VARIANT* param, UINT args, VARIANT* result ) {
  DISPPARAMS ps;
  ps.cArgs = args;
  ps.rgvarg = param;
  ps.cNamedArgs = 0;
  ps.rgdispidNamedArgs = NULL;

  return disp->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, &ps, result, NULL, NULL);
}

DISPID FindId( IDispatch* disp, LPOLESTR name ) {
  DISPID id = 0;
  if(FAILED(disp->GetIDsOfNames(IID_NULL, &name, 1, LOCALE_SYSTEM_DEFAULT, &id))) {
    id = -1;
  }
  return id;
}

bool GetFilesInDir( const std::wstring& dir, std::vector<std::wstring>* pvec ) {
  boost::filesystem::path dir_path(dir);
  boost::filesystem::recursive_directory_iterator iter_end;
  pvec->clear();
  for (boost::filesystem::recursive_directory_iterator iter(dir_path); iter != iter_end; ++iter) {
    if (boost::filesystem::is_regular_file(iter->path())) {
      pvec->push_back(iter->path().wstring());
    }
  }
  return true;
}

}