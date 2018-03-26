//----------------------------------------------------------------------
#ifndef __TFLcut__
#define __TFLcut__

#include "TString.h"

#define NOPER 6

typedef Int_t (*FP) (Double_t, Double_t); // type decl. array of functions

class TFLcut {

 private:
  Double_t fXlim1;       //  cut limit

  Int_t fNaccept;       // counter of accepted events
  Int_t fNreject;       // counter of relected events
  Int_t fNtotal;        // counter of total tries
  
  TString fOper[ NOPER ]; // operators : <,<=,>,>=, ==, !=

  FP fCutFunc[NOPER]; // function pointers 
  FP fCutFunc1      ; // function pointers lower limit 

  Int_t fNoper1;        // operator index used
  TString fVar;         // variable name used in cut 


  TString fComment;       // comment to describe the cut
    
  Int_t Ioper(const char *oper); // identify cut operator
  Int_t Init();                  // initialize

  void Build_0( const char *varname);
  void Build_1( Double_t xlim1)  ;
  void Build_2( Double_t xlim1, const char * varname) ;
  void Build_3( Double_t xlim1, const char* operl, const char * varname);

  
 public:
  // ------------------------------------------------------------
  // Variables
  // ------------------------------------------------------------
  Int_t Cut; // results of the condition (-1 = not tested yet)
  // ------------------------------------------------------------
  // constructors
  // ------------------------------------------------------------

  // constructor for floats
  TFLcut( const char *varname); 

  TFLcut( Double_t xliml);                      
  TFLcut( Double_t xlim1, const char *varname); 
  TFLcut( Double_t xlim1, const char *operl, const char *varname);

  TFLcut( Float_t xliml);
  TFLcut( Float_t xlim1, const char *varname );
  TFLcut( Float_t xlim1, const char *operl, const char *varname);

  // constructor for integers

  TFLcut( Int_t xliml);
  TFLcut( Int_t xlim1, const char *varname);
  TFLcut( Int_t xlim1, const char *operl, const char *varname);

  TFLcut( Long_t xliml);
  TFLcut( Long_t xlim1, const char *varname);
  TFLcut( Long_t xlim1, const char *operl, const char *varname);

  // ------------------------------------------------------------


  Int_t Eval ( Double_t x);
  Int_t Eval ( Float_t x);
  Int_t Eval ( Int_t x);
  Int_t Eval ( Long_t x);


  // get information about cut

  void Print() ;  // print cut definition
  void PrintStat(); // print cut statistics
  void PrintAll(); // print both, cut def. and statistics
  
  Int_t GetNaccept(); // get number of passed 
  Int_t GetNreject(); // get number of rejects
  Int_t GetNtotal(); // get total number of tries

  // set limits

  void SetLimit(Double_t x1) {fXlim1 = x1;} // limits for window cuts
  void SetLimit(Float_t x1);
  void SetLimit(Int_t x1);
  void SetLimit(Long_t x1);
  

  Int_t SetOperL(const char *oper);   // set operator for window cut 
                                     // (lower limit)
  // set variable names
  void SetVarName(const char* name);  // set variable name for cut
  void SetComment(const char* txt);   // enter a comment
};

// ----------------------- inlines

// evaluate functions

inline Int_t TFLcut::Eval ( Float_t x){
  return (Eval ( (Double_t) x ) );
}
inline Int_t TFLcut::Eval ( Int_t x){
  return(Eval ( (Double_t) x ) );
}
inline Int_t TFLcut::Eval ( Long_t x){
  return(Eval ( (Double_t) x ) );
}

inline  Int_t TFLcut::GetNaccept(){return fNaccept;}
inline  Int_t TFLcut::GetNreject(){return fNreject;}
inline  Int_t TFLcut::GetNtotal(){return fNtotal;}  

// other utility functions

inline void TFLcut::SetLimit(Float_t x1) {return( SetLimit( (Double_t) x1) );} 
inline void TFLcut::SetLimit(Int_t x1) {return( SetLimit((Double_t) x1) );} 
inline void TFLcut::SetLimit(Long_t x1) {return( SetLimit((Double_t) x1) );} 

#endif

