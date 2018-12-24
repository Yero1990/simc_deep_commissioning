#include "../simc_analysis/set_deep_histos.h"

void analyze_deepData(int run, int Pmiss)
{

//PREVENT DISPLAY 
  //gROOT->SetBatch(kTRUE);
    
  
  //Define Central Angle for HMS/SHMS
  Double_t htheta_cent = 38.896 * TMath::Pi()/180.;   //              3255: 37.29 deg
  Double_t ptheta_cent = 12.194 * TMath::Pi()/180.;   //3289: 12.194, 3255:12.2  deg
  Double_t xBPM_tar = 0.147674;   //Projected beam position at target (Hall Coordinate System)
  

  //Read DATA ROOTfiles
  TString filename =Form("../../hallc_replay/ROOTfiles/D2_pm80/coin_replay_deep_check_%d_-1_pCorr.root",run);        
  //  TString filename =Form("../../hallc_replay/ROOTfiles/shms_coin_replay_deep_check_%d_-1.root" ,run);                                                   

  TFile *data_file = new TFile(filename, "READ"); 
  TTree *T = (TTree*)data_file->Get("T");
 
  //Create output root file where histograms will be stored
  TFile *outROOT = new TFile(Form("D2data_pm%d_%d.root", Pmiss, run), "recreate");
  

  //********* Create 1D Histograms **************
  
  TH1F *epCT = new TH1F("epCT","e-Proton Coincidence Time", 100, 0, 20);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV

  //Kinematics Quantities

  TH1F *Emiss = new TH1F("Emiss","missing energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *pm = new TH1F("pm","missing momentum", Pm_nbins, Pm_xmin, Pm_xmax);  //min width = 32 MeV (0.032)
  TH1F *Q_2 = new TH1F("Q_2","Q2", Q2_nbins, Q2_xmin, Q2_xmax);
  TH1F *omega = new TH1F("omega","Energy Transfer, #omega", om_nbins, om_xmin, om_xmax);
  TH1F *W_inv = new TH1F("W_inv", "Invariant Mass, W", W_nbins, W_xmin, W_xmax);     //min width = 19.9 MeV (0.0199) (bin width = 25 MeV)
  TH1F *theta_elec = new TH1F("theta_elec", "Electron Scatt. Angle", the_nbins, the_xmin, the_xmax);
  TH1F *theta_prot = new TH1F("theta_prot", "Proton Scatt. Angle", thp_nbins, thp_xmin, thp_xmax);
  
  //Additional Kinematics Variables
  TH1F *W_2 = new TH1F("W2", "Invariant Mass W2", W2_nbins, W2_xmin, W2_xmax);
  TH1F *xbj = new TH1F("xbj", "x-Bjorken", xbj_nbins, xbj_xmin, xbj_xmax);
  TH1F *P_f = new TH1F("P_f", "Final Proton Momentum", Pf_nbins, Pf_xmin, Pf_xmax);
  TH1F *k_f = new TH1F("kf", "Final e^{-} Momentum", kf_nbins, kf_xmin, kf_xmax);
  TH1F *theta_q = new TH1F("theta_q", "q-vector Angle, #theta_{q}", thq_nbins, thq_xmin, thq_xmax);
  TH1F *q_vec = new TH1F("q", "q-vector, |q|", q_nbins, q_xmin, q_xmax);
  TH1F *thet_pq = new TH1F("theta_pq", "(Proton, q-vector) Angle, #theta_{pq}", thpq_nbins, thpq_xmin, thpq_xmax);
  TH1F *E_n = new TH1F("En", "Neutron Final Energy", En_nbins, En_xmin, En_xmax);
  TH1F *theta_nq = new TH1F("theta_nq", "(q-vector,Neutron) Angle, #theta_{nq}", thnq_nbins, thnq_xmin, thnq_xmax);
  TH1F *thet_pq_v2 = new TH1F("theta_pq_v2", "(Proton, q-vector) Angle, #theta_{pq}", thpq_nbins, thpq_xmin, thpq_xmax);
    
  TH1F *Mmiss = new TH1F("Mmiss","Missing Mass", Mm_nbins, Mm_xmin, Mm_xmax);      
  TH1F *Mmissv2 = new TH1F("Mmissv2","Missing Mass Version 2", Mm_nbins, Mm_xmin, Mm_xmax);      
  TH1F *Emiss_nuc = new TH1F("Emiss_nuc","Nuclear Missing Energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *Erecoil = new TH1F("Erecoil","Recoil Neutron Energy", En_nbins, En_xmin, En_xmax);
  TH1F *pmx = new TH1F("pmx","Pmx missing momentum", Pmx_nbins, Pmx_xmin, Pmx_xmax);
  TH1F *pmy = new TH1F("pmy","Pmy missing momentum", Pmy_nbins, Pmy_xmin, Pmy_xmax);
  TH1F *pmz = new TH1F("pmz","Pmz missing momentum", Pmz_nbins, Pmz_xmin, Pmz_xmax);
  TH1F *KinN = new TH1F("Kn","Neutron Kin. Energy", Kn_nbins, Kn_xmin, Kn_xmax);
  TH1F *KinP = new TH1F("Kp","Proton Kin. Energy", Kp_nbins, Kp_xmin, Kp_xmax);
  TH1F *E_p = new TH1F("Ep","Proton Final Energy", Ep_nbins, Ep_xmin, Ep_xmax);  



  //Target Reconstruction Variables
  TH1F *hx_tar = new TH1F("hx_tar", "HMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *hy_tar = new TH1F("hy_tar", "HMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *hz_tar = new TH1F("hz_tar", "HMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
  
  //Target Reconstruction Variables
  TH1F *px_tar = new TH1F("px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *py_tar = new TH1F("py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *pz_tar = new TH1F("pz_tar", "SHMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);

  TH1F *ztar_diff = new TH1F("ztar_diff", "z_Target Difference (hcana)", ztar_nbins, ztar_xmin, ztar_xmax);

  //  ----Calculated Ztarget Quantities (Using a formula)
  //Target Reconstruction Variables
  TH1F *calc_hz_tar = new TH1F("calc_hz_tar", "HMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
  TH1F *calc_pz_tar = new TH1F("calc_pz_tar", "SHMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);

  TH1F *calc_hz_tar2 = new TH1F("calc_hz_tar2", "HMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
  TH1F *calc_pz_tar2 = new TH1F("calc_pz_tar2", "SHMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);

  TH1F *calc_ztar_diff = new TH1F("calc_ztar_diff", "z_Target Difference", ztar_nbins, ztar_xmin, ztar_xmax);
  TH1F *calc_ztar_diff2 = new TH1F("calc_ztar_diff2", "z_Target Difference", ztar_nbins, ztar_xmin, ztar_xmax);

  //Hadron arm Reconstructed Quantities ( xtar, ytar, xptar, yptar, delta)
  TH1F *hytar = new TH1F("hytar", hadron_arm + " Y_{tar}", hytar_nbins, hytar_xmin, hytar_xmax);
  TH1F *hxptar = new TH1F("hxptar", hadron_arm + " X'_{tar}", hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH1F *hyptar = new TH1F("hyptar", hadron_arm + " Y'_{tar}", hyptar_nbins, hyptar_xmin, hyptar_xmax );
  TH1F *hdelta = new TH1F("hdelta", hadron_arm + " Momentum Acceptance, #delta", hdelta_nbins, hdelta_xmin, hdelta_xmax);
  
  //Hadron arm Focal Plane Quantities
  TH1F *hxfp = new TH1F("hxfp", hadron_arm + " X_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax);
  TH1F *hyfp = new TH1F("hyfp", hadron_arm + " Y_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax);
  TH1F *hxpfp = new TH1F("hxpfp", hadron_arm + " X'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax );
  TH1F *hypfp = new TH1F("hypfp", hadron_arm + " Y'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax);

  
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
  
  //Cross-Check correlations
  TH2F *emiss_vs_pmiss = new TH2F("emiss_vs_pmiss", " E_{miss} vs. P_{miss}", Pm_nbins, Pm_xmin, Pm_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *edelta_vs_eyptar = new TH2F("edelta_vs_eyptar", electron_arm + " #delta vs. Y'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  
  
  //Create 2D Histograms at the Focal Plane Quantities
  TH2F *h_xfp_vs_yfp = new TH2F("h_xfp_vs_yfp", "X_{fp} vs Y_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hxfp_nbins, hxfp_xmin, hxfp_xmax);
  TH2F *e_xfp_vs_yfp = new TH2F("e_xfp_vs_yfp", "X_{fp} vs Y_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, exfp_nbins, exfp_xmin, exfp_xmax);
  
  //2D HMS v. SHMS Acceptance Correlations
  TH2F *hytar_vs_eytar = new TH2F("hytar_vs_eytar", "HMS vs. SHMS, Y_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *hxptar_vs_exptar = new TH2F("hxptar_vs_exptar", "HMS vs. SHMS, X'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *hyptar_vs_eyptar = new TH2F("hyptar_vs_eyptar", "HMS vs. SHMS, Y'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *hdelta_vs_edelta = new TH2F("hdelta_vs_edelta", "HMS vs. SHMS, #delta", edelta_nbins, edelta_xmin, edelta_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  
  //OPTICS CHECK (W and Emiss Correlations with elestron-Arm Focal Plane / Target Quantities)
  TH2F *W_vs_exfp = new TH2F("W_vs_exfp", "W vs eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_expfp = new TH2F("W_vs_expfp", "W vs eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_eyfp = new TH2F("W_vs_eyfp", "W vs eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_eypfp = new TH2F("W_vs_eypfp", "W vs eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *W_vs_eytar = new TH2F("W_vs_eytar", "W vs eY_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_exptar = new TH2F("W_vs_exptar", "W vs eX'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_eyptar = new TH2F("W_vs_eyptar", "W vs eY'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_edelta = new TH2F("W_vs_edelta", "W vs edelta", edelta_nbins, edelta_xmin, edelta_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *Em_vs_exfp = new TH2F("Em_vs_exfp", "Em vs eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_expfp = new TH2F("Em_vs_expfp", "Em vs eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_eyfp = new TH2F("Em_vs_eyfp", "Em vs eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_eypfp = new TH2F("Em_vs_eypfp", "Em vs eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  
  TH2F *Em_vs_eytar = new TH2F("Em_vs_eytar", "Em vs eY_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_exptar = new TH2F("Em_vs_exptar", "Em vs eX'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_eyptar = new TH2F("Em_vs_eyptar", "Em vs eY'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_edelta = new TH2F("Em_vs_edelta", "Em vs edelta", edelta_nbins, edelta_xmin, edelta_xmax, Em_nbins, Em_xmin, Em_xmax);
  

  //OPTICS CHECK (W and Emiss Correlations with hadron-Arm Focal Plane / Target Quantities)
  TH2F *W_vs_hxfp = new TH2F("W_vs_hxfp", "W vs hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_hxpfp = new TH2F("W_vs_hxpfp", "W vs hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_hyfp = new TH2F("W_vs_hyfp", "W vs hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_hypfp = new TH2F("W_vs_hypfp", "W vs hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *W_vs_hytar = new TH2F("W_vs_hytar", "W vs hY_{tar}", hytar_nbins, hytar_xmin, hytar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_hxptar = new TH2F("W_vs_hxptar", "W vs hX'_{tar}", hxptar_nbins, hxptar_xmin, hxptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_hyptar = new TH2F("W_vs_hyptar", "W vs hY'_{tar}", hyptar_nbins, hyptar_xmin, hyptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *W_vs_hdelta = new TH2F("W_vs_hdelta", "W vs hdelta", hdelta_nbins, hdelta_xmin, hdelta_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *Em_vs_hxfp = new TH2F("Em_vs_hxfp", "Em vs hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_hxpfp = new TH2F("Em_vs_hxpfp", "Em vs hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_hyfp = new TH2F("Em_vs_hyfp", "Em vs hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_hypfp = new TH2F("Em_vs_hypfp", "Em vs hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  
  TH2F *Em_vs_hytar = new TH2F("Em_vs_hytar", "Em vs hY_{tar}", hytar_nbins, hytar_xmin, hytar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_hxptar = new TH2F("Em_vs_hxptar", "Em vs hX'_{tar}", hxptar_nbins, hxptar_xmin, hxptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_hyptar = new TH2F("Em_vs_hyptar", "Em vs hY'_{tar}", hyptar_nbins, hyptar_xmin, hyptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *Em_vs_hdelta = new TH2F("Em_vs_hdelta", "Em vs hdelta", hdelta_nbins, hdelta_xmin, hdelta_xmax, Em_nbins, Em_xmin, Em_xmax);
 
  TH2F *dP_vs_reacty = new TH2F("dP_vs_reacty", "dP vs hreacsty", 100, -0.5, 0.5, 100 , -0.5, 0.5);

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

  //OPTICS CHECK (Hadron  Arm Reconstructed Quantities vs. Focal Plane Quantities) --Each of the reconstructed quantities is a polynomial expansion of focal plane quantities
  TH2F *hytar_vs_hxfp = new TH2F("hytar_vs_hxfp", "HMS hY_{tar} vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *hytar_vs_hxpfp = new TH2F("hytar_vs_hxpfp", "HMS hY_{tar} vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *hytar_vs_hyfp = new TH2F("hytar_vs_hyfp", "HMS hY_{tar} vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *hytar_vs_hypfp = new TH2F("hytar_vs_hypfp", "HMS hY_{tar} vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);

  TH2F *hyptar_vs_hxfp = new TH2F("hyptar_vs_hxfp", "HMS hY'_{tar} vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *hyptar_vs_hxpfp = new TH2F("hyptar_vs_hxpfp", "HMS hY'_{tar} vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *hyptar_vs_hyfp = new TH2F("hyptar_vs_hyfp", "HMS hY'_{tar} vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *hyptar_vs_hypfp = new TH2F("hyptar_vs_hypfp", "HMS hY'_{tar} vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);

  TH2F *hxptar_vs_hxfp = new TH2F("hxptar_vs_hxfp", "HMS hX'_{tar} vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *hxptar_vs_hxpfp = new TH2F("hxptar_vs_hxpfp", "HMS hX'_{tar} vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *hxptar_vs_hyfp = new TH2F("hxptar_vs_hyfp", "HMS hX'_{tar} vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *hxptar_vs_hypfp = new TH2F("hxptar_vs_hypfp", "HMS hX'_{tar} vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);

  TH2F *hdelta_vs_hxfp = new TH2F("hdelta_vs_hxfp", "HMS Delta h#delta vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  TH2F *hdelta_vs_hxpfp = new TH2F("hdelta_vs_hxpfp", "HMS Delta h#delta vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  TH2F *hdelta_vs_hyfp = new TH2F("hdelta_vs_hyfp", "HMS Delta h#delta vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  TH2F *hdelta_vs_hypfp = new TH2F("hdelta_vs_hypfp", "HMS Delta h#delta vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);

  /************Define Histos to APPLY CUTS*********************************/
 
  TH1F *cut_epCT = new TH1F("cut_epCT","e-Proton Coincidence Time", 100, 0, 20);
  
  //Kinematics Quantities
  TH1F *cut_Emiss = new TH1F("cut_Emiss","missing energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  CUT_OUNTS/25 MeV
  TH1F *cut_pm = new TH1F("cut_pm","missing momentum", Pm_nbins, Pm_xmin, Pm_xmax);  //min width = 32 MeV (0.032)
  TH1F *cut_Q_2 = new TH1F("cut_Q_2","Q2", Q2_nbins, Q2_xmin, Q2_xmax);
  TH1F *cut_omega = new TH1F("cut_omega","Energy Transfer, #omega", om_nbins, om_xmin, om_xmax);
  TH1F *cut_W_inv = new TH1F("cut_W_inv", "Invariant Mass, W", W_nbins, W_xmin, W_xmax);     //min width = 19.9 MeV (0.0199) (bin width = 25 MeV)
  TH1F *cut_theta_elec = new TH1F("cut_theta_elec", "Electron Scatt. Angle", the_nbins, the_xmin, the_xmax);
  TH1F *cut_theta_prot = new TH1F("cut_theta_prot", "Proton Scatt. Angle", thp_nbins, thp_xmin, thp_xmax);
  
  //Additional Kinematics Variables
  TH1F *cut_W_2 = new TH1F("cut_W2", "Invariant Mass W2", W2_nbins, W2_xmin, W2_xmax);
  TH1F *cut_xbj = new TH1F("cut_xbj", "x-Bjorken", xbj_nbins, xbj_xmin, xbj_xmax);
  TH1F *cut_P_f = new TH1F("cut_P_f", "Final Proton Momentum", Pf_nbins, Pf_xmin, Pf_xmax);
  TH1F *cut_k_f = new TH1F("cut_kf", "Final e^{-} Momentum", kf_nbins, kf_xmin, kf_xmax);
  TH1F *cut_q_vec = new TH1F("cut_q", "q-vector, |q|", q_nbins, q_xmin, q_xmax);
  TH1F *cut_theta_q = new TH1F("cut_theta_q", "q-vector Angle, #theta_{q}", thq_nbins, thq_xmin, thq_xmax);
  TH1F *cut_thet_pq = new TH1F("cut_theta_pq", "(Proton, q-vector) Angle, #theta_{pq}", thpq_nbins, thpq_xmin, thpq_xmax);
  TH1F *cut_thet_pq_v2 = new TH1F("cut_theta_pq_v2", "(Proton, q-vector) Angle, #theta_{pq}", thpq_nbins, thpq_xmin, thpq_xmax);
  TH1F *cut_E_n = new TH1F("cut_En", "Neutron Final Energy", En_nbins, En_xmin, En_xmax);
  TH1F *cut_theta_nq = new TH1F("cut_theta_nq", "(q-vector, Neutron) Angle, #theta_{nq}", thnq_nbins, thnq_xmin, thnq_xmax);
  
  TH1F *cut_Mmiss = new TH1F("cut_Mmiss","Missing Mass", Mm_nbins, Mm_xmin, Mm_xmax);      
  TH1F *cut_Mmissv2 = new TH1F("cut_Mmissv2","Missing Mass Version 2", Mm_nbins, Mm_xmin, Mm_xmax);      
  TH1F *cut_Emiss_nuc = new TH1F("cut_Emiss_nuc","Nuclear Missing Energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *cut_Erecoil = new TH1F("cut_Erecoil","Recoil Neutron Energy", En_nbins, En_xmin, En_xmax);
  TH1F *cut_pmx = new TH1F("cut_pmx","Pmx missing momentum", Pmx_nbins, Pmx_xmin, Pmx_xmax);
  TH1F *cut_pmy = new TH1F("cut_pmy","Pmy missing momentum", Pmy_nbins, Pmy_xmin, Pmy_xmax);
  TH1F *cut_pmz = new TH1F("cut_pmz","Pmz missing momentum", Pmz_nbins, Pmz_xmin, Pmz_xmax);
    
  TH1F *cut_KinN = new TH1F("cut_Kn","Neutron Kin. Energy", Kn_nbins, Kn_xmin, Kn_xmax);
  TH1F *cut_KinP = new TH1F("cut_Kp","Proton Kin. Energy", Kp_nbins, Kp_xmin, Kp_xmax);
  TH1F *cut_E_p = new TH1F("cut_Ep","Proton Final Energy", Ep_nbins, Ep_xmin, Ep_xmax);  


  //Target Reconstruction Variables
  TH1F *cut_hx_tar = new TH1F("cut_hx_tar", "HMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *cut_hy_tar = new TH1F("cut_hy_tar", "HMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *cut_hz_tar = new TH1F("cut_hz_tar", "HMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
    
  TH1F *cut_px_tar = new TH1F("cut_px_tar", "SHMS x_Target", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *cut_py_tar = new TH1F("cut_py_tar", "SHMS y_Target", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *cut_pz_tar = new TH1F("cut_pz_tar", "SHMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
    
  TH1F *cut_ztar_diff = new TH1F("cut_ztar_diff", "z_Target Difference (hcana)", ztar_nbins, ztar_xmin, ztar_xmax);

  //Calculated Targ Variables
  TH1F *cut_calc_hz_tar = new TH1F("cut_calc_hz_tar", "HMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
  TH1F *cut_calc_pz_tar = new TH1F("cut_calc_pz_tar", "SHMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);

  TH1F *cut_calc_hz_tar2 = new TH1F("cut_calc_hz_tar2", "HMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);
  TH1F *cut_calc_pz_tar2 = new TH1F("cut_calc_pz_tar2", "SHMS z_Target", ztar_nbins, ztar_xmin, ztar_xmax);

  TH1F *cut_calc_ztar_diff = new TH1F("cut_calc_ztar_diff", "z_Target Difference", ztar_nbins, ztar_xmin, ztar_xmax);
  TH1F *cut_calc_ztar_diff2 = new TH1F("cut_calc_ztar_diff2", "z_Target Difference", ztar_nbins, ztar_xmin, ztar_xmax);

  //Hadron arm Reconstructed Quantities ( xtar, ytar, xptar, yptar, delta)
  TH1F *cut_hytar = new TH1F("cut_hytar", hadron_arm + " Y_{tar}", hytar_nbins, hytar_xmin, hytar_xmax);
  TH1F *cut_hxptar = new TH1F("cut_hxptar", hadron_arm + " X'_{tar}", hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH1F *cut_hyptar = new TH1F("cut_hyptar", hadron_arm + " Y'_{tar}", hyptar_nbins, hyptar_xmin, hyptar_xmax );
  TH1F *cut_hdelta = new TH1F("cut_hdelta", hadron_arm + " Momentum Acceptance, #delta", hdelta_nbins, hdelta_xmin, hdelta_xmax);
  
  //Hadron arm Focal Plane Quantities
  TH1F *cut_hxfp = new TH1F("cut_hxfp", hadron_arm + " X_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax);
  TH1F *cut_hyfp = new TH1F("cut_hyfp", hadron_arm + " Y_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax);
  TH1F *cut_hxpfp = new TH1F("cut_hxpfp", hadron_arm + " X'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax );
  TH1F *cut_hypfp = new TH1F("cut_hypfp", hadron_arm + " Y'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax);
  
  
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
  
  //Cross-Check correlations
  TH2F *cut_emiss_vs_pmiss = new TH2F("cut_emiss_vs_pmiss", " E_{miss} vs. P_{miss}", Pm_nbins, Pm_xmin, Pm_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_edelta_vs_eyptar = new TH2F("cut_edelta_vs_eyptar", electron_arm + " #delta vs. Y'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, edelta_nbins, edelta_xmin, edelta_xmax);
  
  
  //Create 2D Histograms at the Focal Plane Quantities
  TH2F *cut_h_xfp_vs_yfp = new TH2F("cut_h_xfp_vs_yfp", "X_{fp} vs Y_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hxfp_nbins, hxfp_xmin, hxfp_xmax);
  TH2F *cut_e_xfp_vs_yfp = new TH2F("cut_e_xfp_vs_yfp", "X_{fp} vs Y_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, exfp_nbins, exfp_xmin, exfp_xmax);
  
  //2D HMS v. SHMS Acceptance Correlations
  TH2F *cut_hytar_vs_eytar = new TH2F("cut_hytar_vs_eytar", "HMS vs. SHMS, Y_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *cut_hxptar_vs_exptar = new TH2F("cut_hxptar_vs_exptar", "HMS vs. SHMS, X'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *cut_hyptar_vs_eyptar = new TH2F("cut_hyptar_vs_eyptar", "HMS vs. SHMS, Y'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *cut_hdelta_vs_edelta = new TH2F("cut_hdelta_vs_edelta", "HMS vs. SHMS, #delta", edelta_nbins, edelta_xmin, edelta_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  
  //OPTICS CHECK (W correlations with electron arm Focal Plane / Target Quantities)
  TH2F *cut_W_vs_exfp = new TH2F("cut_W_vs_exfp", "cut_W vs eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_expfp = new TH2F("cut_W_vs_expfp", "cut_W vs eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_eyfp = new TH2F("cut_W_vs_eyfp", "cut_W vs eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_eypfp = new TH2F("cut_W_vs_eypfp", "cut_W vs eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *cut_W_vs_eytar = new TH2F("cut_W_vs_eytar", "cut_W vs eY_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_exptar = new TH2F("cut_W_vs_exptar", "cut_W vs eX'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_eyptar = new TH2F("cut_W_vs_eyptar", "cut_W vs eY'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_edelta = new TH2F("cut_W_vs_edelta", "cut_W vs edelta", edelta_nbins, edelta_xmin, edelta_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *cut_Em_vs_exfp = new TH2F("cut_Em_vs_exfp", "cut_Em vs eX_{fp}", exfp_nbins, exfp_xmin, exfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_expfp = new TH2F("cut_Em_vs_expfp", "cut_Em vs eX'_{fp}", expfp_nbins, expfp_xmin, expfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_eyfp = new TH2F("cut_Em_vs_eyfp", "cut_Em vs eY_{fp}", eyfp_nbins, eyfp_xmin, eyfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_eypfp = new TH2F("cut_Em_vs_eypfp", "cut_Em vs eY'_{fp}", eypfp_nbins, eypfp_xmin, eypfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  
  TH2F *cut_Em_vs_eytar = new TH2F("cut_Em_vs_eytar", "cut_Em vs eY_{tar}", eytar_nbins, eytar_xmin, eytar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_exptar = new TH2F("cut_Em_vs_exptar", "cut_Em vs eX'_{tar}", exptar_nbins, exptar_xmin, exptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_eyptar = new TH2F("cut_Em_vs_eyptar", "cut_Em vs eY'_{tar}", eyptar_nbins, eyptar_xmin, eyptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_edelta = new TH2F("cut_Em_vs_edelta", "cut_Em vs edelta", edelta_nbins, edelta_xmin, edelta_xmax, Em_nbins, Em_xmin, Em_xmax);
  
  //OPTICS CHECK (W correlations with hadron arm Focal Plane / Target Quantities)
  TH2F *cut_W_vs_hxfp = new TH2F("cut_W_vs_hxfp", "cut_W vs hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_hxpfp = new TH2F("cut_W_vs_hxpfp", "cut_W vs hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_hyfp = new TH2F("cut_W_vs_hyfp", "cut_W vs hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_hypfp = new TH2F("cut_W_vs_hypfp", "cut_W vs hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *cut_W_vs_hytar = new TH2F("cut_W_vs_hytar", "cut_W vs hY_{tar}", hytar_nbins, hytar_xmin, hytar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_hxptar = new TH2F("cut_W_vs_hxptar", "cut_W vs hX'_{tar}", hxptar_nbins, hxptar_xmin, hxptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_hyptar = new TH2F("cut_W_vs_hyptar", "cut_W vs hY'_{tar}", hyptar_nbins, hyptar_xmin, hyptar_xmax, W_nbins, W_xmin, W_xmax);
  TH2F *cut_W_vs_hdelta = new TH2F("cut_W_vs_hdelta", "cut_W vs hdelta", hdelta_nbins, hdelta_xmin, hdelta_xmax, W_nbins, W_xmin, W_xmax);
  
  TH2F *cut_Em_vs_hxfp = new TH2F("cut_Em_vs_hxfp", "cut_Em vs hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_hxpfp = new TH2F("cut_Em_vs_hxpfp", "cut_Em vs hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_hyfp = new TH2F("cut_Em_vs_hyfp", "cut_Em vs hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_hypfp = new TH2F("cut_Em_vs_hypfp", "cut_Em vs hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, Em_nbins, Em_xmin, Em_xmax);
  
  TH2F *cut_Em_vs_hytar = new TH2F("cut_Em_vs_hytar", "cut_Em vs hY_{tar}", hytar_nbins, hytar_xmin, hytar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_hxptar = new TH2F("cut_Em_vs_hxptar", "cut_Em vs hX'_{tar}", hxptar_nbins, hxptar_xmin, hxptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_hyptar = new TH2F("cut_Em_vs_hyptar", "cut_Em vs hY'_{tar}", hyptar_nbins, hyptar_xmin, hyptar_xmax, Em_nbins, Em_xmin, Em_xmax);
  TH2F *cut_Em_vs_hdelta = new TH2F("cut_Em_vs_hdelta", "cut_Em vs hdelta", hdelta_nbins, hdelta_xmin, hdelta_xmax, Em_nbins, Em_xmin, Em_xmax);
  
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

  //OPTICS CHECK (Hadron  Arm Reconstructed Quantities vs. Focal Plane Quantities) --Each of the reconstructed quantities is a polynomial expansion of focal plane quantities
  TH2F *cut_hytar_vs_hxfp = new TH2F("cut_hytar_vs_hxfp", "HMS hY_{tar} vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *cut_hytar_vs_hxpfp = new TH2F("cut_hytar_vs_hxpfp", "HMS hY_{tar} vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *cut_hytar_vs_hyfp = new TH2F("cut_hytar_vs_hyfp", "HMS hY_{tar} vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);
  TH2F *cut_hytar_vs_hypfp = new TH2F("cut_hytar_vs_hypfp", "HMS hY_{tar} vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hytar_nbins, hytar_xmin, hytar_xmax);

  TH2F *cut_hyptar_vs_hxfp = new TH2F("cut_hyptar_vs_hxfp", "HMS hY'_{tar} vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *cut_hyptar_vs_hxpfp = new TH2F("cut_hyptar_vs_hxpfp", "HMS hY'_{tar} vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *cut_hyptar_vs_hyfp = new TH2F("cut_hyptar_vs_hyfp", "HMS hY'_{tar} vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);
  TH2F *cut_hyptar_vs_hypfp = new TH2F("cut_hyptar_vs_hypfp", "HMS hY'_{tar} vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hyptar_nbins, hyptar_xmin, hyptar_xmax);

  TH2F *cut_hxptar_vs_hxfp = new TH2F("cut_hxptar_vs_hxfp", "HMS hX'_{tar} vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *cut_hxptar_vs_hxpfp = new TH2F("cut_hxptar_vs_hxpfp", "HMS hX'_{tar} vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *cut_hxptar_vs_hyfp = new TH2F("cut_hxptar_vs_hyfp", "HMS hX'_{tar} vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);
  TH2F *cut_hxptar_vs_hypfp = new TH2F("cut_hxptar_vs_hypfp", "HMS hX'_{tar} vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hxptar_nbins, hxptar_xmin, hxptar_xmax);

  TH2F *cut_hdelta_vs_hxfp = new TH2F("cut_hdelta_vs_hxfp", "HMS Delta h#delta vs. hX_{fp}", hxfp_nbins, hxfp_xmin, hxfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  TH2F *cut_hdelta_vs_hxpfp = new TH2F("cut_hdelta_vs_hxpfp", "HMS Delta h#delta vs. hX'_{fp}", hxpfp_nbins, hxpfp_xmin, hxpfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  TH2F *cut_hdelta_vs_hyfp = new TH2F("cut_hdelta_vs_hyfp", "HMS Delta h#delta vs. hY_{fp}", hyfp_nbins, hyfp_xmin, hyfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);
  TH2F *cut_hdelta_vs_hypfp = new TH2F("cut_hdelta_vs_hypfp", "HMS Delta h#delta vs. hY'_{fp}", hypfp_nbins, hypfp_xmin, hypfp_xmax, hdelta_nbins, hdelta_xmin, hdelta_xmax);



  //Set Variable Names and Branches
 
  //------Kinematics
  Double_t  epCoinTime;
  Double_t  theta_e;
  Double_t  W;
  Double_t  Q2;
  Double_t  X;
  Double_t  nu;
  Double_t  q3m;   //q-vect magnitude
  Double_t  th_q;
  Double_t  kf;
  Double_t  Pf;
  Double_t  Ep;
  Double_t  Kp;
  Double_t  Kn;
  Double_t  Em;
  Double_t  Em_nuc;
  Double_t  M_recoil;  //invariant mass of recoiling system (should be equivalent to missing mass of neutron)
  Double_t  E_recoil;   //recoil system energy (should be equivalent to neutron energy)
  Double_t  Pm;
  Double_t  Pmx;
  Double_t  Pmy;
  Double_t  Pmz;
  Double_t  thbq;
  Double_t  thxq;
  Double_t  phbq;
  Double_t  phxq;
  Double_t  xangle;

  
  //Additional Kinematics to be defined within loop
  Double_t  MM;  //Missing Mass of neutron
  Double_t  theta_p;  //to be determined in loop
  Double_t  theta_pq_v2; //to be determined in loop
  Double_t  W2;
  Double_t  En;

  T->SetBranchAddress("CTime.epCoinTime_ROC2", &epCoinTime);

  T->SetBranchAddress("P.kin.primary.scat_ang_rad",&theta_e);
  T->SetBranchAddress("P.kin.primary.W",&W);
  T->SetBranchAddress("P.kin.primary.Q2",&Q2);
  T->SetBranchAddress("P.kin.primary.x_bj",&X);
  T->SetBranchAddress("P.kin.primary.nu",&nu);
  T->SetBranchAddress("P.kin.primary.q3m",&q3m);
  T->SetBranchAddress("P.kin.primary.th_q",&th_q);
  T->SetBranchAddress("P.gtr.p",&kf);
  T->SetBranchAddress("H.gtr.p",&Pf);
  T->SetBranchAddress("H.kin.secondary.xangle",&xangle);  //Angle of detected particle with scattered electron (Used to determine hadron angle)
  


  //Recoil System Variables (Missing Neutron)
  T->SetBranchAddress("H.kin.secondary.pmiss",&Pm);
  T->SetBranchAddress("H.kin.secondary.Prec_x",&Pmx);   //x-component of recoil momentum
  T->SetBranchAddress("H.kin.secondary.Prec_y",&Pmy);   //y
  T->SetBranchAddress("H.kin.secondary.Prec_z",&Pmz);   //z

  T->SetBranchAddress("H.kin.secondary.tx",&Kp);   //kinetic energy of detected particle (proton)
  T->SetBranchAddress("H.kin.secondary.tb",&Kn);   //kinetic energy of recoil system (neutron)

  T->SetBranchAddress("H.kin.secondary.emiss",&Em);
  T->SetBranchAddress("H.kin.secondary.emiss_nuc",&Em_nuc);  //Nuclear definition of Missing Energy
  T->SetBranchAddress("H.kin.secondary.Mrecoil",&M_recoil);  //Missing Mass
  T->SetBranchAddress("H.kin.secondary.Erecoil",&E_recoil);  //Recoil Energy of System (Should be neutron Energy)


  T->SetBranchAddress("H.kin.secondary.th_xq",&thxq);     //Polar angle of detected particle with q    ----> theta_pq angle between proton and q-vector
  T->SetBranchAddress("H.kin.secondary.ph_xq",&phxq);     //Azimuth angle of detected particle with q    ----> phi_pq angle between proton and q-vector
  T->SetBranchAddress("H.kin.secondary.th_bq",&thbq);      //Polar angle of recoil system with q (rad) ----> theta_nq angle between neutron and q-vector
  T->SetBranchAddress("H.kin.secondary.ph_bq",&thbq);      //Azimuth of recoil system with scattering plane (rad) ----> phi_nq angle between neutron and q-vector


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
  
  //-------HMS Focal Plane / Target
  Double_t  h_xfp;
  Double_t  h_xpfp;
  Double_t  h_yfp;
  Double_t  h_ypfp;
  
  Double_t  h_ytar;
  Double_t  h_yptar;
  Double_t  h_xptar;
  Double_t  h_delta;
  
  T->SetBranchAddress("H.dc.x_fp",&h_xfp);
  T->SetBranchAddress("H.dc.xp_fp",&h_xpfp);
  T->SetBranchAddress("H.dc.y_fp",&h_yfp);
  T->SetBranchAddress("H.dc.yp_fp",&h_ypfp);
  
  T->SetBranchAddress("H.gtr.y",&h_ytar);
  T->SetBranchAddress("H.gtr.ph",&h_yptar);
  T->SetBranchAddress("H.gtr.th",&h_xptar);
  T->SetBranchAddress("H.gtr.dp",&h_delta);
  
  //--------Target Quantities (tarx, tary, tarz)
  Double_t  htar_x;
  Double_t  htar_y;
  Double_t  htar_z;
  
  Double_t  ptar_x;
  Double_t  ptar_y;
  Double_t  ptar_z;
  
  T->SetBranchAddress("H.react.x",&htar_x);
  T->SetBranchAddress("H.react.y",&htar_y);
  T->SetBranchAddress("H.react.z",&htar_z);
  
  T->SetBranchAddress("P.react.x",&ptar_x);
  T->SetBranchAddress("P.react.y",&ptar_y);
  T->SetBranchAddress("P.react.z",&ptar_z);
 

  //--------Calculated Alternative Ztar-------------------
  Double_t hcostheta;
  Double_t hsintheta;
  Double_t hztarg;
  Double_t hztarg2;

  Double_t pcostheta;
  Double_t psintheta;
  Double_t pztarg;
  Double_t pztarg2;


  //------SHMS Detector Quantities
  Double_t  pcal_etracknorm;
  Double_t  pngcer_npesum;

  T->SetBranchAddress("P.cal.etracknorm",&pcal_etracknorm);
  T->SetBranchAddress("P.ngcer.npeSum",&pngcer_npesum);
 
 
  //Define Boolean for Kin. Cuts
  Bool_t c_Em;
  Bool_t c_ctime;  //coincidence time cut
  Bool_t c_hdelta;
  Bool_t c_edelta;

  //======================
  // E V E N T   L O O P 
  //======================
  
  
  Long64_t nentries = T->GetEntries();
  
  cout << "nentries = " << nentries << endl;
  
  
  
  for (Long64_t i=0; i<nentries;i++) {
    
    T->GetEntry(i);
    

    //calculate Ztarget varibales from hcana formula (This formula already takes the negative HMS angle sign into account, so ONLY use "+" angles)
    hztarg=-(h_ytar+xBPM_tar*(cos(htheta_cent)-h_yptar*sin(htheta_cent)))/(-sin(htheta_cent)-h_yptar*cos(htheta_cent));
    pztarg=-(e_ytar+xBPM_tar*(cos(ptheta_cent)+e_yptar*sin(ptheta_cent)))/(sin(ptheta_cent)-e_yptar*cos(ptheta_cent));
 
    hztarg2=-(h_ytar+xBPM_tar*cos(htheta_cent))/(-sin(htheta_cent)-h_yptar*cos(htheta_cent));
    pztarg2=-(e_ytar+xBPM_tar*cos(ptheta_cent))/(sin(ptheta_cent)-e_yptar*cos(ptheta_cent));


    //Determine theta_p
    theta_p = xangle - theta_e;
    W2 = W*W;
    theta_pq_v2 = th_q - theta_p;
    Ep = sqrt(MP*MP + Pf*Pf);
    En = sqrt(MN*MN + Pm*Pm);
    MM = sqrt(TMath::Power(nu+MD-Ep,2) - Pm*Pm);

    c_Em = Em_nuc>-0.02 && Em_nuc<0.04;
    //c_Em = Em_nuc<-0.02 || Em_nuc>0.04;
    c_ctime = epCoinTime>8.6 && epCoinTime<13.6;
    c_hdelta = h_delta>-8. && h_delta<8.;
    
    //APPLY CUTS: BEGIN CUTS LOOP
    if (c_Em&&c_ctime&&c_hdelta)
    {

      //cout << "NUM = " <<eytar_off+0.148769*(pcostheta+shmsyptar*psintheta)<<endl;
      //cout << "DEN = " <<psintheta-shmsyptar*pcostheta <<endl;
      //cout << "pztarg = " << pztarg << endl;
      cut_epCT->Fill(epCoinTime);

	  //Kinematics
	  cut_Emiss->Fill(Em);
	  cut_pm->Fill(Pm);
	  cut_Q_2->Fill(Q2);
	  cut_omega->Fill(nu);
	  cut_W_inv->Fill(W);
	  cut_theta_elec->Fill(theta_e/dtr);
	  cut_theta_prot->Fill(theta_p/dtr);

	  
	  //Additional Kinematics Variables
	  cut_W_2->Fill(W2); 
	  cut_xbj->Fill(X); 
	  cut_P_f->Fill(Pf);
	  cut_k_f->Fill(kf);
	  cut_theta_q->Fill(th_q/dtr);
	  cut_q_vec->Fill(q3m);
	  cut_thet_pq->Fill(thxq/dtr);
	  cut_thet_pq_v2->Fill(theta_pq_v2/dtr);
	  cut_theta_nq->Fill(thbq/dtr);
	  cut_E_n->Fill(En);

	  cut_Mmiss->Fill(M_recoil);
	  cut_Mmissv2->Fill(MM); 
	  cut_Emiss_nuc->Fill(Em_nuc);
	  cut_Erecoil->Fill(E_recoil);
	  cut_pmx->Fill(Pmx);
	  cut_pmy->Fill(Pmy);
	  cut_pmz->Fill(Pmz);
	  cut_KinN->Fill(Kn);
	  cut_KinP->Fill(Kp);
	  cut_E_p->Fill(Ep);

	  //Reconstructed Target Quantities (Lab Frame)
	  cut_hx_tar->Fill(htar_x);
	  cut_hy_tar->Fill(htar_y);
	  cut_hz_tar->Fill(htar_z);
	  
	  cut_px_tar->Fill(ptar_x);
	  cut_py_tar->Fill(ptar_y);
	  cut_pz_tar->Fill(ptar_z);

	  cut_calc_hz_tar->Fill(hztarg);
	  cut_calc_pz_tar->Fill(pztarg);
	  
	  cut_calc_hz_tar2->Fill(hztarg2);
	  cut_calc_pz_tar2->Fill(pztarg2);
	  
	  cut_ztar_diff->Fill(ptar_z - htar_z);
	  cut_calc_ztar_diff->Fill(pztarg - hztarg);
	  cut_calc_ztar_diff2->Fill(pztarg2 - hztarg2);


	  //Hadron-Arm Target Reconstruction 
	  cut_hytar->Fill(h_ytar);
	  cut_hxptar->Fill(h_xptar);
	  cut_hyptar->Fill(h_yptar);
	  cut_hdelta->Fill(h_delta);
	  
	  //Hadron-Arm Focal Plane
	  cut_hxfp->Fill(h_xfp);
	  cut_hyfp->Fill(h_yfp);
	  cut_hxpfp->Fill(h_xpfp);
	  cut_hypfp->Fill(h_ypfp);
	  
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
	  cut_h_xfp_vs_yfp->Fill(h_yfp, h_xfp);
	  cut_e_xfp_vs_yfp->Fill(e_yfp, e_xfp);
	  
	  //Fill 2D reconstructed variables
	  cut_hxptar_vs_exptar->Fill(e_xptar, h_xptar);
	  cut_hyptar_vs_eyptar->Fill(e_yptar, h_yptar);
	  cut_hdelta_vs_edelta->Fill(e_delta, h_delta);

	  
	  //Heep cross check
	  cut_emiss_vs_pmiss->Fill(Pm, Em);
	  cut_edelta_vs_eyptar->Fill(e_yptar, e_delta);
	  
	  //OPTICS CHECK (W / Emiss vs. electron Arm Quantities)
	  cut_W_vs_exfp->Fill(e_xfp, W);
	  cut_W_vs_expfp->Fill(e_xpfp, W);
	  cut_W_vs_eyfp->Fill(e_yfp, W);
	  cut_W_vs_eypfp->Fill(e_ypfp, W);
	  
	  cut_W_vs_eytar->Fill(e_ytar, W);
	  cut_W_vs_exptar->Fill(e_xptar, W);
	  cut_W_vs_eyptar->Fill(e_yptar, W);
	  cut_W_vs_edelta->Fill(e_delta, W);

	  cut_Em_vs_exfp->Fill(e_xfp, Em);
	  cut_Em_vs_expfp->Fill(e_xpfp, Em);
	  cut_Em_vs_eyfp->Fill(e_yfp, Em);
	  cut_Em_vs_eypfp->Fill(e_ypfp, Em);
	  
	  cut_Em_vs_eytar->Fill(e_ytar, Em);
	  cut_Em_vs_exptar->Fill(e_xptar, Em);
	  cut_Em_vs_eyptar->Fill(e_yptar, Em);
	  cut_Em_vs_edelta->Fill(e_delta, Em);
	  
	  //OPTICS CHECK (W / Emiss vs. hadron Arm Quantities)
	  cut_W_vs_hxfp->Fill(h_xfp, W);
	  cut_W_vs_hxpfp->Fill(h_xpfp, W);
	  cut_W_vs_hyfp->Fill(h_yfp, W);
	  cut_W_vs_hypfp->Fill(h_ypfp, W);
	  
	  cut_W_vs_hytar->Fill(h_ytar, W);
	  cut_W_vs_hxptar->Fill(h_xptar, W);
	  cut_W_vs_hyptar->Fill(h_yptar, W);
	  cut_W_vs_hdelta->Fill(h_delta, W);

	  cut_Em_vs_hxfp->Fill(h_xfp, Em);
	  cut_Em_vs_hxpfp->Fill(h_xpfp, Em);
	  cut_Em_vs_hyfp->Fill(h_yfp, Em);
	  cut_Em_vs_hypfp->Fill(h_ypfp, Em);
	  
	  cut_Em_vs_hytar->Fill(h_ytar, Em);
	  cut_Em_vs_hxptar->Fill(h_xptar, Em);
	  cut_Em_vs_hyptar->Fill(h_yptar, Em);
	  cut_Em_vs_hdelta->Fill(h_delta, Em);
	  

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

	  //OPTICS CHECK (hadron Arm Recon. vs. Focal Plane)
	  cut_hytar_vs_hxfp->Fill(h_xfp, h_ytar);
	  cut_hytar_vs_hxpfp->Fill(h_xpfp, h_ytar);
	  cut_hytar_vs_hyfp->Fill(h_yfp, h_ytar);
	  cut_hytar_vs_hypfp->Fill(h_ypfp, h_ytar);
  
	  cut_hyptar_vs_hxfp->Fill(h_xfp, h_yptar);
	  cut_hyptar_vs_hxpfp->Fill(h_xpfp, h_yptar);
	  cut_hyptar_vs_hyfp->Fill(h_yfp, h_yptar);
	  cut_hyptar_vs_hypfp->Fill(h_ypfp, h_yptar);

	  cut_hxptar_vs_hxfp->Fill(h_xfp, h_xptar);
	  cut_hxptar_vs_hxpfp->Fill(h_xpfp, h_xptar);
	  cut_hxptar_vs_hyfp->Fill(h_yfp, h_xptar);
	  cut_hxptar_vs_hypfp->Fill(h_ypfp, h_xptar);

	  cut_hdelta_vs_hxfp->Fill(h_xfp, h_delta);
	  cut_hdelta_vs_hxpfp->Fill(h_xpfp, h_delta);
	  cut_hdelta_vs_hyfp->Fill(h_yfp, h_delta);
	  cut_hdelta_vs_hypfp->Fill(h_ypfp, h_delta);

	}//End CUTS LOOP
      
      
      epCT->Fill(epCoinTime);

      //Kinematics
      Emiss->Fill(Em);
      pm->Fill(Pm);
      Q_2->Fill(Q2);
      omega->Fill(nu);
      W_inv->Fill(W);
      theta_elec->Fill(theta_e/dtr);
      theta_prot->Fill(theta_p/dtr);


      //Additional Kinematics Variables
      W_2->Fill(W2); 
      xbj->Fill(X); 
      P_f->Fill(Pf);
      k_f->Fill(kf);
      theta_q->Fill(th_q/dtr);
      q_vec->Fill(q3m);
      thet_pq->Fill(thxq/dtr);
      thet_pq_v2->Fill(theta_pq_v2/dtr);
      theta_nq->Fill(thbq/dtr);
      E_n->Fill(En);

      Mmiss->Fill(M_recoil);                                                                                 
      Mmissv2->Fill(MM);                                                                                     
      Emiss_nuc->Fill(Em_nuc);                                                                               
      Erecoil->Fill(E_recoil);                                                                               
      pmx->Fill(Pmx);                                                                                        
      pmy->Fill(Pmy);                                                                                        
      pmz->Fill(Pmz);                                      
      KinN->Fill(Kn);                                                                                        
      KinP->Fill(Kp); 
      E_p->Fill(Ep);

      //Reconstructed Target Quantities (Lab Frame)
      hx_tar->Fill(htar_x);
      hy_tar->Fill(htar_y);
      hz_tar->Fill(htar_z);
      
      px_tar->Fill(ptar_x);
      py_tar->Fill(ptar_y);
      pz_tar->Fill(ptar_z);
      	 
      calc_hz_tar->Fill(hztarg);
      calc_pz_tar->Fill(pztarg);
      
      calc_hz_tar2->Fill(hztarg2);
      calc_pz_tar2->Fill(pztarg2);  
      
      ztar_diff->Fill(ptar_z - htar_z);
      calc_ztar_diff->Fill(pztarg - hztarg);
      calc_ztar_diff2->Fill(pztarg2 - hztarg2);

      //Hadron-Arm Target Reconstruction 
      hytar->Fill(h_ytar);
      hxptar->Fill(h_xptar);
      hyptar->Fill(h_yptar);
      hdelta->Fill(h_delta);
      
      //Hadron-Arm Focal Plane
      hxfp->Fill(h_xfp);
      hyfp->Fill(h_yfp);
      hxpfp->Fill(h_xpfp);
      hypfp->Fill(h_ypfp);
      
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

      
      //Fill 2D HMS Focal Plane Quantities
      h_xfp_vs_yfp->Fill(h_yfp, h_xfp);
      e_xfp_vs_yfp->Fill(e_yfp, e_xfp);

      //Fill 2D reconstructed variables
      hxptar_vs_exptar->Fill(e_xptar, h_xptar);
      hyptar_vs_eyptar->Fill(e_yptar, h_yptar);
      hdelta_vs_edelta->Fill(e_delta, h_delta);

      //Heep cross check
      emiss_vs_pmiss->Fill(Pm, Em);
      edelta_vs_eyptar->Fill(e_yptar, e_delta);
     	 
      //OPTICS CHECK (W / Em vs. electron arm)
      W_vs_exfp->Fill(e_xfp, W);
      W_vs_expfp->Fill(e_xpfp, W);
      W_vs_eyfp->Fill(e_yfp, W);
      W_vs_eypfp->Fill(e_ypfp, W);
      
      W_vs_eytar->Fill(e_ytar, W);
      W_vs_exptar->Fill(e_xptar, W);
      W_vs_eyptar->Fill(e_yptar, W);
      W_vs_edelta->Fill(e_delta, W);

      Em_vs_exfp->Fill(e_xfp, Em);
      Em_vs_expfp->Fill(e_xpfp, Em);
      Em_vs_eyfp->Fill(e_yfp, Em);
      Em_vs_eypfp->Fill(e_ypfp, Em);
      
      Em_vs_eytar->Fill(e_ytar, Em);
      Em_vs_exptar->Fill(e_xptar, Em);
      Em_vs_eyptar->Fill(e_yptar, Em);
      Em_vs_edelta->Fill(e_delta, Em);
      
      //OPTICS CHECK (W / Em vs. hadron arm)
      W_vs_hxfp->Fill(h_xfp, W);
      W_vs_hxpfp->Fill(h_xpfp, W);
      W_vs_hyfp->Fill(h_yfp, W);
      W_vs_hypfp->Fill(h_ypfp, W);
      
      W_vs_hytar->Fill(h_ytar, W);
      W_vs_hxptar->Fill(h_xptar, W);
      W_vs_hyptar->Fill(h_yptar, W);
      W_vs_hdelta->Fill(h_delta, W);

      Em_vs_hxfp->Fill(h_xfp, Em);
      Em_vs_hxpfp->Fill(h_xpfp, Em);
      Em_vs_hyfp->Fill(h_yfp, Em);
      Em_vs_hypfp->Fill(h_ypfp, Em);
      
      Em_vs_hytar->Fill(h_ytar, Em);
      Em_vs_hxptar->Fill(h_xptar, Em);
      Em_vs_hyptar->Fill(h_yptar, Em);
      Em_vs_hdelta->Fill(h_delta, Em);
      
    
  } //end entry loop
  
   
  outROOT->Write();
  
}
