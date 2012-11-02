// Uploader.h : Declaration of the CUploader

#pragma once
#include "resource.h"       // main symbols

#include "HttpUploader_i.h"

#include <atlctl.h>
#include <atlcoll.h>
#include <vector>
#include <string>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CUploader

class ATL_NO_VTABLE CUploader :
	  public CComObjectRootEx<CComSingleThreadModel>,
	  public CComCoClass<CUploader, &CLSID_Uploader>,
	  public IObjectWithSiteImpl<CUploader>,
	  public IDispatchImpl<IUploader, &IID_IUploader, &LIBID_HttpUploaderLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public IObjectSafetyImpl<CUploader, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA> {
public:
	CUploader()	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_UPLOADER)

DECLARE_NOT_AGGREGATABLE(CUploader)

BEGIN_COM_MAP(CUploader)
	COM_INTERFACE_ENTRY(IUploader)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
  COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() {
		return S_OK;
	}

	void FinalRelease() {
	}

public:
  // IObjectWithSite
  STDMETHOD(SetSite)(IUnknown* punksite);

private:

  //project independent
  bool GetOpenFiles(HWND hwnd, std::vector<std::wstring>* pvec);

  HRESULT InvokeMethod(IDispatch* disp, VARIANT* param, UINT args, VARIANT* result);
  HRESULT InvokeMethod(IDispatch* disp, DISPID dispid, VARIANT* param, UINT args, VARIANT* result);
  DISPID FindId(IDispatch* disp, LPOLESTR name);

  //project related
  HRESULT OnPost(int id, ULONGLONG speed, ULONGLONG posted, USHORT percent, UINT lefttime);
  HRESULT OnStateChanged(int id, int state);

  CComQIPtr<IWebBrowser2> pwebbrowser_;
  CComQIPtr<IHTMLDocument2> phtmldoc_;
  HWND hwnd_browser_;
  CComBSTR post_url_;
  CAtlArray<CComBSTR> selected_file_path_;
  CAtlArray<CComBSTR> selected_file_name_;
  CComQIPtr<IDispatch> ontest_;
  CComQIPtr<IDispatch> on_post_;
  CComQIPtr<IDispatch> on_state_changed_;

public:

  STDMETHOD(Test)(LONG* result);
  STDMETHOD(ShowDialog)(void);
  STDMETHOD(get_UrlPost)(BSTR* pVal);
  STDMETHOD(put_UrlPost)(BSTR newVal);
  STDMETHOD(GetSelectedFiles)(IDispatch** result);
  STDMETHOD(get_OnTest)(IDispatch** pVal);
  STDMETHOD(put_OnTest)(IDispatch* newVal);
  STDMETHOD(get_OnPost)(IDispatch** pVal);
  STDMETHOD(put_OnPost)(IDispatch* newVal);
  STDMETHOD(get_OnStateChanged)(IDispatch** pVal);
  STDMETHOD(put_OnStateChanged)(IDispatch* newVal);
  STDMETHOD(Post)(void);
  STDMETHOD(Stop)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(Uploader), CUploader)
