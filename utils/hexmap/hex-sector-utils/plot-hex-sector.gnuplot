# Gnuplot script to generate a plot of flower data with flowers laid
# out in hex sector space, for all flower types present in a simulation
# run at the specified generation number, using input data from the
# specified file.
#
# The input file is a 7-field CSV file as generated by the utility script
# gen-hex-plot-data
#
# Call like this, e.g.
# > gnuplot -c plot-hex-sector.gnuplot filebase N preftype(=giurfa|flat) titletext
# e.g.
# > gnuplot -c plot-hex-sector.gnuplot hex-info 100
#
# The script looks for an input data file named [filebase]-gen-N.csv
#
# The output is saved in a file named [filebase]-gen-N-hex-sector.png

filebase="hex-info"
gen=0
ptype="giurfa"
titletext=""

if (exists("ARG1")) {
    filebase=ARG1
}

if (exists("ARG2")) {
    gen=ARG2
}

if (exists("ARG3")) {
    ptype=ARG3
}

if (exists("ARG4")) {
    titletext=ARG4." / "
}

fbase = sprintf("%s-gen-%s", filebase, gen)
infile = sprintf("%s.csv", fbase)
outfile = sprintf("%s-hex-sector.png", fbase)

set datafile separator ","
set ytics nomirror
#set yrange [0:20000]
set yrange [0:7500]
set y2range [0:25]
set y2tics 0,5
set xrange [0:360]
set xlabel "Hex Sector (degrees)"
set ylabel "Count"
set y2label "Preference (".ptype.")"
set title titletext."Generation ".gen
set key
PSZ=0.9
set term png size 800,600
set output outfile
plot infile using 4:5 pt 7 lc rgb "red" ps PSZ title "flowers" axis x1y1, infile using 4:6 pt 7 lc rgb "blue" ps PSZ title "pollinations" axis x1y1, infile using 4:7 pt 7 lc rgb "green" ps PSZ title "landings" axis x1y1, infile using 4:9 pt 7 lc rgb "black" ps PSZ title ptype." preference" axis x1y2