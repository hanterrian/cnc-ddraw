#include "IDirect3D.h"
#include "debug.h"


HRESULT __stdcall IDirect3D2__QueryInterface(IDirect3D2Impl* This, REFIID riid, void** obj)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p, riid=%08X, obj=%p)\n", __FUNCTION__, This, (unsigned int)riid, obj);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

ULONG __stdcall IDirect3D2__AddRef(IDirect3D2Impl* This)
{
    dprintf("-> %s(This=%p)\n", __FUNCTION__, This);
    ULONG ret = ++This->ref;
    dprintf("<- %s(This ref=%u)\n", __FUNCTION__, ret);
    return ret;
}

ULONG __stdcall IDirect3D2__Release(IDirect3D2Impl* This)
{
    dprintf("-> %s(This=%p)\n", __FUNCTION__, This);

    ULONG ret = --This->ref;

    if (This->ref == 0)
    {
        dprintf("     Released (%p)\n", This);

        HeapFree(GetProcessHeap(), 0, This);
    }

    dprintf("<- %s(This ref=%u)\n", __FUNCTION__, ret);
    return ret;
}

HRESULT __stdcall IDirect3D2__EnumDevices(IDirect3D2Impl* This, int a, int b)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p)\n", __FUNCTION__, This);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

HRESULT __stdcall IDirect3D2__CreateLight(IDirect3D2Impl* This, int a, int b)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p)\n", __FUNCTION__, This);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

HRESULT __stdcall IDirect3D2__CreateMaterial(IDirect3D2Impl* This, int a, int b)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p)\n", __FUNCTION__, This);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

HRESULT __stdcall IDirect3D2__CreateViewport(IDirect3D2Impl* This, int a, int b)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p)\n", __FUNCTION__, This);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

HRESULT __stdcall IDirect3D2__FindDevice(IDirect3D2Impl* This, int a, int b)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p)\n", __FUNCTION__, This);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

HRESULT __stdcall IDirect3D2__CreateDevice(IDirect3D2Impl* This, int a, int b, int c)
{
    dprintf("NOT_IMPLEMENTED -> %s(This=%p)\n", __FUNCTION__, This);
    HRESULT ret = E_FAIL;
    dprintf("NOT_IMPLEMENTED <- %s\n", __FUNCTION__);
    return ret;
}

struct IDirect3D2ImplVtbl g_d3d2_vtbl =
{
    /* IUnknown */
    IDirect3D2__QueryInterface,
    IDirect3D2__AddRef,
    IDirect3D2__Release,
    /* IDirect3D2Impl */
    IDirect3D2__EnumDevices,
    IDirect3D2__CreateLight,
    IDirect3D2__CreateMaterial,
    IDirect3D2__CreateViewport,
    IDirect3D2__FindDevice,
    IDirect3D2__CreateDevice,
};
