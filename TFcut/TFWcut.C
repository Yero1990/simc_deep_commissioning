//----------------------------------------------------------------------
#include <iostream>
#include "TString.h"
#include "TFWcut.h"

using namespace std;

// cuts functions

inline Int_t d0(Double_t x, Double_t y) {return( x<y);}
inline Int_t d1(Double_t x, Double_t y) {return( x<=y);}
inline Int_t d2(Double_t x, Double_t y) {return( x>y);}
inline Int_t d3(Double_t x, Double_t y) {return( x>=y);}
inline Int_t d4(Double_t x, Double_t y) {return( x==y);}
inline Int_t d5(Double_t x, Double_t y) {return( x!=y);}

// basic function

Int_t TFWcut::Init() // initialize critical variables
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
  fXlim2 = 1.0;

  // initialize counters
  fNbelow = 0;
  fNabove = 0;
  fNaccept = 0;
  fNreject = 0;
  fNtotal = 0;
  
  // default variable name

  fVar.Append("variable");
  return(0);
}

// find the index into the fOper array of possible cut operators

Int_t TFWcut::Ioper(const char *oper){
  Int_t i;
  for (i=0;i<NOPER;i++){               
    if (fOper[i].Contains(oper)) { // found operator
      return(i);
    }
  }
  return(-1); // not found
}


void TFWcut::Build_0(const char* varname)  
{
  Init(); // initialize variables
  fXlim1 = 0.;
  fXlim2 = 1.;
  fNoper1 = 1;
  fNoper2 = 1;
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function : <=
  fCutFunc2 = fCutFunc[fNoper2]; // set pointer to cut function : <=
  fVar=varname;             // save veriable name
  return;
}
  
void TFWcut::Build_1(Double_t xl, Double_t xu)
{
  Init();  // initialize variables
  fXlim1 = xl;
  fXlim2 = xu;
  fNoper1 = 1;
  fNoper2 = 1;
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function : <=
  fCutFunc2 = fCutFunc[fNoper2]; // set pointer to cut function : <=
  return;
}

void TFWcut::Build_2( Double_t xl, const char * varname, Double_t xu)  // window cut constructor
{
  Init();  // initialize variables
  fXlim1 = xl;           // set limits
  fXlim2 = xu;
  fNoper1 = 1;
  fNoper2 = 1;
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function : <=
  fCutFunc2 = fCutFunc[fNoper2]; // set pointer to cut function : <=
  fVar=varname;             // save veriable name
  return;
}

void TFWcut::Build_3( Double_t xl, const char* operl, const char * varname,
               const char *operu, Double_t xu)  // window cut constructor
{
  Init();  // initialize variables
  fXlim1 = xl;           // set limits
  fXlim2 = xu;

  fNoper1 = Ioper(operl);  // get cut function indices
  fNoper2 = Ioper(operu);
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function 
  fCutFunc2 = fCutFunc[fNoper2]; // set pointer to cut function 

  fVar=varname;                    // set new variable name

  return;
}


TFWcut::TFWcut(const char* varname)  // window cut constructor (default)
{
  Build_0(varname);
  Cut = -1;
  return;
}

TFWcut::TFWcut(Double_t xlim1, Double_t xlim2)  // window cut constructor
{
  Build_1(xlim1, xlim2);
  Cut = -1;
  return;
}

TFWcut::TFWcut(Float_t xlim1, Float_t xlim2)  // window cut constructor
{
  Build_1((Double_t)xlim1, (Double_t)xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut(Int_t xlim1, Int_t xlim2)  // window cut constructor
{
  Build_1((Double_t)xlim1, (Double_t)xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut(Long_t xlim1, Long_t xlim2)  // window cut constructor
{
  Build_1((Double_t)xlim1, (Double_t)xlim2);
  Cut = -1;
  return;
}

TFWcut::TFWcut( Double_t xlim1, const char * varname, Double_t xlim2)  // window cut constructor
{
  Build_2(xlim1, varname, xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut( Float_t xlim1, const char * varname, Float_t xlim2)  // window cut constructor
{
  Build_2((Double_t)xlim1, varname, (Double_t)xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut( Int_t xlim1, const char * varname, Int_t xlim2)  // window cut constructor
{
  Build_2((Double_t)xlim1, varname, (Double_t)xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut( Long_t xlim1, const char * varname, Long_t xlim2)  // window cut constructor
{
  Build_2((Double_t)xlim1, varname, (Double_t)xlim2);
  Cut = -1;
  return;
}

TFWcut::TFWcut( Double_t xlim1, const char* operl, const char * varname,
               const char *operu, Double_t xlim2)  // window cut constructor
{
  Build_3(xlim1, operl, varname, operu, xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut( Float_t xlim1, const char* operl, const char * varname,
               const char *operu, Float_t xlim2)  // window cut constructor
{
  Build_3((Double_t)xlim1, operl, varname, operu, (Double_t)xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut( Int_t xlim1, const char* operl, const char * varname,
               const char *operu, Int_t xlim2)  // window cut constructor
{
  Build_3((Double_t)xlim1, operl, varname, operu, (Double_t)xlim2);
  Cut = -1;
  return;
}
TFWcut::TFWcut( Long_t xlim1, const char* operl, const char * varname,
               const char *operu, Long_t xlim2)  // window cut constructor
{
  Build_3((Double_t)xlim1, operl, varname, operu, (Double_t)xlim2);
  Cut = -1;
  return;
}


//----------------------------------------------------------------------
// evaluate cuts
Int_t TFWcut::Eval (const Double_t x ){
  Int_t rl, ru, res; 

  rl = fCutFunc1(fXlim1, x); // check lower limit
  ru = fCutFunc2(x, fXlim2); // check upper limit
  
  res = rl && ru; // result of cut
  Cut = res; //store result
  // handle counters
  fNtotal++; 

  if (res)  fNaccept++; // accpeted by cut
  if (!res) fNreject++; // rejected by cut
  if (!rl)  fNbelow++;  // below lower limit
  if (!ru)  fNabove++;  // above upper limit
  
  return(res);
}

void TFWcut::Print(){
  cout << "------------------------------------------------------------" << endl;
  cout << "Windows cut on variable : "<< fVar << endl;
  cout << "Condition : " << fXlim1 << fOper[fNoper1] << fVar << 
    fOper[fNoper2] << fXlim2 << endl;
  cout << "Comment : " << fComment << endl;
  cout << "------------------------------------------------------------" << endl;
  return;
}
  
void TFWcut::PrintStat(){
  Float_t fac ;
  Float_t fb  ;
  Float_t fa  ;

  if (fNtotal == 0) {
    fac = 0.;
    fb  = 0.;
    fa  = 0.;
  }
  else
    {
      fac = (Float_t)fNaccept/(Float_t)fNtotal*100.;
      fb  = (Float_t)fNbelow/(Float_t)fNtotal*100.;
      fa  = (Float_t)fNabove/(Float_t)fNtotal*100.;
    }
  
  cout << "Total numer of tries : " << fNtotal << endl;
  cout << "Accepted             : " << fNaccept << "(" << 
    fac << " %)" << endl;
  cout << "Below                : " << fNbelow  << "(" << 
    fb << " %)" << endl;
  cout << "Above                : " << fNabove  << "(" << 
    fa << " %)" << endl;
  cout << "------------------------------------------------------------" << endl;
  return;
}

void TFWcut::PrintAll(){
  Print();
  PrintStat();
  return;
}

Int_t TFWcut::SetOperL(const char *oper){
  fNoper1 = Ioper(oper);  // get cut function indices
  if (fNoper1 < 0) {
    cout << "Invalid operator : " << oper << endl;
    return(-1);
  }
  fCutFunc1 = fCutFunc[fNoper1]; // set pointer to cut function 
  return(0);
}

Int_t TFWcut::SetOperU(const char *oper){
  fNoper2 = Ioper(oper);  // get cut function indices
  if (fNoper2 < 0) {
    cout << "Invalid operator : " << oper << endl;
    return(-1);
  }
  fCutFunc2 = fCutFunc[fNoper2]; // set pointer to cut function 
  return(0);
}
  
void TFWcut::SetVarName(const char* name){
  fVar=name;
  return;
}

void TFWcut::SetComment(const char* txt){
  fComment=txt;
  return;
}
