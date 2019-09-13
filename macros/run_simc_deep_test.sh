#!/bin/bash

#RUN SIMC
CMD1="cd /u/group/E12-10-003/cyero/simc_deep"
CMD2="root -l -q -b run_simc_d2.C"

echo "Changing Directory to $CMD1"
eval ${CMD1}

echo "**********************************************"
echo "level 0"
echo "**********************************************"
echo
echo
eval "echo $ROOTSYS"

echo "**********************************************"
echo "level 1"
echo "**********************************************"
source /site/12gev_phys/softenv.sh 2.3

eval "echo $ROOTSYS"

eval ${CMD2}

echo "**********************************************"
echo "Finished!"
