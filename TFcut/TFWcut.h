//----------------------------------------------------------------------
#ifndef __TFWcut__
#define __TFWcut__

#include "TString.h"

#define NOPER 6

typedef Int_t (*FP) (Double_t, Double_t); // type decl. array of functions

class TFWcut {

 private:


  TString fOper[NOPER];  // operators : <,<=,>,>=, ==, !=

  Double_t fXlim1;       //  cut limit
  Double_t fXlim2;       //  cut limit

  Int_t fNbelow;          // counter of events below limit
  Int_t fNabove;        // counter of events above limit
  Int_t fNaccept;       // counter of accepted events
  Int_t fNreject;       // counter of relected events
  Int_t fNtotal;        // counter of total tries
  
  FP fCutFunc1 ; // function pointers lower limit 
  FP fCutFunc2 ; // function pointers upper limit

  Int_t fNoper1;        // operator index used
  Int_t fNoper2;
  TString fVar;         // variable name used in cut 


  TString fComment;       // comment to describe the cut
    
// other utility functions for constructors

  Int_t Ioper(const char *oper); // identify cut operator
  Int_t Init();                  // initialize
  FP fCutFunc[NOPER] ; // array of functions

  void Build_0(const char* varname);
  void Build_1(Double_t xl, Double_t xu);
  void Build_2( Double_t xl, const char * varname, Double_t xu);
  void Build_3( Double_t xl, const char* operl, const char * varname,
  	      const char *operu, Double_t xu);

  
 public:
  // ------------------------------------------------------------
  // constructors
  // ------------------------------------------------------------
  Int_t Cut ; // cut result
  // ------------------------------------------------------------
  // constructors
  // ------------------------------------------------------------

  // constructor for floats
  TFWcut( const char *varname);                      
  TFWcut( Double_t xliml, Double_t xlim2);                      
  TFWcut( Double_t xlim1, const char *varname, Double_t xlim2); 
  TFWcut( Double_t xlim1, const char *operl, const char *varname,  
                             const char *operu, Double_t xlim2 ); 

  TFWcut( Float_t xliml, Float_t xlim2);
  TFWcut( Float_t xlim1, const char *varname , Float_t xlim2);
  TFWcut( Float_t xlim1, const char *operl, const char *varname, 
	  const char *operu, Float_t xlim2);

  // constructor for integers

  TFWcut( Int_t xliml, Int_t xlim2);
  TFWcut( Int_t xlim1, const char *varname, Int_t xlim2);
  TFWcut( Int_t xlim1, const char *operl, const char *varname,
	  const char *operu, Int_t xlim2 );

  TFWcut( Long_t xliml, Long_t xlim2);
  TFWcut( Long_t xlim1, const char *varname, Long_t xlim2);
  TFWcut( Long_t xlim1, const char *operl, const char *varname,
	  const char *operu, Long_t xlim2 );

  // ------------------------------------------------------------


  Int_t Eval ( Double_t x);
  Int_t Eval ( Float_t x);
  Int_t Eval ( Int_t x);
  Int_t Eval ( Long_t x);


  // get information about cut

  void Print() ;  // print cut definition
  void PrintStat(); // print cut statistics
  void PrintAll(); // print both cut def. and statistics

  Int_t GetNaccept(); // get number of passed tries
  Int_t GetNbelow(); // get number of events below
  Int_t GetNabove(); // get number of events above
  Int_t GetNreject(); // get number of rejected events
  Int_t GetNtotal(); // get total number of tries
  

  // set limits


  void SetMin(Double_t x1) {fXlim1 = x1;} // limits for window cuts
  void SetMax(Double_t x2) {fXlim2 = x2;}

  void SetMin(Float_t x1); 
  void SetMax(Float_t x2); 
  void SetMin(Int_t x1); 
  void SetMax(Int_t x2); 
  void SetMin(Long_t x1); 
  void SetMax(Long_t x2); 

  Int_t SetOperL(const char *oper);   // set operator for window cut 
                                     // (lower limit)
  Int_t SetOperU(const char *oper);   // set operator for window cut 
                                     // (upper limit)
  // set variable names
  void SetVarName(const char* name);  // set variable name for cut
  void SetComment(const char* txt);   // enter a comment


};

// inlines (don't work for constructors)

// evaluate functions

inline Int_t TFWcut::Eval (Float_t x){
  return (Eval ( (Double_t) x ) );
}
inline Int_t TFWcut::Eval (Int_t x){
  return(Eval ( (Double_t) x ) );
}
inline Int_t TFWcut::Eval (Long_t x){
  return(Eval ( (Double_t) x ) );
}

inline Int_t TFWcut::GetNaccept() {return fNaccept;}
inline Int_t TFWcut::GetNbelow() {return fNbelow;}
inline Int_t TFWcut::GetNabove() {return fNabove;}
inline Int_t TFWcut::GetNreject() {return fNreject;}
inline Int_t TFWcut::GetNtotal() {return fNtotal;}

inline void TFWcut::SetMin(Float_t x1) {return( SetMin( (Double_t) x1) );} 
inline void TFWcut::SetMax(Float_t x2) {return( SetMax((Double_t) x2) );}
 
inline void TFWcut::SetMin(Int_t x1) {return( SetMin((Double_t) x1) );} 
inline void TFWcut::SetMax(Int_t x2) {return( SetMax((Double_t) x2) );}

inline void TFWcut::SetMin(Long_t x1) {return( SetMin((Double_t) x1) );} 
inline void TFWcut::SetMax(Long_t x2) {return( SetMax((Double_t) x2) );}

#endif

