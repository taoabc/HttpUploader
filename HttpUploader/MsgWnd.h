#pragma once

#include <atlwin.h>

#include <string>

#define UM_MD5GETTED                   WM_USER + 1

struct Md5GettedParam {
  IDispatch* disp;
  std::wstring file;
  std::wstring md5;
};

class CUploader;

class MsgWnd :
      public ATL::CWindowImpl<MsgWnd, ATL::CWindow, ATL::CWinTraits<0, 0>> {

public:
  
  DECLARE_WND_CLASS(L"HttpUploader MsgWnd")

  BEGIN_MSG_MAP(MsgWnd)
    MESSAGE_HANDLER(UM_MD5GETTED, OnCalcMd5)
  END_MSG_MAP()

  MsgWnd(void);
  ~MsgWnd(void);

private:

  CUploader* GetUploader(void);
  
  LRESULT OnCalcMd5(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
};