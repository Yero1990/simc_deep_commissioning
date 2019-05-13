//Ciaode to plot relevant optics for SHMS singles, with a Carbon target and Centered Sieve In 
//Used for Ytar / Yptar Optimization
#include "../../simc_analysis/set_deep_histos.h"                                                                                                                                            

void carbon_check()
{
  
 //Define Central Angle for HMS/SHMS
  Double_t ptheta_cent = 8.938 * TMath::Pi()/180.;   //3289: 12.194, 3255:12.2  deg
  Double_t xBPM_tar =0.026621;   //Projected beam position at target in cm (EPICS Coordinate System, +x beam right)
  Double_t yBPM_tar =0.017116;
  //SHMS X Mispointing   : -0.126000 cm
  //SHMS Y Mispointing   : -0.060000 cm

  //Read DATA ROOTfiles
  //TString filename =Form("../../../hallc_replay/ROOTfiles/shms_coin_replay_deep_check_%d_50000_ZtarOrg.root",run);        
  TString filename ="../../../hallc_replay/ROOTfiles/coin_replay_heep_check_3286_-1.root";                                                

  TFile *data_file = new TFile(filename, "READ"); 
  TTree *T = (TTree*)data_file->Get("T");
 
  //Create output root file where histograms will be stored
  TFile *outROOT = new TFile("D2data_Optics_3286_PASS1.root", "recreate");

  //Optics SIeve SLit
  TH2F *xsieve_v_ysieve = new TH2F("sieve_pattern", "SHMS Y sieve vs. X Sieve", 100, -10, 10, 100, -15, 15);
  
  //Create relevant histograms
  TH1F *Q_2 = new TH1F("Q_2","Q2", Q2_nbins, Q2_xmin, Q2_xmax);
  TH1F *omega = new TH1F("omega","Energy Transfer, #omega", om_nbins, om_xmin, om_xmax);
  TH1F *W_inv = new TH1F("W_inv", "Invariant Mass, W", W_nbins, W_xmin, W_xmax);     //min width = 19.9 MeV (0.0199) (bin width = 25 MeV)
  TH1F *theta_elec = new TH1F("theta_elec", "Electron Scatt. Angle", the_nbins, the_xmin, the_xmax);
  TH1F *xbj = new TH1F("xbj", "x-Bjorken", xbj_nbins, xbj_xmin, xbj_xmax);
  TH1F *k_f = new TH1F("kf", "Final e^{-} Momentum", kf_nbins, kf_xmin, kf_xmax);

  
  //Target Reconstruction Variables
  TH1F *px_tar = new TH1F("px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *py_tar = new TH1F("py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *pz_tar = new TH1F("pz_tar", "SHMS z_Target", ztar_nbins, -15, 15);


  //Electron Arm Reconstructed Quantities ( xtar, ytar, xptar, yptar, delta)
  TH1F *eytar = new TH1F("eytar", electron_arm + " Y_{tar}", eytar_nbins, eytar_xmin, eytar_xmax);
  TH1F *exptar = new TH1F("exptar", electron_arm + " X'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax);
  TH1F *eyptar = new TH1F("eyptar", electron_arm + " Y'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH1F *edelta = new TH1F("edelta", electron_arm + " Momentum Acceptance, #delta", edelta_nbins, edelta_xmin, edelta_xmax);
  
  //Electron Arm Focal Plane Quantities
  TH1F *exfp = new TH1F("exfp", electron_arm + " X_{fp}", exfp_nbins, exfp_xmin, exfp_xmax);
  TH1F *eyfp = new TH1F("eyfp", electron_arm + " Y_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax);
  TH1F *expfp = new TH1F("expfp", electron_arm + " X'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax);
  TH1F *eypfp = new TH1F("eypfp", electron_arm + " Y'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax);
  
  //Create 2D Histograms at the Focal Plane Quantities
  TH2F *e_xfp_vs_yfp = new TH2F("e_xfp_vs_yfp", "X_{fp} vs Y_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, exfp_nbins, exfp_xmin, exfp_xmax);

  //OPTICS CHECK (W and Emiss Correlations with elestron-Arm Focal Plane / Target Quantities)
  TH2F *W_vs_exfp = new TH2F("W_vs_exfp", "W vs eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_expfp = new TH2F("W_vs_expfp", "W vs eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_eyfp = new TH2F("W_vs_eyfp", "W vs eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_eypfp = new TH2F("W_vs_eypfp", "W vs eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *W_vs_eytar = new TH2F("W_vs_eytar", "W vs eY_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_exptar = new TH2F("W_vs_exptar", "W vs eX'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_eyptar = new TH2F("W_vs_eyptar", "W vs eY'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_edelta = new TH2F("W_vs_edelta", "W vs edelta", edelta_nbins, edelta_xmin, edelta_xmax, W_nbins, W_xmin, W_xmax);


  //OPTICS CHECK (Electron Arm Reconstructed Quantities vs. Focal Plane Quantities) --Each of the reconstructed quantities is a polynomial expansion of focal plane quantities
  TH2F *eytar_vs_exfp = new TH2F("eytar_vs_exfp", "SHMS eY_{tar} vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);
  TH2F *eytar_vs_expfp = new TH2F("eytar_vs_expfp", "SHMS eY_{tar} vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);
  TH2F *eytar_vs_eyfp = new TH2F("eytar_vs_eyfp", "SHMS eY_{tar} vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);
  TH2F *eytar_vs_eypfp = new TH2F("eytar_vs_eypfp", "SHMS eY_{tar} vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);

  TH2F *eyptar_vs_exfp = new TH2F("eyptar_vs_exfp", "SHMS eY'_{tar} vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH2F *eyptar_vs_expfp = new TH2F("eyptar_vs_expfp", "SHMS eY'_{tar} vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH2F *eyptar_vs_eyfp = new TH2F("eyptar_vs_eyfp", "SHMS eY'_{tar} vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH2F *eyptar_vs_eypfp = new TH2F("eyptar_vs_eypfp", "SHMS eY'_{tar} vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);

  TH2F *exptar_vs_exfp = new TH2F("exptar_vs_exfp", "SHMS eX'_{tar} vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);
  TH2F *exptar_vs_expfp = new TH2F("exptar_vs_expfp", "SHMS eX'_{tar} vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);
  TH2F *exptar_vs_eyfp = new TH2F("exptar_vs_eyfp", "SHMS eX'_{tar} vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);
  TH2F *exptar_vs_eypfp = new TH2F("exptar_vs_eypfp", "SHMS eX'_{tar} vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);

  TH2F *edelta_vs_exfp = new TH2F("edelta_vs_exfp", "SHMS Delta e#delta vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *edelta_vs_expfp = new TH2F("edelta_vs_expfp", "SHMS Delta e#delta vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *edelta_vs_eyfp = new TH2F("edelta_vs_eyfp", "SHMS Delta e#delta vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *edelta_vs_eypfp = new TH2F("edelta_vs_eypfp", "SHMS Delta e#delta vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *edelta_vs_eytar = new TH2F("edelta_vs_eytar", "SHMS Delta e#delta vs. eYtar", 100, -5., 5., 100, -15, 20);

  //CUTS
  TH2F *cut_xsieve_v_ysieve = new TH2F("cut_sieve_pattern", "SHMS Y sieve vs. X Sieve", 100, -15, 15, 100, -10, 10);  

  TH1F *cut_Q_2 = new TH1F("cut_Q_2","Q2", Q2_nbins, Q2_xmin, Q2_xmax);
  TH1F *cut_omega = new TH1F("cut_omega","Energy Transfer, #omega", om_nbins, om_xmin, om_xmax);
  TH1F *cut_W_inv = new TH1F("cut_W_inv", "Invariant Mass, W", W_nbins, W_xmin, W_xmax);     //min width = 19.9 MeV (0.0199) (bin width = 25 MeV)
  TH1F *cut_theta_elec = new TH1F("cut_theta_elec", "Electron Scatt. Angle", the_nbins, the_xmin, the_xmax);
  
  TH1F *cut_xbj = new TH1F("cut_xbj", "x-Bjorken", xbj_nbins, xbj_xmin, xbj_xmax);
  TH1F *cut_k_f = new TH1F("cut_kf", "Final e^{-} Momentum", kf_nbins, kf_xmin, kf_xmax);
 
  //Target Reconstruction Variables
  TH1F *cut_px_tar = new TH1F("cut_px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *cut_py_tar = new TH1F("cut_py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *cut_pz_tar = new TH1F("cut_pz_tar", "SHMS z_Target", ztar_nbins, -25, 25);

  //Electron Arm Reconstructed Quantities ( xtar, ytar, xptar, yptar, delta)
  TH1F *cut_eytar = new TH1F("cut_eytar", electron_arm + " Y_{tar}", eytar_nbins, eytar_xmin, eytar_xmax);
  TH1F *cut_exptar = new TH1F("cut_exptar", electron_arm + " X'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax);
  TH1F *cut_eyptar = new TH1F("cut_eyptar", electron_arm + " Y'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH1F *cut_edelta = new TH1F("cut_edelta", electron_arm + " Momentum Acceptance, #delta", edelta_nbins, edelta_xmin, edelta_xmax);
  
  //Electron Arm Focal Plane Quantities
  TH1F *cut_exfp = new TH1F("cut_exfp", electron_arm + " X_{fp}", exfp_nbins, exfp_xmin, exfp_xmax);
  TH1F *cut_eyfp = new TH1F("cut_eyfp", electron_arm + " Y_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax);
  TH1F *cut_expfp = new TH1F("cut_expfp", electron_arm + " X'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax);
  TH1F *cut_eypfp = new TH1F("cut_eypfp", electron_arm + " Y'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax);

  
  //Create 2D Histograms at the Focal Plane Quantities
  TH2F *cut_e_xfp_vs_yfp = new TH2F("cut_e_xfp_vs_yfp", "X_{fp} vs Y_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, exfp_nbins, exfp_xmin, exfp_xmax);

  //OPTICS CHECK (W correlations with electron arm Focal Plane / Target Quantities)
  TH2F *cut_W_vs_exfp = new TH2F("cut_W_vs_exfp", "cut_W vs eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_expfp = new TH2F("cut_W_vs_expfp", "cut_W vs eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_eyfp = new TH2F("cut_W_vs_eyfp", "cut_W vs eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_eypfp = new TH2F("cut_W_vs_eypfp", "cut_W vs eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *cut_W_vs_eytar = new TH2F("cut_W_vs_eytar", "cut_W vs eY_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_exptar = new TH2F("cut_W_vs_exptar", "cut_W vs eX'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_eyptar = new TH2F("cut_W_vs_eyptar", "cut_W vs eY'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_edelta = new TH2F("cut_W_vs_edelta", "cut_W vs edelta", edelta_nbins, edelta_xmin, edelta_xmax, W_nbins, W_xmin, W_xmax);

  //OPTICS CHECK (Electron Arm Reconstructed Quantities vs. Focal Plane Quantities) --Each of the reconstructed quantities is a polynomial expansion of focal plane quantities
  TH2F *cut_eytar_vs_exfp = new TH2F("cut_eytar_vs_exfp", "SHMS eY_{tar} vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);
  TH2F *cut_eytar_vs_expfp = new TH2F("cut_eytar_vs_expfp", "SHMS eY_{tar} vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);
  TH2F *cut_eytar_vs_eyfp = new TH2F("cut_eytar_vs_eyfp", "SHMS eY_{tar} vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);
  TH2F *cut_eytar_vs_eypfp = new TH2F("cut_eytar_vs_eypfp", "SHMS eY_{tar} vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, eytar_nbins, eytar_xmin, eytar_xmax);

  TH2F *cut_eyptar_vs_exfp = new TH2F("cut_eyptar_vs_exfp", "SHMS eY'_{tar} vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH2F *cut_eyptar_vs_expfp = new TH2F("cut_eyptar_vs_expfp", "SHMS eY'_{tar} vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH2F *cut_eyptar_vs_eyfp = new TH2F("cut_eyptar_vs_eyfp", "SHMS eY'_{tar} vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);
  TH2F *cut_eyptar_vs_eypfp = new TH2F("cut_eyptar_vs_eypfp", "SHMS eY'_{tar} vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, eyptar_nbins, eyptar_xmin, eyptar_xmax);

  TH2F *cut_exptar_vs_exfp = new TH2F("cut_exptar_vs_exfp", "SHMS eX'_{tar} vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);
  TH2F *cut_exptar_vs_expfp = new TH2F("cut_exptar_vs_expfp", "SHMS eX'_{tar} vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);
  TH2F *cut_exptar_vs_eyfp = new TH2F("cut_exptar_vs_eyfp", "SHMS eX'_{tar} vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);
  TH2F *cut_exptar_vs_eypfp = new TH2F("cut_exptar_vs_eypfp", "SHMS eX'_{tar} vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, exptar_nbins, exptar_xmin, exptar_xmax);

  TH2F *cut_edelta_vs_exfp = new TH2F("cut_edelta_vs_exfp", "SHMS Delta e#delta vs. eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *cut_edelta_vs_expfp = new TH2F("cut_edelta_vs_expfp", "SHMS Delta e#delta vs. eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *cut_edelta_vs_eyfp = new TH2F("cut_edelta_vs_eyfp", "SHMS Delta e#delta vs. eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  TH2F *cut_edelta_vs_eypfp = new TH2F("cut_edelta_vs_eypfp", "SHMS Delta e#delta vs. eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  
  TH2F *cut_edelta_vs_eytar = new TH2F("cut_edelta_vs_eytar", "SHMS Delta e#delta vs. eYtar", 100, -5., 5., 100, -15, 20);



  //Set Variable Names and Branches
 
  //------Kinematics
  Double_t  theta_e;
  Double_t  W;
  Double_t  Q2;
  Double_t  X;
  Double_t  nu;
  Double_t  kf;
  

  T->SetBranchAddress("P.kin.primary.scat_ang_rad",&theta_e);
  T->SetBranchAddress("P.kin.primary.W",&W);
  T->SetBranchAddress("P.kin.primary.Q2",&Q2);
  T->SetBranchAddress("P.kin.primary.x_bj",&X);
  T->SetBranchAddress("P.kin.primary.nu",&nu);
  T->SetBranchAddress("P.gtr.p",&kf);


  //-------SHMS Focal Plane / Target
  Double_t  e_xfp;
  Double_t  e_xpfp;
  Double_t  e_yfp;
  Double_t  e_ypfp;
  Double_t  e_ytar;
  Double_t  e_yptar;
  Double_t  e_xptar;
  Double_t  e_delta;
  
  T->SetBranchAddress("P.dc.x_fp",&e_xfp);
  T->SetBranchAddress("P.dc.xp_fp",&e_xpfp);
  T->SetBranchAddress("P.dc.y_fp",&e_yfp);
  T->SetBranchAddress("P.dc.yp_fp",&e_ypfp);
  
  T->SetBranchAddress("P.gtr.y",&e_ytar);
  T->SetBranchAddress("P.gtr.ph",&e_yptar);
  T->SetBranchAddress("P.gtr.th",&e_xptar);
  T->SetBranchAddress("P.gtr.dp",&e_delta);
  
  
  //--------Target Quantities (tarx, tary, tarz)
  Double_t  ptar_x;
  Double_t  ptar_y;
  Double_t  ptar_z;
 
  Double_t xsieve;
  Double_t ysieve;

  T->SetBranchAddress("P.react.x",&ptar_x);
  T->SetBranchAddress("P.react.y",&ptar_y);
  T->SetBranchAddress("P.react.z",&ptar_z);
  
  T->SetBranchAddress("P.extcor.xsieve", &xsieve);
  T->SetBranchAddress("P.extcor.ysieve", &ysieve);                                                                                                                      


  //------SHMS Detector Quantities
  Double_t  pcal_etotnorm;
  Double_t  pngcer_npesum;

  T->SetBranchAddress("P.cal.etotnorm",&pcal_etotnorm);
  T->SetBranchAddress("P.ngcer.npeSum",&pngcer_npesum);
 
 
  //Define Boolean for Kin. Cuts
  Bool_t c_edelta;

 //===============================
  // E V E N T   L O O P 1st PASS
  //=============================
  
  
  Long64_t nentries = T->GetEntries();
  
  cout << "nentries = " << nentries << endl;
  
  
  
  for (Long64_t i=0; i<nentries;i++) {
    
    T->GetEntry(i);
    


    c_edelta = e_delta>3.5&&e_delta<8.5;
    
    //APPLY CUTS: BEGIN CUTS LOOP
    if (pcal_etotnorm>0.6&&c_edelta)
    {


      cut_xsieve_v_ysieve->Fill(xsieve, ysieve);
      
	  //Kinematics
	  cut_Q_2->Fill(Q2);
	  cut_omega->Fill(nu);
	  cut_W_inv->Fill(W);
	  cut_theta_elec->Fill(theta_e/dtr);

	  
	  //Additional Kinematics Variables
	  cut_xbj->Fill(X); 
	  cut_k_f->Fill(kf);

	  //Reconstructed Target Quantities (Lab Frame)
	  cut_px_tar->Fill(ptar_x);
	  cut_py_tar->Fill(ptar_y);
	  cut_pz_tar->Fill(ptar_z);

	  //Electron-Arm Target Reconstruction
	  cut_eytar->Fill(e_ytar);
	  cut_exptar->Fill(e_xptar);
	  cut_eyptar->Fill(e_yptar);
	  cut_edelta->Fill(e_delta);
	  
	  //Electron-Arm Focal Plane
	  cut_exfp->Fill(e_xfp);
	  cut_eyfp->Fill(e_yfp);
	  cut_expfp->Fill(e_xpfp);
	  cut_eypfp->Fill(e_ypfp);
	  

	  //Fill 2D HMS Focal Plane Quantities
	  cut_e_xfp_vs_yfp->Fill(e_yfp, e_xfp);
	  
	  //OPTICS CHECK (W / Emiss vs. electron Arm Quantities)
	  cut_W_vs_exfp->Fill(e_xfp, W);
	  cut_W_vs_expfp->Fill(e_xpfp, W);
	  cut_W_vs_eyfp->Fill(e_yfp, W);
	  cut_W_vs_eypfp->Fill(e_ypfp, W);
	  
	  cut_W_vs_eytar->Fill(e_ytar, W);
	  cut_W_vs_exptar->Fill(e_xptar, W);
	  cut_W_vs_eyptar->Fill(e_yptar, W);
	  cut_W_vs_edelta->Fill(e_delta, W);

	  //OPTICS CHECK (electron Arm Recon. vs. Focal Plane)
	  cut_eytar_vs_exfp->Fill(e_xfp, e_ytar);
	  cut_eytar_vs_expfp->Fill(e_xpfp, e_ytar);
	  cut_eytar_vs_eyfp->Fill(e_yfp, e_ytar);
	  cut_eytar_vs_eypfp->Fill(e_ypfp, e_ytar);
  
	  cut_eyptar_vs_exfp->Fill(e_xfp, e_yptar);
	  cut_eyptar_vs_expfp->Fill(e_xpfp, e_yptar);
	  cut_eyptar_vs_eyfp->Fill(e_yfp, e_yptar);
	  cut_eyptar_vs_eypfp->Fill(e_ypfp, e_yptar);

	  cut_exptar_vs_exfp->Fill(e_xfp, e_xptar);
	  cut_exptar_vs_expfp->Fill(e_xpfp, e_xptar);
	  cut_exptar_vs_eyfp->Fill(e_yfp, e_xptar);
	  cut_exptar_vs_eypfp->Fill(e_ypfp, e_xptar);

	  cut_edelta_vs_exfp->Fill(e_xfp, e_delta);
	  cut_edelta_vs_expfp->Fill(e_xpfp, e_delta);
	  cut_edelta_vs_eyfp->Fill(e_yfp, e_delta);
	  cut_edelta_vs_eypfp->Fill(e_ypfp, e_delta);
	  cut_edelta_vs_eytar->Fill(e_ytar, e_delta);

	}//End CUTS LOOP


    xsieve_v_ysieve->Fill(xsieve, ysieve);                                                                                                

      //Kinematics  
      Q_2->Fill(Q2);
      omega->Fill(nu);
      W_inv->Fill(W);
      theta_elec->Fill(theta_e/dtr);   
      xbj->Fill(X); 
      k_f->Fill(kf);
     
      //Reconstructed Target Quantities (Lab Frame)
      px_tar->Fill(ptar_x);
      py_tar->Fill(ptar_y);
      pz_tar->Fill(ptar_z);
   
      //Electron-Arm Target Reconstruction
      eytar->Fill(e_ytar);
      exptar->Fill(e_xptar);
      eyptar->Fill(e_yptar);
      edelta->Fill(e_delta);
      
      //Electron-Arm Focal Plane
      exfp->Fill(e_xfp);
      eyfp->Fill(e_yfp);
      expfp->Fill(e_xpfp);
      eypfp->Fill(e_ypfp);

      //OPTICS CHECK (W / Em vs. electron arm)
      W_vs_exfp->Fill(e_xfp, W);
      W_vs_expfp->Fill(e_xpfp, W);
      W_vs_eyfp->Fill(e_yfp, W);
      W_vs_eypfp->Fill(e_ypfp, W);
      
      W_vs_eytar->Fill(e_ytar, W);
      W_vs_exptar->Fill(e_xptar, W);
      W_vs_eyptar->Fill(e_yptar, W);
      W_vs_edelta->Fill(e_delta, W);

      edelta_vs_eytar->Fill(e_ytar, e_delta);

  } //end entry loop
     
  outROOT->Write();
  /*

  TCanvas *c1 = new TCanvas("c1", "", 2000,1000);
  c1->Divide(2,1);
  c1->cd(1);

  //Fit Foils React Z peaks
  cut_pz_tar->GetXaxis()->SetRange(-15,-5);
  int binx1 = cut_pz_tar->GetMaximumBin();
  double g1_mu = cut_pz_tar->GetXaxis()->GetBinCenter(binx1);
  double g1_sig = cut_pz_tar->GetStdDev();                                            

  cut_pz_tar->GetXaxis()->SetRange(-5,5); 
  int binx2 = cut_pz_tar->GetMaximumBin();                                                                                              
  double g2_mu = cut_pz_tar->GetXaxis()->GetBinCenter(binx2);      
  double g2_sig = cut_pz_tar->GetStdDev();  

  cut_pz_tar->GetXaxis()->SetRange(5,15); 
  int binx3 = cut_pz_tar->GetMaximumBin(); 
  double g3_mu = cut_pz_tar->GetXaxis()->GetBinCenter(binx3);      
  double g3_sig = cut_pz_tar->GetStdDev();  
  
  cut_pz_tar->GetXaxis()->SetRange();                                                                            

  
  //Create Fit Functions                                                                  
  TF1 *fGlobal = new TF1("fGlobal", "gaus(0)+gaus(3)+gaus(6)+pol2(9)", -13,16);             
  TF1 *fSignal = new TF1("fSignal", "gaus(0)+gaus(3)+gaus(6)", -13, 16);
  TF1 *fBkg = new TF1("fBkg", "pol2", -15, 16);                   

  fGlobal->SetLineColor(kBlack);
  fSignal->SetLineColor(kRed);
  fBkg->SetLineColor(kBlue);

  Double_t par[11];

  fGlobal->SetParameters(5000, -9, 2.*g1_sig, 5000, 2.5, 3.*g2_sig, 5000, 12, 2.*g3_sig);
  cut_pz_tar->Fit(fGlobal, "R");

  fGlobal->GetParameters(par);
  fSignal->SetParameters(&par[0]);
  fBkg->SetParameters(&par[9]);                                                         

  fSignal->Draw("sames");
  fBkg->Draw("sames");

  TH1F *ztar_Signal = new TH1F(*cut_pz_tar);
  ztar_Signal->Add(fBkg,-1);
  c1->cd(2);
  ztar_Signal->SetLineColor(kRed);
  cut_pz_tar->Draw("hist");
  ztar_Signal->Draw("sames");

  c1->Update();
  //c1->Close();
  //-----------------------------
  
  TCanvas *c2 = new TCanvas("c2", "", 1000,1000);
  c2->cd();
    
  gStyle->SetOptFit();

  //Fit background subtacrted ztar;
  TF1 *g1 = new TF1("g1", "gaus(0)", -12,-5);
  TF1 *g2 = new TF1("g2", "gaus", -3,7);
  TF1 *g3 = new TF1("g3", "gaus", 8,15); 
  
  ztar_Signal->Fit("g1", "R");
  ztar_Signal->Fit("g2", "R+");                                                                                                                                      
  ztar_Signal->Fit("g3", "R+");                                                                                                                                    
    
  //GEt Fit Parameters
  double f1_mu  = g1->GetParameter(1);
  double f1_sig = g1->GetParameter(2);
  double f2_mu  = g2->GetParameter(1);
  double f2_sig = g2->GetParameter(2);
  double f3_mu  = g3->GetParameter(1);
  double f3_sig = g3->GetParameter(2);

  double f1_min = f1_mu-2*f1_sig;
  double f1_max = f1_mu+2*f1_sig;
  double f2_min = f2_mu-2*f2_sig;
  double f2_max = f2_mu+2*f2_sig;
  double f3_min = f3_mu-2*f3_sig;
  double f3_max = f3_mu+2*f3_sig;

  ztar_Signal->SetLineColor(kBlack);
  ztar_Signal->Draw("sames");
  ztar_Signal->GetYaxis()->SetRangeUser(0.0, 5000);
  //Create TLine to draw
  TLine *l1_min = new TLine(f1_mu-2*f1_sig, 0, f1_mu-2*f1_sig, 4500);
  TLine *l1_max = new TLine(f1_mu+2*f1_sig, 0, f1_mu+2*f1_sig, 4500);
  l1_min->SetLineWidth(2);
  l1_min->SetLineStyle(9);
  l1_max->SetLineWidth(2);
  l1_max->SetLineStyle(9);
  l1_min->Draw("sames");
  l1_max->Draw("sames");

  TLine *l2_min = new TLine(f2_mu-2*f2_sig, 0, f2_mu-2*f2_sig, 4500);
  TLine *l2_max = new TLine(f2_mu+2*f2_sig, 0, f2_mu+2*f2_sig, 4500);
  l2_min->SetLineWidth(2);
  l2_min->SetLineStyle(9);
  l2_max->SetLineWidth(2);
  l2_max->SetLineStyle(9);
  l2_min->Draw("sames");
  l2_max->Draw("sames");
  
  TLine *l3_min = new TLine(f3_mu-2*f3_sig, 0, f3_mu-2*f3_sig, 4500);
  TLine *l3_max = new TLine(f3_mu+2*f3_sig, 0, f3_mu+2*f3_sig, 4500);
  l3_min->SetLineWidth(2);
  l3_min->SetLineStyle(9);
  l3_max->SetLineWidth(2);
  l3_max->SetLineStyle(9);
  l3_min->Draw("sames");
  l3_max->Draw("sames");


  cout << "f1_mu = " << f1_mu << endl;
  cout << "f1_sig = " << f1_sig << endl;
  cout << "f2_mu = " << f2_mu << endl;
  cout << "f2_sig = " << f2_sig << endl;
  cout << "f3_mu = " << f3_mu << endl;
  cout << "f3_sig = " << f3_sig << endl;

  //----------------------------------------------------
  
  //Do Second Pass Over DATA to apply the Ztarget Cuts, and look at Sieve Slit
  //===============================
  // E V E N T   L O O P 2nd PASS
  //=============================
   
  TFile *outROOT2 = new TFile("D2data_Optics_3286_PASS2.root", "recreate");

  TH1F *cut_px_tar2 = new TH1F("cut_px_tar2", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *cut_py_tar2 = new TH1F("f1cut_py_tar2", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *cut_pz_tar2 = new TH1F("f1cut_pz_tar2", "SHMS z_Target", ztar_nbins, -25, 25);
  TH2F *cut_xsieve_v_ysieve2 = new TH2F("no_foil_f1cut_sieve_pattern", "FOIL 1(-10 cm): SHMS Y vs. X Sieve", 100, -15, 15, 100, -10, 10);  
  
  //Create New Histograms for each foil
  TH1F *f1cut_px_tar = new TH1F("f1cut_px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *f1cut_py_tar = new TH1F("f1cut_py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *f1cut_pz_tar = new TH1F("f1cut_pz_tar", "SHMS z_Target", ztar_nbins, -25, 25);
  TH2F *f1cut_xsieve_v_ysieve = new TH2F("f1cut_sieve_pattern", "FOIL 1(-10 cm): SHMS Y vs. X Sieve", 100, -15, 15, 100, -10, 10);  
  
  TH1F *f2cut_px_tar = new TH1F("f2cut_px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *f2cut_py_tar = new TH1F("f2cut_py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *f2cut_pz_tar = new TH1F("f2cut_pz_tar", "SHMS z_Target", ztar_nbins, -25, 25);
  TH2F *f2cut_xsieve_v_ysieve = new TH2F("f2cut_sieve_pattern", "FOIL 2(0 cm): SHMS Y vs. X Sieve", 100, -15, 15, 100, -10, 10);  

  TH1F *f3cut_px_tar = new TH1F("f3cut_px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *f3cut_py_tar = new TH1F("f3cut_py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *f3cut_pz_tar = new TH1F("f3cut_pz_tar", "SHMS z_Target", ztar_nbins, -25, 25);
  TH2F *f3cut_xsieve_v_ysieve = new TH2F("f3cut_sieve_pattern", "FOIL 3(+10 cm): SHMS Y vs. X Sieve", 100, -15, 15, 100, -10, 10);  
 
  cout << "nentries = " << nentries << endl;
  
  //Z Target cut on Foils
  Bool_t ztar_cut_f1;
  Bool_t ztar_cut_f2;
  Bool_t ztar_cut_f3;

  

  for (Long64_t i=0; i<nentries;i++) {
    
    T->GetEntry(i);
    
    ztar_cut_f1 = ptar_z>f1_min&&ptar_z<f1_max;
    ztar_cut_f2 = ptar_z>f2_min&&ptar_z<f2_max;
    ztar_cut_f3 = ptar_z>f3_min&&ptar_z<f3_max;
    c_edelta = e_delta>-10.&&e_delta<22.;
    

    //APPLY CUTS: Delta AND SHMS Cal Cuts
    if (pcal_etotnorm>0.85&&c_edelta)
    {

      cut_xsieve_v_ysieve2->Fill(xsieve, ysieve);
      
      //Reconstructed Target Quantities (Lab Frame)
      cut_px_tar2->Fill(ptar_x);
      cut_py_tar2->Fill(ptar_y);
      cut_pz_tar2->Fill(ptar_z);
        
    }

    
    //APPLY CUTS: Delta / SHMS Cal Cuts / FOIL 1 Ztar
    if (pcal_etotnorm>0.85&&c_edelta&&ztar_cut_f1)
    {
      //Reconstructed Target Quantities (Lab Frame)
      f1cut_xsieve_v_ysieve->Fill(xsieve, ysieve);
      f1cut_px_tar->Fill(ptar_x);
      f1cut_py_tar->Fill(ptar_y);
      f1cut_pz_tar->Fill(ptar_z);        
    }
    
    //APPLY CUTS: Delta / SHMS Cal Cuts / FOIL 2 Ztar
    if (pcal_etotnorm>0.85&&c_edelta&&ztar_cut_f2)
      {
	//Reconstructed Target Quantities (Lab Frame)
	f2cut_xsieve_v_ysieve->Fill(xsieve, ysieve);
	f2cut_px_tar->Fill(ptar_x);
	f2cut_py_tar->Fill(ptar_y);
	f2cut_pz_tar->Fill(ptar_z);        
      }
    
    //APPLY CUTS: Delta / SHMS Cal Cuts / FOIL 3 Ztar
    if (pcal_etotnorm>0.85&&c_edelta&&ztar_cut_f3)
      {
	//Reconstructed Target Quantities (Lab Frame)
	f3cut_xsieve_v_ysieve->Fill(xsieve, ysieve);
	f3cut_px_tar->Fill(ptar_x);
	f3cut_py_tar->Fill(ptar_y);
	f3cut_pz_tar->Fill(ptar_z);        
      }
  
    
  }//end event loop
  
  outROOT2->Write();

  //Draw To Canvas
  TCanvas *cFoil = new TCanvas("cFoil", "", 1500, 1000);
  cFoil->Divide(2,2);
  cFoil->cd(1);
  cut_xsieve_v_ysieve->Draw("colz");
  cFoil->cd(2);
  f1cut_xsieve_v_ysieve->Draw("colz");
  cFoil->cd(3);
  f2cut_xsieve_v_ysieve->Draw("colz");
  cFoil->cd(4);
  f3cut_xsieve_v_ysieve->Draw("colz");
  
  cFoil->SaveAs("Foil_Sieve_Pattern_3286.pdf");
  */
}
