target = hash

target:hash.o
	gcc -o $(target) hash.o ../lib/hash.so

hash.o:hash.c
	gcc -c hash.c
clean:
	rm $(target) hash.o
