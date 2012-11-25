/*
** 该类实现回调后在同一线程中进行处理
** 使用窗口消息可以避免在别的线程中调用IDispatch的Invoke函数失败的问题
** author
**   taoabc@gmail.com
*/
#pragma once

#include <atlwin.h>

#include <string>

#define UM_CALCMD5                     WM_USER + 1
#define UM_CALCMD5_COMPLETE            WM_USER + 2

class CUploader;

class MsgWnd :
      public ATL::CWindowImpl<MsgWnd, ATL::CWindow, ATL::CWinTraits<0, 0>> {

public:
  
  DECLARE_WND_CLASS(L"HttpUploader MsgWnd")

  BEGIN_MSG_MAP(MsgWnd)
    MESSAGE_HANDLER(UM_CALCMD5, OnCalcMd5)
    MESSAGE_HANDLER(UM_CALCMD5_COMPLETE, OnCalcMd5Completed)
  END_MSG_MAP()

  MsgWnd(void);
  ~MsgWnd(void);

private:

  enum {
    kStateLeisure        = 0,
    kStateUploading      = 1,
    kStateStop           = 2,
    kStateUploadComplate = 3,
    kStateError          = 4,
    kStateConnected      = 5,
    kStateMd5Working     = 6,
    kStateMd5Complete    = 7,
  };

  CUploader* GetUploader(void);

  void SetUploaderState(LONG state);

  LRESULT OnCalcMd5(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
  LRESULT OnCalcMd5Completed(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled);
};