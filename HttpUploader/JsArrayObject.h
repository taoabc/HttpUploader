/*
** 返回给JS的IDispatch指针
** 这里主要处理JS数组
** 返回的不是一个标准JS数组
** 而是一个对象，在JS中调用该对象的特定方法，可以完成遍历
*/
#pragma once
#include <atlcoll.h>
using namespace ATL;

class JsArrayObject : public IDispatch {

public:

  JsArrayObject(void) {
    cref_ = 1;
  }
  ~JsArrayObject(void) {
  }

  //IUnknown
  STDMETHODIMP QueryInterface(REFIID riid, void** ppobj) {
    if (riid == IID_IUnknown) {
      *ppobj = this;
    } else if (riid == IID_IDispatch) {
      *ppobj = (IDispatch*)this;
    } else {
      *ppobj = NULL;
      return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
  }

  STDMETHODIMP_(ULONG) AddRef(void) {
    return ::InterlockedIncrement(&cref_);
  }

  STDMETHODIMP_(ULONG) Release(void) {
    ::InterlockedDecrement(&cref_);
    if (cref_ == 0) {
      delete this;
      return 0;
    }
    return cref_;
  }

  //IDispatch
  STDMETHODIMP GetTypeInfoCount(UINT* pctinfo) {   
    return E_NOTIMPL;
  }

  STDMETHODIMP GetTypeInfo(UINT ninfo, LCID lcid, ITypeInfo **ppt_info) {
    return E_NOTIMPL;
  }

  //js can call these functions
  STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR *rgsz_names, UINT cnames,
      LCID lcid, DISPID *rgdispid) {
    if (0 == wcscmp(rgsz_names[0], L"Size")) {
      *rgdispid = 1;
    } else if (0 == wcscmp(rgsz_names[0], L"At")) {
      *rgdispid = 2;
    } else if (0 == wcscmp(rgsz_names[0], L"lbound")) {
      *rgdispid = 3;
    } else if (0 == wcscmp(rgsz_names[0], L"ubound")) {
      *rgdispid = 4;
    } else if (0 == wcscmp(rgsz_names[0], L"getItem")) {
      *rgdispid = 5;
    } else {
      return E_FAIL;
    }
    return S_OK;
  }

  STDMETHODIMP Invoke(DISPID dispid_member, REFIID riid, LCID lcid, WORD wflags,
      DISPPARAMS *pdisp_params, VARIANT *pvar_result, EXCEPINFO *pexcep_info, UINT *puarg_err) {
    switch (dispid_member) {
    case 1:
      pvar_result->vt = VT_UINT;
      pvar_result->intVal = Size();
      break;
    case 2:
    case 5:
      return GetArrayAt(pdisp_params->rgvarg[0].ulVal, pvar_result);
      break;
    case 3:
      return LBound(pdisp_params->rgvarg[0].ulVal, pvar_result);
      break;
    case 4:
      return UBound(pdisp_params->rgvarg[0].ulVal, pvar_result);
      break;
    default:
      break;
    }
    return S_OK;
  }
  //public function
  void PushBack(const CComVariant& v) {
    array_.Add(v);
  }

  CComVariant At(size_t idx) const {
    return array_.GetAt(idx);
  }

  size_t Size(void) const {
    return array_.GetCount();
  }

  bool Empty(void) const {
    return array_.IsEmpty();
  }

  void Clear(void) {
    array_.RemoveAll();
  }

private:

  HRESULT LBound(ULONG dimension, VARIANT* result) {
    //暂不支持多维
    if (dimension != 1) {
      result->vt = VT_NULL;
      return E_FAIL;
    }
    result->ulVal = 0;
    result->vt = VT_UINT;
    return S_OK;
  }

  HRESULT UBound(ULONG dimension, VARIANT* result) {
    //暂不支持多维
    if (dimension != 1) {
      result->vt = VT_NULL;
      return E_FAIL;
    }
    //上限索引为大小-1
    if (Size() == 0) {
      result->vt = VT_NULL;
    } else {
      result->ulVal = Size()-1;
      result->vt = VT_UINT;
    }
    return S_OK;
  }

  HRESULT GetArrayAt(size_t idx, VARIANT* result) {
    CComVariant vat(array_.GetAt(idx));
    return vat.Detach(result);
  }

  ULONG cref_;
  CAtlArray<CComVariant> array_;
};