/***************************************************************************

    THistogrator1.h - 1D histogrator class

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

#ifndef FIU_THISTOGRATOR1
#define FIU_THISTOGRATOR1

#include <iostream.h>
#include <stdlib.h>
#include <snprintf.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TPaveStats.h>

#include "THistogrator.h"

class THistogrator1:public THistogrator {
 public:
   //public methods
   THistogrator1();
   THistogrator1(const char *name, const char *title, TH1 * h, TH1 *ah);
   virtual void Delete() { delete this; }
   virtual void ExecuteButton1Up(double padx, double pady);
   virtual void ExecuteClosed() { fCanvas=0; fState=kZOMBIE; }
   virtual void ExecuteMotion(double padx, double pady);
   virtual void Paint();
   virtual void SetFillColor(Color_t fcolor);
   virtual void SetFillStyle(Style_t fstyle);
   virtual void SetLineColor(Color_t lcolor);
   virtual void SetLineStyle(Style_t lstyle);
 private:
   //private methods
   void CreateStats();
   void Init();
   void SelectBins(int bin1, int bin2);
   void UnselectAll() { if (fHist) fHist->Reset("ICE"); }
   void UpdateStats(Stat_t sum, double integral, double left,
                    double right);
   //private data members
   int ffirst_bin;

   ClassDef(THistogrator1, 1)
};

#endif
