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
  std::shared_ptr<Md5GettedParam> param((Md5GettedParam*)wparam);
  CUploader* uploader = GetUploader();
  uploader->OnMd5Getted(param->id, param->md5);
  return 0;
}

LRESULT MsgWnd::OnPost(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled) {
  std::shared_ptr<PostParam> param((PostParam*)wparam);
  CUploader* uploader = GetUploader();
  uploader->OnPost(param->id, param->speed, param->posted, param->percent);
  return 0;
}

LRESULT MsgWnd::OnStateChanged(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled) {
  std::shared_ptr<StateChangedParam> param((StateChangedParam*)wparam);
  CUploader* uploader = GetUploader();
  uploader->OnStateChanged(param->id, param->state);
  return 0;
}