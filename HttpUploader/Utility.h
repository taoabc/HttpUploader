#pragma once

namespace ult {

HRESULT InvokeMethod(IDispatch* disp, VARIANT* param, UINT args, VARIANT* result);
HRESULT InvokeMethod(IDispatch* disp, DISPID dispid, VARIANT* param, UINT args, VARIANT* result);
DISPID FindId(IDispatch* disp, LPOLESTR name);
void StringAddNull(std::wstring* toadd);
bool GetFilesInDir(const std::wstring& dir, std::vector<std::wstring>* pvec);

}