{
	TCanvas *c1 = new TCanvas("c1", "test canvas", 400, 400);
	
	TPad *p1 = new TPad("p1", "TH1C pad", 0.0, 0.0, 1.0, 1.0);
	p1->Draw();
	
	p1->cd();
	TH2F *h1 = new TH2F("h1", "TH2F", 25, -1, 1, 25, -1, 1);	
	h1->SetFillColor(41);
   h1->Draw("CONT");

	for (int i=0; i<5000; i++) {
		h1->Fill(gRandom->Gaus(0,0.5),gRandom->Gaus(0,0.5));
	}

	c1->Modified();
	c1->Update();
}
