all: lab0

lab0: lab0.c
	gcc -g -o lab0 lab0.c -Wall -Wextra

check: lab0
	touch errors.txt; \

	# 1 input, output
	echo "dino nugs" > 1.txt; \
	./lab0 --input=1.txt --output=2.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; input&1output failed" >> errors.txt; \
	fi;  \
	cmp -s 1.txt 2.txt >> errors.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; input & output failed" >> errors.txt; \
	fi;  \
	rm 1.txt 2.txt; \
	
	# 2 output, input
	echo "dino nugs" > 1.txt; \
	./lab0 --output=2.txt --input=1.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; input&output failed" >> errors.txt; \
	fi;  \
	cmp -s 1.txt 2.txt >> errors.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; input&output failed" >> errors.txt; \
	fi;  \
	rm 1.txt 2.txt; \
	
	# 3 check catch with no segfault
	echo "dino nugs" > 1.txt; \
	./lab0 --output=2.txt --input=1.txt --catch; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; input&output failed" >> errors.txt; \
	fi;  \
	cmp -s 1.txt 2.txt >> errors.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; input&output failed" >> errors.txt; \
	fi;  \
	rm 1.txt 2.txt; \

	#5 check catch with segfault 
	echo "dino nugs" > 1.txt; \
	./lab0 --input=1.txt --output=2.txt --catch --segfault; \
	if [ $$? -ne 4 ]; \
	then \
		echo "smoke test failed; segfault with catch failed" >> errors.txt; \
	fi;  \
	cmp -s 1.txt 2.txt >> errors.txt; \
	if [ -s 2.txt ]; \
	then \
		echo "smoke test failed; segfault did not work" >> errors.txt; \
	fi;  \
	rm 1.txt 2.txt; \

	#6 check segfault 
	echo "dino nugs" > 1.txt; \
	./lab0 --input=1.txt --output=2.txt --segfault; \
	if [ $$? -ne 139 ]; \
	then \
		echo "smoke test failed; segfault failed" >> errors.txt; \
	fi;  \
	cmp -s 1.txt 2.txt >> errors.txt; \
	if [ -s 2.txt ]; \
	then \
		echo "smoke test failed; segfault did not work" >> errors.txt; \
	fi;  \
	rm 1.txt 2.txt; \

	#7 check incorrect/missing args; exit 2 
	./lab0 --input; \
	if [ $$? -ne 1 ]; \
	then \
		echo "smoke test failed; incorrect/missing args not exited with correct code" >> errors.txt; \
	fi;  \

	#8 check incorrect/missing args; exit 2 
	./lab0 --output; \
	if [ $$? -ne 1 ]; \
	then \
		echo "smoke test failed; incorrect/missing args not exited with correct code" >> errors.txt; \
	fi;  \

	#9 check bad input; exit 2 
	./lab0 --input= ; \
	if [ $$? -ne 2 ]; \
	then \
		echo "smoke test failed; bad input not exited with correct code" >> errors.txt; \
	fi;  \

	#10 check bad input; exit 2 
	./lab0 --input=idontexist.txt ; \
	if [ $$? -ne 2 ]; \
	then \
		echo "smoke test failed; bad input not exited with correct code" >> errors.txt; \
	fi;  \

	#10 check bad output; exit 3 
	echo "dino nugs" > 1.txt; \
	./lab0 --output=directory/idontexist.txt --input 1.txt ; \
	if [ $$? -ne 3 ]; \
	then \
		echo "smoke test failed; bad output not exited with correct code" >> errors.txt; \
	fi;  \
	rm 1.txt; \

	#11 check good output; exit 0 
	echo "dino nugs" > 1.txt; \
	./lab0 --output=idontexist.txt --input 1.txt ; \
	if [ $$? -ne 0 ]; \
	then \
		echo "smoke test failed; good output not exited with correct code" >> errors.txt; \
	fi;  \
	rm 1.txt idontexist.txt; \

	#12 check no input; exit 0
	echo "dino nugs" | ./lab0 --output=2.txt; \
	if [[ $$? -ne 0 ]]; \
	then \
		echo "smoke test failed; no input not exited with correct code" >> errors.txt ; \
	fi; \
	rm 2.txt; \

	# final
	if [ -s errors.txt ]; \
	then \
		echo -e "\n\n *** :( smoke test failed *** "; \
	else \
		echo -e "\npassed bois"; \
	fi; \

	# cat errors.txt; \

	rm errors.txt lab0; \

dist: 
	tar -cvzf lab0-705124638.tar.gz lab0.c Makefile backtrace.png breakpoint.png README

clean: 
	rm -f lab0 lab0-705124638.tar.gz
.ONESHELL: 