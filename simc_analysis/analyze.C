#include "TROOT.h"
#include <TChain.h>
#include "deep.C"
#include <fstream>

// run an analysis based on SNT.C the analyysis script for the simc n-tuple
//
// this script is setup for the proposed commissioning runs. the steps in pm are 0.15 GeV/c

void analyze()
{



  gROOT->Reset();
  //gROOT->LoadMacro("deep.C");
  //Create a TChain
  TChain chain("SNT");

  //Create an instance of the heep class
  deep* simc = new deep(&chain);

  Double_t time;     //beam time in hours
  Double_t Ib;       //beam current n uA

  //Chain each file

  TString simc_file;

  /*
  //pmiss = 500 MeV
  Ib = 70.;
  time = 8.;
  simc_file = "d2_pm500_pwia_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();
  */

  
  //----LOW MISSING MOMENTUM ( 80MeV ) calibration-------
  //PWIA = FSI
  
  //pmiss = 80 MeV  -- PWIA
  Ib = 40.;
  time = 1.;
  simc_file = "d2_pm80_lagetpwia_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();

  //pmiss = 80 MeV  --  FSI
  Ib = 40.;
  time = 1.;
  simc_file = "d2_pm80_lagetfsi_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();
  
  //--------------------------------------------------------

  
  //-------------HIGH MISSING MOMENTUM SETTINGS-------------

  /*
  //pmiss = 580 MeV  -- PWIA
  Ib = 40.;
  time = 20.;
  simc_file = "d2_pm580_lagetpwia_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();

  
  //pmiss = 580 MeV  --  FSI
  Ib = 40.;
  time = 20.;
  simc_file = "d2_pm580_lagetfsi_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();
  */
  
  /*
  //pmiss = 750 MeV  -- PWIA
  Ib = 40.;
  time = 42.;
  simc_file = "d2_pm750_lagetpwia_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();

  //pmiss = 750 MeV  --  FSI
  Ib = 40.;
  time = 42.;
  simc_file = "d2_pm750_lagetfsi_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();
  */
  /*
  //---------------------------------------------------

 

  //Calibration run at low missing momentum
 //pmiss = 80 MeV  -- PWIA
  Ib = 40.;
  time = 1.;
  simc_file = "d2_pm80_lagetpwia_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();

  //pmiss = 80 MeV  --  FSI
  Ib = 40.;
  time = 1.;
  simc_file = "d2_pm80_lagetfsi_rad.root";
  cout << "Analyzing: " << simc_file << endl;
  chain.Add("../worksim/"+simc_file);
  simc->Init(&chain);
  simc->Loop(simc_file, Ib, time);
  chain.Reset();
  
  */
}
