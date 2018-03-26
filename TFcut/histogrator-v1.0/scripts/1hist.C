{
	TCanvas *c2 = new TCanvas("c2", "test canvas", 400, 400);
	
	TPad *p2 = new TPad("p2", "TH1C pad", 0.0, 0.0, 1.0, 1.0);
	p2->Draw();
	
	p2->cd();
	TH1F *h2 = new TH1F("h2", "TH1F", 10, -1, 1);	
	h2->SetFillColor(41);
	h2->FillRandom("gaus", 1000);
	h2->Draw("HIST");
	
	c2->Modified();
	c2->Update();
}
