#include "../simc_analysis/set_deep_histos.h"

void analyze_deepData(int set, int Pmiss, bool Qnorm=true)
{

  //the set="", represents different data sets, with ideally same kinematics, but spectrometer has been moved back and forth
  //so the reproducibility needs to be checked.  For 80 MeV, use set=0
  //QNorm--> Normalize data by charge/live time/tracking efficiencies. Set to true by default

//PREVENT DISPLAY 
  //gROOT->SetBatch(kTRUE);
    
  Double_t charge_factor = 1.; 
  Double_t e_trkEff = 1.;
  Double_t h_trkEff = 1.; 
  Double_t c_LT = 1.;
  Double_t t_LT = 1.;

  if (Qnorm){                                                                                                                      

    if(set==0&&Pmiss==80){                                                                                                           
                                                                                                                                              
      charge_factor = 142.553;   //BCM4A                                                                                                                                                                                   
      c_LT = 0.97881;          //computer live time                                                                              
      t_LT = 0.909529;          //total live time                                                                                                                                                                                                       
      e_trkEff = 0.966524;       //shms e- trk eff                                                          
      h_trkEff = 0.989003;        //hms had trk eff
    }

    //Combined 580 data sets 
    if(set==-1&&Pmiss==580){                                                                                                                                                                                                                                       
      charge_factor = 3759.779;   //BCM4A (mC)                                                                                                   
      c_LT = 0.998465;          //computer live time                                                                  
      t_LT = 0.930204;          //total live time                                                                                 
      
      e_trkEff = 0.96600;       //shms e- trk eff                                                                       
      h_trkEff = 0.974655;        //hms had trk eff                                                         
      
    } 

    if(set==1&&Pmiss==580){                                                                                                                                                                                                                                       
      charge_factor =1827.029;   //BCM4A (mC)                                                                                                   
      c_LT = 0.998534;          //computer live time                                                                  
      t_LT = 0.930728;          //total live time                                                                                 
      
      e_trkEff = 0.966850;       //shms e- trk eff                                                                       
      h_trkEff = 0.962029;        //hms had trk eff                                                         
      
    } 


    if(set==2&&Pmiss==580){                                        
                                                                                                                                  
      charge_factor = 1932.75;   //BCM4A (mC)                                                                               
                                                                                                                        
      c_LT = 0.998398;          //computer live time                                                               
      t_LT = 0.929696;          //total live time                                                                               
                                                                                                           
      e_trkEff = 0.965208;       //shms e- trk eff                                                    
      h_trkEff = 0.987885;        //hms had trk eff                                                                             
                                                                                                                                  
    }  

    //Combined 750 MeV sets
    if(set==-1&&Pmiss==750){                                                                                                          
                                                                                                                                    
      charge_factor = 8315.383;   //BCM4A (mC)                                                                               
                                                                                                                                        
      c_LT = 0.998544;          //computer live time                                                                              
      t_LT = 0.925702;          //total live time                                                                                    
                                                                                                                                          
      e_trkEff = 0.962190;       //shms e- trk eff                                                                                            
      h_trkEff = 0.989080;        //hms had trk eff                                                
                                                                                                       
    }    

    if(set==1&&Pmiss==750){                                                                                                          
                                                                                                                                    
      charge_factor = 5335.617;   //BCM4A (mC)                                                                               
                                                                                                                                        
      c_LT = 0.998538;          //computer live time                                                                              
      t_LT = 0.926217;          //total live time                                                                                    
                                                                                                                                          
      e_trkEff = 0.962456;       //shms e- trk eff                                                                                            
      h_trkEff = 0.988749;        //hms had trk eff                                                
                                                                                                       
    }                               

    if(set==2&&Pmiss==750){                                                                                              
                                                                                                            
      charge_factor = 1894.894;   //BCM4A (mC)                                                                                    
                                                                                                                           
      c_LT = 0.998538;          //computer live time                                                               
      t_LT = 0.924257;          //total live time                                                                            
                                                                                                                                  
      e_trkEff = 0.960770;       //shms e- trk eff                                                                                 
      h_trkEff = 0.989432;        //hms had trk eff                                                                           
                                                                                       
    }    

    if(set==3&&Pmiss==750){                                                                                            
                                                                                                                               
      charge_factor = 1084.872;   //BCM4A (mC)                                                                                
                                                                                                                                    
      c_LT = 0.998583;          //computer live time                                                                                
      t_LT = 0.925570;          //total live time                                                                                          
                                                                                                                              
      e_trkEff = 0.963303;       //shms e- trk eff                                                                          
      h_trkEff = 0.990051;        //hms had trk eff                                                             
                                                                                                 
    } 

    cout << "Qnorm? = " << Qnorm << endl;

}
  //Read DATA ROOTfiles
  TString filename; 
  
  if(set==0&&Pmiss==80){ filename = "../../hallc_replay/ROOTfiles/coin_replay_deep_check_3289_-1.root"; }

  if(set==-1&&Pmiss==580){ filename = "../../hallc_replay/ROOTfiles/pm580_total.root"; }
  if(set==1&&Pmiss==580){ filename = "../../hallc_replay/ROOTfiles/pm580_set1.root"; }
  if(set==2&&Pmiss==580){ filename = "../../hallc_replay/ROOTfiles/pm580_set2.root"; }

  if(set==-1&&Pmiss==750){ filename = "../../hallc_replay/ROOTfiles/pm750_total.root"; }
  if(set==1&&Pmiss==750){ filename = "../../hallc_replay/ROOTfiles/pm750_set1.root"; }
  if(set==2&&Pmiss==750){ filename = "../../hallc_replay/ROOTfiles/pm750_set2.root"; }
  if(set==3&&Pmiss==750){ filename = "../../hallc_replay/ROOTfiles/pm750_set3.root"; }



  TFile *data_file = new TFile(filename, "READ"); 
  TTree *T = (TTree*)data_file->Get("T");
 
  TFile *outROOT;
  if(set==-1){
    outROOT = new TFile(Form("D2data_pm%d_total.root", Pmiss), "recreate");
  }
  else{
  //Create output root file where histograms will be stored
    outROOT = new TFile(Form("D2data_pm%d_set%d.root", Pmiss, set), "recreate");
  }

  //********* Create 1D Histograms **************
  
  TH1F *epCT = new TH1F("epCT","e-Proton Coincidence Time", 100, 0, 20);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *ecal_etotnorm = new TH1F("ecal_etotnorm","SHMS Calorimeter Total Norm. Energy", 100, 0.1, 2.);

  //Kinematics Quantities

  TH1F *Emiss = new TH1F("Emiss","missing energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *pm = new TH1F("pm","missing momentum", Pm_nbins, Pm_xmin, Pm_xmax);  //min width = 32 MeV (0.032)

  TH1F *pmX_lab = new TH1F("pmX_Lab","Pmiss X (Lab) ", Pmx_nbins, Pmx_xmin, Pmx_xmax); 
  TH1F *pmY_lab = new TH1F("pmY_Lab","Pmiss Y (Lab) ", Pmy_nbins, Pmy_xmin, Pmy_xmax);  
  TH1F *pmZ_lab = new TH1F("pmZ_Lab","Pmiss Z (Lab) ", Pmz_nbins, Pmz_xmin, Pmz_xmax);  
  TH1F *pmX_q = new TH1F("pmX_q","Pmiss X (w.r.t q-vec) ", Pmx_nbins, Pmx_xmin, Pmx_xmax); 
  TH1F *pmY_q = new TH1F("pmY_q","Pmiss Y (w.r.t q-vec) ", Pmy_nbins, Pmy_xmin, Pmy_xmax);  
  TH1F *pmZ_q = new TH1F("pmZ_q","Pmiss Z (w.r.t. q-vec) ", Pmz_nbins, Pmz_xmin, Pmz_xmax);  
  

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
  TH1F *Emiss_nuc = new TH1F("Emiss_nuc","Nuclear Missing Energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *Erecoil = new TH1F("Erecoil","Recoil Neutron Energy", En_nbins, En_xmin, En_xmax);
  TH1F *pmx = new TH1F("pmx","Pmx missing momentum", Pmx_nbins, Pmx_xmin, Pmx_xmax);
  TH1F *pmy = new TH1F("pmy","Pmy missing momentum", Pmy_nbins, Pmy_xmin, Pmy_xmax);
  TH1F *pmz = new TH1F("pmz","Pmz missing momentum", Pmz_nbins, Pmz_xmin, Pmz_xmax);
  TH1F *KinN = new TH1F("Kn","Neutron Kin. Energy", Kn_nbins, Kn_xmin, Kn_xmax);
  TH1F *KinP = new TH1F("Kp","Proton Kin. Energy", Kp_nbins, Kp_xmin, Kp_xmax);
  TH1F *E_p = new TH1F("Ep","Proton Final Energy", Ep_nbins, Ep_xmin, Ep_xmax);  



  //Target Reconstruction Variables
  TH1F *hx_tar = new TH1F("hx_tar", "HMS x-Target (Lab)", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *hy_tar = new TH1F("hy_tar", "HMS y_Target (Lab)", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *hz_tar = new TH1F("hz_tar", "HMS z_Target (Lab)", ztar_nbins, ztar_xmin, ztar_xmax);
  
  //Target Reconstruction Variables
  TH1F *px_tar = new TH1F("px_tar", "SHMS x-Target (Lab)", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *py_tar = new TH1F("py_tar", "SHMS y-Target (Lab)", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *pz_tar = new TH1F("pz_tar", "SHMS z-Target (Lab)", ztar_nbins, ztar_xmin, ztar_xmax);


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

  TH2F *Q2_vs_thnq = new TH2F("Q2_vs_thnq", "Q2 vs. #theta_{nq}", thnq_nbins, thnq_xmin, thnq_xmax, Q2_nbins, Q2_xmin, Q2_xmax);                
  TH2F *Q2_vs_Pm = new TH2F("Q2_vs_Pm", "Q2 vs. Pm", Pm_nbins, Pm_xmin, Pm_xmax, Q2_nbins, Q2_xmin, Q2_xmax);                     

  /************Define Histos to APPLY CUTS*********************************/
 
  TH1F *cut_epCT = new TH1F("cut_epCT","e-Proton Coincidence Time", 100, 0, 20);
  TH1F *cut_ecal_etotnorm = new TH1F("cut_ecal_etotnorm","SHMS Calorimeter Total Norm. Energy", 100, 0.1, 2.); 
  
  //Kinematics Quantities
  TH1F *cut_Emiss = new TH1F("cut_Emiss","missing energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  CUT_OUNTS/25 MeV
  TH1F *cut_pm = new TH1F("cut_pm","missing momentum", Pm_nbins, Pm_xmin, Pm_xmax);  //min width = 32 MeV (0.032)

  cut_Emiss->Sumw2();
  cut_pm->Sumw2();

  TH1F *cut_pmX_lab = new TH1F("cut_pmX_Lab","Pmiss X (Lab) ", Pmx_nbins, Pmx_xmin, Pmx_xmax); 
  TH1F *cut_pmY_lab = new TH1F("cut_pmY_Lab","Pmiss Y (Lab) ", Pmy_nbins, Pmy_xmin, Pmy_xmax);  
  TH1F *cut_pmZ_lab = new TH1F("cut_pmZ_Lab","Pmiss Z (Lab) ", Pmz_nbins, Pmz_xmin, Pmz_xmax);  
  TH1F *cut_pmX_q = new TH1F("cut_pmX_q","Pmiss X (w.r.t q-vec) ", Pmx_nbins, Pmx_xmin, Pmx_xmax); 
  TH1F *cut_pmY_q = new TH1F("cut_pmY_q","Pmiss Y (w.r.t q-vec) ", Pmy_nbins, Pmy_xmin, Pmy_xmax);  
  TH1F *cut_pmZ_q = new TH1F("cut_pmZ_q","Pmiss Z (w.r.t. q-vec) ", Pmz_nbins, Pmz_xmin, Pmz_xmax);  

  TH1F *cut_Q_2 = new TH1F("cut_Q_2","Q2", Q2_nbins, Q2_xmin, Q2_xmax);
  TH1F *cut_omega = new TH1F("cut_omega","Energy Transfer, #omega", om_nbins, om_xmin, om_xmax);
  TH1F *cut_W_inv = new TH1F("cut_W_inv", "Invariant Mass, W", W_nbins, W_xmin, W_xmax);     //min width = 19.9 MeV (0.0199) (bin width = 25 MeV)
  TH1F *cut_theta_elec = new TH1F("cut_theta_elec", "Electron Scatt. Angle", the_nbins, the_xmin, the_xmax);
  TH1F *cut_theta_prot = new TH1F("cut_theta_prot", "Proton Scatt. Angle", thp_nbins, thp_xmin, thp_xmax);
  
  cut_Q_2->Sumw2();
  cut_omega->Sumw2();

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
  TH1F *cut_Emiss_nuc = new TH1F("cut_Emiss_nuc","Nuclear Missing Energy", Em_nbins, Em_xmin, Em_xmax);       //min width = 21.6 (0.0216)MeV,  COUNTS/25 MeV
  TH1F *cut_Erecoil = new TH1F("cut_Erecoil","Recoil Neutron Energy", En_nbins, En_xmin, En_xmax);

  TH1F *cut_KinN = new TH1F("cut_Kn","Neutron Kin. Energy", Kn_nbins, Kn_xmin, Kn_xmax);
  TH1F *cut_KinP = new TH1F("cut_Kp","Proton Kin. Energy", Kp_nbins, Kp_xmin, Kp_xmax);
  TH1F *cut_E_p = new TH1F("cut_Ep","Proton Final Energy", Ep_nbins, Ep_xmin, Ep_xmax);  

  cut_Emiss_nuc->Sumw2();
  cut_Mmiss->Sumw2();
  cut_Erecoil->Sumw2();
  cut_theta_nq->Sumw2();
  cut_xbj->Sumw2();
  cut_P_f->Sumw2();
  cut_k_f->Sumw2();
  cut_q_vec->Sumw2();
  cut_theta_q->Sumw2();
  cut_thet_pq->Sumw2();
  
  //Target Reconstruction Variables
  TH1F *cut_hx_tar = new TH1F("cut_hx_tar", "HMS x-Target (Lab)", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *cut_hy_tar = new TH1F("cut_hy_tar", "HMS y-Target (Lab)", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *cut_hz_tar = new TH1F("cut_hz_tar", "HMS z-Target (Lab)", ztar_nbins, ztar_xmin, ztar_xmax);
    
  TH1F *cut_px_tar = new TH1F("cut_px_tar", "SHMS x-Target (Lab)", xtar_nbins, xtar_xmin, xtar_xmax);
  TH1F *cut_py_tar = new TH1F("cut_py_tar", "SHMS y-Target (Lab)", ytar_nbins, ytar_xmin, ytar_xmax);
  TH1F *cut_pz_tar = new TH1F("cut_pz_tar", "SHMS z-Target (Lab)", ztar_nbins, ztar_xmin, ztar_xmax);
    


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

  TH2F *cut_Q2_vs_thnq = new TH2F("cut_Q2_vs_thnq", "Q2 vs. #theta_{nq}", thnq_nbins, thnq_xmin, thnq_xmax, Q2_nbins, Q2_xmin, Q2_xmax);       
  TH2F *cut_Q2_vs_Pm = new TH2F("cut_Q2_vs_Pm", "Q2 vs. Pm", Pm_nbins, Pm_xmin, Pm_xmax, Q2_nbins, Q2_xmin, Q2_xmax);   
      
  //Set Variable Names and Branches
 
  //------Kinematics
  Double_t  Eb = 10.6005;
  Double_t  epCoinTime;
  Double_t  theta_e;
  Double_t  W;
  Double_t  Q2;
  Double_t  X;
  Double_t  nu;
  Double_t  q3m;   //q-vect magnitude
  Double_t  th_q;
  Double_t  kf;
  Double_t  kfv2;  //Final electron momentum (NOT using delta)
  Double_t  Pf;
  Double_t Pfv2;  //final proton momentum (NOT using delta)
  Double_t  Ep;
  Double_t  Kp;
  Double_t  Kn;
  Double_t  Em;
  Double_t  Em_nuc;
  Double_t  M_recoil;  //invariant mass of recoiling system (should be equivalent to missing mass of neutron)
  Double_t  E_recoil;   //recoil system energy (should be equivalent to neutron energy)
  Double_t  Pm;
  Double_t  Pmx_lab;
  Double_t  Pmy_lab;
  Double_t  Pmz_lab;
  Double_t  Pmx_q;
  Double_t  Pmy_q;
  Double_t  Pmz_q;
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

  T->SetBranchAddress("H.kin.secondary.Prec_x",&Pmx_lab);   //x-component of recoil momentum ( in Hall or Lab Coordinates)
  T->SetBranchAddress("H.kin.secondary.Prec_y",&Pmy_lab);   //y
  T->SetBranchAddress("H.kin.secondary.Prec_z",&Pmz_lab);   //z
  
  T->SetBranchAddress("H.kin.secondary.pmiss_x",&Pmx_q);   //x-component of recoil momentum (perpendicular with respect to the q-vector)
  T->SetBranchAddress("H.kin.secondary.pmiss_y",&Pmy_q);   //y (Out-of plane Oop)
  T->SetBranchAddress("H.kin.secondary.pmiss_z",&Pmz_q);   //z (Parallel)

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
 
  //------SHMS Detector Quantities
  Double_t  pcal_etotnorm;
  Double_t  pngcer_npesum;

  T->SetBranchAddress("P.cal.etotnorm",&pcal_etotnorm);
  T->SetBranchAddress("P.ngcer.npeSum",&pngcer_npesum);


  //Determine Full Weight
  //Each data event will be corrected for by dividing it by charge, efficencys and live time
  Double_t FullWeight = 1. / (charge_factor*e_trkEff*h_trkEff*t_LT);
 
  //Define Boolean for Kin. Cuts
  Bool_t c_Em;
  Bool_t c_ctime;  //coincidence time cut
  Bool_t c_hdelta;
  Bool_t c_edelta;
  Bool_t c_ecal;
  Bool_t c_ngc_NpeSum;

  //Kinematic Cuts to select PWIA region
  Bool_t c_Q2;
  Bool_t c_th_nq;
  Bool_t c_MM;

  //======================
  // E V E N T   L O O P 
  //======================
  
  
  Long64_t nentries = T->GetEntries();
  
  cout << "nentries = " << nentries << endl;
  
  
  
  for (Long64_t i=0; i<nentries;i++) {
    
    T->GetEntry(i);
    
    //Determine theta_p
    theta_p = xangle - theta_e;
    W2 = W*W;
    theta_pq_v2 = th_q - theta_p;
    En = sqrt(MN*MN + Pm*Pm);
    Pfv2 = sqrt(pow(nu + MD - En,2) - MP*MP);
    Ep = sqrt(MP*MP + Pfv2*Pfv2);

    //Define Cuts
    c_Em = Em_nuc<0.04;
    c_ctime = epCoinTime>10.5 && epCoinTime<15.5;
    c_hdelta = h_delta>-8. && h_delta<8.;
    c_edelta = e_delta>-10. && e_delta<22.;
    c_ecal = pcal_etotnorm >0.6;
    c_ngc_NpeSum = pngcer_npesum > 0.5;
    c_Q2 = Q2 >= 4.0;
    c_th_nq = (thbq/dtr) >= 35. && (thbq/dtr) <= 45.;
    //c_th_nq = (thbq/dtr) >= 55. && (thbq/dtr) <= 65.;
    //c_th_nq = (thbq/dtr) >= 45. && (thbq/dtr) <= 55.;


    //c_MM = M_recoil > 0.92 && M_recoil < 0.96;

    //APPLY CUTS: BEGIN CUTS LOOP
    if (c_Em&&c_hdelta&&c_edelta&&c_ecal&&c_ctime&&c_th_nq&&c_Q2)
    {

      cut_epCT->Fill(epCoinTime, FullWeight);
      cut_ecal_etotnorm->Fill(pcal_etotnorm, FullWeight);

	  //Kinematics
	  cut_Emiss->Fill(Em, FullWeight);
	  cut_pm->Fill(Pm, FullWeight);

	  cut_pmX_lab->Fill(Pmx_lab, FullWeight);
	  cut_pmY_lab->Fill(Pmy_lab, FullWeight);
	  cut_pmZ_lab->Fill(Pmz_lab, FullWeight);
	  
	  cut_pmX_q->Fill(Pmx_q, FullWeight);
	  cut_pmY_q->Fill(Pmy_q, FullWeight);
	  cut_pmZ_q->Fill(Pmz_q, FullWeight);

	  cut_Q_2->Fill(Q2, FullWeight);
	  cut_omega->Fill(nu, FullWeight);
	  cut_W_inv->Fill(W, FullWeight);
	  cut_theta_elec->Fill(theta_e/dtr, FullWeight);
	  cut_theta_prot->Fill(theta_p/dtr, FullWeight);

	  
	  //Additional Kinematics Variables
	  cut_W_2->Fill(W2, FullWeight); 
	  cut_xbj->Fill(X, FullWeight); 
	  cut_P_f->Fill(Pfv2, FullWeight);
	  cut_k_f->Fill(kf, FullWeight);
	  cut_theta_q->Fill(th_q/dtr, FullWeight);
	  cut_q_vec->Fill(q3m, FullWeight);
	  cut_thet_pq->Fill(thxq/dtr, FullWeight);
	  cut_thet_pq_v2->Fill(theta_pq_v2/dtr, FullWeight);
	  cut_theta_nq->Fill(thbq/dtr, FullWeight);
	  cut_E_n->Fill(En, FullWeight);

	  cut_Mmiss->Fill(M_recoil, FullWeight);
	  cut_Emiss_nuc->Fill(Em_nuc, FullWeight);
	  cut_Erecoil->Fill(E_recoil, FullWeight);

	  cut_KinN->Fill(Kn, FullWeight);
	  cut_KinP->Fill(Kp, FullWeight);
	  cut_E_p->Fill(Ep, FullWeight);

	  //Reconstructed Target Quantities (Lab Frame)
	  cut_hx_tar->Fill(htar_x, FullWeight);
	  cut_hy_tar->Fill(htar_y, FullWeight);
	  cut_hz_tar->Fill(htar_z, FullWeight);
	  
	  cut_px_tar->Fill(ptar_x, FullWeight);
	  cut_py_tar->Fill(ptar_y, FullWeight);
	  cut_pz_tar->Fill(ptar_z, FullWeight);
	  

	  //Hadron-Arm Target Reconstruction 
	  cut_hytar->Fill(h_ytar, FullWeight);
	  cut_hxptar->Fill(h_xptar, FullWeight);
	  cut_hyptar->Fill(h_yptar, FullWeight);
	  cut_hdelta->Fill(h_delta, FullWeight);
	  
	  //Hadron-Arm Focal Plane
	  cut_hxfp->Fill(h_xfp, FullWeight);
	  cut_hyfp->Fill(h_yfp, FullWeight);
	  cut_hxpfp->Fill(h_xpfp, FullWeight);
	  cut_hypfp->Fill(h_ypfp, FullWeight);
	  
	  //Electron-Arm Target Reconstruction
	  cut_eytar->Fill(e_ytar, FullWeight);
	  cut_exptar->Fill(e_xptar, FullWeight);
	  cut_eyptar->Fill(e_yptar, FullWeight);
	  cut_edelta->Fill(e_delta, FullWeight);
	  
	  //Electron-Arm Focal Plane
	  cut_exfp->Fill(e_xfp, FullWeight);
	  cut_eyfp->Fill(e_yfp, FullWeight);
	  cut_expfp->Fill(e_xpfp, FullWeight);
	  cut_eypfp->Fill(e_ypfp, FullWeight);
	  

	  //Fill 2D HMS Focal Plane Quantities
	  cut_h_xfp_vs_yfp->Fill(h_yfp, h_xfp, FullWeight);
	  cut_e_xfp_vs_yfp->Fill(e_yfp, e_xfp, FullWeight);
	  
	  //Fill 2D reconstructed variables
	  cut_hxptar_vs_exptar->Fill(e_xptar, h_xptar, FullWeight);
	  cut_hyptar_vs_eyptar->Fill(e_yptar, h_yptar, FullWeight);
	  cut_hdelta_vs_edelta->Fill(e_delta, h_delta, FullWeight);

	  
	  //Heep cross check
	  cut_emiss_vs_pmiss->Fill(Pm, Em, FullWeight);
	  cut_edelta_vs_eyptar->Fill(e_yptar, e_delta, FullWeight);
	  
	  //OPTICS CHECK (W / Emiss vs. electron Arm Quantities)
	  cut_W_vs_exfp->Fill(e_xfp, W, FullWeight);
	  cut_W_vs_expfp->Fill(e_xpfp, W, FullWeight);
	  cut_W_vs_eyfp->Fill(e_yfp, W, FullWeight);
	  cut_W_vs_eypfp->Fill(e_ypfp, W, FullWeight);
	  
	  cut_W_vs_eytar->Fill(e_ytar, W, FullWeight);
	  cut_W_vs_exptar->Fill(e_xptar, W, FullWeight);
	  cut_W_vs_eyptar->Fill(e_yptar, W, FullWeight);
	  cut_W_vs_edelta->Fill(e_delta, W, FullWeight);

	  cut_Em_vs_exfp->Fill(e_xfp, Em, FullWeight);
	  cut_Em_vs_expfp->Fill(e_xpfp, Em, FullWeight);
	  cut_Em_vs_eyfp->Fill(e_yfp, Em, FullWeight);
	  cut_Em_vs_eypfp->Fill(e_ypfp, Em, FullWeight);
	  
	  cut_Em_vs_eytar->Fill(e_ytar, Em, FullWeight);
	  cut_Em_vs_exptar->Fill(e_xptar, Em, FullWeight);
	  cut_Em_vs_eyptar->Fill(e_yptar, Em, FullWeight);
	  cut_Em_vs_edelta->Fill(e_delta, Em, FullWeight);
	  
	  //OPTICS CHECK (W / Emiss vs. hadron Arm Quantities)
	  cut_W_vs_hxfp->Fill(h_xfp, W, FullWeight);
	  cut_W_vs_hxpfp->Fill(h_xpfp, W, FullWeight);
	  cut_W_vs_hyfp->Fill(h_yfp, W, FullWeight);
	  cut_W_vs_hypfp->Fill(h_ypfp, W, FullWeight);
	  
	  cut_W_vs_hytar->Fill(h_ytar, W, FullWeight);
	  cut_W_vs_hxptar->Fill(h_xptar, W, FullWeight);
	  cut_W_vs_hyptar->Fill(h_yptar, W, FullWeight);
	  cut_W_vs_hdelta->Fill(h_delta, W, FullWeight);

	  cut_Em_vs_hxfp->Fill(h_xfp, Em, FullWeight);
	  cut_Em_vs_hxpfp->Fill(h_xpfp, Em, FullWeight);
	  cut_Em_vs_hyfp->Fill(h_yfp, Em, FullWeight);
	  cut_Em_vs_hypfp->Fill(h_ypfp, Em, FullWeight);
	  
	  cut_Em_vs_hytar->Fill(h_ytar, Em, FullWeight);
	  cut_Em_vs_hxptar->Fill(h_xptar, Em, FullWeight);
	  cut_Em_vs_hyptar->Fill(h_yptar, Em, FullWeight);
	  cut_Em_vs_hdelta->Fill(h_delta, Em, FullWeight);
	  

	  //OPTICS CHECK (electron Arm Recon. vs. Focal Plane)
	  cut_eytar_vs_exfp->Fill(e_xfp, e_ytar, FullWeight);
	  cut_eytar_vs_expfp->Fill(e_xpfp, e_ytar, FullWeight);
	  cut_eytar_vs_eyfp->Fill(e_yfp, e_ytar, FullWeight);
	  cut_eytar_vs_eypfp->Fill(e_ypfp, e_ytar, FullWeight);
  
	  cut_eyptar_vs_exfp->Fill(e_xfp, e_yptar, FullWeight);
	  cut_eyptar_vs_expfp->Fill(e_xpfp, e_yptar, FullWeight);
	  cut_eyptar_vs_eyfp->Fill(e_yfp, e_yptar, FullWeight);
	  cut_eyptar_vs_eypfp->Fill(e_ypfp, e_yptar, FullWeight);

	  cut_exptar_vs_exfp->Fill(e_xfp, e_xptar, FullWeight);
	  cut_exptar_vs_expfp->Fill(e_xpfp, e_xptar, FullWeight);
	  cut_exptar_vs_eyfp->Fill(e_yfp, e_xptar, FullWeight);
	  cut_exptar_vs_eypfp->Fill(e_ypfp, e_xptar, FullWeight);

	  cut_edelta_vs_exfp->Fill(e_xfp, e_delta, FullWeight);
	  cut_edelta_vs_expfp->Fill(e_xpfp, e_delta, FullWeight);
	  cut_edelta_vs_eyfp->Fill(e_yfp, e_delta, FullWeight);
	  cut_edelta_vs_eypfp->Fill(e_ypfp, e_delta, FullWeight);

	  //OPTICS CHECK (hadron Arm Recon. vs. Focal Plane)
	  cut_hytar_vs_hxfp->Fill(h_xfp, h_ytar, FullWeight);
	  cut_hytar_vs_hxpfp->Fill(h_xpfp, h_ytar, FullWeight);
	  cut_hytar_vs_hyfp->Fill(h_yfp, h_ytar, FullWeight);
	  cut_hytar_vs_hypfp->Fill(h_ypfp, h_ytar, FullWeight);
  
	  cut_hyptar_vs_hxfp->Fill(h_xfp, h_yptar, FullWeight);
	  cut_hyptar_vs_hxpfp->Fill(h_xpfp, h_yptar, FullWeight);
	  cut_hyptar_vs_hyfp->Fill(h_yfp, h_yptar, FullWeight);
	  cut_hyptar_vs_hypfp->Fill(h_ypfp, h_yptar, FullWeight);

	  cut_hxptar_vs_hxfp->Fill(h_xfp, h_xptar, FullWeight);
	  cut_hxptar_vs_hxpfp->Fill(h_xpfp, h_xptar, FullWeight);
	  cut_hxptar_vs_hyfp->Fill(h_yfp, h_xptar, FullWeight);
	  cut_hxptar_vs_hypfp->Fill(h_ypfp, h_xptar, FullWeight);

	  cut_hdelta_vs_hxfp->Fill(h_xfp, h_delta, FullWeight);
	  cut_hdelta_vs_hxpfp->Fill(h_xpfp, h_delta, FullWeight);
	  cut_hdelta_vs_hyfp->Fill(h_yfp, h_delta, FullWeight);
	  cut_hdelta_vs_hypfp->Fill(h_ypfp, h_delta, FullWeight);

	  cut_Q2_vs_thnq->Fill(thbq/dtr, Q2, FullWeight);                                                                                     
	  cut_Q2_vs_Pm->Fill(Pm, Q2, FullWeight);

	}//End CUTS LOOP
      
      
      epCT->Fill(epCoinTime, FullWeight);
      ecal_etotnorm->Fill(pcal_etotnorm, FullWeight); 

      //Kinematics
      Emiss_nuc->Fill(Em_nuc, FullWeight);                                                                               
      Mmiss->Fill(M_recoil, FullWeight);

      Emiss->Fill(Em, FullWeight);
      pm->Fill(Pm, FullWeight);
      
      pmX_lab->Fill(Pmx_lab, FullWeight);
      pmY_lab->Fill(Pmy_lab, FullWeight);
      pmZ_lab->Fill(Pmz_lab, FullWeight);
      
      pmX_q->Fill(Pmx_q, FullWeight);
      pmY_q->Fill(Pmy_q, FullWeight);
      pmZ_q->Fill(Pmz_q, FullWeight);

      Q_2->Fill(Q2, FullWeight);
      omega->Fill(nu, FullWeight);
      W_inv->Fill(W, FullWeight);
      theta_elec->Fill(theta_e/dtr, FullWeight);
      theta_prot->Fill(theta_p/dtr, FullWeight);


      //Additional Kinematics Variables
      W_2->Fill(W2, FullWeight); 
      xbj->Fill(X, FullWeight); 
      P_f->Fill(Pfv2, FullWeight);
      k_f->Fill(kf, FullWeight);
      theta_q->Fill(th_q/dtr, FullWeight);
      q_vec->Fill(q3m, FullWeight);
      thet_pq->Fill(thxq/dtr, FullWeight);
      thet_pq_v2->Fill(theta_pq_v2/dtr, FullWeight);
      theta_nq->Fill(thbq/dtr, FullWeight);
      E_n->Fill(En, FullWeight);

      Erecoil->Fill(E_recoil, FullWeight);                                                                               
                                    
      KinN->Fill(Kn, FullWeight);                                                                                        
      KinP->Fill(Kp, FullWeight); 
      E_p->Fill(Ep, FullWeight);

      //Reconstructed Target Quantities (Lab Frame)
      hx_tar->Fill(htar_x, FullWeight);
      hy_tar->Fill(htar_y, FullWeight);
      hz_tar->Fill(htar_z, FullWeight);
      
      px_tar->Fill(ptar_x, FullWeight);
      py_tar->Fill(ptar_y, FullWeight);
      pz_tar->Fill(ptar_z, FullWeight);
      	 

      //Hadron-Arm Target Reconstruction 
      hytar->Fill(h_ytar, FullWeight);
      hxptar->Fill(h_xptar, FullWeight);
      hyptar->Fill(h_yptar, FullWeight);
      hdelta->Fill(h_delta, FullWeight);
      
      //Hadron-Arm Focal Plane
      hxfp->Fill(h_xfp, FullWeight);
      hyfp->Fill(h_yfp, FullWeight);
      hxpfp->Fill(h_xpfp, FullWeight);
      hypfp->Fill(h_ypfp, FullWeight);
      
      //Electron-Arm Target Reconstruction
      eytar->Fill(e_ytar, FullWeight);
      exptar->Fill(e_xptar, FullWeight);
      eyptar->Fill(e_yptar, FullWeight);
      edelta->Fill(e_delta, FullWeight);
      
      //Electron-Arm Focal Plane
      exfp->Fill(e_xfp, FullWeight);
      eyfp->Fill(e_yfp, FullWeight);
      expfp->Fill(e_xpfp, FullWeight);
      eypfp->Fill(e_ypfp, FullWeight);

      
      //Fill 2D HMS Focal Plane Quantities
      h_xfp_vs_yfp->Fill(h_yfp, h_xfp, FullWeight);
      e_xfp_vs_yfp->Fill(e_yfp, e_xfp, FullWeight);

      //Fill 2D reconstructed variables
      hxptar_vs_exptar->Fill(e_xptar, h_xptar, FullWeight);
      hyptar_vs_eyptar->Fill(e_yptar, h_yptar, FullWeight);
      hdelta_vs_edelta->Fill(e_delta, h_delta, FullWeight);

      //Heep cross check
      emiss_vs_pmiss->Fill(Pm, Em, FullWeight);
      edelta_vs_eyptar->Fill(e_yptar, e_delta, FullWeight);
     	 
      //OPTICS CHECK (W / Em vs. electron arm)
      W_vs_exfp->Fill(e_xfp, W, FullWeight);
      W_vs_expfp->Fill(e_xpfp, W, FullWeight);
      W_vs_eyfp->Fill(e_yfp, W, FullWeight);
      W_vs_eypfp->Fill(e_ypfp, W, FullWeight);
      
      W_vs_eytar->Fill(e_ytar, W, FullWeight);
      W_vs_exptar->Fill(e_xptar, W, FullWeight);
      W_vs_eyptar->Fill(e_yptar, W, FullWeight);
      W_vs_edelta->Fill(e_delta, W, FullWeight);

      Em_vs_exfp->Fill(e_xfp, Em, FullWeight);
      Em_vs_expfp->Fill(e_xpfp, Em, FullWeight);
      Em_vs_eyfp->Fill(e_yfp, Em, FullWeight);
      Em_vs_eypfp->Fill(e_ypfp, Em, FullWeight);
      
      Em_vs_eytar->Fill(e_ytar, Em, FullWeight);
      Em_vs_exptar->Fill(e_xptar, Em, FullWeight);
      Em_vs_eyptar->Fill(e_yptar, Em, FullWeight);
      Em_vs_edelta->Fill(e_delta, Em, FullWeight);
      
      //OPTICS CHECK (W / Em vs. hadron arm)
      W_vs_hxfp->Fill(h_xfp, W, FullWeight);
      W_vs_hxpfp->Fill(h_xpfp, W, FullWeight);
      W_vs_hyfp->Fill(h_yfp, W, FullWeight);
      W_vs_hypfp->Fill(h_ypfp, W, FullWeight);
      
      W_vs_hytar->Fill(h_ytar, W, FullWeight);
      W_vs_hxptar->Fill(h_xptar, W, FullWeight);
      W_vs_hyptar->Fill(h_yptar, W, FullWeight);
      W_vs_hdelta->Fill(h_delta, W, FullWeight);

      Em_vs_hxfp->Fill(h_xfp, Em, FullWeight);
      Em_vs_hxpfp->Fill(h_xpfp, Em, FullWeight);
      Em_vs_hyfp->Fill(h_yfp, Em, FullWeight);
      Em_vs_hypfp->Fill(h_ypfp, Em, FullWeight);
      
      Em_vs_hytar->Fill(h_ytar, Em, FullWeight);
      Em_vs_hxptar->Fill(h_xptar, Em, FullWeight);
      Em_vs_hyptar->Fill(h_yptar, Em, FullWeight);
      Em_vs_hdelta->Fill(h_delta, Em, FullWeight);
      
      Q2_vs_thnq->Fill(thbq/dtr, Q2, FullWeight);                    
      Q2_vs_Pm->Fill(Pm, Q2, FullWeight);
    
  } //end entry loop
  
   
  outROOT->Write();
  
}
