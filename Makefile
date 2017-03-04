CC=gcc
OPTIONS=

all: test

test: lala.c lala.h
	@echo "Creation de l'executable helloworld ... "
	@${CC} ${OPTIONS} lala.c -o helloworld
	@echo -e "Fait.\n"

clean:
	@rm -f test
