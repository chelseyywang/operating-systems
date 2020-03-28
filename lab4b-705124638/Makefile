build: 
	gcc -lmraa -Wall -Wextra -o lab4b lab4b.c -lm
clean: 
	rm -f lab4b lab4b-705124638.tar.gz
check: build
	touch errors.txt; \
	echo -e "hello\nOFF\n" < ./lab4b > out.txt; \
	if [ ! -s out.txt ]; \
	then \
		echo 'nothing logged' > errors.txt; \
	fi; \
	rm out.txt; \
	echo -e "START\nSTOP\nPERIOD=3\nSTART\nSCALE=C\nOFF\n" < ./lab4b > out.txt; \
	if [ ! -s out.txt ]; \
	then \
		echo 'nothing logged' > errors.txt; \
	fi; \
	grep "START" out.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo 'START not received' > errors.txt; \
	fi; \
	grep "STOP" out.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo 'STOP not received' > errors.txt; \
	fi; \
	grep "PERIOD=3" out.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo 'PERIOD=3 not received' > errors.txt; \
	fi; \
	grep "SCALE=C" out.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo 'SCALE=C not received' > errors.txt; \
	fi; \
	grep "OFF" out.txt; \
	if [ $$? -ne 0 ]; \
	then \
		echo 'OFF not received' > errors.txt; \
	fi; \
	rm out.txt; \
	if [ -s errors.txt ]; \
	then \
		echo -e "\n SMOKE TEST FAILED"; \
	else \
		echo -e "\n PASSED BBY"; \
	fi; \
	rm errors.txt lab4b; \

dist: 
	tar -cvzf lab4b-705124638.tar.gz lab4b.c README Makefile
