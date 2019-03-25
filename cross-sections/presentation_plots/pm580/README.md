**********************
 DATA/SIMC Comparison
**********************

Brief: The SIMC/DATA comparison for the 80 MeV setting looked OK. For
the higher missing momentum settings however, some of the kinematic
distributions shape in the data looked defficient as compared to simc in 
some regions. Also, the missing momentum components did NOT match well.
It was found that the SHMS DC calibration was not OK, so that needed to be
checked.

To address these issues, the following will be checked for the 580/750 MeV:

** Check the reference time / time window cuts

** Check the calibrations.

** Look at DATA/SIMC with NO CUTS. Then with a Emiss cut, etc. Try to figure
   out if any of the cuts is causing the shapes to get worse.


To address the Missing Momentum components:

--->We compared the components in the lab frame:
** The data/simc:   Pmx_recoil_data = -Pmy_simc  (These do NOT agree.)
       		    Pmy_recoil_data = Pmx_simc  (These seem to agree.)
		    Pmz_recoil_data = Pmz_simc  (@580, data was centerd at 580 MeV
		    		      		  which would indicate tha most Pmiss
						  is going along +z. )


---> The Missing Momentum components should be compared in the
     q-vector ref. frame.  With Pm_z along q (Parallel)   
     	      	   	        Pm_x         (Perpendicular)	
				Pm_y	     (Out of Plane Oop)