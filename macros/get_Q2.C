//Code to get Deuteron Electro-Disintegration Kinematics
//for E12-10-003 Experiment in Hall C


void get_Q2() 
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
  E_e = 10.6;         //GeV
  theta_e = 12.1686;
  
  ofstream ofs;
  TString my_file = "deepn_kin.dat"; 

  ofs.open(my_file);     

  ofs << "#! p_miss[f,0]/ " << "  " << " x_bj[f,1]/ " << " " << " w[f,2]/ " << "  E_ep[f,3]/ " << " " << " Ep_f[f,4]/ " << " " << " En_f[f,5]/ " << " " 
      << " P_p[f,6]/ " << " " << " q[f,7]/ " << " " << "    theta_q[f,8]/ " << " Q2[f,9]/ " << " " << "    theta_p[f,10]/ " << " " << " theta_nq[f,11]/ " << " " << " theta_pq[f,12]/ " << endl;
  
       for (p_miss = 0.05; p_miss <= 0.120; p_miss = p_miss + 0.01)
	 {
	 //Loop over scattered electron energy [GeV]
	   for (E_ep =8.40; E_ep < 8.95; E_ep = E_ep + 0.0001)
	     {
	       Q2 = 4. * E_e*E_ep * pow(sin(theta_e/(2*rad2deg)),2);
	       
	       //electron kinematics
	       w = E_e - E_ep;
	       q = sqrt(w*w +Q2);
	       x_bj = Q2/(2.*m_p*w);
	       p_e = sqrt(E_e*E_e - m_e*m_e);     //e- initial momentum
	       p_ep = sqrt(E_ep*E_ep - m_e*m_e);  //e- final momentum
	       E_n = sqrt(m_n*m_n + p_miss*p_miss);
	       p_p = sqrt(pow(w + m_d - E_n,2) - m_p*m_p );
	       
	       E_p = sqrt(m_p*m_p + p_p*p_p);

	       if ( (fabs(p_e*p_e + q*q - p_ep*p_ep) < fabs(2.*p_e*q) ) && (fabs(p_p*p_p + q*q - p_miss*p_miss) < fabs(2.*p_p*q) )  
		    && (fabs(q*q + p_miss*p_miss - p_p*p_p) < fabs(2.*q*p_miss)) && theta_p*rad2deg )
		 {
	       theta_q = acos( (p_e*p_e + q*q - p_ep*p_ep) / (2.*p_e*q) );  //in radians
	       theta_pq = acos((p_p*p_p + q*q - p_miss*p_miss)/(2.*p_p*q));
	       theta_p = theta_q + theta_pq;	
	       //theta_nq = acos( (q*q + p_miss*p_miss - p_p*p_p) / (2.*q*p_miss) ) ;
	       theta_nq = acos( (q - p_p*cos(theta_pq))/ p_miss);

		 }
	       
	       if (w!=0 && theta_p*rad2deg < 70.0) {

		 if (Q2 > 4.249 && Q2 < 4.259 && x_bj > 1.349 && x_bj < 1.351 ) {
		 ofs << p_miss << "                " << x_bj << "      " << w << "    " << E_ep << "       " << E_p << "      " << E_n << "      " << p_p << "     " << q << "      " <<
		   theta_q*rad2deg << "         " << Q2 << "       " << theta_p*rad2deg << "          " << theta_nq*rad2deg << "          " << theta_pq*rad2deg << endl;
		 }

	       }
	     }
	   
	   
	 }
       
}
