#! /usr/bin/gnuplot

set terminal png
set datafile separator ","

# graph 1
# total number of operations per second 
# for each synchronization method

set title "List-1 Throughput vs. Number of Threads"
set xlabel "Number of Threads"
set xrange [0.75:24]
set logscale x 2 
set ylabel "Throughput"
set logscale y 10 
set output 'lab2b_1.png' 

plot \
     "< grep 'list-none-m,[0-9]*,1000,1,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title 'mutex' with linespoints lc rgb 'green', \
     "< grep 'list-none-s,[0-9]*,1000,1,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title 'spin-lock' with linespoints lc rgb 'red', \

# graph 2

set title "List-2 Mean Time per Mutex Wait and Mean Time per Operation"
set xlabel "Number of Threads"
set xrange [0.75:24]
set logscale x 2 
set ylabel "Average Time"
set logscale y 10 
set output 'lab2b_2.png' 

plot \
     "< grep 'list-none-m,[0-9]*,1000,1,' lab2b_list.csv" using ($2):($7) \
	title 'avg time per op' with linespoints lc rgb 'green', \
     "< grep 'list-none-m,[0-9]*,1000,1,' lab2b_list.csv" using ($2):($8) \
	title 'avg lock wait time' with linespoints lc rgb 'red', \

# graph 3
# plot the wait-for-lock time, and the average time per operation 
# against the number of competing threads
# 1,4,8,12,16 threads, and 10, 20, 40, 80

set title "List-3 Successful Iterations vs. Number of Threads"
set xlabel "Number of Threads"
set xrange [0.75:16]
set logscale x 2 
set ylabel "Successful Iterations"
set logscale y 10 
set output 'lab2b_3.png' 

plot \
     "< grep 'list-id-m,[0-9]*,[1-8][0],' lab2b_list.csv" using ($2):($3) \
	title 'mutex protected' with points lc rgb 'red', \
     "< grep 'list-id-s,[0-9]*,[1-8][0],' lab2b_list.csv" using ($2):($3) \
	title 'spinlock protected' with points lc rgb 'green', \
     "< grep 'list-id-none,[0-9]*,[0-9][6]*,4' lab2b_list.csv" using ($2):($3) \
	title 'unprotected threads' with points lc rgb 'blue', \

set title "List-4 Throughput vs. Mutex Synchronized Number of Threads"
set xlabel "Number of Threads"
set xrange [0.75:12]
set logscale x 2 
set ylabel "Throughput"
set logscale y 10 
set output 'lab2b_4.png' 

plot \
     "< grep 'list-none-m,[0-9][2]*,1000,1,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '1 list' with linespoints lc rgb 'red', \
     "< grep 'list-none-m,[0-9]*,1000,4,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '4 lists' with linespoints lc rgb 'green', \
     "< grep 'list-none-m,[0-9]*,1000,8,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '8 lists' with linespoints lc rgb 'blue', \
     "< grep 'list-none-m,[0-9]*,1000,16,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '16 lists' with linespoints lc rgb 'violet', \


#1000 iterations, 1,2,4,8,12 threads, and 1,4,8,16 lists.

set title "List-5 Throughput vs. Spin-Lock Synchronized Number of Threads"
set xlabel "Number of Threads"
set xrange [0.75:12]
set logscale x 2 
set ylabel "Throughput"
set logscale y 10 
set output 'lab2b_5.png' 

plot \
     "< grep -e 'list-none-s,[0-9][2]*,1000,1,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '1 list' with linespoints lc rgb 'red', \
     "< grep -e 'list-none-s,[0-9]*,1000,4,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '4 lists' with linespoints lc rgb 'green', \
     "< grep -e 'list-none-s,[0-9]*,1000,8,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '8 lists' with linespoints lc rgb 'blue', \
     "< grep -e 'list-none-s,[0-9]*,1000,16,' lab2b_list.csv" using ($2):(1000000000/($7)) \
	title '16 lists' with linespoints lc rgb 'violet',