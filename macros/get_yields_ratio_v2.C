//Script to get yield (number of events) for missing momentum and take
//ratio of missing momentum after applying small variations in kinematic 
//variables E_beam, k_f, P_f, theta_e and theta_p
#include <vector>
#include "TMath.h"
#include <iomanip>
#include <iostream>

void get_yields_ratio_v2() 
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

  Double_t pmW_cross_sec;
  Double_t pmW_cross_sec_err;
  

  TH1F *h1 = new TH1F("h1", "", 41, 0, 1.6);
	
  TGraphErrors *graph_fw[3];
  TGraphErrors *graph_w[3];

  TString pmiss[3] = {"0.5", "0.65", "0.8"};
  Double_t beam_hrs[3] = {8.0, 18.0, 36.0};

  ofstream ofile;
  ofstream fw_ofs;
  ofstream w_ofs;
  

  TString file_out = "scaled_yield.dat";
  ofile.open(file_out);
  

    //beam hours: 8(pm=0.5), 18(pm=0.65), 36(0.8)
  
  for (int i = 0;  i < 3; i++) 
    {
  
      f[i]->cd();
      
    

      ofile << "#U.W. Pmiss_"+pmiss[i] << setw(12) << "err" << setw(20) << "W. Pmiss " << setw(15) << " err " << setw(19) << "Full W. Pmiss" << setw(15) << " err " << endl;

      TString fw_sig_out = "fw_cross_sec_"+pmiss[i]+".dat";
      fw_ofs.open(fw_sig_out);


      TString w_sig_out = "w_cross_sec_"+pmiss[i]+".dat";
      w_ofs.open(w_sig_out);

	

      fw_ofs << "#Pmiss: " << pmiss[i] << endl;
      fw_ofs << "#pmiss: " << setw(15) << "#FW Cross Sec" << setw(15) << " err " << endl;


      w_ofs << "#Pmiss: " << pmiss[i] << endl;
      w_ofs << "#pmiss: " << setw(15) << "#W Cross Sec" << setw(15) << " err " << endl;


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

	
	pmW_scale[i]->SetBinContent(bin, binContent_w);
       	pmW_scale[i]->SetBinError(bin, err_w);
       

	//Get Bin Center correcponding to cross section value
	binCenter = pmFW_scale[i]->GetXaxis()->GetBinCenter(bin);
	  
 
	if (binContent_ps!=0 && binContent_fw!=0) {
	   
	  //calculate the cross section for pmiss = 0.5 GeV/c
	  if (i==0 && binCenter>=0.4 && binCenter<=0.7){
	 
	    pmW_cross_sec = binContent_w / binContent_ps ;
	    pmW_cross_sec_err = pmW_cross_sec * (1./sqrt(binContent_fw));
	    w_ofs << binCenter << setw(15) << pmW_cross_sec * 0.0001 << setw(15) << pmW_cross_sec_err * 0.0001 << endl;  //*0.0001 converts microbrarns to fm^{2}, 1ub == 0.0001 fm^{2}

	    

	    pmFW_cross_sec = binContent_fw / binContent_ps ;
	    pmFW_cross_sec_err = pmFW_cross_sec * (1./sqrt(binContent_fw));
	    fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;

	  }

	  //calculate the cross section for pmiss = 0.65 GeV/c
	  if (i==1 && binCenter>=0.585 && binCenter<=0.8125){
	    
	    pmW_cross_sec = binContent_w / binContent_ps ;
	    pmW_cross_sec_err = pmW_cross_sec * (1./sqrt(binContent_fw));
	    w_ofs << binCenter << setw(15) << pmW_cross_sec * 0.0001 << setw(15) << pmW_cross_sec_err * 0.0001 << endl;

	    pmFW_cross_sec = binContent_fw / binContent_ps ;
	    pmFW_cross_sec_err = pmFW_cross_sec * (1./sqrt(binContent_fw));
	    fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;
		
	  }
	  
	  //calculate the cross section for pmiss = 0.8 GeV/c
	  if (i==2 && binCenter>=0.719 && binCenter<=1.0){

	    pmW_cross_sec = binContent_w / binContent_ps ;
	    pmW_cross_sec_err = pmW_cross_sec * (1./sqrt(binContent_fw));
	    w_ofs << binCenter << setw(15) << pmW_cross_sec * 0.0001 << setw(15) << pmW_cross_sec_err * 0.0001 << endl;

	    pmFW_cross_sec = binContent_fw / binContent_ps ;
	    pmFW_cross_sec_err = pmFW_cross_sec * (1./sqrt(binContent_fw));
	    fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;
		
	  }

	}

	
	else {

	  pmW_cross_sec = 0.0;
	  pmW_cross_sec_err = 0.0;
	  w_ofs << binCenter << setw(15) << pmW_cross_sec << setw(15) << pmW_cross_sec_err << endl;

	  pmFW_cross_sec = 0.0;
	  pmFW_cross_sec_err = 0.0;
	fw_ofs << binCenter << setw(15) << pmFW_cross_sec << setw(15) << pmFW_cross_sec_err << endl;

	}


      } // end loop over bins

      w_ofs.close();
      fw_ofs.close();
      
      //Graph the full weighted cross sections
      graph_w[i] = new TGraphErrors(w_sig_out, "%lg %lg %lg");
  
      //Graph the full weighted cross sections
      graph_fw[i] = new TGraphErrors(fw_sig_out, "%lg %lg %lg");
  
  
      
    }

  
  TCanvas *c1 = new TCanvas("c1", "", 800,800);
  c1->SetLogy();
  TMultiGraph *mg = new TMultiGraph();
  graph_fw[0]->SetMarkerStyle(22);
  graph_fw[0]->SetMarkerColor(kBlack);
  graph_fw[0]->SetLineColor(kBlack);
  graph_fw[1]->SetMarkerStyle(20);
  graph_fw[1]->SetMarkerColor(kRed);
  graph_fw[1]->SetLineColor(kRed);
  graph_fw[2]->SetMarkerStyle(21);
  graph_fw[2]->SetMarkerColor(kBlue);
  graph_fw[2]->SetLineColor(kBlue);

  mg->SetTitle("D(e,e'p)n Cross Sections; Missing Momentum (GeV/c); #frac{d#sigma^{5}}{d#omegad#Omega_{e}d#Omega_{p}} (Arb. Units) ");

  mg->Add(graph_fw[0]);
  mg->Add(graph_fw[1]);
  mg->Add(graph_fw[2]);
  mg->Draw("AP");


TCanvas *c2 = new TCanvas("c2", "", 800,800);
  c2->SetLogy();
  TMultiGraph *wmg = new TMultiGraph();
  graph_w[0]->SetMarkerStyle(22);
  graph_w[0]->SetMarkerColor(kBlack);
  graph_w[0]->SetLineColor(kBlack);
  graph_w[1]->SetMarkerStyle(20);
  graph_w[1]->SetMarkerColor(kRed);
  graph_w[1]->SetLineColor(kRed);
  graph_w[2]->SetMarkerStyle(21);
  graph_w[2]->SetMarkerColor(kBlue);
  graph_w[2]->SetLineColor(kBlue);

  wmg->SetTitle("D(e,e'p)n Cross Sections; Missing Momentum (GeV/c); #frac{d#sigma^{5}}{d#omegad#Omega_{e}d#Omega_{p}} (#frac{#mub}{MeV#bulletSr^{2}}) ");


  wmg->Add(graph_w[0]);
  wmg->Add(graph_w[1]);
  wmg->Add(graph_w[2]);
  wmg->Draw("AP");


  ofile.close();

    }
