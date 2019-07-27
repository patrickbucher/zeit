zeit: src/zeit.c src/duration.c src/utils.c
	gcc -Wpedantic -std=c99 $^ -o $@

test: duration_test

duration_test: src/duration_test.c src/duration.c
	gcc -Wpedantic -std=c99 $^ -o $@
	./duration_test
	rm -f duration_test

clean:
	rm -f zeit
