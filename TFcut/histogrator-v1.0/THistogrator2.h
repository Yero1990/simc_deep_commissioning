/***************************************************************************

    THistogrator2.h - 2D histogrator class

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

#ifndef FIU_THISTOGRATOR2
#define FIU_THISTOGRATOR2

#include <TCanvas.h>
#include <TPolyLine.h>
#include <TPad.h>
#include <TH1.h>
#include <TAxis.h>
#include <TPoints.h>
#include <TList.h>
#include <TCutG.h>
#include <stdio.h>
#include <snprintf.h>

#include "THistogrator.h"

class THistogrator2:public THistogrator {
 public:
   THistogrator2();
   THistogrator2(const char *name, const char *title, TH1 * h, TH1 *ah);
   ~THistogrator2();
   virtual void DelCut();
   virtual void Delete()         { delete this; }
   virtual void ExecuteButton1Up(double padx, double pady);
   virtual void ExecuteClosed()  { fCanvas=0; fState=kZOMBIE; }
   virtual void ExecuteKey();
   virtual void ExecuteMotion(double padx, double pady);
   virtual TPolyLine* GetPoly(TObject *p);
   virtual void Paint();
   virtual void SetCut(const TCutG& cut);
   virtual void SetFillColor(Color_t fcolor);
   virtual void SetFillStyle(Style_t fstyle);
   virtual void SetLineColor(Color_t fcolor);
   virtual void SetLineStyle(Style_t fstyle);
 private:
   //private methods
   void         CreateBinShade(int binx, int biny);
   void         CreateStats();
   void         Init();
   void         SelectBins();
   void         UnselectAll();
   void         UpdateStats(Stat_t sum, double integral);
   //private members
   TList*       fBinShadeList;   // List of shaded bin polylines
   double       fLastIntegral;
   int          fLastPoint;      // Point number of last point added to fCut
   Stat_t       fLastSum;
   TLine*       fLine;           // Line from last point in fCut to mouse position

   ClassDef(THistogrator2, 1)
};

#endif
