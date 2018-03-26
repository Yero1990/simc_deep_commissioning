/***************************************************************************

    grootutil.h - Utility functions for ROOT

    begin                : Sun Jun 08 2003
    version              : 1
    author               : Micha D. Niskin
    email                : mniskin@yahoo.com

    Copyright (C) 2003 Micha D. Niskin

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
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

 ***************************************************************************/

#ifndef FIU_GROOTUTIL
#define FIU_GROOTUTIL

#include <TObject.h>
#include <TPad.h>
#include <TCanvas.h>
#include <TClass.h>
#include <TClassMenuItem.h>
#include <TSeqCollection.h>
#include <TList.h>
#include <TROOT.h>
#include <iostream.h>
#include <TGPicture.h>
#include <TGWindow.h>
#include <TGClient.h>
#include <TGMsgBox.h>

namespace grootutil {
   void     WarnMsgBox(const char *text);
	void     AddMenuItem(const char *classname, TClassMenuItem *item);
   TObject* FindObject(TObject *obj);
   TObject* GetPad(TObject *obj, TObject *parent=0);
	void	   PaintAllCanvases();
	int		GetContrastingColor(int color);
};

#endif //ifndef __grootutil
