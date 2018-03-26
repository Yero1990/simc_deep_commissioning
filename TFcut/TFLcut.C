//----------------------------------------------------------------------
#include <iostream>
#include "TString.h"
#include "TFLcut.h"

using namespace std;

// cuts functions

inline Int_t d0(Double_t x, Double_t y) {return( x<y);}
inline Int_t d1(Double_t x, Double_t y) {return( x<=y);}
inline Int_t d2(Double_t x, Double_t y) {return( x>y);}
inline Int_t d3(Double_t x, Double_t y) {return( x>=y);}
inline Int_t d4(Double_t x, Double_t y) {return( x==y);}
inline Int_t d5(Double_t x, Double_t y) {return( x!=y);}

// basic function



Int_t TFLcut::Init() // initialize critical variables
{
  // Operators : '<'[0],'<='[1],'>'[2],'>=1'[3], '=='[4], '!='[5]
  fOper[0].Append("<"); // careful the sequence is important for
  fOper[1].Append("<=");// searching the right id in Ioper
  fOper[2].Append(">");
  fOper[3].Append(">=");
  fOper[4].Append("==");
  fOper[5].Append("!=");

  // assign function ponters
  fCutFunc[0] = &d0;
  fCutFunc[1] = &d1;
  fCutFunc[2] = &d2;
  fCutFunc[3] = &d3;
  fCutFunc[4] = &d4;
  fCutFunc[5] = &d5;

  // default limits
  fXlim1 = .0;

  // initialize counters
  fNaccept = 0;
  fNreject = 0;
  fNtotal = 0;
  
  // default variable name

  fVar.Append("variable");
  return(0);
}

// find the index into the fOper array of possible cut operators

Int_t TFLcut::Ioper(const char *oper){
  Int_t i;
  for (i=0;i<NOPER;i++){               
    if (fOper[i].Contains(oper)) { // found operator
      return(i);
    }
  }
  return(-1); // not found
}
  
void TFLcut::Build_0(const char *varname)  // single cut constructor
{
  Init();
  fXlim1 = 0.;
  fNoper1 = 0;   // important different default operator 
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function : <=
  fVar=varname;             // save veriable name
  return;
}
void TFLcut::Build_1(Double_t xlim1)  // single cut constructor
{
  Init();  // initialize variables
  fXlim1 = xlim1;
  fNoper1 = 1;
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function : <=
  return;
}

void TFLcut::Build_2( Double_t xlim1, const char * varname)  // single cut constructor
{
  Init();  // initialize variables
  fXlim1 = xlim1;           // set limits
  fNoper1 = 1;
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function : <=
  fVar=varname;             // save veriable name
  return;
}

void TFLcut::Build_3( Double_t xlim1, const char* operl, const char * varname)
{
  Init();  // initialize variables
  fXlim1 = xlim1;           // set limits

  fNoper1 = Ioper(operl);  // get cut function indices

  if (fNoper1 < 0) {
    cout << "Error in cut operator   : " << operl << endl;
    cout << "Set to default operator : " << fOper[0] << endl;
    fNoper1 = 0;
  }

  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function 

  fVar=varname;                    // set new variable name
  return;
}


TFLcut::TFLcut(const char *varname)  // single cut constructor
{
  Build_0(varname);
  Cut = -1;
  return;
}

TFLcut::TFLcut(Double_t xlim1)  // single cut constructor
{
  Build_1(xlim1);
  Cut = -1;
  return;
}
TFLcut::TFLcut(Float_t xlim1)  // single cut constructor
{
  Build_1((Double_t)xlim1);
  Cut = -1;
  return;
}
TFLcut::TFLcut(Int_t xlim1)  // single cut constructor
{
  Build_1((Double_t)xlim1);
  Cut = -1;
  return;
}
TFLcut::TFLcut(Long_t xlim1)  // single cut constructor
{
  Build_1((Double_t)xlim1);
  Cut = -1;
  return;
}

TFLcut::TFLcut( Double_t xlim1, const char * varname)  // single cut constructor
{
  Build_2(xlim1, varname);
  Cut = -1;
  return;
}
TFLcut::TFLcut( Float_t xlim1, const char * varname)  // single cut constructor
{
  Build_2((Double_t)xlim1, varname);
  Cut = -1;
  return;
}
TFLcut::TFLcut( Int_t xlim1, const char * varname)  // single cut constructor
{
  Build_2((Double_t)xlim1, varname);
  Cut = -1;
  return;
}
TFLcut::TFLcut( Long_t xlim1, const char * varname)  // single cut constructor
{
  Build_2((Double_t)xlim1, varname);
  Cut = -1;
  return;
}

TFLcut::TFLcut( Double_t xlim1, const char* operl, const char * varname)
{
  Build_3(xlim1, operl, varname);
  Cut = -1;
  return;
}
TFLcut::TFLcut( Float_t xlim1, const char* operl, const char * varname)
{
  Build_3((Double_t)xlim1, operl, varname);
  Cut = -1;
  return;
}
TFLcut::TFLcut( Int_t xlim1, const char* operl, const char * varname)
{
  Build_3((Double_t)xlim1, operl, varname);
  Cut = -1;
  return;
}
TFLcut::TFLcut( Long_t xlim1, const char* operl, const char * varname)
{
  Build_3((Double_t)xlim1, operl, varname);
  Cut = -1;
  return;
}

// evaluate cuts
Int_t TFLcut::Eval (Double_t x ){
  Int_t res; 

  res = fCutFunc1(fXlim1, x); // check limit
  Cut = res; // store result, mark that it has been used
  // handle counters
  fNtotal++; 

  if (res)  fNaccept++; // accpeted by cut
  if (!res) fNreject++; // rejected by cut
  
  return(res);
}

void TFLcut::Print(){
  cout << "------------------------------------------------------------" << endl;
  cout << "Limit cut on variable : "<< fVar << endl;
  cout << "Condition : " << fXlim1 << fOper[fNoper1] << fVar << endl;
  cout << "Comment : " << fComment << endl;
  cout << "------------------------------------------------------------" << endl;
  return;
}
  
void TFLcut::PrintStat(){
  Float_t fac,fr;

  if (fNtotal == 0) {
    fac = 0.;
    fr  = 0.;
  }
  else
    {
      fac = (Float_t)fNaccept/(Float_t)fNtotal*100.;
      fr  = (Float_t)fNreject/(Float_t)fNtotal*100.;
    }

  cout << "Total numer of tries : " << fNtotal << endl;
  cout << "Accepted             : " << fNaccept << "(" << 
    fac << " %)" << endl;
  cout << "Rejected             : " << fNreject  << "(" << 
    fr << " %)" << endl;
  cout << "------------------------------------------------------------" << endl;
  return;
}

void TFLcut::PrintAll(){
  Print();
  PrintStat();
  return;
}

Int_t TFLcut::SetOperL(const char *oper){
  Int_t i_oper;
  i_oper = Ioper(oper);  // get cut function indices
  if (i_oper < 0) {
    cout << "Invalid operator : " << oper << endl;
    return(-1);
  }
  fNoper1 = i_oper;
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function 
  return(0);
}

void TFLcut::SetVarName(const char* name){
  fVar=name;
  return;
}

void TFLcut::SetComment(const char* txt){
  fComment=txt;
  return;
}


