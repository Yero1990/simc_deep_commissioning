/***************************************************************************

    THistList.h - Histogrator container class

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

#ifndef FIU_THISTLIST
#define FIU_THISTLIST

#include <TList.h>
#include <TObject.h>
#include <stdio.h>
#include <snprintf.h>
#include <TH1C.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH1S.h>
#include <TH2C.h>
#include <TH2D.h>
#include <TH2F.h>
#include <TH2S.h>

#include "THistogrator1.h"
#include "THistogrator2.h"

class THistList {
   TList fList;   // List containing histogrators
public:
   THistList():fList() { fMaxID = 0; }
   bool           Add(TObject * hist);
   bool           CheckForZombies();
   THistogrator  *Find(TObject * hist);
   bool           Remove(TObject * hist);
private:
   int fMaxID;    // Incremented by one whenever a histogrator is added
};

#endif
