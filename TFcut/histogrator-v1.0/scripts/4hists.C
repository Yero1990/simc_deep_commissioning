{
	TCanvas *c1 = new TCanvas("c1", "test canvas", 800, 800);
	
	TPad *p1 = new TPad("p1", "TH1C pad", 0.0, 0.5, 0.5, 1.0);
	p1->Draw();
	TPad *p2 = new TPad("p2", "TH1D pad", 0.5, 0.5, 1.0, 1.0);
	p2->Draw();
	TPad *p3 = new TPad("p3", "TH1F pad", 0.0, 0.0, 0.5, 0.5);
	p3->Draw();
	TPad *p4 = new TPad("p4", "TH1S pad", 0.5, 0.0, 1.0, 0.5);
	p4->Draw();
	
	p1->cd();
	TH1C *h1 = new TH1C("h1", "TH1C", 25, -1, 1);	
	h1->SetFillColor(41);
	h1->FillRandom("gaus", 1000);
	h1->Draw();
	
	p2->cd();
	TH1D *h2 = new TH1D("h2", "TH1D", 25, -1, 1);	
	h2->SetFillColor(40);
	h2->FillRandom("gaus", 1000);
	h2->Draw();
	
	p3->cd();
	TH1F *h3 = new TH1F("h3", "TH1F", 25, -1, 1);	
	h3->SetFillColor(16);
	h3->FillRandom("gaus", 1000);
	h3->Draw();
	
	p4->cd();
	TH1S *h4 = new TH1S("h4", "TH1S", 25, -1, 1);	
	h4->SetFillColor(42);
	h4->FillRandom("gaus", 1000);
	h4->Draw();
	
	c1->Modified();
	c1->Update();
}
