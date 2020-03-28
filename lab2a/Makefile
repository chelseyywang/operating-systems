build: add list
	
add: lab2_add.c
	gcc -Wall -Wextra -pthread -o lab2_add lab2_add.c
list: lab2_list.c SortedList.h SortedList.c
	gcc -Wall -Wextra -pthread -o lab2_list lab2_list.c SortedList.h SortedList.c
tests: build
	touch lab2_add.csv
	# lab2_add-1.png
	./lab2_add --iterations=10 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=10 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=10 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=10 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=20 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=20 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=20 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=20 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=40 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=40 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=40 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=40 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=80 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=80 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=80 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=80 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=100 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=100 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=100 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=100 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=100 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=100 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --yield >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=2 --yield >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=4 --yield >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=8 --yield >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=12 --yield >> lab2_add.csv
	#lab2-nonyield
	./lab2_add --iterations=10 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=10 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=10 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=10 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=10 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=20 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=20 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=20 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=20 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=20 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=40 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=40 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=40 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=40 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=40 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=80 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=80 --threads=2 >> lab2_add.csv
	./lab2_add --iterations=80 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=80 --threads=8 >> lab2_add.csv
	./lab2_add --iterations=80 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=100 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=100 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=100 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=1 >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=4 >> lab2_add.csv
	./lab2_add --iterations=100000 --threads=12 >> lab2_add.csv
	# locks
	./lab2_add --iterations=10000 --threads=2 --sync=m --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --sync=m --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --sync=m --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --sync=m --yield >> lab2_add.csv

	./lab2_add --iterations=10000 --threads=2 --sync=c --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --sync=c --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --sync=c --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --sync=c --yield >> lab2_add.csv

	./lab2_add --iterations=1000 --threads=2 --sync=s --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=4 --sync=s --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=8 --sync=s --yield >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=12 --sync=s --yield >> lab2_add.csv

	./lab2_add --iterations=10000 --threads=2 --sync=s --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --sync=s --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --sync=s --yield >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --sync=s --yield >> lab2_add.csv
	#no yield
	./lab2_add --iterations=10000 --threads=1 --sync=m >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=2 --sync=m >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --sync=m >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --sync=m >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --sync=m >> lab2_add.csv

	./lab2_add --iterations=10000 --threads=1 --sync=c >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=2 --sync=c >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --sync=c >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --sync=c >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --sync=c >> lab2_add.csv

	./lab2_add --iterations=1000 --threads=1 --sync=s >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=2 --sync=s >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=4 --sync=s >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=8 --sync=s >> lab2_add.csv
	./lab2_add --iterations=1000 --threads=12 --sync=s >> lab2_add.csv

	./lab2_add --iterations=10000 --threads=1 --sync=s >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=2 --sync=s >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=4 --sync=s >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=8 --sync=s >> lab2_add.csv
	./lab2_add --iterations=10000 --threads=12 --sync=s >> lab2_add.csv

	touch lab2_list.csv
	 -./lab2_list --iterations=10 >> lab2_list.csv
	 -./lab2_list --iterations=100 >> lab2_list.csv
	 -./lab2_list --iterations=1000 >> lab2_list.csv
	 -./lab2_list --iterations=10000 >> lab2_list.csv
	 -./lab2_list --iterations=20000 >> lab2_list.csv

	# ./lab2_list --iterations=10 --sync=m >> lab2_list.csv
	# ./lab2_list --iterations=100 --sync=m >> lab2_list.csv
	# ./lab2_list --iterations=1000 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --sync=m >> lab2_list.csv

	# ./lab2_list --iterations=10 --sync=s >> lab2_list.csv
	# ./lab2_list --iterations=100 --sync=s >> lab2_list.csv
	# ./lab2_list --iterations=1000 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --sync=m >> lab2_list.csv

	# # hey

	 -./lab2_list --iterations=32 --threads=12 --yield=i --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=32 --threads=12 --yield=d --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=32 --threads=12 --yield=il --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=32 --threads=12 --yield=dl --sync=s >> lab2_list.csv

	 -./lab2_list --iterations=32 --threads=12 --yield=i --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=32 --threads=12 --yield=d --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=32 --threads=12 --yield=il --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=32 --threads=12 --yield=dl --sync=m >> lab2_list.csv

	 -./lab2_list --iterations=1000 --threads=1 --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=2 --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=4 --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=8 --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=12 --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=16 --sync=m >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=24 --sync=m >> lab2_list.csv

	 -./lab2_list --iterations=1000 --threads=1 --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=2 --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=4 --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=8 --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=12 --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=16 --sync=s >> lab2_list.csv
	 -./lab2_list --iterations=1000 --threads=24 --sync=s >> lab2_list.csv






	#end hey

	-./lab2_list --iterations=1 --threads=12 >> lab2_list.csv	
	-./lab2_list --iterations=2 --threads=12 >> lab2_list.csv	
	-./lab2_list --iterations=10 --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=100 --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=1000 --threads=12 >> lab2_list.csv

	-./lab2_list --iterations=1 --threads=2 >> lab2_list.csv	
	-./lab2_list --iterations=2 --threads=2 >> lab2_list.csv	
	-./lab2_list --iterations=10 --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=100 --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=1000 --threads=2 >> lab2_list.csv

	-./lab2_list --iterations=1 --threads=4 >> lab2_list.csv	
	-./lab2_list --iterations=2 --threads=4 >> lab2_list.csv	
	-./lab2_list --iterations=10 --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=100 --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=1000 --threads=4 >> lab2_list.csv

	-./lab2_list --iterations=1 --threads=8 >> lab2_list.csv	
	-./lab2_list --iterations=2 --threads=8 >> lab2_list.csv	
	-./lab2_list --iterations=10 --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=100 --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=1000 --threads=8 >> lab2_list.csv

	-./lab2_list --iterations=1 --threads=16 >> lab2_list.csv	
	-./lab2_list --iterations=2 --threads=16 >> lab2_list.csv	
	-./lab2_list --iterations=10 --threads=16 >> lab2_list.csv
	-./lab2_list --iterations=100 --threads=16 >> lab2_list.csv
	-./lab2_list --iterations=1000 --threads=16 >> lab2_list.csv

	-./lab2_list --iterations=1 --threads=32 >> lab2_list.csv	
	-./lab2_list --iterations=2 --threads=32 >> lab2_list.csv	
	-./lab2_list --iterations=10 --threads=32 >> lab2_list.csv
	-./lab2_list --iterations=100 --threads=32 >> lab2_list.csv
	-./lab2_list --iterations=1000 --threads=32 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=i --threads=12 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=i --threads=12 >> lab2_list.csv	
	# -./lab2_list --iterations=10 --yield=i --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=d >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=d --threads=12 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=d --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=d --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=12 >> lab2_list.csv

	# ./lab2_list --iterations=10 --yield=il >> lab2_list.csv
	# ./lab2_list --iterations=100 --yield=il >> lab2_list.csv
	# ./lab2_list --iterations=1000 --yield=il >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=il >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=il --threads=12 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=il --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=il --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=12>> lab2_list.csv

	# ./lab2_list --iterations=10 --yield=dl >> lab2_list.csv
	# ./lab2_list --iterations=100 --yield=dl >> lab2_list.csv
	# ./lab2_list --iterations=1000 --yield=dl >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=dl >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=dl --threads=12 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=dl --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=dl --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=12 >> lab2_list.csv


	# -./lab2_list --iterations=10 --yield=i --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=m >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=s >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=m >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=s >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=d --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=d --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=il --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=il --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=dl --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=12 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=dl --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl --threads=12 >> lab2_list.csv


	# # second run

	# -./lab2_list --iterations=10 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=i --threads=2 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=i --threads=2 >> lab2_list.csv	
	# -./lab2_list --iterations=10 --yield=i --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=2 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=d >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=d --threads=2 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=d --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=d --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=2 >> lab2_list.csv

	# ./lab2_list --iterations=10 --yield=il >> lab2_list.csv
	# ./lab2_list --iterations=100 --yield=il >> lab2_list.csv
	# ./lab2_list --iterations=1000 --yield=il >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=il >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=il --threads=2 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=il --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=il --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=2 >> lab2_list.csv

	# ./lab2_list --iterations=10 --yield=dl >> lab2_list.csv
	# ./lab2_list --iterations=100 --yield=dl >> lab2_list.csv
	# ./lab2_list --iterations=1000 --yield=dl >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=dl >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=dl --threads=2 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=dl --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=dl --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=2 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=i --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=2 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=i --threads=2 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=2 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=2 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=m >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=i --threads=2 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=2 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=2 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=s >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d --threads=2 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=2 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=2 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=m >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d --threads=2 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=2 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=2 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=s >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=2 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=d --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=d --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=il --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=2 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=il --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il --threads=12 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=dl --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=2 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=2 >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=dl --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl --threads=12 >> lab2_list.csv

	# third run 

	-./lab2_list --iterations=1 --yield=i >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=i >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=i >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=i >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=i >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=i >> lab2_list.csv
	# omg
	-./lab2_list --iterations=1 --yield=i --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=i --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=i --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=i --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=i --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=i --threads=2 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=i --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=i --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=i --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=i --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=i --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=i --threads=4 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=i --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=i --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=i --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=i --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=i --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=i --threads=8 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=i --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=i --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=i --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=i --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=i --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=i --threads=12 >> lab2_list.csv

	# dos baby 
	-./lab2_list --iterations=1 --yield=d >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=d >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=d >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=d >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=d >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=d >> lab2_list.csv
	# omg
	-./lab2_list --iterations=1 --yield=d --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=d --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=d --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=d --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=d --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=d --threads=2 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=d --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=d --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=d --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=d --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=d --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=d --threads=4 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=d --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=d --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=d --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=d --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=d --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=d --threads=8 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=d --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=d --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=d --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=d --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=d --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=d --threads=12 >> lab2_list.csv

	# tres 
	-./lab2_list --iterations=1 --yield=il >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=il >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=il >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=il >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=il >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=il >> lab2_list.csv
	# omg
	-./lab2_list --iterations=1 --yield=il --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=il --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=il --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=il --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=il --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=il --threads=2 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=il --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=il --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=il --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=il --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=il --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=il --threads=4 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=il --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=il --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=il --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=il --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=il --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=il --threads=8 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=il --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=il --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=il --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=il --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=il --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=il --threads=12 >> lab2_list.csv
	# end tres

	# cuatro
	-./lab2_list --iterations=1 --yield=dl >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=dl >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=dl >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=dl >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=dl >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=dl >> lab2_list.csv
	# omg
	-./lab2_list --iterations=1 --yield=dl --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=dl --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=dl --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=dl --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=dl --threads=2 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=dl --threads=2 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=dl --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=dl --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=dl --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=dl --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=dl --threads=4 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=dl --threads=4 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=dl --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=dl --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=dl --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=dl --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=dl --threads=8 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=dl --threads=8 >> lab2_list.csv

	-./lab2_list --iterations=1 --yield=dl --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=2 --yield=dl --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=4 --yield=dl --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=8 --yield=dl --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=16 --yield=dl --threads=12 >> lab2_list.csv
	-./lab2_list --iterations=32 --yield=dl --threads=12 >> lab2_list.csv
	#end cuatro

	# # ./lab2_list --iterations=10000 --yield=i >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=i --threads=4 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=i --threads=4 >> lab2_list.csv	
	# -./lab2_list --iterations=10 --yield=i --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=i --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=i --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=i --threads=4 >> lab2_list.csv

	# -./lab2_list --iterations=10 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=d >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=d >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=d --threads=4 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=d --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=d --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=d --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=d --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=d --threads=4 >> lab2_list.csv


	# # ./lab2_list --iterations=10000 --yield=il >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il >> lab2_list.csv



	# # ./lab2_list --iterations=10000 --yield=dl >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl >> lab2_list.csv

	# # ./lab2_list --iterations=10000 --yield=i --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 >> lab2_list.csv

	# # -./lab2_list --iterations=10 --yield=i --threads=4 --sync=m >> lab2_list.csv
	# # -./lab2_list --iterations=100 --yield=i --threads=4 --sync=m >> lab2_list.csv
	# # -./lab2_list --iterations=1000 --yield=i --threads=4 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=m >> lab2_list.csv

	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=s >> lab2_list.csv

	# # -./lab2_list --iterations=10 --yield=d --threads=4 --sync=m >> lab2_list.csv
	# # -./lab2_list --iterations=100 --yield=d --threads=4 --sync=m >> lab2_list.csv
	# # -./lab2_list --iterations=1000 --yield=d --threads=4 --sync=m >> lab2_list.csv
	# # # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=m >> lab2_list.csv
	# # # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=m >> lab2_list.csv

	# # -./lab2_list --iterations=10 --yield=d --threads=4 --sync=s >> lab2_list.csv
	# # -./lab2_list --iterations=100 --yield=d --threads=4 --sync=s >> lab2_list.csv
	# # -./lab2_list --iterations=1000 --yield=d --threads=4 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=i --threads=12 --sync=s >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=i --threads=12 --sync=s >> lab2_list.csv

	# # ./lab2_list --iterations=10000 --yield=d --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=d --threads=12 >> lab2_list.csv

	
	# # ./lab2_list --iterations=10000 --yield=il --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il --threads=12 >> lab2_list.csv

	
	# # ./lab2_list --iterations=10000 --yield=dl --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl --threads=12 >> lab2_list.csv


	# # ./lab2_list --iterations=10000 --yield=il --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il --threads=12 >> lab2_list.csv

	
	# # ./lab2_list --iterations=10000 --yield=dl --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl --threads=12 >> lab2_list.csv
	# ./lab2_list --iterations=10 --yield=il >> lab2_list.csv
	# ./lab2_list --iterations=100 --yield=il >> lab2_list.csv
	# ./lab2_list --iterations=1000 --yield=il >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=il --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=il --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=il --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=il --threads=4 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=il --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=il --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=il --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=il --threads=4>> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=il --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=il --threads=12 >> lab2_list.csv
	# ./lab2_list --iterations=10 --yield=dl >> lab2_list.csv
	# ./lab2_list --iterations=100 --yield=dl >> lab2_list.csv
	# ./lab2_list --iterations=1000 --yield=dl >> lab2_list.csv
	# -./lab2_list --iterations=1 --yield=dl --threads=4 >> lab2_list.csv	
	# -./lab2_list --iterations=2 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=4 >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=dl --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=12 --sync=s >> lab2_list.csv
	# -./lab2_list --iterations=10 --yield=dl --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=100 --yield=dl --threads=12 --sync=m >> lab2_list.csv
	# -./lab2_list --iterations=1000 --yield=dl --threads=12 --sync=m >> lab2_list.csv
	# # ./lab2_list --iterations=10000 --yield=dl --threads=12 >> lab2_list.csv
	# # ./lab2_list --iterations=20000 --yield=dl --threads=12 >> lab2_list.csv

graphs: lab2_add.csv lab2_list.csv
	./lab2_add.gp
	./lab2_list.gp


dist: tests graphs 
	tar -cvzf lab2a-705124638.tar.gz lab2_add.c lab2_list.c SortedList.h SortedList.c Makefile README lab2_add.csv lab2_list.csv lab2_add.gp lab2_list.gp *.png
clean:
	rm -f lab2_add lab2_list lab2a-705124638.tar.gz