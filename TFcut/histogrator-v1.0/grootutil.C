/***************************************************************************

    grootutil.C - Utility functions for ROOT

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

#include "grootutil.h"

void grootutil::WarnMsgBox(const char *text)
{
   const TGWindow *main = gClient->GetRoot();
   const TGPicture *pic = gClient->GetPicture("mb_exclamation_s.xpm");
   TGMsgBox *mb = new TGMsgBox(main, main, "Warning", text, pic);
   mb = 0;
}

//-----------------------------------------------------------------------------

void grootutil::AddMenuItem(const char *classname, TClassMenuItem *item) {
	TClass *cl = gROOT->GetClass(classname);
	if (!cl) return;
	TList	*l = cl->GetMenuList();
	TIter next(l);
	while (TObject *i = next()) {
		if ( !strcmp(item->GetTitle(),((TClassMenuItem *)i)->GetTitle()) ) {
			l->AddAfter(i,item);
			l->Remove(i);
			return;
		}
	}
	l->AddFirst(item);
}

//-----------------------------------------------------------------------------

TObject* grootutil::FindObject(TObject *obj) {
   TObject *retval = 0;
   TList *list = gDirectory->GetList();
   TIter next(list);
   while (TObject * dirobj = next()) {
      if (dirobj == obj)
         retval = obj;
   }
   return retval;
}

//-----------------------------------------------------------------------------

TObject* grootutil::GetPad(TObject *obj, TObject *parent) {
   TObject *retval=0, *o=0;
   if (!parent) {
      TSeqCollection *canvases = gROOT->GetListOfCanvases();
      TObject *p = canvases->First();
      while (p) {
         if (p == obj)
            retval = p;
         if ( (o = GetPad(obj,p)) ) {
            retval = o;
         }
         TObject *p2 = canvases->After(p);
         p = p2;
      }
   } else if (parent->InheritsFrom("TPad")) {
      TList *primitives = ((TPad *) parent)->GetListOfPrimitives();
      TIter next(primitives);
      while (TObject *p = next()) {
         if (p == obj) {
            retval = parent;
         } else if (p->InheritsFrom("TPad") && (o = GetPad(obj,p))) {
            retval = o;
         }
      }
   }
   return retval;
}

//-----------------------------------------------------------------------------

void grootutil::PaintAllCanvases() {
	TSeqCollection *l = gROOT->GetListOfCanvases();
	TCanvas *c, *c2;
	c = (TCanvas *) l->First();
	while (c) {
		c->Modified();
		c->Update();
		c2 = (TCanvas *) l->After(c);
		c = c2;
	}
}

//-----------------------------------------------------------------------------	

int grootutil::GetContrastingColor(int color) {
	if (color <= 10) {
		return (color == 4) ? 2 : 4;
	} else if (color <= 128) {
		return color + 100;
	} else {
		return color - 100;
	}
}
