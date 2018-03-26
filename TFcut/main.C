//----------------------------------------------------------------------
// this works 
//
#include "TROOT.h"
#include "TRint.h"


int main(int argc, char **argv)
{
  // create the interactive interface
  TRint *theApp = new TRint("ROOT example", &argc, argv);

  // Run the interactive interface
  theApp->Run();
  return(0);
}

