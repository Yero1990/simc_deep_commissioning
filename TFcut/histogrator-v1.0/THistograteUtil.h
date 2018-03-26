/***************************************************************************

    THistograteUtil.h - Utility class for dealing with histogrators

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

#ifndef FIU_HISTOGRATEUTIL
#define FIU_HISTOGRATEUTIL

#include <TROOT.h>
#include <iostream.h>
#include <TObject.h>
#include <TH1F.h>
#include <TClassMenuItem.h>
#include <TGClient.h>
#include <TGPicture.h>
#include <TGWindow.h>
#include <TGMsgBox.h>

#include "THistList.h"
#include "grootutil.h"

class THistograteUtil : public TObject {

public:
   THistograteUtil();
	void   			 AddMenu();
   void            HistDelete(TObject *hist);
   void            PaveDelete(TObject *pave);
   void            CutDelete(TObject *cut);
   void            HistAddCut(const char *cutname, TObject *hist);
   void            HistFillAttributes(TObject *hist);
   void            HistLineAttributes(TObject *hist);
   //void            HistMarkerAttributes(TObject *hist);
   void            Histograte(TObject *hist);
   void            Unimplemented(TObject *obj);

private:
	void   			 AddClassMenus(const char *classname);
   TClassMenuItem* AddCutMenuItem(const char* classname);
   TClassMenuItem* DelMenuItem(const char *classname);
   TClassMenuItem* FillMenuItem(const char *classname);
   TClassMenuItem* LineMenuItem(const char *classname);
   //TClassMenuItem* MarkerMenuItem(const char *classname);
   TClassMenuItem* SeparatorMenuItem(const char *classname);
	TClassMenuItem* StartMenuItem(const char *classname);
	TClassMenuItem* UnimplMenuItem(const char *classname, const char *title);
   
   THistList       fHistList;

   ClassDef(THistograteUtil,1)
};


#endif
