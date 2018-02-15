{

  //CHARGE factor
    //Charge factor is the total integrated charge assuming a beam current and run time
  //Double_t Ib = 65;       //beam current in microamps (micro-Coulombs / sec),   1 mC = 1000 uC
   Double_t run_time;     //estimated time (in hours) a run takes (start - end) of run
   // Double_t charge_factor = Ib * time * 3600. / 1000.;

   //Coin. Run 1866
   Double_t Q_bcm1 = 2876.8;  //uC
   Double_t Q_bcm2 = 2927.310;
   Double_t Q_avg = (Q_bcm1 + Q_bcm2) / 2.;
   
   Double_t charge_factor = Q_avg / 1000.;   //in mC
  
   cout << "Total Charge: " << Q_avg << endl;
   cout << "Charge Factor: " << charge_factor << endl;

   //  fullweight = Normfac*Weight*2.90206/50000.
   //  SNT->Draw("e_delta:e_yptar>>(60, -0.04,0.04, 100, -20, 10)", "", "colz");
   SNT->Draw("e_delta>>(100, -20, 10)");


  
}
