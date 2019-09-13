#!/bin/bash

#shell script to make multiple copies of the same file

for ijob in {1..5} ; do
        
    cmd0="cp d2_pm580_lagetfsi_rad_set1.data d2_pm580_lagetfsi_rad_set1_job$ijob.data"
    cmd1="cp d2_pm580_lagetfsi_norad_set1.data d2_pm580_lagetfsi_norad_set1_job$ijob.data"
    cmd2="cp d2_pm580_lagetpwia_rad_set1.data d2_pm580_lagetpwia_rad_set1_job$ijob.data"
    cmd3="cp d2_pm580_lagetpwia_norad_set1.data d2_pm580_lagetpwia_norad_set1_job$ijob.data"
    eval ${cmd0}
    eval ${cmd1}
    eval ${cmd2}
    eval ${cmd3}
done
