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

LRESULT MsgWnd::OnCalcMd5(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled) {
  SetUploaderState(kStateMd5Working);
  return 0;
}

LRESULT MsgWnd::OnCalcMd5Completed( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled ) {
  SetUploaderState(kStateMd5Complete);
  return 0;
}

void MsgWnd::SetUploaderState( LONG state ) {
  CUploader* up = GetUploader();
  up->SetState(state);
}
