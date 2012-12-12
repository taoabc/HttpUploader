#include "stdafx.h"
#include "MsgWnd.h"
#include "Uploader.h"

#include <memory>

MsgWnd::MsgWnd(void) {
}

MsgWnd::~MsgWnd(void) {
  DestroyWindow();
}

CUploader* MsgWnd::GetUploader(void) {
  return (CUploader*)GetWindowLongPtr(GWLP_USERDATA);
}

void MsgWnd::SetUploaderState( LONG state ) {
  CUploader* up = GetUploader();
  up->SetState(state);
}

LRESULT MsgWnd::OnStateChange( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled ) {
  SetUploaderState(wparam);
  return 0;
}

bool MsgWnd::SetPostTimer( void ) {
  post_timer_ = GetUniqueId();
  return NULL != SetTimer(post_timer_, kCheckPostInteval_);
}

UINT_PTR MsgWnd::GetUniqueId( void ) {
  static UINT_PTR id = 1;
  return id++;
}

bool MsgWnd::KillPostTimer( void ) {
  return TRUE == KillTimer(post_timer_);
}

LRESULT MsgWnd::OnTimer( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled ) {
  if (wparam == post_timer_) {
    CUploader* uploader = GetUploader();
    uploader->OnPostTimer();
  }
  return 0;
}

LRESULT MsgWnd::OnPost( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled ) {
  CUploader* uploader = GetUploader();
  OnPostParam* param = (OnPostParam*)wparam;
  uploader->OnPostCallback(param->speed, param->posted, param->percent, param->left_time);
  return 0;
}
