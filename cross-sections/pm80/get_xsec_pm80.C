//Code to get preliminary cross setions from data / simc

#include "../../simc_analysis/set_deep_histos.h"
void get_xsec_pm80()
{


  gStyle->SetOptStat(kFALSE);

  TString simc_fsi80 = "../../data_analysis/pm80/Weighted/D2simc_pm80_lagetfsi_rad_set0.root";       
  TString simc_pwia80 = "../../data_analysis/pm80/Weighted/D2simc_pm80_lagetpwia_rad_set0.root"; 

  TString data_pm80 = "../../data_analysis/pm80/Weighted/D2data_pm80_set0.root";
  

  TFile *simc_fsi80_file = new TFile(simc_fsi80); 
  TFile *simc_pwia80_file = new TFile(simc_pwia80); 

  TFile *data_pm80_file = new TFile(data_pm80);              

  //Create Histograms to store objects 
  TH1F *simcfsi80_cut_pm = 0;                                                              
  TH1F *simcpwia80_cut_pm = 0; 
  TH1F *simcpwia80_cut_pm_ps = 0;
  TH1F *simcfsi80_cut_pm_ps = 0; 
  TH1F *data80_cut_pm = 0;   

  //DATA/SIMC Ratio for 80 MeV
  TH1F *ratio_pwia = new TH1F("ratio_pwia", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *ratio_fsi = new TH1F("ratio_fsi", "", Pm_nbins, Pm_xmin, Pm_xmax); 
  
  //-----------------


  ratio_pwia->GetXaxis()->SetTitle("Missing Momentum, Pm [GeV/c]");
  ratio_pwia->GetXaxis()->CenterTitle();

  ratio_pwia->GetYaxis()->SetTitle("Data / SIMC Yield Ratio Pm^{data} / Pm^{simc} "); 
  ratio_pwia->GetYaxis()->CenterTitle();  
  
  ratio_pwia->SetTitle("DATA / SIMC Yield Ratio");



  //------Get Histograms---------
  

  simc_fsi80_file->cd();
  simc_fsi80_file->GetObject("cut_pm", simcfsi80_cut_pm);
  simc_fsi80_file->GetObject("cut_pm_ps",simcfsi80_cut_pm_ps); 

  simc_pwia80_file->cd();                                                 
  simc_pwia80_file->GetObject("cut_pm", simcpwia80_cut_pm);                                                
  simc_pwia80_file->GetObject("cut_pm_ps",simcpwia80_cut_pm_ps);       

  data_pm80_file->cd();
  data_pm80_file->GetObject("cut_pm", data80_cut_pm); 

  ratio_pwia->Divide(data80_cut_pm, simcpwia80_cut_pm);
  ratio_fsi->Divide(data80_cut_pm, simcfsi80_cut_pm); 

 

  ratio_pwia->SetMarkerStyle(20);
  ratio_pwia->SetMarkerColor(kRed); 
  ratio_fsi->SetMarkerStyle(20);
  ratio_fsi->SetMarkerColor(kBlue); 

  /*
  // Pm = 750 MeV

  simc_fsi750_file->cd();
  simc_fsi750_file->GetObject("cut_pm", simcfsi750_cut_pm);
  simc_fsi750_file->GetObject("cut_pm_ps",simcfsi750_cut_pm_ps); 
  
  data_750_file->cd();
  data_750_file->GetObject("cut_pm", data750_cut_pm); 

  ratio_data750->Divide(data750_cut_pm, simcfsi750_cut_pm_ps);
  ratio_data750->SetMarkerStyle(20);
  ratio_data750->SetMarkerColor(kBlue); 
  */

  //simc_cut_pm->Draw();
  //data_cut_pm->Draw("sames");
  TCanvas *c1 = new TCanvas("c1", "", 2000,2000);
  
  ratio_pwia->Draw("E1");
  ratio_fsi->Draw("E1sames");

  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->SetHeader("D2, Pm = 80 MeV/c","C"); // option "C" allows to center the header
  legend->AddEntry(ratio_fsi,"FSI","lep");
  legend->AddEntry(ratio_pwia,"PWIA","lep"); 
  legend->Draw();

  
  TCanvas *c2 = new TCanvas("c2", "", 2000,2000); 
  //ratio_pwia->GetXaxis()->SetRangeUser(0, 0.2);
  //ratio_fsi->GetXaxis()->SetRangeUser(0, 0.2); 
  ratio_pwia->Draw("E1");                                                                                                    
  ratio_fsi->Draw("E1sames");                                                                                                
                                                                                                                           
  auto legend2 = new TLegend(0.1,0.7,0.48,0.9);                                                                                             
  legend2->SetHeader("D2, Pm = 80 MeV/c","C"); // option "C" allows to center the header                                           
  legend2->AddEntry(ratio_fsi,"FSI","lep");                                                                                       
  legend2->AddEntry(ratio_pwia,"PWIA","lep");                                                                        
  legend2->Draw();    

}
