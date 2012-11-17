/*
** 该类实现回调后在同一线程中进行处理
** 使用窗口消息可以避免在别的线程中调用IDispatch的Invoke函数失败的问题
** author
**   taoabc@gmail.com
*/
#pragma once

#include <atlwin.h>

#include <string>

#define UM_MD5GETTED                   WM_USER + 1
#define UM_STATECHANGED                WM_USER + 2
#define UM_POST                        WM_USER + 3

struct Md5GettedParam {
  ULONG id;
  std::wstring md5;
};

struct StateChangedParam {
  ULONG id;
  LONG state;
};

struct PostParam {
  ULONG id;
  ULONGLONG speed;
  ULONGLONG posted;
  USHORT percent;
};

class CUploader;

class MsgWnd :
      public ATL::CWindowImpl<MsgWnd, ATL::CWindow, ATL::CWinTraits<0, 0>> {

public:
  
  DECLARE_WND_CLASS(L"HttpUploader MsgWnd")

  BEGIN_MSG_MAP(MsgWnd)
    MESSAGE_HANDLER(UM_MD5GETTED, OnCalcMd5)
    MESSAGE_HANDLER(UM_POST, OnPost)
    MESSAGE_HANDLER(UM_STATECHANGED, OnStateChanged)
  END_MSG_MAP()

  MsgWnd(void);
  ~MsgWnd(void);

private:

  CUploader* GetUploader(void);
  
  LRESULT OnCalcMd5(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
  LRESULT OnPost(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
  LRESULT OnStateChanged(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
};