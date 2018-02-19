void calc_kin()
{

  ofstream ofile;
  ofile.open("low_pmiss.data");
  
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

  Double_t pi = 3.141592654;
  double dtr = pi / 180.;
  
  //masses
  m_p = 0.938272;
  m_n = 0.939565;
  m_d = 1.875612;
  m_e = 0.000511;
  
    // INPUT KINEMATICS
    //Q2 = 4.25;     
    E_e = 10.6;
    theta_e = 12.169*dtr;


    w = 1. / ((1./E_e) + m_p/(2.*E_e*E_e*pow(sin(theta_e/2.),2))); // require x = 1
    Q2 = 2.*m_p*w;
    E_ep = Q2 / (4.*E_e*pow(sin(theta_e/2.),2));
    x_bj = Q2 / (2*m_p*w);

    		
    p_e = sqrt(E_e*E_e - m_e*m_e);    
    p_ep = sqrt(E_ep*E_ep - m_e*m_e);     //E^2 = me^2 + pe^2 ~ pe^2 
    
    //Calculate scattered proton momenta
    q = sqrt(Q2 + w*w);

    cout << "***** Electron Kinematics ******" << endl;
    cout << "Ebeam: " << E_e << " GeV" << endl;
    cout << "e- Momentum: " << p_ep << " GeV" << endl;
    cout << "e- Angle: " << theta_e/dtr << " deg" << endl;
    cout << "xbj " << x_bj << endl;
    cout << "omega: " << w << " GeV" << endl;
    cout << "Q2: " << Q2 << " GeV2" << endl;
    
     for (p_miss = 0.08; p_miss <0.1; p_miss = p_miss + 0.001)
      {
	//loop over pmiss
	//for(pmiss = 0.07; pmiss<0.120; pmiss = pmiss + 0.001)
	
	E_n = sqrt(m_n*m_n + p_miss*p_miss);
	E_p = w + m_d - E_n;
	p_p = sqrt(E_p*E_p - m_p*m_p);

	
	
	if ( (fabs(p_e*p_e + q*q - p_ep*p_ep) < fabs(2.*p_e*q) ) && (fabs(p_p*p_p + q*q - p_miss*p_miss) < fabs(2.*p_p*q) )  
	     && (fabs(q*q + p_miss*p_miss - p_p*p_p) < fabs(2.*q*p_miss)))
	  {
	    
	    //Calculate theta_q
	    theta_q = acos((p_e*p_e + q*q - p_ep*p_ep) / (2.*p_e*q));
	    //    cout << "theta_q = " << theta_q*rad2deg << endl;  
	    
	    //Calculate theta_pq
	    theta_pq = acos((p_p*p_p + q*q - p_miss*p_miss)/(2.*p_p*q));
	    //cout << "theta_pq = " << theta_pq*rad2deg << endl;
	    //Calculate theta_nq
	    //theta_nq = acos( (q*q + p_miss*p_miss - p_p*p_p) / (2.*q*p_miss) ) ;
	    theta_nq = acos((q - p_p*cos(theta_pq))/p_miss);
	    //cout << "theta_nq = " << theta_nq*rad2deg << endl;
	    
	    //Calculate theta_p
	    theta_p = theta_q + theta_pq;	
	    //cout << "theta_p = " << theta_p*rad2deg << endl;
	  
	    
	  
	    ofile << "++++Pmiss++++++: " << p_miss << endl; 
	    ofile << "***** Electron Kinematics ******" << endl;
	    ofile << "Ebeam: " << E_e << " GeV" << endl;
	    ofile << "e- Momentum: " << p_ep << " GeV" << endl;
	    ofile << "e- Angle: " << theta_e/dtr << " deg" << endl;
	    ofile << "xbj " << x_bj << endl;
	    ofile << "omega: " << w << " GeV" << endl;
	    ofile << "Q2: " << Q2 << " GeV2" << endl;
	    ofile << "|q|: " << q << " GeV" << endl;
	    
	    ofile << "***** Proton Kinematics" << endl;
	    ofile << "Proton Momentum: " << p_p << " GeV" << endl;
	    ofile << "p Angle: " << theta_p/dtr << " deg" << endl;
	    ofile << "theta_pq: " << theta_pq/dtr << endl;
	    ofile << "theta_q: " << theta_q/dtr << endl;
	    
	    ofile << "***Neutron Kinematics: " << endl;
	    ofile << "theta_nq: " << theta_nq/dtr << endl;
	  }

      }
     
	    

}

//}  //end loop over missing momentum

