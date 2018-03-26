/***************************************************************************

    THistogrator.h - Histogrator base class

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

#ifndef FIU_THISTOGRATOR
#define FIU_THISTOGRATOR

#include <TObject.h>
#include <TAttFill.h>
#include <TAttLine.h>
#include <RQ_OBJECT.h>
#include <stdio.h>
#include <iostream.h>
#include <TCanvas.h>
#include <TDialogCanvas.h>
#include <TSeqCollection.h>
#include <TH1.h>
#include <TPad.h>
#include <TCutG.h>
#include <TPaveStats.h>
#include <TPolyLine.h>

#include "grootutil.h"

enum State_t { kNEW, kREADY, kSELECT, kDISPLAY, kEDIT, kZOMBIE };

class THistogrator:public TObject, public TAttFill, public TAttLine {
   RQ_OBJECT("THistogrator")
 public:
   //public methods
   THistogrator();
   THistogrator(const char *name, const char *title, TH1 *h, TH1 *ah);
   ~THistogrator();
   virtual bool CheckIfZombie();
   virtual void DelAssocHist()     { if (fAssocHist) delete fAssocHist; 
                                     fAssocHist = 0; }
   virtual void DelCut();
   virtual void Delete() {};
   virtual void DelHist()          { if (fHist) delete fHist; fHist = 0; }
   virtual void DelPave()          { if (fStats) delete fStats; fStats = 0; }
   virtual void ExecuteButton1Up(double padx, double pady) {};
   virtual void ExecuteClosed() {};
   virtual void ExecuteKey() {};
   virtual void ExecuteMotion(double padx, double pady) {};
   virtual TH1* GetAssocHist()     { return fAssocHist; }
   virtual TCutG*      GetCut()    { return fCut; }
   virtual TH1*        GetHist()   { return fHist; }
   virtual TPaveStats* GetPave()   { return fStats; }
   virtual TPolyLine*  GetPoly(TObject *p) { return 0; }
   void         GotClosed()        { ExecuteClosed(); }
   void GotMouseEvent(Int_t evt, Int_t x, Int_t y, TObject * sel);
   virtual void Paint() {};
   virtual void SetCut(const TCutG& cut) {};
   virtual void SetFillColor(Color_t fcolor) { fFillColor = fcolor; }
   virtual void SetFillStyle(Style_t fstyle) { fFillStyle = fstyle; }
   virtual void SetLineColor(Color_t lcolor) { fLineColor = lcolor; }
   virtual void SetLineStyle(Style_t lstyle) { fLineStyle = lstyle; }
 protected:
   //protected data members
   TH1*         fAssocHist;   // Histogram which is to be integrated
   TCanvas*     fCanvas;      // Canvas containing associated histogram
   TCutG*       fCut;         // Graphical cut
   TH1*         fHist;        // Histogram used to draw the shaded area
   TPad*        fPad;         // Pad containing associated histogram
   State_t      fState;       // Internal state of histogrator
   TPaveStats*  fStats;       // Stats box for displaying integral and sum

   ClassDef(THistogrator, 1)  // Graphical histogram integrator base class
};

#endif // ifndef FIU_THISTOGRATOR
