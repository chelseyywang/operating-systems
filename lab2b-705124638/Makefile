build: list

list: lab2_list.c SortedList.h SortedList.c
	gcc -Wall -Wextra -pthread -o lab2_list lab2_list.c SortedList.h SortedList.c
tool:
	gcc -Wall -Wextra -pthread -g -L \
	/u/ma/ugrad/chelsey/lib/ \
	-lprofiler -o lab2_list lab2_list.c SortedList.h SortedList.c \
	
profile: tool 
	-rm -f ./raw.gperf 
	LD_PRELOAD=/usr/lib64/libprofiler.so 
	CPUPROFILE=./raw.gperf ./lab2_list --threads=12 --iterations=1000 --sync=s
	pprof --text lab2_list ./raw.gperf > profile.out
	pprof --list=threadFunc lab2_list ./raw.gperf >> profile.out
	-rm -f ./raw.gperf

first: list
	# Mutex synchronized list operations, 1,000 iterations, 1,2,4,8,12,16,24 threads
	# Spin-lock synchronized list operations, 1,000 iterations, 1,2,4,8,12,16,24 threads
	touch lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=1 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=2 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=4 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=8 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=12 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=16 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=24 --sync=m >> lab2b_list.csv
	# -./lab2_list --iterations=1000 --threads=32 --sync=m >> lab2b_list.csv
	# -./lab2_list --iterations=1000 --threads=48 --sync=m >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=1 --sync=s >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=2 --sync=s >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=4 --sync=s >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=8 --sync=s >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=12 --sync=s >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=16 --sync=s >> lab2b_list.csv
	-./lab2_list --iterations=1000 --threads=24 --sync=s >> lab2b_list.csv
	# -./lab2_list --iterations=1000 --threads=32 --sync=s >> lab2b_list.csv
	# -./lab2_list --iterations=1000 --threads=48 --sync=s >> lab2b_list.csv
	# second	
	# Run the list mutex test again for 1,000 iterations and 1, 2, 4, 8, 16, 24 threads, 
	# and plot the wait-for-lock time, and the average time per operation against the number of competing threads
third: list
	# Run your program with --yield=id, 4 lists, 1,4,8,12,16 threads, and 1, 2, 4, 8, 16 iterations (and no synchronization) 
	# to see how many iterations it takes to reliably fail (and make sure your Makefile expects some of these tests to fail).
	# touch lab2b_list.csv
	-./lab2_list --iterations=1 --threads=1 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=1 --threads=4 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=1 --threads=8 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=1 --threads=12 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=1 --threads=16 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=2 --threads=1 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=2 --threads=4 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=2 --threads=8 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=2 --threads=12 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=2 --threads=16 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=4 --threads=1 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=4 --threads=4 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=4 --threads=8 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=4 --threads=12 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=4 --threads=16 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=8 --threads=1 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=8 --threads=4 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=8 --threads=8 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=8 --threads=12 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=8 --threads=16 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=16 --threads=1 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=16 --threads=4 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=16 --threads=8 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=16 --threads=12 --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=16 --threads=16 --yield=id --lists=4 >> lab2b_list.csv
	# --yield=id, 4 lists, 1,4,8,12,16 threads, and 10, 20, 40, 80 iterations, --sync=s and --sync=m
	-./lab2_list --iterations=10 --threads=1 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=4 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=8 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=12 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=16 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=1 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=4 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=8 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=12 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=16 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=1 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=4 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=8 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=12 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=16 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=1 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=4 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=8 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=12 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=16 --sync=m --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=1 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=4 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=8 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=12 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=10 --threads=16 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=1 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=4 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=8 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=12 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=20 --threads=16 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=1 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=4 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=8 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=12 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=40 --threads=16 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=1 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=4 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=8 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=12 --sync=s --yield=id --lists=4 >> lab2b_list.csv
	-./lab2_list --iterations=80 --threads=16 --sync=s --yield=id --lists=4 >> lab2b_list.csv	
fourth: list
	# Rerun both synchronized versions, without yields, 
	# for 1000 iterations, 1,2,4,8,12 threads, and 1,4,8,16 lists	
	# -./lab2_list --iterations=1000 --threads=1 --sync=m --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=2 --sync=m --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=4 --sync=m --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=8 --sync=m --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=12 --sync=m --lists=1 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=1 --sync=m --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=2 --sync=m --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=4 --sync=m --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=8 --sync=m --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=12 --sync=m --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=1 --sync=m --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=2 --sync=m --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=4 --sync=m --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=8 --sync=m --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=12 --sync=m --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=1 --sync=m --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=2 --sync=m --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=4 --sync=m --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=8 --sync=m --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=12 --sync=m --lists=16 >> lab2b_list.csv	
	# fifth
	# -./lab2_list --iterations=1000 --threads=1 --sync=s --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=2 --sync=s --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=4 --sync=s --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=8 --sync=s --lists=1 >> lab2b_list.csv	
	# -./lab2_list --iterations=1000 --threads=12 --sync=s --lists=1 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=1 --sync=s --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=2 --sync=s --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=4 --sync=s --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=8 --sync=s --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=12 --sync=s --lists=4 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=1 --sync=s --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=2 --sync=s --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=4 --sync=s --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=8 --sync=s --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=12 --sync=s --lists=8 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=1 --sync=s --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=2 --sync=s --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=4 --sync=s --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=8 --sync=s --lists=16 >> lab2b_list.csv	
	-./lab2_list --iterations=1000 --threads=12 --sync=s --lists=16 >> lab2b_list.csv
tests: first third fourth

graphs: tests
	./lab2_list.gp

dist: tests graphs 
	tar -cvzf lab2b-705124638.tar.gz lab2_list.c SortedList.h SortedList.c Makefile README lab2b_list.csv lab2_list.gp *.png profile.out
clean:
	rm -f lab2_list lab2b-705124638.tar.gz