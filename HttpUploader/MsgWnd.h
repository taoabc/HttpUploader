/*
** 该类实现回调后在同一线程中进行处理
** 使用窗口消息可以避免在别的线程中调用IDispatch的Invoke函数失败的问题
** author
**   taoabc@gmail.com
*/
#pragma once

#include <atlwin.h>

#include <string>

#define UM_STATE_CHANGE                             WM_USER + 1
#define UM_ON_POST                                  WM_USER + 2

struct OnPostParam {
  USHORT percent;
  DWORD left_time;
  ULONGLONG speed;
  ULONGLONG posted;
};

class CUploader;

class MsgWnd :
      public ATL::CWindowImpl<MsgWnd, ATL::CWindow, ATL::CWinTraits<0, 0>> {

public:
  
  DECLARE_WND_CLASS(L"HttpUploader MsgWnd")

  BEGIN_MSG_MAP(MsgWnd)
    MESSAGE_HANDLER(UM_STATE_CHANGE, OnStateChange)
    MESSAGE_HANDLER(UM_ON_POST, OnPost)
    MESSAGE_HANDLER(WM_TIMER, OnTimer)
  END_MSG_MAP()

  MsgWnd(void);
  ~MsgWnd(void);

  bool SetPostTimer(void);
  bool KillPostTimer(void);

private:

  CUploader* GetUploader(void);
  void SetUploaderState(LONG state);
  UINT_PTR GetUniqueId(void);

  LRESULT OnStateChange(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
  LRESULT OnPost(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
  LRESULT OnTimer(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);

  UINT_PTR post_timer_;

  static const UINT kCheckPostInteval_ = 1500;
};