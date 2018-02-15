//Code to get Deuteron Electro-Disintegration Kinematics
//for E12-10-003 Experiment in Hall C


void get_deuteron_kinematics() 
{
  
  double rad2deg = 180./3.14159265359;
  
  //units: energy: GeV, angle: degree,  set speed of light c = 1.  

  //Declare Kinematic Variables (3 different momentum settings will be used -- reason for array in some variables)
  double Q2;           //4-momentum transfer squared
  double E_e;               //INITIAL e- beam energy
  double E_ep;              //SCATTERED e- beam energy
  double E_p;                //proton energy
  double E_n;                //neutron energy
  double p_e;               //initial e- 3-momentum magnitude
  double p_ep;              //scattered e- 3-momentum magnitude 
  double p_p;               //proton momentum magnitude
  double p_miss;          //missing momentum magnitude
  double theta_e;           //e- scattering angle
  double theta_p;           //proton scattering angle
  double theta_nq;          //neutron angle relative to virtual photon 3-vec q
  double theta_pq;           //proton angle relative to virtual photon 3-vec q
  double theta_q;
  double w;                 //energy transfer
  double q;                 //3-momentum transfer magnitude
  double m_p;                //proton mass
  double m_n;
  double m_d;
  double x_bj;               //B-jorken scale
  double m_e;
  //masses
  m_p = 0.938272;
  m_n = 0.939565;
  m_d = 1.875612;
  m_e = 0.000511;
  
    // INPUT KINEMATICS
    Q2 = 4.25;     
    E_e = 10.6;
    //x_bj = 1.35;
    //p_miss = 0.5;

    //Create file string names
    TString Q_sqrd = "4.25_";
    TString beamE = "10.60";
     
    ofstream ofs;
    TString my_file = "d2_kinematics_0.5to0.8_" + Q_sqrd +  beamE + ".dat"; 
    ofs.open(my_file);     
    ofs << "#! p_miss[f,0]/ " << " " << " x_bj[f,1]/ " << " " << " w[f,2]/ " << " Ee_f[f,3]/ " << " " << " Ep_f[f,4]/ " << " " << " En_f[f,5]/ " << " " 
	<< " P_p[f,6]/ " << " " << " q[f,7]/ " << " " << " theta_q[f,8]/ " << " theta_e[f,9]/ " << " " << " theta_p[f,10]/ " << " " << " theta_nq[f,11]/ " << " " << " theta_pq[f,12]/ " << "    " << " Q_sqrd[f,13] " << endl;

    //for (Q2 = 4.245; Q2 < 4.251; Q2 = Q2 + 0.01)
    
//LOOP OVER Missing Momentum
    for (p_miss = 0.5;  p_miss<=0.80; p_miss = p_miss+0.15)
      {
	
	//LOOP X-Bjorken
	for (x_bj = 1.2; x_bj <= 1.4; x_bj = x_bj + 0.001)
	  
	{
	
	    //Calculate electron scattering angle
	    w = Q2 / (2. * x_bj * m_p);
	    
	    //	cout << "p_miss = " << p_miss << endl;
	    //	cout << "w = " << w << endl;
	    //	cout << "x_bj = " << x_bj << endl;
	    
	    E_ep = E_e - w;                        //scattered e- energy
	    //	cout << "E_ep = " << E_ep << endl;
	    
		theta_e = 2. * asin( sqrt(Q2/(4.*E_e*E_ep) ) );
		//	cout << "theta_e = " << theta_e*rad2deg << endl;
		
		p_e = sqrt(E_e*E_e - m_e*m_e);
		//	cout << "p_e = " << p_e << endl;
		
		p_ep = sqrt(E_ep*E_ep - m_e*m_e);     //E^2 = me^2 + pe^2 ~ pe^2 
		//	cout << "p_ep = " << p_ep << endl;
		


	//Calculate scattered proton momenta
	q = sqrt(Q2 + w*w);
	E_n = sqrt(m_n*m_n + p_miss*p_miss);
	E_p = w + m_d - E_n;
	p_p = sqrt(E_p*E_p - m_p*m_p);


	
	     if ( (fabs(p_e*p_e + q*q - p_ep*p_ep) < fabs(2.*p_e*q) ) && (fabs(p_p*p_p + q*q - p_miss*p_miss) < fabs(2.*p_p*q) )  
			&& (fabs(q*q + p_miss*p_miss - p_p*p_p) < fabs(2.*q*p_miss)) )
						{
					
						
						//Calculate theta_q
						theta_q = acos((p_e*p_e + q*q - p_ep*p_ep) / (2.*p_e*q));
						//    cout << "theta_q = " << theta_q*rad2deg << endl;  
	
						//Calculate theta_pq
						theta_pq = acos((p_p*p_p + q*q - p_miss*p_miss)/(2.*p_p*q));
						//cout << "theta_pq = " << theta_pq*rad2deg << endl;
						//Calculate theta_nq
						theta_nq = acos( (q*q + p_miss*p_miss - p_p*p_p) / (2.*q*p_miss) ) ;
						//cout << "theta_nq = " << theta_nq*rad2deg << endl;

						//Calculate theta_p
						theta_p = theta_q + theta_pq;	
						//cout << "theta_p = " << theta_p*rad2deg << endl;
					
						
						ofs << p_miss  << "     " <<  x_bj  << "    " <<  w  << "    " << E_ep  << "    " << E_p << "    " << E_n << "   " << p_p << "    " << q << "    " << theta_q*rad2deg << "    " << theta_e*rad2deg  << "    " << theta_p*rad2deg << "    " << theta_nq*rad2deg << "    " << theta_pq*rad2deg << "    " << Q2 <<  endl;

	
	/*
						ofs << "              USER INPUT: p_miss = "  << p_miss << " GeV " << endl;
						ofs << "**************************************************" << endl;
						ofs << "Q^2 = " << Q2 << " GeV " << endl;
						ofs << "Electron Energy E = " << E_e << " GeV " << endl;
						ofs << "x-Bjorken = " << x_bj << endl;
						ofs << "neutron missing momentum = " << p_miss << " GeV " << endl;
	
						ofs << "             KINEMATIC SETTINGS fot p_miss = " <<  p_miss << endl; 
						ofs << "                                            " << endl;
						ofs << "e- scattering angle = " <<theta_e*rad2deg << " degrees " << endl;
						ofs << "energy transfer w = " << w << " GeV " << endl;
						ofs << "3-momentum transfer q = " << q << " GeV" << endl;
						ofs << "e- scattered energy = " << E_ep << " GeV " << endl;
						ofs << "proton scattered momentum = " << p_p << " GeV/c" << endl;
						ofs << "photon scattering angle theta_q = " << theta_q * rad2deg << " degrees " << endl;
						ofs << "proton scattering angle theta_pq = " << theta_pq * rad2deg << " degrees " << endl;
						ofs << "neutron scattering angle theta_nq = " << theta_nq * rad2deg << " degrees " << endl;
						ofs << "proton scattering angle theta_p = " << theta_p * rad2deg << " degrees " << endl;
						ofs << "**************************************************" << endl;
		*/			
						
						}

						else (cout << "Non-Sense" << endl);
	}
	
      }


//Plot kinematic variables as a function of missing momenta	
/*	
TCanvas *t1 = new TCanvas("t1", "", 2000,500);
t1->SetGrid();

TGraph *graph1 = new TGraphErrors(my_file, "%*lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg %*lg ");
graph1->SetName("graph1");
TString title1 = "B-Jorken x Scale vs. Neutron Recoil Momenta";
graph1->SetTitle(title1);
graph1->SetMarkerStyle(8);
graph1->SetMarkerColor(1);
graph1->GetXaxis()->SetTitle("Neutron Missing Momenta (Gev/c)");
graph1->GetXaxis()->CenterTitle();
graph1->GetYaxis()->SetTitle("x-Bjorken");
graph1->GetYaxis()->CenterTitle();
graph1->Draw("AP");
t1->Update();
*/	
}


