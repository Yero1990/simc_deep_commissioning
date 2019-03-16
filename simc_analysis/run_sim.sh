#!/bin/bash


CMD1="root -l -q \"D2_simc.C(1,580, \\\"fsi\\\",\\\"rad\\\")\" "
CMD2="root -l -q \"D2_simc.C(1,580, \\\"pwia\\\",\\\"rad\\\")\" " 

CMD3="root -l -q \"D2_simc.C(2,580, \\\"fsi\\\",\\\"rad\\\")\" "    
CMD4="root -l -q \"D2_simc.C(2,580, \\\"pwia\\\",\\\"rad\\\")\" "

CMD5="root -l -q \"D2_simc.C(1,750, \\\"fsi\\\",\\\"rad\\\")\" "    
CMD6="root -l -q \"D2_simc.C(1,750, \\\"pwia\\\",\\\"rad\\\")\" " 
                                                        
CMD7="root -l -q \"D2_simc.C(2,750, \\\"fsi\\\",\\\"rad\\\")\" "      
CMD8="root -l -q \"D2_simc.C(2,750, \\\"pwia\\\",\\\"rad\\\")\" "    
  
CMD9="root -l -q \"D2_simc.C(3,750, \\\"fsi\\\",\\\"rad\\\")\" "   
CMD10="root -l -q \"D2_simc.C(3,750, \\\"pwia\\\",\\\"rad\\\")\" " 
  
eval ${CMD1}
eval ${CMD2} 
eval ${CMD3}                                                     
eval ${CMD4}
eval ${CMD5}                                                      
eval ${CMD6}
eval ${CMD7}                                                           
eval ${CMD8}   
eval ${CMD9}   
eval ${CMD10} 
