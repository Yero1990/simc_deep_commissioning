/***************************************************************************

    THistogrator2.C - 2D histogrator class

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

#include "THistogrator2.h"

ClassImp(THistogrator2)

THistogrator2::THistogrator2():THistogrator()
{
   fBinShadeList = 0;
   fCut = 0;
   fLastIntegral = 0;
   fLastPoint = 0;
   fLastSum = 0;
   fLine = 0;
}

//-----------------------------------------------------------------------------

THistogrator2::THistogrator2(const char *name, const char *title, TH1 * h, TH1 *ah):THistogrator(name, title, h, ah)
{
   fCut = 0;
   fBinShadeList = new TList;
   fLastIntegral = 0;
   fLastPoint = 0;
   fLastSum = 0;
   fLine = 0;
   if (fState==kZOMBIE)
      return;
   Init();
}

//-----------------------------------------------------------------------------

THistogrator2::~THistogrator2()
{
   if (fHist)
      fHist->Reset("Ice");
   UnselectAll();
   if (fCut) {
      gROOT->RecursiveRemove(fCut);
      delete fCut;
   }
   if (fLine)
      delete fLine;
   if (fBinShadeList)
      delete fBinShadeList;
}

//-----------------------------------------------------------------------------

void THistogrator2::Init()
{
   fPad->cd();
   fHist->Reset("Ice");

   SetFillColor(grootutil::GetContrastingColor(fAssocHist->GetMarkerColor()));
   SetFillStyle(3001);
   SetLineColor(kRed);

   TString opts = fAssocHist->GetDrawOption();
   opts += " SAME";
   fHist->Draw((const char*) opts);
   fAssocHist->Pop();
   
   CreateStats();
   fStats->Draw();

   UpdateStats(0, 0);
   fPad->RedrawAxis();
   Paint();

   fState = kREADY;
}

//-----------------------------------------------------------------------------

TPolyLine* THistogrator2::GetPoly(TObject *p)
{
   TPolyLine *retval = 0;
   
   TIter next(fBinShadeList);
   while (TObject * obj = next()) {
      if (obj == p)
         retval = (TPolyLine *) obj;
   }
   return retval;
}

//-----------------------------------------------------------------------------

void THistogrator2::SetFillColor(Color_t fcolor) 
{
   fFillColor = fcolor;

   TIter next(fBinShadeList);
   while (TObject * obj = next()) {
      ((TPolyLine *)obj)->SetFillColor(fcolor);
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::SetFillStyle(Style_t fstyle) 
{
   fFillStyle = fstyle;

   TIter next(fBinShadeList);
   while (TObject * obj = next()) {
      ((TPolyLine *) obj)->SetFillStyle(fstyle);
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::SetLineColor(Color_t fcolor) 
{
   fLineColor = fcolor;

   if (fCut)
      fCut->SetLineColor(fcolor);
}

//-----------------------------------------------------------------------------

void THistogrator2::SetLineStyle(Style_t fstyle) 
{
   fLineStyle = fstyle;

   if (fCut)
      fCut->SetLineStyle(fstyle);
}

//-----------------------------------------------------------------------------

void THistogrator2::SetCut(const TCutG& cut) {
   char cutname[64];
   if (CheckIfZombie())
      return;

   fHist->Reset("ICE");
   UnselectAll();
   
   snprintf(cutname,sizeof(cutname),"%scut",fHist->GetName());
   fCut = new TCutG(cut);
   fCut->SetNameTitle(cutname,fHist->GetTitle());
   fCut->SetLineColor(GetLineColor());
   fCut->SetLineStyle(GetLineStyle());
   fCut->Draw();

   fState = kDISPLAY;
   SelectBins();
   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator2::DelCut() {
   fState = kREADY;
   fHist->Reset("Ice");
   UnselectAll();
   
   if (fCut) {
      gROOT->RecursiveRemove(fCut);
      delete fCut;
      fCut = 0;
   }
   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator2::Paint()
{
   if (!fPad)
      return;

   fPad->cd();

   if (fAssocHist)
      fAssocHist->Pop();
   if (fStats)
      fStats->Pop();
   
   TIter next(fBinShadeList);
   while (TObject * obj = next()) {
      obj->Pop();
      obj->Paint();
   }
      
   if (fCut) {
      fCut->Pop();
      fCut->Paint();
   }
   if (fStats) {
      fStats->Pop();
      fStats->Paint();
   }
      
   fPad->Modified();
   fPad->Update();
}

//-----------------------------------------------------------------------------

void THistogrator2::CreateStats()
{
   double textx1, textx2, texty1, texty2, width, height;
   TPaveStats *s1 =
       (TPaveStats *) fAssocHist->GetListOfFunctions()->
       FindObject("stats");
   if (s1) {
      TObject & statsref = *fStats;
      ((TPave *) s1)->Copy(statsref);

      textx1 = s1->GetX1NDC();
      textx2 = s1->GetX2NDC();
      texty1 = s1->GetY1NDC();
      texty2 = s1->GetY2NDC();

      width = textx2 - textx1;
      height = texty2 - texty1;
      height -= height / 2;

      textx1 -= 1.12 * width;
      textx2 -= 1.12 * width;
      texty1 = texty2 - height;

      fStats->SetTextSize(s1->GetTextSize());
      fStats->SetMargin(s1->GetMargin());
      fStats->SetBorderSize(s1->GetBorderSize());
      fStats->SetTextColor(s1->GetTextColor());
   } else {
      textx1 = 1 - 0.25;
      textx2 = 1;
      texty1 = 1 - 0.15;
      texty2 = 1;

      fStats->SetTextSize(0);
      fStats->SetMargin(0.05);
      fStats->SetBorderSize(2);
      fStats->SetTextColor(1);
   }

   fStats->SetX1NDC(textx1);
   fStats->SetX2NDC(textx2);
   fStats->SetY1NDC(texty1);
   fStats->SetY2NDC(texty2);
}

//-----------------------------------------------------------------------------

void THistogrator2::UnselectAll()
{
   if (fLine) {
      delete fLine;
      fLine = 0;
   }
   TIter next(fBinShadeList);
   while (TObject * obj = next()) {
      fBinShadeList->Remove(obj);
      delete obj;
   }
   if (fStats) {
      UpdateStats(0, 0);
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::SelectBins()
{
   if (!fHist || !fAssocHist)
      return;

   fHist->Reset("Ice");
   UnselectAll();
   TAxis *xaxis = fAssocHist->GetXaxis();
   TAxis *yaxis = fAssocHist->GetYaxis();
   for (int binx = 1; binx <= fHist->GetNbinsX(); binx++) {
      double x = xaxis->GetBinCenter(binx);
      for (int biny = 1; biny <= fHist->GetNbinsY(); biny++) {
         double y = yaxis->GetBinCenter(biny);
         if (fCut->IsInside(x, y)) {
            fHist->SetBinContent(binx, biny,
                                 fAssocHist->GetBinContent(binx, biny));
            CreateBinShade(binx, biny);
         }
      }
   }
   fCut->Pop();
   
   Stat_t sum = fHist->Integral();
   double integral = fHist->Integral("WIDTH");
   UpdateStats(sum, integral);

   if ( (sum != fLastSum) || (integral != fLastIntegral) ) {
      fLastSum = sum;
      fLastIntegral = integral;
      cout << endl;
      cout << fAssocHist->GetName() << ": SUM = " << sum << endl;
      cout << fAssocHist->GetName() << ": INT = " << integral << endl;
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::CreateBinShade(int binx, int biny)
{
   if (fAssocHist) {
      TAxis *xaxis = fAssocHist->GetXaxis();
      TAxis *yaxis = fAssocHist->GetYaxis();
      double lowx = xaxis->GetBinLowEdge(binx);
      double hix = lowx + xaxis->GetBinWidth(binx);
      double lowy = yaxis->GetBinLowEdge(biny);
      double hiy = lowy + yaxis->GetBinWidth(biny);

      TPolyLine *binbox = new TPolyLine;
      binbox->SetPoint(0, lowx, lowy);
      binbox->SetPoint(1, hix, lowy);
      binbox->SetPoint(2, hix, hiy);
      binbox->SetPoint(3, lowx, hiy);
      binbox->SetPoint(4, lowx, lowy);
      binbox->SetLineColor(GetFillColor());
      binbox->SetFillColor(GetFillColor());
      binbox->SetFillStyle(GetFillStyle());
      binbox->Draw("f");
      fBinShadeList->AddLast(binbox);
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::UpdateStats(Stat_t sum, double integral)
{
   char line0[27], line1[27], line2[27];
   double sum_dbl = sum;

   if (fStats) {
      fStats->Clear();
      snprintf(line0, sizeof(line0), "Histogrator");
      snprintf(line1, sizeof(line1), "%7s %-6.4g", "Sum:", sum_dbl);
      snprintf(line2, sizeof(line2), "%7s %-6.4g", "Int:", integral);

      fStats->Clear();
      fStats->AddText(line0);
      fStats->AddText(line1);
      fStats->AddText(line2);
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::ExecuteButton1Up(double padx, double pady)
{
   char cutname[64];
   if (CheckIfZombie())
      return;
   fPad->cd();
   if (fState == kREADY) {
      fState = kSELECT;
      fLastPoint = 0;
      
      fLine = new TLine(padx, pady, padx, pady);
      fLine->SetLineColor(GetLineColor());
      fLine->SetLineStyle(GetLineStyle());
      fLine->Draw();
      
      snprintf(cutname,sizeof(cutname),"%scut",fHist->GetName());

      fCut = new TCutG;
      fCut->SetNameTitle(cutname,fHist->GetTitle());
      fCut->SetLineColor(GetLineColor());
      fCut->SetLineStyle(GetLineStyle());
      fCut->SetPoint(0, padx, pady);
      fCut->Draw();
      gROOT->Add(fCut);
   } else if (fState == kSELECT) {
      fCut->SetPoint(++fLastPoint, padx, pady);
      fCut->Paint();
      
      fPad->Modified();
      fPad->Update();
      
      fLine->SetX1(padx);
      fLine->SetY1(pady);
   } else if (fState == kDISPLAY) {
      SelectBins();
      Paint();
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::ExecuteKey()
{
   double x, y;
   if (CheckIfZombie())
      return;
   if ( (!fCut) || (fCut->GetN() <= 0) ) {
      grootutil::WarnMsgBox("Illegal number of points (0) in TCutG!");
      fState = kDISPLAY;
      ExecuteButton1Up(0, 0);
   } else {
      fPad->cd();
      fState = kDISPLAY;
      fCut->GetPoint(0, x, y);
      fCut->SetPoint(++fLastPoint, x, y);
      SelectBins();
      Paint();
   }
}

//-----------------------------------------------------------------------------

void THistogrator2::ExecuteMotion(double padx, double pady)
{
   if ( (fState == kSELECT) && (fLine) && (!CheckIfZombie()) ) {
      fPad->cd();
      fLine->SetX2(padx);
      fLine->SetY2(pady);
      fLine->Paint();
      fPad->Modified();
      fPad->Update();
   }
}
