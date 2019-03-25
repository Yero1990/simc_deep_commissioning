//Code to get preliminary cross setions from data / simc

#include "../../simc_analysis/set_deep_histos.h"
void compare_xsec()
{

  string model = "PWIA";   //FSI --> Does NOT apply cuts to select PWIA.   //PWIA Applies th_nq/Q2 cuts to select small FSI

  gStyle->SetOptStat(kFALSE);

  //These Files do NOT use PWIA Cuts
  
  //SIMC MODEL: FSI
  TString simc_fsi580set1 = Form( "../../simc_analysis/simc%s/th_nq_35_45/D2simc_pm580_lagetfsi_rad_total.root", model.c_str() );
  //TString simc_fsi580set1 = Form( "../../simc_analysis/simc%s/D2simc_pm580_lagetfsi_rad_total.root", model.c_str() );
  TString simc_fsi580set2 = Form( "../../simc_analysis/simc%s/D2simc_pm580_lagetfsi_rad_set2.root", model.c_str() );

 

  TString simc_fsi750set1 = Form( "../../simc_analysis/simc%s/th_nq_35_45/D2simc_pm750_lagetfsi_rad_total.root", model.c_str() );   
  //TString simc_fsi750set1 = Form( "../../simc_analysis/simc%s/D2simc_pm750_lagetfsi_rad_total.root", model.c_str() );   
  TString simc_fsi750set2 = Form( "../../simc_analysis/simc%s/D2simc_pm750_lagetfsi_rad_set2.root", model.c_str() );         
  TString simc_fsi750set3 = Form( "../../simc_analysis/simc%s/D2simc_pm750_lagetfsi_rad_set3.root", model.c_str() ); 
  

  //SIMC MODEL: PWIA
  TString simc_pwia580set1 = Form( "../../simc_analysis/simc%s/th_nq_35_45/D2simc_pm580_lagetpwia_rad_total.root", model.c_str() );
  //TString simc_pwia580set1 = Form( "../../simc_analysis/simc%s/D2simc_pm580_lagetpwia_rad_total.root", model.c_str() );
  TString simc_pwia580set2 = Form( "../../simc_analysis/simc%s/D2simc_pm580_lagetpwia_rad_set2.root", model.c_str() );

  TString simc_pwia750set1 = Form( "../../simc_analysis/simc%s/th_nq_35_45/D2simc_pm750_lagetpwia_rad_total.root", model.c_str() ); 
  //TString simc_pwia750set1 = Form( "../../simc_analysis/simc%s/D2simc_pm750_lagetpwia_rad_total.root", model.c_str() );   
  TString simc_pwia750set2 = Form( "../../simc_analysis/simc%s/D2simc_pm750_lagetpwia_rad_set2.root", model.c_str() );         
  TString simc_pwia750set3 = Form( "../../simc_analysis/simc%s/D2simc_pm750_lagetpwia_rad_set3.root", model.c_str() ); 


  //DATA: Naturally, FSI.  If CUTS are made, then, PWIA.
  TString data_580set1 = Form( "../../data_analysis/%s/th_nq_35_45/D2data_pm580_total.root", model.c_str() );
  //TString data_580set1 = Form( "../../data_analysis/%s/D2data_pm580_total.root", model.c_str() );
  TString data_580set2 = Form( "../../data_analysis/%s/D2data_pm580_set2.root", model.c_str() );

  TString data_750set1 = Form( "../../data_analysis/%s/th_nq_35_45/D2data_pm750_total.root", model.c_str() );
  //TString data_750set1 = Form( "../../data_analysis/%s/D2data_pm750_total.root", model.c_str() ); 
  TString data_750set2 = Form( "../../data_analysis/%s/D2data_pm750_set2.root", model.c_str() );  
  TString data_750set3 = Form( "../../data_analysis/%s/D2data_pm750_set3.root", model.c_str() );

  //-----------------------------------------------------------------------------------------

  //MODEL: FSI
  TFile *simc_fsi580set1_file = new TFile(simc_fsi580set1);
  TFile *simc_fsi580set2_file = new TFile(simc_fsi580set2);
  
  TFile *simc_fsi750set1_file = new TFile(simc_fsi750set1);          
  TFile *simc_fsi750set2_file = new TFile(simc_fsi750set2); 
  TFile *simc_fsi750set3_file = new TFile(simc_fsi750set3); 


  //MODEL: PWIA
  TFile *simc_pwia580set1_file = new TFile(simc_pwia580set1);
  TFile *simc_pwia580set2_file = new TFile(simc_pwia580set2);
  
  TFile *simc_pwia750set1_file = new TFile(simc_pwia750set1);          
  TFile *simc_pwia750set2_file = new TFile(simc_pwia750set2); 
  TFile *simc_pwia750set3_file = new TFile(simc_pwia750set3); 


  //DATA
  TFile *data_580set1_file = new TFile(data_580set1);           
  TFile *data_580set2_file = new TFile(data_580set2); 

  TFile *data_750set1_file = new TFile(data_750set1);                   
  TFile *data_750set2_file = new TFile(data_750set2);  
  TFile *data_750set3_file = new TFile(data_750set3);   


  //--------------------------------------------------------------------------------------------

  //Create Histograms to store objects 

  //Pmiss = 580 MeV /c
  TH1F *simc580set1_cut_pm = 0;                                                              
  TH1F *simc580set1_cut_pm_ps = 0;       //Phase SPace used for cross section
  TH1F *simc580set1_cut_pm_ps_red = 0;   //Pure Pmiss Phase Space., used to get the average of K*sigma_cc for reduced cross section
  TH1F *simc580set1_Kred = 0;             //simc Pmiss weighted by K*sigma_cc
  
  //Missing Momentum Weighted by  main%sigma / (K*sigma_cc), main%sigma --> simc cross section, leaf_name:  sig [NOTE: This is NOT the Weight, which has corrections]
  TH1F *fsi_simc580set1_cut_pm_red = 0;      
  TH1F *pwia_simc580set1_cut_pm_red = 0;      


  TH1F *simc580set2_cut_pm = 0;                                                              
  TH1F *simc580set2_cut_pm_ps = 0;  
  TH1F *simc580set2_cut_pm_ps_red = 0;   
  TH1F *simc580set2_Kred = 0;           
  
  //Missing Momentum Weighted by  main%sigma / (K*sigma_cc)
  TH1F *fsi_simc580set2_cut_pm_red = 0;      
  TH1F *pwia_simc580set2_cut_pm_red = 0;      


  //Data Missing Momentum
  TH1F *data580set1_cut_pm = 0;   
  TH1F *data580set2_cut_pm = 0; 

  //DATA Cross Sections
  TH1F *Xsec_data580set1 = new TH1F("Xsec_data580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *Xsec_data580set2 = new TH1F("Xsec_data580set2", "", Pm_nbins, Pm_xmin, Pm_xmax);  

  TH1F *redXsec_data580set1 = new TH1F("redXsec_data580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *redXsec_data580set2 = new TH1F("redXsec_data580set2", "", Pm_nbins, Pm_xmin, Pm_xmax);  


  //SIMC Cross Sections
  TH1F *fsiXsec_simc580set1 = new TH1F("fsiXsec_simc580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *fsiXsec_simc580set2 = new TH1F("fsiXsec_simc580set2", "", Pm_nbins, Pm_xmin, Pm_xmax);  
  
  TH1F *pwiaXsec_simc580set1 = new TH1F("pwiaXsec_simc580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *pwiaXsec_simc580set2 = new TH1F("pwiaXsec_simc580set2", "", Pm_nbins, Pm_xmin, Pm_xmax); 

  TH1F *fsi_redXsec_simc580set1 = new TH1F("fsi_redXsec_simc580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *fsi_redXsec_simc580set2 = new TH1F("fsi_redXsec_simc580set2", "", Pm_nbins, Pm_xmin, Pm_xmax); 
 
  TH1F *pwia_redXsec_simc580set1 = new TH1F("pwia_redXsec_simc580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *pwia_redXsec_simc580set2 = new TH1F("pwia_redXsec_simc580set2", "", Pm_nbins, Pm_xmin, Pm_xmax); 



  //K*sigma_cc average
  TH1F *simc580set1_Kred_avg =  new TH1F("KsigAvg_data580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);   
  TH1F *simc580set2_Kred_avg =  new TH1F("KsigAvg_data580set2", "", Pm_nbins, Pm_xmin, Pm_xmax);   

  

  //-----------------
  //Pmiss = 750 MeV /c
  TH1F *simc750set1_cut_pm = 0;                                                                                                                  
  TH1F *simc750set1_cut_pm_ps = 0;                                                                                                                            
  TH1F *simc750set1_cut_pm_ps_red = 0;  
  TH1F *simc750set1_Kred = 0;            
               
  //Missing Momentum Weighted by  main%sigma / (K*sigma_cc), main%sigma --> simc cross section, leaf_name:  sig [NOTE: This is NOT the Weight, which has corrections]
  TH1F *fsi_simc750set1_cut_pm_red = 0;      
  TH1F *pwia_simc750set1_cut_pm_red = 0;      
  
                                                                                                                                      
  TH1F *simc750set2_cut_pm = 0;                                                                                                                            
  TH1F *simc750set2_cut_pm_ps = 0;                                                                                                                            

  TH1F *simc750set3_cut_pm = 0; 
  TH1F *simc750set3_cut_pm_ps = 0; 
                                                                                                                                              
  TH1F *data750set1_cut_pm = 0;                                                                                                                                   
  TH1F *data750set2_cut_pm = 0;                                                                                                                    
  TH1F *data750set3_cut_pm = 0;  

  //Data Cross Section
  TH1F *Xsec_data750set1 = new TH1F("Xsec_data750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);     
  TH1F *Xsec_data750set2 = new TH1F("Xsec_data750set2", "", Pm_nbins, Pm_xmin, Pm_xmax);                  
  TH1F *Xsec_data750set3 = new TH1F("Xsec_data750set3", "", Pm_nbins, Pm_xmin, Pm_xmax);

  TH1F *redXsec_data750set1 = new TH1F("redXsec_data750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *redXsec_data750set2 = new TH1F("redXsec_data750set2", "", Pm_nbins, Pm_xmin, Pm_xmax);  


  //SIMC Cross Sections
  TH1F *fsiXsec_simc750set1 = new TH1F("fsiXsec_simc750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *fsiXsec_simc750set2 = new TH1F("fsiXsec_simc750set2", "", Pm_nbins, Pm_xmin, Pm_xmax);  
  
  TH1F *pwiaXsec_simc750set1 = new TH1F("pwiaXsec_simc750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *pwiaXsec_simc750set2 = new TH1F("pwiaXsec_simc750set2", "", Pm_nbins, Pm_xmin, Pm_xmax); 

  TH1F *fsi_redXsec_simc750set1 = new TH1F("fsi_redXsec_simc750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *fsi_redXsec_simc750set2 = new TH1F("fsi_redXsec_simc750set2", "", Pm_nbins, Pm_xmin, Pm_xmax); 
 
  TH1F *pwia_redXsec_simc750set1 = new TH1F("pwia_redXsec_simc750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *pwia_redXsec_simc750set2 = new TH1F("pwia_redXsec_simc750set2", "", Pm_nbins, Pm_xmin, Pm_xmax); 

  //K*sigma_cc average
  TH1F *simc750set1_Kred_avg =  new TH1F("KsigAvg_data750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);   
  TH1F *simc750set2_Kred_avg =  new TH1F("KsigAvg_data750set2", "", Pm_nbins, Pm_xmin, Pm_xmax);   




  Xsec_data580set1->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  Xsec_data580set1->GetXaxis()->CenterTitle();

  Xsec_data580set1->GetYaxis()->SetTitle("Pm^{Data} / Pm^{Phase Space} (Arbitrary Units)"); 
  Xsec_data580set1->GetYaxis()->CenterTitle();  
  
  Xsec_data580set1->SetTitle("Ratio of Data Yield to Phase Space: Pm = 580 MeV");

  //Reduced
  redXsec_data580set1->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  redXsec_data580set1->GetXaxis()->CenterTitle();

  redXsec_data580set1->GetYaxis()->SetTitle("#frac{#sigma^{Exp.}}{ K#sigma_{cc}} (Arbitrary Units)"); 
  redXsec_data580set1->GetYaxis()->CenterTitle();  
  
  redXsec_data580set1->SetTitle("Reduced Cross Sections: Pm = 580 MeV");


  
  Xsec_data750set1->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  Xsec_data750set1->GetXaxis()->CenterTitle();

  Xsec_data750set1->GetYaxis()->SetTitle("Pm^{Data} / Pm^{Phase Space} (Arbitrary Units)"); 
  Xsec_data750set1->GetYaxis()->CenterTitle();  
  
  Xsec_data750set1->SetTitle("Ratio of Data Yield to Phase Space: Pm = 750 MeV");
  
  //Reduced
  redXsec_data750set1->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  redXsec_data750set1->GetXaxis()->CenterTitle();

  redXsec_data750set1->GetYaxis()->SetTitle("#frac{#sigma^{Exp.}}{ K#sigma_{cc}} (Arbitrary Units)"); 
  redXsec_data750set1->GetYaxis()->CenterTitle();  
  
  redXsec_data750set1->SetTitle("Reduced Cross Sections: Pm = 750 MeV");


  

  //------Get Histograms---------
  
  //Pm = 580 MeV

  simc_fsi580set1_file->cd();
  simc_fsi580set1_file->GetObject("cut_pm", simc580set1_cut_pm);
  simc_fsi580set1_file->GetObject("cut_pm_ps",simc580set1_cut_pm_ps); 
  simc_fsi580set1_file->GetObject("cut_pm_ps_red",simc580set1_cut_pm_ps_red); 
  simc_fsi580set1_file->GetObject("cut_Kred",simc580set1_Kred);

  simc_fsi580set2_file->cd();
  simc_fsi580set2_file->GetObject("cut_pm", simc580set2_cut_pm);
  simc_fsi580set2_file->GetObject("cut_pm_ps",simc580set2_cut_pm_ps); 
  simc_fsi580set2_file->GetObject("cut_pm_ps_red",simc580set2_cut_pm_ps_red); 
  simc_fsi580set2_file->GetObject("cut_Kred",simc580set2_Kred); 

  //Get Model Dependent Weighted Missing Momentum
  //Pm = 580
  simc_fsi580set1_file->cd();
  simc_fsi580set1_file->GetObject("cut_pm_red",fsi_simc580set1_cut_pm_red);
  simc_pwia580set1_file->cd();
  simc_pwia580set1_file->GetObject("cut_pm_red",pwia_simc580set1_cut_pm_red);
  
  simc_fsi580set2_file->cd();
  simc_fsi580set2_file->GetObject("cut_pm_red",fsi_simc580set2_cut_pm_red);
  simc_pwia580set2_file->cd();
  simc_pwia580set2_file->GetObject("cut_pm_red",pwia_simc580set2_cut_pm_red);


  //Get the Average K*sigma_cc
  simc580set1_Kred_avg->Divide(simc580set1_Kred, simc580set1_cut_pm_ps_red);
  simc580set2_Kred_avg->Divide(simc580set2_Kred, simc580set2_cut_pm_ps_red);


  //Get Data Yield [Charge Normalized Pmiss Yield (Corrected for L.T., trk eff)]
  data_580set1_file->cd();
  data_580set1_file->GetObject("cut_pm", data580set1_cut_pm); 
  
  data_580set2_file->cd();
  data_580set2_file->GetObject("cut_pm", data580set2_cut_pm); 

  //Get Experimental Cross Section
  Xsec_data580set1->Divide(data580set1_cut_pm, simc580set1_cut_pm_ps);
  Xsec_data580set2->Divide(data580set2_cut_pm, simc580set2_cut_pm_ps); 

  Xsec_data580set1->SetMarkerStyle(20);
  Xsec_data580set1->SetMarkerColor(kRed); 

  Xsec_data580set2->SetMarkerStyle(20);                                                                                                
  Xsec_data580set2->SetMarkerColor(kBlue); 

  //Get Experimental Reduced Cross Section [data_Yield / K*sigma_cc_AVG]
  redXsec_data580set1->Divide(Xsec_data580set1, simc580set1_Kred_avg);
  redXsec_data580set2->Divide(Xsec_data580set2, simc580set2_Kred_avg);
  
  redXsec_data580set1->SetMarkerStyle(20);
  redXsec_data580set1->SetMarkerColor(kRed); 

  redXsec_data580set2->SetMarkerStyle(20);                                                                                                
  redXsec_data580set2->SetMarkerColor(kBlue);


  //Get Model Cross Section

  //Get Model Reduced Cross Section
  fsi_redXsec_simc580set1->Divide(fsi_simc580set1_cut_pm_red, simc580set1_cut_pm_ps_red);
  fsi_redXsec_simc580set2->Divide(fsi_simc580set2_cut_pm_red, simc580set2_cut_pm_ps_red);
 
  pwia_redXsec_simc580set1->Divide(pwia_simc580set1_cut_pm_red, simc580set1_cut_pm_ps_red);
  pwia_redXsec_simc580set2->Divide(pwia_simc580set2_cut_pm_red, simc580set2_cut_pm_ps_red);

  fsi_redXsec_simc580set1->SetMarkerStyle(20);
  fsi_redXsec_simc580set1->SetMarkerColor(kBlack); 

  pwia_redXsec_simc580set1->SetMarkerStyle(21);                                                                                                
  pwia_redXsec_simc580set1->SetMarkerColor(kBlue);


  // Pm = 750 MeV

  simc_fsi750set1_file->cd();
  simc_fsi750set1_file->GetObject("cut_pm", simc750set1_cut_pm);
  simc_fsi750set1_file->GetObject("cut_pm_ps",simc750set1_cut_pm_ps); 
  simc_fsi750set1_file->GetObject("cut_pm_ps_red",simc750set1_cut_pm_ps_red); 
  simc_fsi750set1_file->GetObject("cut_Kred",simc750set1_Kred);

  simc_fsi750set2_file->cd();
  simc_fsi750set2_file->GetObject("cut_pm", simc750set2_cut_pm);
  simc_fsi750set2_file->GetObject("cut_pm_ps",simc750set2_cut_pm_ps); 
  
  simc_fsi750set3_file->cd();
  simc_fsi750set3_file->GetObject("cut_pm", simc750set3_cut_pm);
  simc_fsi750set3_file->GetObject("cut_pm_ps",simc750set3_cut_pm_ps); 
  
    //Get Model Dependent Weighted Missing Momentum
  //Pm = 750
  simc_fsi750set1_file->cd();
  simc_fsi750set1_file->GetObject("cut_pm_red",fsi_simc750set1_cut_pm_red);
  simc_pwia750set1_file->cd();
  simc_pwia750set1_file->GetObject("cut_pm_red",pwia_simc750set1_cut_pm_red);

  //Get the Average K*sigma_cc
  simc750set1_Kred_avg->Divide(simc750set1_Kred, simc750set1_cut_pm_ps_red);


  data_750set1_file->cd();
  data_750set1_file->GetObject("cut_pm", data750set1_cut_pm); 
  
  data_750set2_file->cd();
  data_750set2_file->GetObject("cut_pm", data750set2_cut_pm); 

  data_750set3_file->cd();
  data_750set3_file->GetObject("cut_pm", data750set3_cut_pm); 

  Xsec_data750set1->Divide(data750set1_cut_pm, simc750set1_cut_pm_ps);
  Xsec_data750set2->Divide(data750set2_cut_pm, simc750set2_cut_pm_ps); 
  Xsec_data750set3->Divide(data750set3_cut_pm, simc750set3_cut_pm_ps); 

  Xsec_data750set1->SetMarkerStyle(20);
  Xsec_data750set1->SetMarkerColor(kBlack); 

  Xsec_data750set2->SetMarkerStyle(20);                                                                                                
  Xsec_data750set2->SetMarkerColor(kBlue); 

  Xsec_data750set3->SetMarkerStyle(20);                                                                                                
  Xsec_data750set3->SetMarkerColor(kBlack); 

  //Get Experimental Reduced Cross Section [data_Yield / K*sigma_cc_AVG]
  redXsec_data750set1->Divide(Xsec_data750set1, simc750set1_Kred_avg);
  redXsec_data750set2->Divide(Xsec_data750set2, simc750set2_Kred_avg);
  
  redXsec_data750set1->SetMarkerStyle(20);
  redXsec_data750set1->SetMarkerColor(kRed); 

  redXsec_data750set2->SetMarkerStyle(20);                                                                                                
  redXsec_data750set2->SetMarkerColor(kBlue);

    //Get Model Cross Section

  //Get Model Reduced Cross Section
  fsi_redXsec_simc750set1->Divide(fsi_simc750set1_cut_pm_red, simc750set1_cut_pm_ps_red);

  pwia_redXsec_simc750set1->Divide(pwia_simc750set1_cut_pm_red, simc750set1_cut_pm_ps_red);

  fsi_redXsec_simc750set1->SetMarkerStyle(20);
  fsi_redXsec_simc750set1->SetMarkerColor(kBlack); 

  pwia_redXsec_simc750set1->SetMarkerStyle(21);                                                                                                
  pwia_redXsec_simc750set1->SetMarkerColor(kBlue);


  //Plot Data Cross Sections For each Data Set

    
  //-----------------------------------------------------------------------
  TCanvas *c1 = new TCanvas("c1", "", 2000,2000);
  
  Xsec_data580set1->Draw("E1");
  Xsec_data750set1->Draw("E1sames");

  //  Xsec_data580set2->Draw("E1sames");
  
  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->SetHeader("Combined Data Sets","C"); // option "C" allows to center the header
  legend->AddEntry(Xsec_data580set1,"Pm = 580 MeV","lep");
  legend->AddEntry(Xsec_data750set1,"Pm = 750 MeV","lep"); 
  legend->Draw();
  
  /*
  TCanvas *c2 = new TCanvas("c2", "", 2000,2000);
  
  Xsec_data750set1->Draw("E1");
  Xsec_data750set2->Draw("E1sames");
  Xsec_data750set3->Draw("E1sames");

  auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
  legend2->SetHeader("D2, Pm = 750 MeV","C"); // option "C" allows to center the header
  legend2->AddEntry(Xsec_data750set1,"DataSet:1","lep");
  legend2->AddEntry(Xsec_data750set2,"DataSet:2","lep"); 
  legend2->AddEntry(Xsec_data750set3,"DataSet:3","lep"); 
  legend2->Draw();
  */
  
  //-----------------------------------------------------------------------

  /*
  //-----------------------------------------------------------------------
  
  //Plot Reduced Cross Section:  DATA: FSI: PWIA  
  //For each Data Set,  Compare DATA to FSI/PWIA 
  
  TCanvas *c1 = new TCanvas("c1", "Data/Model", 2000,2000);
    
  redXsec_data580set1->Draw("E1");
  fsi_redXsec_simc580set1->Draw("E1sames");
  pwia_redXsec_simc580set1->Draw("E1sames");
  
  auto leg580red = new TLegend(0.1,0.7,0.48,0.9);
  leg580red->SetHeader("D2, Pm = 580 MeV","C"); // option "C" allows to center the header
  leg580red->AddEntry(redXsec_data580set1,"Combined Data Set","lep");
  leg580red->AddEntry(pwia_redXsec_simc580set1,"PWIA (Laget)","lep"); 
  leg580red->AddEntry(fsi_redXsec_simc580set1,"FSI (Laget)","lep"); 

  leg580red->Draw();
  
  TCanvas *c2 = new TCanvas("c2", "Data/Model", 2000,2000);
    
  redXsec_data750set1->Draw("E1");
  fsi_redXsec_simc750set1->Draw("E1sames");
  pwia_redXsec_simc750set1->Draw("E1sames");
  
  auto leg750red = new TLegend(0.1,0.7,0.48,0.9);
  leg750red->SetHeader("D2, Pm = 750 MeV","C"); // option "C" allows to center the header
  leg750red->AddEntry(redXsec_data750set1,"Combined Data Set","lep");
  leg750red->AddEntry(pwia_redXsec_simc750set1,"PWIA (Laget)","lep"); 
  leg750red->AddEntry(fsi_redXsec_simc750set1,"FSI (Laget)","lep"); 

  leg750red->Draw();

  //---------------------------------------------------------------------------
  */


  /*  
  
  //simc_cut_pm->Draw();
  //data_cut_pm->Draw("sames");
  TCanvas *c1 = new TCanvas("c1", "Pm580MeV", 2000,2000);
  
  Xsec_data580set1->Draw("E1");
  Xsec_data580set2->Draw("E1sames");
  
  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->SetHeader("D2, Pm = 580 MeV","C"); // option "C" allows to center the header
  legend->AddEntry(Xsec_data580set1,"DataSet:1","lep");
  legend->AddEntry(Xsec_data580set2,"DataSet:2","lep"); 
  legend->Draw();

  TCanvas *c1red = new TCanvas("c1red", "Reduced Pm580MeV", 2000,2000);
  
  redXsec_data580set1->Draw("E1");
  redXsec_data580set2->Draw("E1sames");
  
  auto leg580red = new TLegend(0.1,0.7,0.48,0.9);
  leg580red->SetHeader("D2, Pm = 580 MeV","C"); // option "C" allows to center the header
  leg580red->AddEntry(redXsec_data580set1,"DataSet:1","lep");
  leg580red->AddEntry(redXsec_data580set2,"DataSet:2","lep"); 
  leg580red->Draw();

  TCanvas *c2 = new TCanvas("c2", "Pm750MeV", 2000,2000);

  Xsec_data750set1->Draw("E1");
  Xsec_data750set2->Draw("E1sames");
  Xsec_data750set3->Draw("E1sames");

  auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
  legend2->SetHeader("D2, Pm = 750 MeV","C"); // option "C" allows to center the header
  legend2->AddEntry(Xsec_data750set1,"DataSet:1","lep");
  legend2->AddEntry(Xsec_data750set2,"DataSet:2","lep"); 
  legend2->AddEntry(Xsec_data750set3,"DataSet:3","lep");
  legend2->Draw();

  */


  /*
  TCanvas *c3 = new TCanvas("c3", "", 1500,2000); 
  c3->Divide(2,1);

  c3->cd(1);
  simc580set1_cut_pm_ps->Draw();
  data580set1_cut_pm->Draw("sames");

  c3->cd(2);                                     
  simc580set2_cut_pm_ps->Draw();                                                                              
  data580set2_cut_pm->Draw("sames");   


  TCanvas *c4 = new TCanvas("c4", "", 1500,2000);                                                                                                       
  c4->Divide(3,1);                                                                                                                                                           
                       
  c4->cd(1);                                           
  simc750set1_cut_pm_ps->Draw();                                                      
  data750set1_cut_pm->Draw("sames");                                                                                              
                                                                                                                                                  
  c4->cd(2);                                                                      
  simc750set2_cut_pm_ps->Draw();                   
  data750set2_cut_pm->Draw("sames");
 
  c4->cd(3); 
  simc750set3_cut_pm_ps->Draw();                                                                                        
  data750set3_cut_pm->Draw("sames");
  */


}
