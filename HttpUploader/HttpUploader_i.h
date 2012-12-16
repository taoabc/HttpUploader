

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Dec 16 17:32:57 2012
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
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MD5( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PostedLength( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PostUrl( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PostUrl( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodeType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodeType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_OnPost( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_OnPost( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_OnStateChanged( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_OnStateChanged( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LocalFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FileSizeLimit( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FileSizeLimit( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RangeSize( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RangeSize( 
            /* [in] */ DOUBLE newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CompanyLicensed( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CompanyLicensed( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FileID( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FileID( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearFields( 
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddField( 
            /* [in] */ BSTR key,
            /* [in] */ BSTR value,
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Post( 
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CheckFile( 
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Stop( 
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Object( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Md5Percent( 
            /* [retval][out] */ USHORT *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorCode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FileSize( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorMsg( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PostFromPosition( 
            /* [in] */ DOUBLE position,
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HttpStatus( 
            /* [retval][out] */ DOUBLE *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ReturnedString( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MD5 )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PostedLength )( 
            IUploader * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PostUrl )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PostUrl )( 
            IUploader * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodeType )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodeType )( 
            IUploader * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnPost )( 
            IUploader * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnPost )( 
            IUploader * This,
            /* [in] */ IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OnStateChanged )( 
            IUploader * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OnStateChanged )( 
            IUploader * This,
            /* [in] */ IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalFile )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalFile )( 
            IUploader * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileSizeLimit )( 
            IUploader * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileSizeLimit )( 
            IUploader * This,
            /* [in] */ DOUBLE newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RangeSize )( 
            IUploader * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RangeSize )( 
            IUploader * This,
            /* [in] */ DOUBLE newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompanyLicensed )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompanyLicensed )( 
            IUploader * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileID )( 
            IUploader * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileID )( 
            IUploader * This,
            /* [in] */ ULONG newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearFields )( 
            IUploader * This,
            /* [retval][out] */ BYTE *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddField )( 
            IUploader * This,
            /* [in] */ BSTR key,
            /* [in] */ BSTR value,
            /* [retval][out] */ BYTE *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Post )( 
            IUploader * This,
            /* [retval][out] */ BYTE *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CheckFile )( 
            IUploader * This,
            /* [retval][out] */ BYTE *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IUploader * This,
            /* [retval][out] */ BYTE *result);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IUploader * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Object )( 
            IUploader * This,
            /* [in] */ IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Md5Percent )( 
            IUploader * This,
            /* [retval][out] */ USHORT *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorCode )( 
            IUploader * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileSize )( 
            IUploader * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorMsg )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PostFromPosition )( 
            IUploader * This,
            /* [in] */ DOUBLE position,
            /* [retval][out] */ BYTE *result);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HttpStatus )( 
            IUploader * This,
            /* [retval][out] */ DOUBLE *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReturnedString )( 
            IUploader * This,
            /* [retval][out] */ BSTR *pVal);
        
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


#define IUploader_get_MD5(This,pVal)	\
    ( (This)->lpVtbl -> get_MD5(This,pVal) ) 

#define IUploader_get_PostedLength(This,pVal)	\
    ( (This)->lpVtbl -> get_PostedLength(This,pVal) ) 

#define IUploader_get_PostUrl(This,pVal)	\
    ( (This)->lpVtbl -> get_PostUrl(This,pVal) ) 

#define IUploader_put_PostUrl(This,newVal)	\
    ( (This)->lpVtbl -> put_PostUrl(This,newVal) ) 

#define IUploader_get_EncodeType(This,pVal)	\
    ( (This)->lpVtbl -> get_EncodeType(This,pVal) ) 

#define IUploader_put_EncodeType(This,newVal)	\
    ( (This)->lpVtbl -> put_EncodeType(This,newVal) ) 

#define IUploader_get_OnPost(This,pVal)	\
    ( (This)->lpVtbl -> get_OnPost(This,pVal) ) 

#define IUploader_put_OnPost(This,newVal)	\
    ( (This)->lpVtbl -> put_OnPost(This,newVal) ) 

#define IUploader_get_OnStateChanged(This,pVal)	\
    ( (This)->lpVtbl -> get_OnStateChanged(This,pVal) ) 

#define IUploader_put_OnStateChanged(This,newVal)	\
    ( (This)->lpVtbl -> put_OnStateChanged(This,newVal) ) 

#define IUploader_get_LocalFile(This,pVal)	\
    ( (This)->lpVtbl -> get_LocalFile(This,pVal) ) 

#define IUploader_put_LocalFile(This,newVal)	\
    ( (This)->lpVtbl -> put_LocalFile(This,newVal) ) 

#define IUploader_get_FileSizeLimit(This,pVal)	\
    ( (This)->lpVtbl -> get_FileSizeLimit(This,pVal) ) 

#define IUploader_put_FileSizeLimit(This,newVal)	\
    ( (This)->lpVtbl -> put_FileSizeLimit(This,newVal) ) 

#define IUploader_get_RangeSize(This,pVal)	\
    ( (This)->lpVtbl -> get_RangeSize(This,pVal) ) 

#define IUploader_put_RangeSize(This,newVal)	\
    ( (This)->lpVtbl -> put_RangeSize(This,newVal) ) 

#define IUploader_get_CompanyLicensed(This,pVal)	\
    ( (This)->lpVtbl -> get_CompanyLicensed(This,pVal) ) 

#define IUploader_put_CompanyLicensed(This,newVal)	\
    ( (This)->lpVtbl -> put_CompanyLicensed(This,newVal) ) 

#define IUploader_get_FileID(This,pVal)	\
    ( (This)->lpVtbl -> get_FileID(This,pVal) ) 

#define IUploader_put_FileID(This,newVal)	\
    ( (This)->lpVtbl -> put_FileID(This,newVal) ) 

#define IUploader_ClearFields(This,result)	\
    ( (This)->lpVtbl -> ClearFields(This,result) ) 

#define IUploader_AddField(This,key,value,result)	\
    ( (This)->lpVtbl -> AddField(This,key,value,result) ) 

#define IUploader_Post(This,result)	\
    ( (This)->lpVtbl -> Post(This,result) ) 

#define IUploader_CheckFile(This,result)	\
    ( (This)->lpVtbl -> CheckFile(This,result) ) 

#define IUploader_Stop(This,result)	\
    ( (This)->lpVtbl -> Stop(This,result) ) 

#define IUploader_get_Object(This,pVal)	\
    ( (This)->lpVtbl -> get_Object(This,pVal) ) 

#define IUploader_put_Object(This,newVal)	\
    ( (This)->lpVtbl -> put_Object(This,newVal) ) 

#define IUploader_get_Md5Percent(This,pVal)	\
    ( (This)->lpVtbl -> get_Md5Percent(This,pVal) ) 

#define IUploader_get_ErrorCode(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrorCode(This,pVal) ) 

#define IUploader_get_FileSize(This,pVal)	\
    ( (This)->lpVtbl -> get_FileSize(This,pVal) ) 

#define IUploader_get_ErrorMsg(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrorMsg(This,pVal) ) 

#define IUploader_PostFromPosition(This,position,result)	\
    ( (This)->lpVtbl -> PostFromPosition(This,position,result) ) 

#define IUploader_get_HttpStatus(This,pVal)	\
    ( (This)->lpVtbl -> get_HttpStatus(This,pVal) ) 

#define IUploader_get_ReturnedString(This,pVal)	\
    ( (This)->lpVtbl -> get_ReturnedString(This,pVal) ) 

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
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FileFilter( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FileFilter( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowMultiSelect( 
            /* [retval][out] */ BYTE *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowMultiSelect( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowFolder( 
            /* [retval][out] */ BYTE *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSelectedFiles( 
            /* [retval][out] */ IDispatch **result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetClipboardFiles( 
            /* [retval][out] */ IDispatch **result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [in] */ BSTR file,
            /* [retval][out] */ DOUBLE *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearSelectedFiles( 
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileFilter )( 
            IPartition * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileFilter )( 
            IPartition * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowMultiSelect )( 
            IPartition * This,
            /* [retval][out] */ BYTE *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowMultiSelect )( 
            IPartition * This,
            /* [in] */ BYTE newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowFolder )( 
            IPartition * This,
            /* [retval][out] */ BYTE *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSelectedFiles )( 
            IPartition * This,
            /* [retval][out] */ IDispatch **result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetClipboardFiles )( 
            IPartition * This,
            /* [retval][out] */ IDispatch **result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IPartition * This,
            /* [in] */ BSTR file,
            /* [retval][out] */ DOUBLE *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearSelectedFiles )( 
            IPartition * This,
            /* [retval][out] */ BYTE *result);
        
        END_INTERFACE
    } IPartitionVtbl;

    interface IPartition
    {
        CONST_VTBL struct IPartitionVtbl *lpVtbl;
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

#define IPartition_get_FileFilter(This,pVal)	\
    ( (This)->lpVtbl -> get_FileFilter(This,pVal) ) 

#define IPartition_put_FileFilter(This,newVal)	\
    ( (This)->lpVtbl -> put_FileFilter(This,newVal) ) 

#define IPartition_get_AllowMultiSelect(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowMultiSelect(This,pVal) ) 

#define IPartition_put_AllowMultiSelect(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowMultiSelect(This,newVal) ) 

#define IPartition_ShowFolder(This,result)	\
    ( (This)->lpVtbl -> ShowFolder(This,result) ) 

#define IPartition_GetSelectedFiles(This,result)	\
    ( (This)->lpVtbl -> GetSelectedFiles(This,result) ) 

#define IPartition_GetClipboardFiles(This,result)	\
    ( (This)->lpVtbl -> GetClipboardFiles(This,result) ) 

#define IPartition_GetFileSize(This,file,result)	\
    ( (This)->lpVtbl -> GetFileSize(This,file,result) ) 

#define IPartition_ClearSelectedFiles(This,result)	\
    ( (This)->lpVtbl -> ClearSelectedFiles(This,result) ) 

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

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


