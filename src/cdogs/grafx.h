/*
    C-Dogs SDL
    A port of the legendary (and fun) action/arcade cdogs.
    Copyright (C) 1995 Ronny Wester
    Copyright (C) 2003 Jeremy Chin
    Copyright (C) 2003-2007 Lucas Martin-King

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    This file incorporates work covered by the following copyright and
    permission notice:

    Copyright (c) 2013, Cong Xu
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __GRAFX
#define __GRAFX

#include <SDL_video.h>

#include "sys_specifics.h"

typedef struct
{
	int Brightness;
	int ResolutionWidth;
	int ResolutionHeight;
	int Fullscreen;
	int ScaleFactor;
	int ShakeMultiplier;
} GraphicsConfig;

typedef struct
{
	int IsInitialized;
	int IsWindowInitialized;
	SDL_Surface *screen;
	GraphicsConfig cachedConfig;
} GraphicsDevice;

extern GraphicsDevice gGraphicsDevice;

void SetColorZero(
	GraphicsDevice *device, unsigned char r, unsigned char g, unsigned char b);

typedef struct {
	unsigned int w, h;
} GFX_Mode;

void GraphicsInitialize(GraphicsDevice *device, GraphicsConfig *config, int force);
void GraphicsTerminate(GraphicsDevice *device);
int GraphicsGetMemSize(GraphicsConfig *config);

void Gfx_ModePrev(void);
void Gfx_ModeNext(void);

char *GrafxGetResolutionStr(void);

#define CenterX(w)		((gGraphicsDevice.cachedConfig.ResolutionWidth - w) / 2)
#define CenterY(h)		((gGraphicsDevice.cachedConfig.ResolutionHeight - h) / 2)

#define CenterOf(a, b, w)	((a + (((b - a) - w) / 2)))

#define CenterOfRight(w)	CenterOf((gGraphicsDevice.cachedConfig.ResolutionWidth / 2), (gGraphicsDevice.cachedConfig.ResolutionWidth), w)
#define CenterOfLeft(w)		CenterOf(0, (gGraphicsDevice.cachedConfig.ResolutionWidth / 2), w)

#endif
