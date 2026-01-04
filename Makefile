CC = clang

peanutd: peanutd.c
	$(CC) -o peanutd peanutd.c

install: peanutd
	mkdir -p /var/peanut/
	cp peanutmap /var/peanut/
	mv peanutd /usr/local/bin
