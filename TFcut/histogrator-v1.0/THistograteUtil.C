/***************************************************************************

    THistograteUtil.C - Utility class for dealing with histogrators

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

#include "THistograteUtil.h"

ClassImp(THistograteUtil)

THistograteUtil::THistograteUtil() : TObject(), fHistList()
{
   if (gROOT->IsBatch()) {
      Warning("THistograteUtil","Can't run in batch mode.");
   }
}

//-----------------------------------------------------------------------------

void THistograteUtil::AddClassMenus(const char *classname) 
{
	gROOT->GetClass(classname)->MakeCustomMenuList();
	grootutil::AddMenuItem(classname,AddCutMenuItem(classname));
	grootutil::AddMenuItem(classname,LineMenuItem(classname));
	grootutil::AddMenuItem(classname,FillMenuItem(classname));
	grootutil::AddMenuItem(classname,StartMenuItem(classname));
	grootutil::AddMenuItem(classname,DelMenuItem(classname));
	grootutil::AddMenuItem(classname,SeparatorMenuItem(classname));
}

//-----------------------------------------------------------------------------

void THistograteUtil::AddMenu() 
{
   AddClassMenus("TH1C");
   AddClassMenus("TH1D");
   AddClassMenus("TH1F");
   AddClassMenus("TH1S");

   AddClassMenus("TH2C");
   AddClassMenus("TH2D");
   AddClassMenus("TH2F");
   AddClassMenus("TH2S");

	gROOT->GetClass("TPaveStats")->MakeCustomMenuList();
	grootutil::AddMenuItem("TPaveStats",DelMenuItem("TPaveStats"));

	gROOT->GetClass("TCutG")->MakeCustomMenuList();
	grootutil::AddMenuItem("TCutG",DelMenuItem("TCutG"));

	gROOT->GetClass("TPolyLine")->MakeCustomMenuList();
	grootutil::AddMenuItem("TPolyLine",DelMenuItem("TPolyLine"));
}

//-----------------------------------------------------------------------------

TClassMenuItem* THistograteUtil::LineMenuItem(const char *classname) 
{
	TClass *cl = gROOT->GetClass(classname);
	TClassMenuItem *item = new TClassMenuItem(0,cl,"HG SetLineAttributes","HistLineAttributes",this,"TObject*",2);
	return item;
}

//-----------------------------------------------------------------------------

TClassMenuItem* THistograteUtil::AddCutMenuItem(const char* classname) 
{
	TClass *cl = gROOT->GetClass(classname);
	TClassMenuItem *item = new TClassMenuItem(0,cl,"HG Set Cut","HistAddCut",this,"const char*,TObject*",1);
	return item;
}

//-----------------------------------------------------------------------------

TClassMenuItem* THistograteUtil::FillMenuItem(const char *classname) 
{
	TClass *cl = gROOT->GetClass(classname);
	TClassMenuItem *item = new TClassMenuItem(0,cl,"HG SetFillAttributes","HistFillAttributes",this,"TObject*",2);
	return item;
}

//-----------------------------------------------------------------------------

TClassMenuItem* THistograteUtil::SeparatorMenuItem(const char *classname) 
{
	TClass *cl = gROOT->GetClass(classname);
	TClassMenuItem *item = new TClassMenuItem(1,cl,"Histogrator","",0,"");
	return item;
}

//-----------------------------------------------------------------------------
	
TClassMenuItem* THistograteUtil::StartMenuItem(const char *classname) 
{
	TClass *cl = gROOT->GetClass(classname);
	TClassMenuItem *item = new TClassMenuItem(0,cl,"Start/Stop Integrating","Histograte",this,"TObject*",2);
	return item;
}

//-----------------------------------------------------------------------------
	
TClassMenuItem* THistograteUtil::DelMenuItem(const char *classname) 
{
   char method[64];
	TClass *cl = gROOT->GetClass(classname);

   if (!strcmp(classname,"TPaveStats")) {
      snprintf(method,sizeof(method),"PaveDelete");
   } else if (!strcmp(classname,"TCutG")) {
      snprintf(method,sizeof(method),"CutDelete");
   } else if (strstr(classname,"TH")) {
      snprintf(method,sizeof(method),"HistDelete");
   } else if (!strcmp(classname,"TPolyLine")) {
      snprintf(method,sizeof(method),"CutDelete");
   }

	TClassMenuItem *item = new TClassMenuItem(0, cl, "Delete", 
                           (const char*) method, this, "TObject*",2);
	return item;
}

//-----------------------------------------------------------------------------
	
TClassMenuItem* THistograteUtil::UnimplMenuItem(const char *classname, const char *title) 
{
	TClass *cl = gROOT->GetClass(classname);
	TClassMenuItem *item = new TClassMenuItem(0, cl, title, "Unimplemented",
                                             this,"TObject*",2);
	return item;
}

//-----------------------------------------------------------------------------
	
void THistograteUtil::Unimplemented(TObject *obj) 
{
   grootutil::WarnMsgBox("That action is not implemented =(");
}

//-----------------------------------------------------------------------------
	
void THistograteUtil::CutDelete(TObject *cut) 
{
   THistogrator *hg = 0;
	if ( (hg = fHistList.Find(cut)) ) {
      hg->DelCut();
   } else {
		delete cut;
   }
	grootutil::PaintAllCanvases();
}

//-----------------------------------------------------------------------------
	
void THistograteUtil::PaveDelete(TObject *pave) 
{
   THistogrator *hg = 0;
	if ( (hg = fHistList.Find(pave)) ) {
      hg->DelPave();
   } else {
		delete pave;
   }
	grootutil::PaintAllCanvases();
}

//-----------------------------------------------------------------------------
	
void THistograteUtil::HistAddCut(const char *cutname, TObject *hist) 
{
   THistogrator *hg = 0;
   bool err = kFALSE, created = kFALSE;
   
   if ( !(hg = fHistList.Find(hist)) ) {
      fHistList.Add(hist);
      created = kTRUE;
   }

   if ( (hg = fHistList.Find(hist)) ) {
      TObject *cut = gROOT->FindObject(cutname);
      if ( (cut) && (cut->InheritsFrom("TCutG")) ) {
         if ( ((TCutG *)cut)->GetN() > 0 ) {
            const TCutG& cutref = *((TCutG *) cut);
            hg->SetCut(cutref);
         } else {
            grootutil::WarnMsgBox("Illegal number of points (0) in TCutG!");
            err = kTRUE;
         }
      } else {
         grootutil::WarnMsgBox("Can't find a TCutG object with that name!");
         err = kTRUE;
      }
   } else {
      grootutil::WarnMsgBox("Can't create histogrator!");
      err = kTRUE;
   }
   if ( (created) && (err) )
      fHistList.Remove(hist);
}

//-----------------------------------------------------------------------------

void THistograteUtil::HistDelete(TObject *hist) 
{
	if ( !fHistList.Remove(hist) )
		delete hist;
	grootutil::PaintAllCanvases();
}

//-----------------------------------------------------------------------------
	
void THistograteUtil::HistLineAttributes(TObject *hist) 
{
   THistogrator *hg;
   if ( !(hg = fHistList.Find((TObject *) hist)) ) {
      grootutil::WarnMsgBox("No histogrator to set attributes for!");
   } else {
      gROOT->SetSelectedPrimitive(hg);
      hg->SetLineAttributes();
   }
}
   
//-----------------------------------------------------------------------------
	
void THistograteUtil::HistFillAttributes(TObject *hist) 
{
   THistogrator *hg;
   if ( !(hg = fHistList.Find((TObject *) hist)) ) {
      grootutil::WarnMsgBox("No histogrator to set attributes for!");
   } else {
      gROOT->SetSelectedPrimitive(hg);
      hg->SetFillAttributes();
   }
}
   
//-----------------------------------------------------------------------------
	
void THistograteUtil::Histograte(TObject *hist) 
{
	if ( !fHistList.Remove((TObject *)hist) ) {
      if (fHistList.Add((TObject *)hist)) {
         grootutil::PaintAllCanvases();
      } else {
         grootutil::WarnMsgBox("Unable to create histogrator");
      }
   }
}
