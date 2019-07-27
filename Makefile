zeit: zeit.c duration.c utils.c
	gcc -Wpedantic -std=c99 $^ -o $@

test: duration_test

duration_test: duration_test.c duration.c
	gcc -Wpedantic -std=c99 $^ -o $@
	./duration_test
	rm -f duration_test

clean:
	rm -f zeit
