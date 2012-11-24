

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Nov 25 01:17:24 2012
 */
/* Compiler settings for HttpUploader.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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


#ifndef __IPartition_FWD_DEFINED__
#define __IPartition_FWD_DEFINED__
typedef interface IPartition IPartition;
#endif 	/* __IPartition_FWD_DEFINED__ */


#ifndef __Uploader_FWD_DEFINED__
#define __Uploader_FWD_DEFINED__

#ifdef __cplusplus
typedef class Uploader Uploader;
#else
typedef struct Uploader Uploader;
#endif /* __cplusplus */

#endif 	/* __Uploader_FWD_DEFINED__ */


#ifndef __Partition_FWD_DEFINED__
#define __Partition_FWD_DEFINED__

#ifdef __cplusplus
typedef class Partition Partition;
#else
typedef struct Partition Partition;
#endif /* __cplusplus */

#endif 	/* __Partition_FWD_DEFINED__ */


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
    
    MIDL_INTERFACE("F80C6A56-E036-4AD8-8896-94295D242FC0")
    IUploader : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IUploaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUploader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
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
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
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


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUploader_INTERFACE_DEFINED__ */


#ifndef __IPartition_INTERFACE_DEFINED__
#define __IPartition_INTERFACE_DEFINED__

/* interface IPartition */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPartition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ABEAD3B2-6F91-416C-846A-E339B25CA57C")
    IPartition : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowDialog( 
            /* [retval][out] */ BYTE *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPartitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPartition * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPartition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPartition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPartition * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPartition * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPartition * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPartition * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowDialog )( 
            IPartition * This,
            /* [retval][out] */ BYTE *result);
        
        END_INTERFACE
    } IPartitionVtbl;

    interface IPartition
    {
        CONST_VTBL struct IPartitionVtbl *lpVtbl;
        [propget] HRESULT FileFilter([out, retval] BSTR* pVal);
        [propput] HRESULT FileFilter([in] BSTR newVal);
    };

    

#ifdef COBJMACROS


#define IPartition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPartition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPartition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPartition_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPartition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPartition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPartition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPartition_ShowDialog(This,result)	\
    ( (This)->lpVtbl -> ShowDialog(This,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPartition_INTERFACE_DEFINED__ */



#ifndef __HttpUploaderLib_LIBRARY_DEFINED__
#define __HttpUploaderLib_LIBRARY_DEFINED__

/* library HttpUploaderLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_HttpUploaderLib;

EXTERN_C const CLSID CLSID_Uploader;

#ifdef __cplusplus

class DECLSPEC_UUID("7E406662-E762-45BE-9552-51D900C61A14")
Uploader;
#endif

EXTERN_C const CLSID CLSID_Partition;

#ifdef __cplusplus

class DECLSPEC_UUID("DE4934DA-A37E-4E47-88A7-521DB39A5EE4")
Partition;
#endif
#endif /* __HttpUploaderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


