/*
** 返回给JS的IDispatch指针
** 这里主要处理JS数组
** 返回的不是一个标准JS数组
** 而是一个对象，在JS中调用该对象的特定方法，可以完成遍历
*/
#pragma once
#include <atlcoll.h>
using namespace ATL;

template<typename T, VARTYPE VT>
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

  STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR *rgsz_names, UINT cnames,
      LCID lcid, DISPID *rgdispid) {
    if (wcscmp(rgsz_names[0], L"Size") == 0) {
      *rgdispid = 1;
    } else if (wcscmp(rgsz_names[0], L"At") == 0) {
      *rgdispid = 2;
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
      GetArrayAt(pdisp_params->rgvarg[0].lVal, pvar_result);
      break;
    default:
      break;
    }
    return S_OK;
  }
  //public function
  void PushBack(const T& v) {
    array_.Add(v);
  }

  T At(size_t idx) const {
    return array_.GetAr(idx);
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

  HRESULT GetArrayAt(size_t idx, VARIANT* result) {
    CComVariant vat(array_.GetAt(idx));
    vat.ChangeType(VT);
    return vat.Detach(result);
  }

  ULONG cref_;
  CAtlArray<T> array_;
};