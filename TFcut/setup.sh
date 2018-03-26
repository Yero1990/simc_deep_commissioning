# setup links to include this moduel for analysis
#
# this creates the necessary symbolic links

TFCUT_DIR=/Users/deuteron/HallC/simc_deep/TFcut

# library
for i in $TFCUT_DIR/*.so; do ln -s $i; done

# pcm files
for i in $TFCUT_DIR/*.pcm; do ln -s $i; done

# include files
for i in $TFCUT_DIR/*.h; do ln -s $i; done

