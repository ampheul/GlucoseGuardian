set terminal pngcairo size 1600, 600 font "Verdana, 12"
# Style
set style line 1 lc rgb '#8b1a0e' pt 1 ps 1 lt 1 lw 2 # --- red
set style line 2 lc rgb '#5e9c36' pt 6 ps 1 lt 1 lw 2 # --- green
set style line 11 lc rgb '#808080' lt 1
set border 3 back ls 11
set tics nomirror
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12
#
set border ls 50
set title "Glucose Graph"
set style data fsteps
set xlabel "Date\nTime"
set timefmt "%s"
set xdata time
set format x "%a/%H:%M"
set ylabel "Concentration\nmg/dl"
set xtics rotate by -45
set tics front
unset key
file = '< cat -'
plot file using 1:2 with filledcurves x1