//Code to get preliminary cross setions from data / simc

#include "../simc_analysis/set_deep_histos.h"
void combined_xsec()
{


  gStyle->SetOptStat(kFALSE);

  TString simc_fsi580 = "../data_analysis/pm580/dataWeighted/TOTAL_PWIA_Selection/D2simc_pm580_lagetfsi_rad_total.root";       
  TString simc_fsi750 = "../data_analysis/pm750/dataWeighted/TOTAL_PWIA_Selection/D2simc_pm750_lagetfsi_rad_total.root"; 

  TString data_580 = "../data_analysis/pm580/dataWeighted/TOTAL_PWIA_Selection/D2data_pm580_total.root";
  TString data_750 = "../data_analysis/pm750/dataWeighted/TOTAL_PWIA_Selection/D2data_pm750_total.root"; 

  TFile *simc_fsi580_file = new TFile(simc_fsi580); 
  TFile *simc_fsi750_file = new TFile(simc_fsi750); 

  TFile *data_580_file = new TFile(data_580);           
  TFile *data_750_file = new TFile(data_750);   

  //Create Histograms to store objects 
  TH1F *simcfsi580_cut_pm = 0;                                                              
  TH1F *simcfsi580_cut_pm_ps = 0; 
  TH1F *data580_cut_pm = 0;   


  TH1F *ratio_data580 = new TH1F("ratio_data580", "", Pm_nbins, Pm_xmin, Pm_xmax);

  //-----------------

  TH1F *simcfsi750_cut_pm = 0;                                                                                                                  
  TH1F *simcfsi750_cut_pm_ps = 0;                                                                                                                          
  TH1F *data750_cut_pm = 0;                                                                                                                                   

  TH1F *ratio_data750 = new TH1F("ratio_data750", "", Pm_nbins, Pm_xmin, Pm_xmax);     


  ratio_data580->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  ratio_data580->GetXaxis()->CenterTitle();

  ratio_data580->GetYaxis()->SetTitle("Pm^{Weight} / Pm^{Phase Space} (Arbitrary Units)"); 
  ratio_data580->GetYaxis()->CenterTitle();  
  
  ratio_data580->SetTitle("Ratio of Weighted to Phase Space P_{miss} Yield");

  
  ratio_data750->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  ratio_data750->GetXaxis()->CenterTitle();

  ratio_data750->GetYaxis()->SetTitle("Pm^{Weight} / Pm^{Phase Space} (Arbitrary Units)"); 
  ratio_data750->GetYaxis()->CenterTitle();  
  
  ratio_data750->SetTitle("Ratio of Weighted to Phase Space P_{miss} Yield");


  //------Get Histograms---------
  
  //Pm = 580 MeV

  simc_fsi580_file->cd();
  simc_fsi580_file->GetObject("cut_pm", simcfsi580_cut_pm);
  simc_fsi580_file->GetObject("cut_pm_ps",simcfsi580_cut_pm_ps); 

  data_580_file->cd();
  data_580_file->GetObject("cut_pm", data580_cut_pm); 

  ratio_data580->Divide(data580_cut_pm, simcfsi580_cut_pm_ps);

  ratio_data580->SetMarkerStyle(20);
  ratio_data580->SetMarkerColor(kRed); 

  // Pm = 750 MeV

  simc_fsi750_file->cd();
  simc_fsi750_file->GetObject("cut_pm", simcfsi750_cut_pm);
  simc_fsi750_file->GetObject("cut_pm_ps",simcfsi750_cut_pm_ps); 
  
  data_750_file->cd();
  data_750_file->GetObject("cut_pm", data750_cut_pm); 

  ratio_data750->Divide(data750_cut_pm, simcfsi750_cut_pm_ps);
  ratio_data750->SetMarkerStyle(20);
  ratio_data750->SetMarkerColor(kBlue); 


  //simc_cut_pm->Draw();
  //data_cut_pm->Draw("sames");
  TCanvas *c1 = new TCanvas("c1", "", 2000,2000);
  
  ratio_data580->Draw("E1");
  ratio_data750->Draw("E1sames");

  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->SetHeader("D2, Pm = 580/750 MeV/c","C"); // option "C" allows to center the header
  legend->AddEntry(ratio_data580,"Combined: Pm = 580 MeV/c","lep");
  legend->AddEntry(ratio_data750,"Combined: Pm = 750 MeV/c","lep"); 
  legend->Draw();

  TCanvas *c3 = new TCanvas("c3", "", 1500,2000); 
  c3->Divide(2,1);

  c3->cd(1);
  simcfsi580_cut_pm_ps->Draw();
  data580_cut_pm->Draw("sames");

  c3->cd(2);                                                                      
  simcfsi750_cut_pm_ps->Draw();                   
  data750_cut_pm->Draw("sames");
 

}
