c2.a: show-bytes.o
	rm -f $@
	ar cr $@ $^
	ranlib $@

show-bytes.o: show-bytes.c show-bytes.h
	gcc -c -g -Wall -std=gnu99 $^

clean:
	rm *.o *.a