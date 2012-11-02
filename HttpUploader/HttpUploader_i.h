

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Fri Nov 02 11:10:00 2012
 */
/* Compiler settings for HttpUploader.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __HttpUploader_i_h__
#define __HttpUploader_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUploader_FWD_DEFINED__
#define __IUploader_FWD_DEFINED__
typedef interface IUploader IUploader;

#endif 	/* __IUploader_FWD_DEFINED__ */


#ifndef __Uploader_FWD_DEFINED__
#define __Uploader_FWD_DEFINED__

#ifdef __cplusplus
typedef class Uploader Uploader;
#else
typedef struct Uploader Uploader;
#endif /* __cplusplus */

#endif 	/* __Uploader_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IUploader_INTERFACE_DEFINED__
#define __IUploader_INTERFACE_DEFINED__

/* interface IUploader */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUploader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F6A0A1C9-F652-4FDD-A455-1402D4C97C8E")
    IUploader : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Test( 
            /* [retval][out] */ LONG *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowDialog( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlPost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UrlPost( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSelectedFiles( 
            /* [retval][out] */ IDispatch **result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUploaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUploader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUploader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUploader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUploader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUploader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUploader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUploader * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Test )( 
            IUploader * This,
            /* [retval][out] */ LONG *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowDialog )( 
            IUploader * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlPost )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UrlPost )( 
            IUploader * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSelectedFiles )( 
            IUploader * This,
            /* [retval][out] */ IDispatch **result);
        
        END_INTERFACE
    } IUploaderVtbl;

    interface IUploader
    {
        CONST_VTBL struct IUploaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUploader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUploader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUploader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUploader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUploader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUploader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUploader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUploader_Test(This,result)	\
    ( (This)->lpVtbl -> Test(This,result) ) 

#define IUploader_ShowDialog(This)	\
    ( (This)->lpVtbl -> ShowDialog(This) ) 

#define IUploader_get_UrlPost(This,pVal)	\
    ( (This)->lpVtbl -> get_UrlPost(This,pVal) ) 

#define IUploader_put_UrlPost(This,newVal)	\
    ( (This)->lpVtbl -> put_UrlPost(This,newVal) ) 

#define IUploader_GetSelectedFiles(This,result)	\
    ( (This)->lpVtbl -> GetSelectedFiles(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUploader_INTERFACE_DEFINED__ */



#ifndef __HttpUploaderLib_LIBRARY_DEFINED__
#define __HttpUploaderLib_LIBRARY_DEFINED__

/* library HttpUploaderLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_HttpUploaderLib;

EXTERN_C const CLSID CLSID_Uploader;

#ifdef __cplusplus

class DECLSPEC_UUID("3F31A1AB-6A27-4459-B9D8-C8C459F1F30D")
Uploader;
#endif
#endif /* __HttpUploaderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


