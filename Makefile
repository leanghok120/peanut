peanut: peanut.c
	gcc -o peanut peanut.c

install: peanut
	cp peanutmap /var/peanut/
	mv peanut /usr/local/bin
