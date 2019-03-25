//Code to get preliminary cross setions from data / simc

#include "../simc_analysis/set_deep_histos.h"
void compare_xsec()
{


  gStyle->SetOptStat(kFALSE);

  TString simc_fsi580set1 = "../simc_analysis/D2simc_pm580_lagetfsi_rad_set1.root";
  TString simc_fsi580set2 = "../simc_analysis/D2simc_pm580_lagetfsi_rad_set2.root";

  TString simc_fsi750set1 = "../simc_analysis/D2simc_pm750_lagetfsi_rad_set1.root";   
  TString simc_fsi750set2 = "../simc_analysis/D2simc_pm750_lagetfsi_rad_set2.root";         
  TString simc_fsi750set3 = "../simc_analysis/D2simc_pm750_lagetfsi_rad_set3.root"; 

  TString data_580set1 = "../data_analysis/D2data_pm580_set1.root";
  TString data_580set2 = "../data_analysis/D2data_pm580_set2.root";

  TString data_750set1 = "../data_analysis/D2data_pm750_set1.root"; 
  TString data_750set2 = "../data_analysis/D2data_pm750_set2.root";  
  TString data_750set3 = "../data_analysis/D2data_pm750_set3.root";

  TFile *simc_fsi580set1_file = new TFile(simc_fsi580set1);
  TFile *simc_fsi580set2_file = new TFile(simc_fsi580set2);
  
  TFile *simc_fsi750set1_file = new TFile(simc_fsi750set1);          
  TFile *simc_fsi750set2_file = new TFile(simc_fsi750set2); 
  TFile *simc_fsi750set3_file = new TFile(simc_fsi750set3); 

  TFile *data_580set1_file = new TFile(data_580set1);           
  TFile *data_580set2_file = new TFile(data_580set2); 

  TFile *data_750set1_file = new TFile(data_750set1);                   
  TFile *data_750set2_file = new TFile(data_750set2);  
  TFile *data_750set3_file = new TFile(data_750set3);   

  //Create Histograms to store objects 
  TH1F *simcfsi580set1_cut_pm = 0;                                                              
  TH1F *simcfsi580set1_cut_pm_ps = 0; 
  
  TH1F *simcfsi580set2_cut_pm = 0;                                                              
  TH1F *simcfsi580set2_cut_pm_ps = 0; 

  TH1F *data580set1_cut_pm = 0;   
  TH1F *data580set2_cut_pm = 0; 

  TH1F *ratio_data580set1 = new TH1F("ratio_data580set1", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *ratio_data580set2 = new TH1F("ratio_data580set2", "", Pm_nbins, Pm_xmin, Pm_xmax);  

  //-----------------

  TH1F *simcfsi750set1_cut_pm = 0;                                                                                                                  
  TH1F *simcfsi750set1_cut_pm_ps = 0;                                                                                                                            
                                                                                                                                                            
  TH1F *simcfsi750set2_cut_pm = 0;                                                                                                                            
  TH1F *simcfsi750set2_cut_pm_ps = 0;                                                                                                                            

  TH1F *simcfsi750set3_cut_pm = 0; 
  TH1F *simcfsi750set3_cut_pm_ps = 0; 
                                                                                                                                              
  TH1F *data750set1_cut_pm = 0;                                                                                                                                   
  TH1F *data750set2_cut_pm = 0;                                                                                                                    
  TH1F *data750set3_cut_pm = 0;  

  TH1F *ratio_data750set1 = new TH1F("ratio_data750set1", "", Pm_nbins, Pm_xmin, Pm_xmax);     
  TH1F *ratio_data750set2 = new TH1F("ratio_data750set2", "", Pm_nbins, Pm_xmin, Pm_xmax);                  
  TH1F *ratio_data750set3 = new TH1F("ratio_data750set3", "", Pm_nbins, Pm_xmin, Pm_xmax);


  ratio_data580set1->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  ratio_data580set1->GetXaxis()->CenterTitle();

  ratio_data580set1->GetYaxis()->SetTitle("Pm^{Weight} / Pm^{Phase Space} (Arbitrary Units)"); 
  ratio_data580set1->GetYaxis()->CenterTitle();  
  
  ratio_data580set1->SetTitle("Ratio of Weighted to Phase Space P_{miss} Yield");

  
  ratio_data750set1->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  ratio_data750set1->GetXaxis()->CenterTitle();

  ratio_data750set1->GetYaxis()->SetTitle("Pm^{Weight} / Pm^{Phase Space} (Arbitrary Units)"); 
  ratio_data750set1->GetYaxis()->CenterTitle();  
  
  ratio_data750set1->SetTitle("Ratio of Weighted to Phase Space P_{miss} Yield");


  //------Get Histograms---------
  
  //Pm = 580 MeV

  simc_fsi580set1_file->cd();
  simc_fsi580set1_file->GetObject("cut_pm", simcfsi580set1_cut_pm);
  simc_fsi580set1_file->GetObject("cut_pm_ps",simcfsi580set1_cut_pm_ps); 
  
  simc_fsi580set2_file->cd();
  simc_fsi580set2_file->GetObject("cut_pm", simcfsi580set2_cut_pm);
  simc_fsi580set2_file->GetObject("cut_pm_ps",simcfsi580set2_cut_pm_ps); 
  

  data_580set1_file->cd();
  data_580set1_file->GetObject("cut_pm", data580set1_cut_pm); 
  
  data_580set2_file->cd();
  data_580set2_file->GetObject("cut_pm", data580set2_cut_pm); 

  ratio_data580set1->Divide(data580set1_cut_pm, simcfsi580set1_cut_pm_ps);
  ratio_data580set2->Divide(data580set2_cut_pm, simcfsi580set2_cut_pm_ps); 

  ratio_data580set1->SetMarkerStyle(20);
  ratio_data580set1->SetMarkerColor(kRed); 

  ratio_data580set2->SetMarkerStyle(20);                                                                                                
  ratio_data580set2->SetMarkerColor(kBlue); 

  // Pm = 750 MeV

  simc_fsi750set1_file->cd();
  simc_fsi750set1_file->GetObject("cut_pm", simcfsi750set1_cut_pm);
  simc_fsi750set1_file->GetObject("cut_pm_ps",simcfsi750set1_cut_pm_ps); 
  
  simc_fsi750set2_file->cd();
  simc_fsi750set2_file->GetObject("cut_pm", simcfsi750set2_cut_pm);
  simc_fsi750set2_file->GetObject("cut_pm_ps",simcfsi750set2_cut_pm_ps); 
  
  simc_fsi750set3_file->cd();
  simc_fsi750set3_file->GetObject("cut_pm", simcfsi750set3_cut_pm);
  simc_fsi750set3_file->GetObject("cut_pm_ps",simcfsi750set3_cut_pm_ps); 
  

  data_750set1_file->cd();
  data_750set1_file->GetObject("cut_pm", data750set1_cut_pm); 
  
  data_750set2_file->cd();
  data_750set2_file->GetObject("cut_pm", data750set2_cut_pm); 

  data_750set3_file->cd();
  data_750set3_file->GetObject("cut_pm", data750set3_cut_pm); 

  ratio_data750set1->Divide(data750set1_cut_pm, simcfsi750set1_cut_pm_ps);
  ratio_data750set2->Divide(data750set2_cut_pm, simcfsi750set2_cut_pm_ps); 
  ratio_data750set3->Divide(data750set3_cut_pm, simcfsi750set3_cut_pm_ps); 

  ratio_data750set1->SetMarkerStyle(20);
  ratio_data750set1->SetMarkerColor(kRed); 

  ratio_data750set2->SetMarkerStyle(20);                                                                                                
  ratio_data750set2->SetMarkerColor(kBlue); 

  ratio_data750set3->SetMarkerStyle(20);                                                                                                
  ratio_data750set3->SetMarkerColor(kBlack); 


  //simc_cut_pm->Draw();
  //data_cut_pm->Draw("sames");
  TCanvas *c1 = new TCanvas("c1", "Pm580MeV", 2000,2000);
  
  ratio_data580set1->Draw("E1");
  ratio_data580set2->Draw("E1sames");
  
  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->SetHeader("D2, Pm = 580 MeV","C"); // option "C" allows to center the header
  legend->AddEntry(ratio_data580set1,"DataSet:1","lep");
  legend->AddEntry(ratio_data580set2,"DataSet:2","lep"); 
  legend->Draw();

  TCanvas *c2 = new TCanvas("c2", "Pm750MeV", 2000,2000);

  ratio_data750set1->Draw("E1");
  ratio_data750set2->Draw("E1sames");
  ratio_data750set3->Draw("E1sames");

  auto legend2 = new TLegend(0.1,0.7,0.48,0.9);
  legend2->SetHeader("D2, Pm = 750 MeV","C"); // option "C" allows to center the header
  legend2->AddEntry(ratio_data750set1,"DataSet:1","lep");
  legend2->AddEntry(ratio_data750set2,"DataSet:2","lep"); 
  legend2->AddEntry(ratio_data750set3,"DataSet:3","lep");
  legend2->Draw();

  TCanvas *c3 = new TCanvas("c3", "", 1500,2000); 
  c3->Divide(2,1);

  c3->cd(1);
  simcfsi580set1_cut_pm_ps->Draw();
  data580set1_cut_pm->Draw("sames");

  c3->cd(2);                                     
  simcfsi580set2_cut_pm_ps->Draw();                                                                              
  data580set2_cut_pm->Draw("sames");   


  TCanvas *c4 = new TCanvas("c4", "", 1500,2000);                                                                                                       
  c4->Divide(3,1);                                                                                                                                                           
                       
  c4->cd(1);                                           
  simcfsi750set1_cut_pm_ps->Draw();                                                      
  data750set1_cut_pm->Draw("sames");                                                                                              
                                                                                                                                                  
  c4->cd(2);                                                                      
  simcfsi750set2_cut_pm_ps->Draw();                   
  data750set2_cut_pm->Draw("sames");
 
  c4->cd(3); 
  simcfsi750set3_cut_pm_ps->Draw();                                                                                        
  data750set3_cut_pm->Draw("sames");

}
