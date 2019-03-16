//Code to get preliminary cross setions from data / simc

#include "../simc_analysis/set_deep_histos.h"
void get_xsec()
{

  gStyle->SetOptStat(kFALSE);

  TString simc_filename = "../simc_analysis/D2simc_pm80_lagetfsi_rad.root";
  TString data_filename = "../data_analysis/D2data_pm80_3289.root";

  TFile *simc_file = new TFile(simc_filename);
  TFile *data_file = new TFile(data_filename);           
  
  //Create Histograms to store objects 
  TH1F *simc_cut_pm = 0;
  TH1F *simc_cut_pm_ps = 0;

  TH1F *data_cut_pm = 0;   

  TH1F *ratio_simc = new TH1F("ratio_simc", "", Pm_nbins, Pm_xmin, Pm_xmax);
  TH1F *ratio_data = new TH1F("ratio_data", "", Pm_nbins, Pm_xmin, Pm_xmax);  

  simc_file->cd();
  simc_file->GetObject("cut_pm", simc_cut_pm);
  simc_file->GetObject("cut_pm_ps", simc_cut_pm_ps); 
  
  data_file->cd();
  data_file->GetObject("cut_pm", data_cut_pm); 

  ratio_simc->Divide(simc_cut_pm, simc_cut_pm_ps);
  ratio_data->Divide(data_cut_pm, simc_cut_pm_ps); 

  ratio_simc->SetMarkerStyle(20);
  ratio_simc->SetMarkerColor(kRed); 

  ratio_data->SetMarkerStyle(20);                                                                                                
  ratio_data->SetMarkerColor(kBlue); 

  //simc_cut_pm->Draw();
  //data_cut_pm->Draw("sames");
    ratio_simc->Draw("E1");
    ratio_data->Draw("E1sames");

    auto legend = new TLegend(0.1,0.7,0.48,0.9);
    legend->SetHeader("D2, Pm = 80 MeV","C"); // option "C" allows to center the header
    legend->AddEntry(ratio_simc,"SIMC","lep");
    legend->AddEntry(ratio_data,"DATA","lep"); 
    legend->Draw();

}
