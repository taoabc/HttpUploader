// Partition.h : Declaration of the CPartition

#pragma once
#include "resource.h"       // main symbols



#include "HttpUploader_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CPartition

class ATL_NO_VTABLE CPartition :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPartition, &CLSID_Partition>,
	public IObjectWithSiteImpl<CPartition>,
  public IDispatchImpl<IPartition, &IID_IPartition, &LIBID_HttpUploaderLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
  public IObjectSafetyImpl<CPartition, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA> {
public:
	CPartition(void);

DECLARE_REGISTRY_RESOURCEID(IDR_PARTITION)

DECLARE_NOT_AGGREGATABLE(CPartition)

BEGIN_COM_MAP(CPartition)
	COM_INTERFACE_ENTRY(IPartition)
	COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(IObjectWithSite)
  COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() {
		return S_OK;
	}

	void FinalRelease()	{
	}

private:

  // IObjectWithSite
  STDMETHOD(SetSite)(IUnknown* punksite);

  //project independent
  bool GetOpenFiles(HWND hwnd, std::wstring file_filter, bool multi_select, std::vector<std::wstring>* pvec);
  bool GetOpenDir(HWND hwnd, std::wstring* dir);

  //project depend
  std::wstring NormalFileFilter(const std::wstring& filter);

  //ie related
  CComQIPtr<IWebBrowser2> pwebbrowser_;
  CComQIPtr<IHTMLDocument2> phtmldoc_;
  HWND hwnd_browser_;

  std::vector<std::wstring> selected_file_;
  std::wstring file_filter_;
  bool allow_select_multi_file_;

public:
  STDMETHOD(ShowDialog)(BYTE* result);
  STDMETHOD(get_FileFilter)(BSTR* pVal);
  STDMETHOD(put_FileFilter)(BSTR newVal);
  STDMETHOD(get_AllowMultiSelect)(BYTE* pVal);
  STDMETHOD(put_AllowMultiSelect)(BYTE newVal);
  STDMETHOD(ShowFolder)(BYTE* result);
  STDMETHOD(GetSelectedFiles)(IDispatch** result);
  STDMETHOD(GetClipboardFiles)(IDispatch** result);
  STDMETHOD(GetFileSize)(BSTR file, ULONGLONG* result);
};

OBJECT_ENTRY_AUTO(__uuidof(Partition), CPartition)
