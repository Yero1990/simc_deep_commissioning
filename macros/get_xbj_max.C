void get_xbj_max () {
	
	//units: energy: GeV, angle: degree,  set speed of light c = 1.  

//Declare Kinematic Variables (3 different momentum settings will be used -- reason for array in some variables)
double Q_sqrd;           //4-momentum transfer squared
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
double w_max;
double q;                 //3-momentum transfer magnitude
double m_p;                //proton mass
double m_n;
double m_d;
double x_bj;               //B-jorken scale
double x_bj_min;

    //masses
    m_p = 0.938272;
    m_n = 0.939565;
    m_d = 1.875612;

    // INPUT KINEMATICS
    Q_sqrd = 4.25;     
    E_e = 10.6;
//    p_miss = 0.3;

//Calculate maximum energy transfer (threshol x-Bj) to proton 
E_n = sqrt(m_n*m_n + p_miss*p_miss);
////cout << E_n << endl;
//double delta = m_d*m_d - Q_sqrd - 2.*E_n*m_d;
//cout << "delta = " << delta << endl;
//double beta = m_d - E_n;
//cout << "beta = " << beta << endl;

//double A = 4.*(beta*beta - p_miss*p_miss);
//cout << "A = " << A << endl;
//double B = 4.*delta*beta;
//cout << "B = " << B << endl;
//double C = delta*delta -4.*p_miss*p_miss*Q_sqrd;
//cout << "C = " << C << endl;
//cout << sqrt(B*B -4.*A*C) << endl;

//w_max =  (-B + sqrt(B*B -4.*A*C))/(2.*A);
//cout << "w_max = " << w_max << " GeV " << endl;
// x_bj_min = Q_sqrd / (2.*m_p*w_max);
//cout << "x_bj_min = " << x_bj_min << endl;

ofstream ofs;
TString file1 = "d2_xbj_th.dat";
ofs.open(file1);

ofs << "# " << " p_miss " << " w_th " << " x_bj_th " << endl;

 double p_miss_min = 0.1;   //units of GeV
double p_miss_max = 1.0;
double step = 0.01;


	for (p_miss = p_miss_min; p_miss <=p_miss_max; p_miss = p_miss + step) {
				
				E_n = sqrt(m_n*m_n + p_miss*p_miss);
				double delta = m_d*m_d - Q_sqrd - 2.*E_n*m_d;
				double beta = m_d - E_n;
				double A = 4.*(beta*beta - p_miss*p_miss);
				double B = 4.*delta*beta;
				double C = delta*delta -4.*p_miss*p_miss*Q_sqrd;

				
				
				w_max =  (-B - sqrt(B*B -4.*A*C))/(2.*A);
				x_bj_min = Q_sqrd / (2.*m_p*w_max);

		        ofs << p_miss << " " << w_max << " " << x_bj_min << " " << endl;
				
				
				
				
											}
												
//Plot B-jorken x threshold as a function of missing momenta	
	

TCanvas *t1 = new TCanvas("t1", "", 2000,500);
t1->SetGrid();

//TString mygraph = "hdc"+plane_names[ip]+Form("_t_zero_run%d.txt", run);
TGraph *graph1 = new TGraphErrors(file1, "%lg %*lg %lg ");
graph1->SetName("graph1");
TString title1 = "B-Jorken x Scale vs. Neutron Recoil Momenta";
graph1->SetTitle(title1);
graph1->SetMarkerStyle(8);
graph1->SetMarkerColor(1);
graph1->GetXaxis()->SetTitle("Neutron Missing Momenta (Gev/c)");
graph1->GetXaxis()->CenterTitle();
graph1->GetYaxis()->SetTitle("x-Bjorken Upper Limit");
graph1->GetYaxis()->CenterTitle();
graph1->Draw("AP");
t1->Update();
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
