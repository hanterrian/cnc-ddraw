/*
 * Copyright (c) 2010 Toni Spets <toni.spets@iki.fi>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <windows.h>
#include <stdio.h>
#include "palette.h"

/* from main */
HRESULT QueryInterface(void *This, REFIID riid, void **obj);
ULONG AddRef(void *This);
ULONG Release(void *This);
HRESULT null();

HRESULT ddraw_CreatePalette(void *This, LPPALETTEENTRY DDColorArray, LPDIRECTDRAWPALETTE FAR * DDPalette, IUnknown FAR * unkOuter)
{
    printf("DirectDraw::CreatePalette(This=%p, DDColorArray=%p, DDPalette=%p, unkOuter=%p)\n", This, DDColorArray, DDPalette, unkOuter);

    fakeDirectDrawPaletteObject *Palette = (fakeDirectDrawPaletteObject *)malloc(sizeof(fakeDirectDrawPaletteObject));
    Palette->Ref = 1;
    Palette->Functions = &piface;
    printf(" Palette = %p\n", Palette);
    *DDPalette = (LPDIRECTDRAWPALETTE)Palette;

    return DD_OK;
}

fakeDirectDrawPalette piface =
{
    /* IUnknown */
    QueryInterface,
    AddRef,
    Release,
    /* IDirectDrawPalette */
    null, // ddraw_palette_GetCaps
    null, // ddraw_palette_GetEntries
    null, // ddraw_palette_Initialize
    null  // ddraw_palette_SetEntries
};
