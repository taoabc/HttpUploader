// dllmain.h : Declaration of module class.

class CHttpUploaderModule : public ATL::CAtlDllModuleT< CHttpUploaderModule >
{
public :
	DECLARE_LIBID(LIBID_HttpUploaderLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HTTPUPLOADER, "{FF5FAEE7-D8CD-44DF-A08E-C306A8A4255D}")
};

extern class CHttpUploaderModule _AtlModule;
