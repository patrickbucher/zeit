zeit: src/zeit.c src/duration.c src/utils.c
	gcc -g -Wpedantic -std=c99 $^ -o $@

diet: src/zeit.c src/duration.c src/utils.c
	diet gcc -g -Wpedantic -std=c99 $^ -o zeit

test: utils_test duration_test

utils_test: src/utils_test.c src/utils.c
	gcc -Wpedantic -std=c99 $^ -o $@
	./utils_test
	rm -f utils_test

duration_test: src/duration_test.c src/duration.c
	gcc -Wpedantic -std=c99 $^ -o $@
	./duration_test
	rm -f duration_test

clean:
	rm -f zeit
