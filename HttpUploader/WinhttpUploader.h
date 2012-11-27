#pragma once

#include "ult/net/winhttp-downloader-status.h"
#include "ult/sync-winhttp-request.h"

#ifndef RETURN_IF_FAILED
#define RETURN_IF_FAILED(x) { HRESULT __result_ = (x); if (FAILED(__result_)) return __result_; }
#endif

class WinhttpUploader :
    public ult::SyncWinHttpRequest {

public:

  WinhttpUploader(void);
  ~WinhttpUploader(void);

  void Reset(void);

  void AddField(const std::wstring& field, const char* data, DWORD len);
  int BeginPost(const std::wstring& url, const std::wstring& filename,
      ULONGLONG sendsize, const std::wstring& field=L"file");
  HRESULT PostFile(const void* data, DWORD len);
  HRESULT EndPost(void);

private:

  int InitRequest(const std::wstring& url);
  void InitBoundary(void);

  ult::WinHttpSession session_;
  ult::WinHttpConnection connection_;

  std::string aboundary_;
  std::wstring wboundary_;
  std::string sendfield_;
  std::string postend_;
  
  static const std::string kLineEnd_;
  static const std::wstring kLineEndW_;
};