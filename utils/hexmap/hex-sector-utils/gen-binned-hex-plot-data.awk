# Script to process a logfile that was generated by gen-hex-plot-data
# and output (to stdout) binned data about the number of flowers
#
# The binning is done according to hex theta angle, using bin widths
# of 10 degrees by default (different widths can be specified by setting
# the value of W on the command line).
#
# The output is in csv format with lines of the form:
#   BIN_NUMBER, NUM_FLOWERS_IN_BIN
#
# usage:
# >  gawk -f [-vW=10] gen-binned-hex-plot-data.awk logfile
#

BEGIN {
    FS=","
    if (! W) {
        W=10;
    }
    NB=360/W;
    for (i=0;i<NB;i++) {
        BIN[i]=0;
    }
}

{
    B=int($4/W);
    BIN[B]+=$5
}

END {
    for (i=0;i<NB;i++) {
        print i", "BIN[i];
    }
}
