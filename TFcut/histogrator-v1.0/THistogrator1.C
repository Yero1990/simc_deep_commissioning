/***************************************************************************

    THistogrator1.C - 1D histogrator class

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

#include "THistogrator1.h"

ClassImp(THistogrator1)

THistogrator1::THistogrator1():THistogrator()
{
   ffirst_bin = 0;
}

//-----------------------------------------------------------------------------

THistogrator1::THistogrator1(const char *name, const char *title, TH1 * h, 
                             TH1 *ah):THistogrator(name, title, h, ah)
{
   ffirst_bin = 0;
   if (fState==kZOMBIE) {
      return;
   }
   Init();
}

//-----------------------------------------------------------------------------

void THistogrator1::Init()
{
   fPad->cd();

   SetFillColor(grootutil::
                GetContrastingColor(fAssocHist->GetFillColor()));
   SetFillStyle(3004);
   fHist->SetLineColor(kRed);
   UnselectAll();

   fPad->cd();
   fHist->Draw("SAME");
   fStats->Draw();
   fPad->RedrawAxis();

   CreateStats();
   UpdateStats(0, 0, 0, 0);
   Paint();

   fState = kREADY;
}

//-----------------------------------------------------------------------------

void THistogrator1::Paint()
{
   if (fPad)
      fPad->cd();
   if (fStats) {
      fStats->Pop();
      fStats->Paint();
   }
   if (fHist)
      fHist->Paint();
   if (fPad) {
      fPad->Modified();
      fPad->Update();
   }
}

//-----------------------------------------------------------------------------

void THistogrator1::SetLineColor(Color_t lcolor) {
   fLineColor = lcolor;
   if (fHist)
      fHist->SetLineColor(lcolor);
   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator1::SetLineStyle(Style_t lstyle) {
   fLineStyle = lstyle;
   if (fHist)
      fHist->SetLineStyle(lstyle);
   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator1::SetFillColor(Color_t fcolor) {
   fFillColor = fcolor;
   if (fHist)
      fHist->SetFillColor(fcolor);
   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator1::SetFillStyle(Style_t fstyle) {
   fFillStyle = fstyle;
   if (fHist)
      fHist->SetFillStyle(fstyle);
   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator1::CreateStats()
{
   double textx1, texty1, textx2, texty2, width, height;
   TPaveStats *s1 =
       (TPaveStats *) fAssocHist->GetListOfFunctions()->
       FindObject("stats");
   if (s1) {
      //existing hist stats box corner points
      textx1 = s1->GetX1NDC();
      textx2 = s1->GetX2NDC();
      texty1 = s1->GetY1NDC();
      texty2 = s1->GetY2NDC();
      width = textx2 - textx1;
      height = texty2 - texty1;
      //add a little for an extra line of text
      height += height / 4;
      //set corner points so that the new stats box is drawn just to
      //the left of the existing one
      textx1 -= 1.12 * width;
      textx2 -= 1.12 * width;

      fStats->SetMargin(s1->GetMargin());
      fStats->SetBorderSize(s1->GetBorderSize());
      fStats->SetTextSize(s1->GetTextSize());
      fStats->SetTextColor(s1->GetTextColor());
   } else {
      width = height = 0.2;
      textx1 = 1 - width;
      textx2 = 1;
      texty1 = 1 - height;
      texty2 = 1;

      fStats->SetMargin(0.05);
      fStats->SetBorderSize(2);
      fStats->SetTextSize(0);
      fStats->SetTextColor(1);
   }
   fStats->SetX1NDC(textx1);
   fStats->SetX2NDC(textx2);
   fStats->SetY1NDC(texty1);
   fStats->SetY2NDC(texty2);
}

//-----------------------------------------------------------------------------

void THistogrator1::SelectBins(int bin1, int bin2)
{
   double left, right, integral;
   Stat_t sum;

   if (bin1 > bin2) {
      int temp = bin1;
      bin1 = bin2;
      bin2 = temp;
   }

   UnselectAll();

   if (fHist) {
      for (int i = bin1; i <= bin2; i++) {
         fHist->SetBinContent(i, fAssocHist->GetBinContent(i));
      }
      left     = fHist->GetBinLowEdge(bin1);
      right    = fHist->GetBinLowEdge(bin2) + fHist->GetBinWidth(bin2);
      integral = fHist->Integral(bin1, bin2, "WIDTH");
      sum      = fHist->Integral(bin1, bin2);
      UpdateStats(sum, integral, left, right);

      if (fState==kDISPLAY) {
         cout << endl;
         cout << fAssocHist->GetName() << ": SUM   = " << sum << endl;
         cout << fAssocHist->GetName() << ": INT   = " << integral << endl;
         cout << fAssocHist->GetName() << ": LEFT  = " << left << endl;
         cout << fAssocHist->GetName() << ": RIGHT = " << right << endl;
      }
   }

   Paint();
}

//-----------------------------------------------------------------------------

void THistogrator1::UpdateStats(Stat_t sum, double integral, double left,
                                double right)
{
   char s1[27], s2[27], s3[27], s4[27], s5[27];
   double sum_dbl = sum;

   if (!fStats)
      return;

   fStats->Clear();

   snprintf(s1, sizeof(s1), "Histogrator");
   snprintf(s2, sizeof(s2), " %-7s % 6.4g ", "Sum:", sum_dbl);
   snprintf(s3, sizeof(s3), " %-7s % 6.4g ", "Int:", integral);
   snprintf(s4, sizeof(s4), " %-7s % 6.4g ", "Left:", left);
   snprintf(s5, sizeof(s5), " %-7s % 6.4g ", "Right:", right);

   fStats->Clear();
   fStats->AddText(s1);
   fStats->AddText(s2);
   fStats->AddText(s3);
   fStats->AddText(s4);
   fStats->AddText(s5);
}

//-----------------------------------------------------------------------------

void THistogrator1::ExecuteButton1Up(double padx, double pady)
{
   int bin = 0;

   if (CheckIfZombie())
      return;
   
   if (fHist) {
      bin = fHist->FindBin(padx);
   
      if (fState==kREADY) {
         fState = kSELECT;
         ffirst_bin = bin;
      } else if (fState==kSELECT) {
         fState = kDISPLAY;
      } else if (fState==kDISPLAY) {
         fState = kREADY;
         ffirst_bin = bin;
      }
   
      SelectBins(ffirst_bin, bin);
   }
}

//-----------------------------------------------------------------------------

void THistogrator1::ExecuteMotion(double padx, double pady)
{
   int bin = 0;

   if (CheckIfZombie())
      return;
   
   if (fHist) {
      bin = fHist->FindBin(padx);
   
      if (fState == kDISPLAY) {
         return;
      } else if (fState == kREADY) {
         ffirst_bin = bin;
      }
   
      SelectBins(ffirst_bin, bin);
   }
}
