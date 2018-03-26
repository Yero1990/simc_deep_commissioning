/***************************************************************************
    grootutilLinkDef.C - linking rules for makecint
                             -------------------
    begin                : Fri Jun 06 2003
    version              : 1
    author               : Micha D. Niskin
    email                : mniskin@yahoo.com
 ***************************************************************************/

#ifdef __MAKECINT__

#pragma link off all functions;
#pragma link off all globals;
#pragma link off all classes;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ namespace grootutil;
#pragma link C++ function grootutil::WarnMsgBox;
#pragma link C++ function grootutil::AddMenuItem;
#pragma link C++ function grootutil::FindObject;
#pragma link C++ function grootutil::GetPad;
#pragma link C++ function grootutil::PaintAllCanvases;

#endif
