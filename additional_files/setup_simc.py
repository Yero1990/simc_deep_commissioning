# -*- coding: utf-8 -*-
"""
Created on Thu Aug 11 17:03:47 2016

setup links to run simc from another directory

@author: boeglinw
"""

import shutil as sh


#-------------------------------------------------------------------------
# adjust to your needs
#-------------------------------------------------------------------------
LOCALDIR = './'
SIMCDIR = '/data/boeglin.1/HallC/simc_gfortran.1/'


# for spectrometers
directories = ['hrsr','hrsl','shms','hms']

# for data files, add more files for other physics models if needed
simc_files = ['simc', 'nml_default.data', 'h2.theory']
#-------------------------------------------------------------------------


# do not touch, unless you know what you are doing



def update_link(l):
    # try to delete the old link
    try:    
        sh.os.remove(l)
    except: 
        print 'cannot remove :', l
    # make new links
    try:    
        sh.os.symlink(SIMCDIR+l, LOCALDIR + l)  
    except: 
        print "cannot crate link for ", l
        return  
    print "link : ", l, " setup "            
    return
    

# setup standard directories

print "Setup directories"

INDIR =  LOCALDIR+'./infiles/'
if not sh.os.path.exists(INDIR):
    print INDIR + ' does not exist, will create it !'
    sh.os.mkdir(INDIR)

RESDIR = LOCALDIR+'./worksim/'
if not sh.os.path.exists(RESDIR):
    print RESDIR + ' does not exist, will create it !'
    sh.os.mkdir(RESDIR)

OUTDIR = LOCALDIR+'./outfiles/'
if not sh.os.path.exists(OUTDIR):
    print OUTDIR + ' does not exist, will create it !'
    sh.os.mkdir(OUTDIR)

ERRDIR = LOCALDIR+'./err/'
if not sh.os.path.exists(ERRDIR):
    print ERRDIR + ' does not exist, will create it !'
    sh.os.mkdir(ERRDIR)

LOGDIR = LOCALDIR+'./log/'
if not sh.os.path.exists(LOGDIR):
    print LOGDIR + ' does not exist, will create it !'
    sh.os.mkdir(LOGDIR)



print "Setup links: "

for dd in directories:
    update_link(dd)

for df in simc_files:
    update_link(df)

print "ready to run SIMC"

