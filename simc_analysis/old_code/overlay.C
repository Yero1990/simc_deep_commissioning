void overlay()
{

  //Define file naming system
  TString prefix = Form("weighted_d2_pm80");
  TString model1 = "_lagetpwia_rad";
  TString model2 = "_lagetfsi_rad";
  TString ext = ".root";

  //Defile filenames
  TString file1 = prefix + model1 + ext;
  TString file2 = prefix + model2 + ext;

  //Open root files
  TFile *f1 = new TFile(file1, "READ");
  TFile *f2 = new TFile(file2, "READ");


  //Define Histos for file1
  TH1F* Em1 = 0;
  TH1F* pm1 = 0;
  TH1F* cpm1 = 0;
  
  
  //Define Histos for file2
  TH1F* Em2 = 0;
  TH1F* pm2 = 0;
  TH1F* cpm2 = 0;


  //change to file1
  f1->cd();

  //Get objects from file1
  f1->GetObject("pm", pm1);
  f1->GetObject("cut_pm", cpm1);
  f1->GetObject("Em", Em1);


   //change to file2
  f2->cd();

  //Get Objects from file2
  f2->GetObject("pm", pm2);
  f2->GetObject("cpm", cpm2);
  f2->GetObject("Em", Em2);


  
  //Compare  Histograms with/without cuts 
  pm1->Draw("hist");
  cpm1->Draw("hist sames");

}
