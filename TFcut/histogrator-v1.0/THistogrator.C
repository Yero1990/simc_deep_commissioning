/***************************************************************************

    THistogrator.C - Histogrator base class

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

#include "THistogrator.h"

ClassImp(THistogrator)
   
THistogrator::THistogrator():TAttFill(), TAttLine()
{
   fAssocHist = 0;
   fCanvas = 0;
   fCut = 0;
   fHist = 0;
   fPad = 0;
   fState = kZOMBIE;
   fStats = 0;
}

//-----------------------------------------------------------------------------

THistogrator::THistogrator(const char *name, const char *title, TH1 * h,
                           TH1 *ah):TAttFill(), TAttLine()
{
   fCut = 0;
   fStats = new TPaveStats;

   fHist = h;
   fHist->SetNameTitle(name, title);
   fHist->SetStats(kFALSE);
   fHist->SetDrawOption("HIST");

   fAssocHist = ah;

   fPad = (TPad *) grootutil::GetPad(fAssocHist);
   fCanvas = (TCanvas *) fPad->GetCanvas();
   fCanvas->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)",
                    "THistogrator", this,
                    "GotMouseEvent(Int_t,Int_t,Int_t,TObject*)");
   fCanvas->Connect("Closed()", "THistogrator", this, "GotClosed()");

   TString option = (const char *) fAssocHist->GetDrawOption();
   option.ToUpper();
   if (strstr((const char *) option, "LEGO") || 
       strstr((const char *) option, "SURF")) {
      char text[128];
      snprintf(text, sizeof(text),
               "Integrating histogram with option '%s' not implemented",
               (const char*) option);
      grootutil::WarnMsgBox(text);
      fState = kZOMBIE;
   } else {
      fState = kNEW;
   }
}

//-----------------------------------------------------------------------------

THistogrator::~THistogrator()
{
   TDialogCanvas *d;
   TSeqCollection *l = gROOT->GetListOfCanvases();
   if ( (d = (TDialogCanvas*) l->FindObject("R__attfill")) )
      delete d;
   if ( (d = (TDialogCanvas*) l->FindObject("R__attline")) )
      delete d;
   if (fCanvas)
      fCanvas->Disconnect(fCanvas, 0, this, 0);
   if (fStats)
      delete fStats;
   if (fHist)
      delete fHist;
}

//-----------------------------------------------------------------------------

void THistogrator::DelCut() {
   if (fCut) {
      gDirectory->RecursiveRemove((TObject *)fCut);
      delete fCut;
      fCut = 0;
   }
}

//-----------------------------------------------------------------------------

bool THistogrator::CheckIfZombie()
{
   if (fHist && !grootutil::GetPad(fHist)) {
      fState = kZOMBIE;
      fHist = 0;
   }
   if (fAssocHist && !grootutil::GetPad(fAssocHist)) {
      fState = kZOMBIE;
      fAssocHist = 0;
   }
   if (fCanvas && !grootutil::GetPad(fCanvas)) {
      fState = kZOMBIE;
      fCanvas = 0;
   }
   if (fPad && !grootutil::GetPad(fPad)) {
      fState = kZOMBIE;
      fPad = 0;
   }
   if (fCut && !grootutil::GetPad(fCut)) {
      fState = kZOMBIE;
      fCut = 0;
   }
   if (fState == kZOMBIE) {
      return kTRUE;
   } else {
      return kFALSE;
   }
}

//-----------------------------------------------------------------------------

void THistogrator::GotMouseEvent(Int_t evt, Int_t x, Int_t y,
                                 TObject * sel)
{
   TCanvas *cnv = (TCanvas *) gTQSender;
   TPad *pad = (TPad *) cnv->GetSelectedPad();
   if (pad != fPad)
      return;

   double padx = fPad->AbsPixeltoX(x);
   double pady = fPad->AbsPixeltoY(y);

   switch (evt) {
   case kButton1Up:
      ExecuteButton1Up(padx, pady);
      break;
   case kMouseMotion:
      ExecuteMotion(padx, pady);
      break;
   case kKeyPress:
      ExecuteKey();
      break;
   default:
      break;
   }
}
