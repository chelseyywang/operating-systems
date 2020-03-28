default: tls
	gcc -lmraa -lz -Wall -Wextra -o lab4c_tcp lab4c_tcp.c -lm
tls: 
	gcc -lmraa -lz -Wall -Wextra -o lab4c_tls lab4c_tls.c -lm -L/usr/lib -lssl -lcrypto
dist: 
	tar -czvf lab4c-705124638.tar.gz Makefile README lab4c_tcp.c lab4c_tls.c
clean: 
	rm -f lab4c_tcp lab4c_tls lab4c-705124638.tar.gz
