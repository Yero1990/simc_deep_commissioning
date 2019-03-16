#ifndef SET_HISTOS_H
#define SET_HISTOS_H

//Header file designed to set global histogram ranges that would apply
//to both simc/data histogram declarations. This way, one makes a single
//configuration of this file, and it will set the histogram ranges of multiple
//files simultaneosuly, if included as a header in that file.

TString hadron_arm="HMS";
TString electron_arm = "SHMS";

// define some constants
static const Double_t pi = 3.141592654;
static const Double_t dtr = pi/180.;
static const Double_t MP = 0.938272; //GeV
static const Double_t MD = 1.87561; //GeV
static const Double_t MN = 0.939566; //GeV
static const Double_t me = 0.00051099;

//Units in GeV, degrees

//=====================================================
// D E F I N E    H I S T O G R A M    B I N N I N G
//=====================================================

Double_t nbins = 30;


//----------Kinematic Quantities---------

//Missing Mass
Double_t MM2_nbins = 100;                                                                     
Double_t MM2_xmin = 0.6;                                                                              
Double_t MM2_xmax = 0.95;  


//Neutron Energy
Double_t En_nbins = nbins;

//Proton Energy
Double_t Ep_nbins = nbins;

//Proton / Neutron Kin Energy
Double_t Kn_nbins = nbins;

Double_t Kp_nbins = nbins;                                        

//Q2
Double_t Q2_nbins = nbins;

//omega (E-E')
Double_t om_nbins = nbins;

//W_inv
Double_t W_nbins = nbins;
Double_t W_xmin = -2;
Double_t W_xmax = 2.;

//theta_elec
Double_t the_nbins = nbins;
Double_t the_xmin = 10.;
Double_t the_xmax = 15.;

//theta_prot
Double_t thp_nbins = nbins;

//-------Additional Kinematic Variables----------

//W2
Double_t W2_nbins = nbins;
Double_t W2_xmin = -2.;
Double_t W2_xmax = 2.;

//xBj
Double_t xbj_nbins = nbins;


//Pf
Double_t Pf_nbins = nbins;

//kf
Double_t kf_nbins = nbins;


//th_q
Double_t thq_nbins = nbins;


//|q| vector magnitude
Double_t q_nbins = nbins;

//th_pq
Double_t thpq_nbins = nbins;


//------Target Reconstruction Variables----------
Double_t xtar_nbins = nbins;
Double_t xtar_xmin = -0.5;
Double_t xtar_xmax = 0.5;

Double_t ytar_nbins = nbins;
Double_t ytar_xmin = -0.5;
Double_t ytar_xmax = 0.5;

Double_t ztar_nbins = nbins;
Double_t ztar_xmin = -10.0;
Double_t ztar_xmax = 10.0;

//Hadron arm Reconstructed Quantities ( xtar, ytar, xptar, yptar, delta)
Double_t hytar_nbins = nbins;
Double_t hytar_xmin = -7.;
Double_t hytar_xmax = 7.;

Double_t hxptar_nbins = nbins;
Double_t hxptar_xmin = -0.1;
Double_t hxptar_xmax = 0.1;

Double_t hyptar_nbins = nbins;
Double_t hyptar_xmin = -0.1;
Double_t hyptar_xmax = 0.1;

Double_t hdelta_nbins = nbins;
Double_t hdelta_xmin = -15.;
Double_t hdelta_xmax = 15.;

//Hadron arm Focal Plane Quantities

//X-focal plane
Double_t hxfp_nbins = nbins;
Double_t hyfp_nbins = nbins;
Double_t hxpfp_nbins = nbins;
Double_t hypfp_nbins = nbins;

Double_t hxfp_xmin = -50.;
Double_t hxfp_xmax = 40.;

Double_t hyfp_xmin = -15.;
Double_t hyfp_xmax = 25.;

Double_t hxpfp_xmin = -0.08;
Double_t hxpfp_xmax = 0.06;

Double_t hypfp_xmin = -0.025;
Double_t hypfp_xmax = 0.03;

//Electron Arm Reconstructed Quantities ( xtar, ytar, xptar, yptar, delta)
Double_t eytar_nbins = nbins;
Double_t eytar_xmin = -2.;
Double_t eytar_xmax = 2.;

Double_t exptar_nbins = nbins;
Double_t exptar_xmin = -0.06;
Double_t exptar_xmax = 0.06;

Double_t eyptar_nbins = nbins;
Double_t eyptar_xmin = -0.03;
Double_t eyptar_xmax = 0.03;


Double_t edelta_nbins = nbins;


//Electron Arm Focal Plane Quantities
Double_t exfp_nbins = nbins;
Double_t eyfp_nbins = nbins;
Double_t expfp_nbins = nbins;
Double_t eypfp_nbins = nbins;



/*
//Pmiss = 80 MeV
//Missing Mass          
Double_t Mm_nbins = 50;                                       
Double_t Mm_xmin = 0.9;    
Double_t Mm_xmax = 0.985;    

//Emiss                                   
Double_t Em_nbins = 80; 
Double_t Em_xmin = -0.1;                           
Double_t Em_xmax = 0.1;  

Double_t Pm_nbins = 60;   //bin width; 10 MeV
Double_t Pm_xmin = -0.1;
Double_t Pm_xmax = 0.5;

Double_t Pmx_nbins = 100.;
Double_t Pmx_xmin = -0.5;                                                                      
Double_t Pmx_xmax = 0.5;   

Double_t Pmy_nbins = 100.;  
Double_t Pmy_xmin = -0.5;                                                                                
Double_t Pmy_xmax = 0.5; 

Double_t Pmz_nbins = 100.;  
Double_t Pmz_xmin = -0.5;                       
Double_t Pmz_xmax = 0.5; 

Double_t exfp_xmin = -15.;
Double_t exfp_xmax = 10.;

Double_t eyfp_xmin = -10.;
Double_t eyfp_xmax = 10.;

Double_t expfp_xmin = -0.04;
Double_t expfp_xmax = 0.04;

Double_t eypfp_xmin = -0.03;
Double_t eypfp_xmax = 0.03;

Double_t edelta_xmin = -6.;
Double_t edelta_xmax = 6.;

Double_t Q2_xmin = 2.5;
Double_t Q2_xmax = 5;

Double_t om_xmin = 1.5;
Double_t om_xmax = 2.7;

//th_pq
Double_t thpq_xmin = -2.0;
Double_t thpq_xmax = 6.0;

Double_t thp_xmin = 34.;
Double_t thp_xmax = 42.;

Double_t kf_xmin = 8;
Double_t kf_xmax = 9;

Double_t Pf_xmin = 2.3;
Double_t Pf_xmax = 3.5;

Double_t thq_xmin = 32.;
Double_t thq_xmax = 42.;

Double_t q_xmin = 2.;
Double_t q_xmax = 4.;

//th_nq                                   
Double_t thnq_nbins = 20;   //10 degree bins             
Double_t thnq_xmin = -10;
Double_t thnq_xmax = 190;

Double_t Ep_xmin = 2.4;        
Double_t Ep_xmax = 3.6; 

Double_t Kn_xmin = -0.005;                                                                                                  
Double_t Kn_xmax = 0.02; 

Double_t Kp_xmin = 1.6;                                    
Double_t Kp_xmax = 2.6;  

Double_t En_xmin = 0.93;   
Double_t En_xmax = 0.96;

Double_t xbj_xmin = 0.5;                                                                
Double_t xbj_xmax = 1.5; 
*/


//Pm = 580
//Missing Mass                                       
Double_t Mm_nbins = 50;                                          
Double_t Mm_xmin = 0.9;    
Double_t Mm_xmax = 0.985;    

//Emiss                                    
Double_t Em_nbins = 80; 
Double_t Em_xmin = -0.1;                       
Double_t Em_xmax = 0.1;  

Double_t Pm_nbins = 40;    //40 MeV bin width  
Double_t Pm_xmin = 0.1;     
Double_t Pm_xmax = 1.5;  

Double_t Pmx_nbins = 40.;  
Double_t Pmx_xmin = -2.;                        
Double_t Pmx_xmax = 2.;   

Double_t Pmy_nbins = 40.;  
Double_t Pmy_xmin = -2.;                        
Double_t Pmy_xmax = 2.; 

Double_t Pmz_nbins = 40.;  
Double_t Pmz_xmin = -2.;                       
Double_t Pmz_xmax = 2.; 

Double_t exfp_xmin = -40.;
Double_t exfp_xmax = 40.;

Double_t eyfp_xmin = -40.;
Double_t eyfp_xmax = 40.;

Double_t expfp_xmin = -0.1;
Double_t expfp_xmax = 0.1;

Double_t eypfp_xmin = -0.1;
Double_t eypfp_xmax = 0.1;

Double_t edelta_xmin = -5.;
Double_t edelta_xmax = 15;

Double_t kf_xmin = 8;
Double_t kf_xmax = 10.;

Double_t Pf_xmin = 1.5;
Double_t Pf_xmax = 2.5;

Double_t Q2_xmin = 2.5;
Double_t Q2_xmax = 5.5;

Double_t om_xmin = 1.;
Double_t om_xmax = 2.5;

Double_t thp_xmin = 50.;
Double_t thp_xmax = 65.;

Double_t thq_xmin = 30.;
Double_t thq_xmax = 55.;

Double_t q_xmin = 2.;
Double_t q_xmax = 3.5;

Double_t thpq_xmin = 0.;
Double_t thpq_xmax = 30.0;

//th_nq [5 deg bins]                           
Double_t thnq_nbins = 16;   
Double_t thnq_xmin = 0;
Double_t thnq_xmax = 80;

Double_t Ep_xmin = 2.;  
Double_t Ep_xmax = 2.8; 

Double_t Kn_xmin = 0;   
Double_t Kn_xmax = 0.8;

Double_t Kp_xmin = 1;                                                                                       
Double_t Kp_xmax = 1.8;  

Double_t En_xmin = 0.;
Double_t En_xmax = 2.;

Double_t xbj_xmin = 0.5;    
Double_t xbj_xmax = 2.0; 


#endif

    
