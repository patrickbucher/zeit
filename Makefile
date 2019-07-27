zeit: zeit.c
	gcc -Wpedantic -std=c99 $^ -o $@

clean:
	rm -rf zeit
