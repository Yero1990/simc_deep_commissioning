//Script to get yield (number of events) for missing momentum and take
//ratio of missing momentum after applying small variations in kinematic 
//variables E_beam, k_f, P_f, theta_e and theta_p
#include <vector>
#include "TMath.h"
#include <iomanip>
#include <iostream>

void get_yields_ratio() 
{
  
  //Open root file    
  TFile *f[3];
  
  f[0] = new TFile("simc_results_comm_10.6_1250.root", "READ");
  f[1] = new TFile("simc_results_comm_10.6_1265.root", "READ");
  f[2] = new TFile("simc_results_comm_10.6_1280.root", "READ");

  TH1F *pm[3];       //uXnweighted missing momentum
  TH1F *pmFW[3];     //FUll weighted
  TH1F *pmW[3];      //Weighted
 
  TH1F *pm_scale[3];       //unweighted (phase space) missing momentum
  TH1F *pmFW_scale[3];     //FUll weighted
  TH1F *pmW_scale[3];      //Weighted
 
  Int_t binContent_ps;  //phase space
  Double_t binContent_w;   //weight
  Double_t binContent_fw;   //full weight

  Double_t binCenter;

 
  Double_t err_ps;  //phase space
  Double_t err_w;   //weight
  Double_t err_fw;   //full weight
  
  Double_t pmFW_cross_sec;
  Double_t pmFW_cross_sec_err;

  TH1F *h1 = new TH1F("h1", "", 41, 0, 1.6);
	
  TGraphErrors *graph_fw[3];

  TString pmiss[3] = {"0.5", "0.65", "0.8"};
  Double_t beam_hrs[3] = {8.0, 18.0, 36.0};

  ofstream ofile;
  ofstream fw_ofs;
  

  TString file_out = "scaled_yield.dat";
  ofile.open(file_out);
  

    //beam hours: 8(pm=0.5), 18(pm=0.65), 36(0.8)
  
  for (int i = 0;  i < 3; i++) 
    {
  
      f[i]->cd();
      
    

      ofile << "#U.W. Pmiss_"+pmiss[i] << setw(12) << "err" << setw(20) << "W. Pmiss " << setw(15) << " err " << setw(19) << "Full W. Pmiss" << setw(15) << " err " << endl;

      TString fw_sig_out = "fw_cross_sec_"+pmiss[i]+".dat";
      fw_ofs.open(fw_sig_out);
	
      //      cout << fw_sig_out << endl;

      fw_ofs << "#Pmiss: " << pmiss[i] << endl;
      fw_ofs << "#pmiss: " << setw(15) << "#FW Cross Sec" << setw(15) << " err " << endl;



      // Get histograms from root file
      pm[i] = (TH1F*)f[i]->Get("cpm_ps");
      pmFW[i] = (TH1F*)f[i]->Get("cpm");
      pmW[i] = (TH1F*)f[i]->Get("cpm_sig");

      pm_scale[i] = (TH1F*)(pm[i]->Clone());
      pmFW_scale[i] = (TH1F*)(pmFW[i]->Clone());
      pmW_scale[i] = (TH1F*)(pmW[i]->Clone());

      //Loop over all bins
      for(int bin=0; bin<41; bin++ ) {
	
	binContent_ps = pm_scale[i]->GetBinContent(bin);
	binContent_w = pmW_scale[i]->GetBinContent(bin);
	binContent_fw = pmFW_scale[i]->GetBinContent(bin);
	
	//pmW_scale[i]->Draw();

	err_ps = pm_scale[i]->GetBinError(bin);
	err_w = pmW_scale[i]->GetBinError(bin);
	err_fw = pmFW_scale[i]->GetBinError(bin);

	
	//scale the bin content and its error by beam time (hrs)
	binContent_ps = binContent_ps * beam_hrs[i];
	binContent_w = binContent_w * beam_hrs[i];
	binContent_fw = binContent_fw * beam_hrs[i];

	//the error of a weighted bin content is: sqrt(sum_{i} weight_i**2), scaling the bin content by 'scale', the bin error is: sqrt(sum_{i} weight_i**2 * scale**2) 

	//scale the bin content weighted errors by the beam time (scale factor)
	err_ps = err_ps * beam_hrs[i];
	err_w = err_w * beam_hrs[i];
	err_fw = err_fw * beam_hrs[i];
	
	ofile << binContent_ps << setw(25) << err_ps << setw(15) << setprecision(6) << binContent_w << setw(19) << err_w << setw(15) << binContent_fw << setw(19) << err_fw << endl;

	pmFW_scale[i]->SetBinContent(bin, binContent_fw);
       	pmFW_scale[i]->SetBinError(bin, err_fw);
       
	//Get Bin Center correcponding to cross section value
	binCenter = pmFW_scale[i]->GetXaxis()->GetBinCenter(bin);
	  
 
	if (binContent_ps!=0 && binContent_fw!=0) {

	  if (i==0 && binCenter>=0.4 && binCenter<=0.7){
	     //calculate the cross section
	  pmFW_cross_sec = binContent_fw / binContent_ps ;
	  pmFW_cross_sec_err = pmFW_cross_sec * (1./sqrt(binContent_fw));
	  fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;

	  }
	  if (i==1 && binCenter>=0.585 && binCenter<=0.8125){
	    //calculate the cross section
	    pmFW_cross_sec = binContent_fw / binContent_ps ;
	    pmFW_cross_sec_err = pmFW_cross_sec * (1./sqrt(binContent_fw));
	    fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;
		
	  }
	  if (i==2 && binCenter>=0.719 && binCenter<=1.0){
	    //calculate the cross section
	    pmFW_cross_sec = binContent_fw / binContent_ps ;
	    pmFW_cross_sec_err = pmFW_cross_sec * (1./sqrt(binContent_fw));
	    fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;
		
	  }

	}

	
	else {
	  pmFW_cross_sec = 0.0;
	  pmFW_cross_sec_err = 0.0;
	fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;

	}


      } // end loop over bins
   
      fw_ofs.close();
      
      //Graph the weighted cross sections
      graph_fw[i] = new TGraphErrors(fw_sig_out, "%lg %lg %lg");
  
  
      
    }

  
  TCanvas *c1 = new TCanvas("c1", "", 800,800);
  c1->SetLogy();
  TMultiGraph *mg = new TMultiGraph();
  graph_fw[0]->SetMarkerStyle(22);
  graph_fw[0]->SetMarkerColor(kBlack);
  graph_fw[1]->SetMarkerStyle(20);
  graph_fw[1]->SetMarkerColor(kRed);
  graph_fw[2]->SetMarkerStyle(21);
  graph_fw[2]->SetMarkerColor(kBlue);
  

  mg->Add(graph_fw[0]);
  mg->Add(graph_fw[1]);
  mg->Add(graph_fw[2]);
  mg->Draw("AP");



  //  pmFW_scale[0]->Draw();
  // pmFW_scale[1]->Draw("same");
  //pmFW_scale[2]->Draw("same");
      


  ofile.close();

  //pmFW_scale[0]->Draw();
  //pmFW[0]->Draw("same");
 
  //pmFW_scale[1]->SetLineColor()
  //pmFW_scale[2]->Draw("same");
  
  
  //TFile *myfile = new TFile("yield_ratios.root", "RECREATE");
  //myfile->cd();

  //	TH1F *h1 = new TH1F("h1", "", 60, 0.0,1.6);
  //	hcpy[0]->SetTitle("Missing Momentum Yield, P_{m} = 0.08 GeV");
  //	hcpy[0]->GetXaxis()->SetTitle("Missing Momentum P_{miss} (GeV/c)");
  //	hcpy[0]->GetYaxis()->SetTitle("Counts / 39 MeV");
  //	hcpy[0]->Draw();
	//h1->Draw(hcpy[0]);
 /*
   hcpy[0]->Divide(hcpy[1]);
   hcpy[0]->SetTitle("Relative Yield for Variation #deltaE_{beam}");
   hcpy[0]->GetXaxis()->SetTitle("Missing Momentum P_{miss} (GeV/c)");   
   hcpy[0]->GetXaxis()->CenterTitle();
   hcpy[0]->GetYaxis()->SetTitle("Relative Counts / 39 MeV");   
   hcpy[0]->GetYaxis()->CenterTitle();
   hcpy[0]->Draw();
   myfile->Append(hcpy[0]);
   hcpy[0]->SetName("pm_" + pm + "_delta_E");
   myfile->Write();
   hcpy[0]->Multiply(hcpy[1]);
   
   hcpy[2]->Divide(hcpy[0]);
   hcpy[2]->SetTitle("Relative Yield for Variation #delta k_{f}");
   hcpy[2]->GetXaxis()->SetTitle("Missing Momentum P_{miss} (GeV/c)");   
   hcpy[2]->GetXaxis()->CenterTitle();
   hcpy[2]->GetYaxis()->SetTitle("Relative Counts / 39 MeV");   
   hcpy[2]->GetYaxis()->CenterTitle();
   hcpy[2]->Draw();
   myfile->Append(hcpy[2]);
   hcpy[2]->SetName("pm_" + pm + "_delta_kf");
   myfile->Write();
   hcpy[2]->Multiply(hcpy[0]);
   
   hcpy[0]->Divide(hcpy[3]);
   hcpy[0]->SetTitle("Relative Yield for Variation #delta P_{f}");
   hcpy[0]->GetXaxis()->SetTitle("Missing Momentum P_{miss} (GeV/c)");   
   hcpy[0]->GetXaxis()->CenterTitle();
   hcpy[0]->GetYaxis()->SetTitle("Relative Counts / 39 MeV");   
   hcpy[0]->GetYaxis()->CenterTitle();   
   hcpy[0]->Draw();
   myfile->Append(hcpy[0]);
   hcpy[0]->SetName("pm_" + pm + "_delta_Pf");
   myfile->Write();
   hcpy[0]->Multiply(hcpy[3]);
   hcpy[0]->Divide(hcpy[4]);
   hcpy[0]->SetTitle("Relative Yield for Variation #delta#theta_{e}");   
   hcpy[0]->GetXaxis()->SetTitle("Missing Momentum P_{miss} (GeV/c)");   
   hcpy[0]->GetXaxis()->CenterTitle();
   hcpy[0]->GetYaxis()->SetTitle("Relative Counts / 39 MeV");   
   hcpy[0]->GetYaxis()->CenterTitle();   
   hcpy[0]->Draw();
   myfile->Append(hcpy[0]);
   hcpy[0]->SetName("pm_" + pm + "_delta_theta_e");
   myfile->Write();
   hcpy[0]->Multiply(hcpy[4]);
   
   hcpy[5]->Divide(hcpy[0]);
   hcpy[5]->SetTitle("Relative Yield for Variation #delta#theta_{p}");   
   hcpy[5]->GetXaxis()->SetTitle("Missing Momentum P_{miss} (GeV/c)");   
   hcpy[5]->GetXaxis()->CenterTitle();
   hcpy[5]->GetYaxis()->SetTitle("Relative Counts / 39 MeV");   
   hcpy[5]->GetYaxis()->CenterTitle();   
   hcpy[5]->Draw();
   myfile->Append(hcpy[5]);
   hcpy[5]->SetName("pm_" + pm + "_delta_theta_p");
   myfile->Write();
   hcpy[5]->Multiply(hcpy[0]);
*/
    
    }
