/***************************************************************************

    THistList.C - Histogrator container class

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

#include "THistList.h"

bool THistList::Add(TObject * hist)
{
   if (!gROOT->FindObject(hist->GetName()))
      return kFALSE;
 
   char name[16], title[32];

   THistogrator *hg = 0;
   TH1 *newhist = 0;

   int id = fMaxID++;
   
   snprintf(name, sizeof(name), "histogrator%d", id);
   snprintf(title, sizeof(title), "in %s %s", hist->IsA()->GetName(), hist->GetName());

   if (hist->InheritsFrom("TH3")) {
      cout << "3D histogram integration not implemented" << endl;
   } else if (hist->InheritsFrom("TH2")) {
      if (hist->InheritsFrom("TH2C")) {
         const TH2C& histref = *((TH2C*) hist);
         newhist = new TH2C(histref);
      } else if (hist->InheritsFrom("TH2D")) {
         const TH2D& histref = *((TH2D*) hist);
         newhist = new TH2D(histref);
      } else if (hist->InheritsFrom("TH2F")) {
         const TH2F& histref = *((TH2F*) hist);
         newhist = new TH2F(histref);
      } else if (hist->InheritsFrom("TH2S")) {
         const TH2S& histref = *((TH2S*) hist);
         newhist = new TH2S(histref);
      }
      hg = new THistogrator2(name, title, (TH1 *) newhist, (TH1 *) hist);
   } else if (hist->InheritsFrom("TH1")) {
      if (hist->InheritsFrom("TH1C")) {
         const TH1C& histref = *((TH1C*) hist);
         newhist = new TH1C(histref);
      } else if (hist->InheritsFrom("TH1D")) {
         const TH1D& histref = *((TH1D*) hist);
         newhist = new TH1D(histref);
      } else if (hist->InheritsFrom("TH1F")) {
         const TH1F& histref = *((TH1F*) hist);
         newhist = new TH1F(histref);
      } else if (hist->InheritsFrom("TH1S")) {
         const TH1S& histref = *((TH1S*) hist);
         newhist = new TH1S(histref);
      }
      hg = new THistogrator1((const char*) name, (const char*) title, (TH1 *) newhist, (TH1 *) hist);
   }
   if (!hg)
      return kFALSE;
   fList.AddLast((TObject *) hg);
   CheckForZombies();
   return kTRUE;
}

//-----------------------------------------------------------------------------

bool THistList::CheckForZombies()
{
   bool retval = kFALSE;
   TIter next(&fList);
   while (THistogrator * obj = (THistogrator *) next()) {
      if (obj->CheckIfZombie()) {
         Remove((TObject *) obj);
         retval = kTRUE;
      }
   }
   return retval;
}

//-----------------------------------------------------------------------------

THistogrator *THistList::Find(TObject * hist)
{
   TIter next(&fList);
   while (THistogrator * obj = (THistogrator *) next()) {
      if ( (obj->GetHist() == hist) || (obj->GetAssocHist() == hist)
           || (obj->GetPave() == hist) || (obj->GetCut() == hist)
           || (obj->GetPoly(hist) == hist) || (obj == hist) ) {
         return obj;
      }
   }
   return 0;
}

//-----------------------------------------------------------------------------

bool THistList::Remove(TObject * hist)
{
   bool retval = kFALSE;
   THistogrator *hg;
   if ( (hg = Find(hist)) ) {
      fList.Remove((TObject *) hg);
      hg->Delete();
      retval = kTRUE;
   }
   return retval;
}
