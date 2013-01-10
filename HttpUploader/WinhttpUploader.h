#pragma once

#include "ult/net/winhttp-downloader-status.h"
#include "ult/sync-winhttp-request.h"
#include <vector>

#ifndef RETURN_IF_FAILED
#define RETURN_IF_FAILED(x) { HRESULT __result_ = (x); if (FAILED(__result_)) return __result_; }
#endif

struct PostField {
  std::wstring key;
  std::wstring value;
};

class WinhttpUploader :
    public ult::SyncWinHttpRequest {

public:

  WinhttpUploader(void);
  ~WinhttpUploader(void);

  void Reset(void);

  int InitRequest(const std::wstring& url);
  std::string AddTempFiled(const std::wstring& field, const char* data, DWORD len);
  void ClearField(void);
  HRESULT PreparePost(const std::wstring& url, const std::wstring& filename, const std::vector<PostField>& post_fields);
  HRESULT PostFile(const void* data, DWORD len, ULONGLONG begine_pos);
  DWORD GetStatus(void) const;
  std::string GetRecvString(void) const;
  DWORD GetWritted(void) const;

private:
  
  HRESULT OnReadComplete(const void* info, DWORD length);
  void AddField(const std::wstring& field, const char* data, DWORD len);
  void InitBoundary(void);

  ult::WinHttpSession session_;
  ult::WinHttpConnection connection_;

  std::string aboundary_;
  std::wstring wboundary_;
  std::string sendfield_;
  std::wstring header_;
  std::string postbegin_;
  std::string postend_;
  DWORD status_;
  std::string string_rcv_;
  std::wstring url_;
  std::string ufilename_;
  std::vector<PostField> post_fields_;

  DWORD writed_;
  
  static const std::string kLineEnd_;
  static const std::wstring kLineEndW_;
  static const DWORD kChunkSize_;
};