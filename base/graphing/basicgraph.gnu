set terminal pngcairo
set title "POPEY pant"
set style data fsteps
set xlabel "Date\nTime"
set timefmt "%s"
set xdata time
set format x "%H:%M"
set ylabel "Concentration\nmg/dl"
set xtics
set xtics rotate
set grid
unset key
plot '< cat -' using 1:2 with filledcurves x1