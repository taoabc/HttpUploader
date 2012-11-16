#include "stdafx.h"
#include "MsgWnd.h"
#include "Uploader.h"

#include <memory>

MsgWnd::MsgWnd(void) {
}

MsgWnd::~MsgWnd(void) {
  DestroyWindow();
}

LRESULT MsgWnd::OnCalcMd5(UINT msg, WPARAM wparam, LPARAM lparam, BOOL& handled) {
  CUploader* uploader = GetUploader();
  std::shared_ptr<Md5GettedParam> param((Md5GettedParam*)wparam);
  CComVariant callback_param[2];
  callback_param[0] = param->md5.c_str();
  callback_param[1] = param->file.c_str();
  CComVariant result;
  uploader->InvokeMethod(param->disp, callback_param, 2, &result);
  param->disp->Release();
  return 0;
}

CUploader* MsgWnd::GetUploader(void) {
  return (CUploader*)GetWindowLongPtr(GWLP_USERDATA);
}