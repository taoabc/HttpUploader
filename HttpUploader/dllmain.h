// dllmain.h : Declaration of module class.

class CHttpUploaderModule : public ATL::CAtlDllModuleT< CHttpUploaderModule >
{
public :
	DECLARE_LIBID(LIBID_HttpUploaderLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HTTPUPLOADER, "{646C4FB0-DC50-45F3-8480-507C03118B00}")
};

extern class CHttpUploaderModule _AtlModule;
