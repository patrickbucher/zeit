zeit: zeit.c duration.c utils.c
	gcc -Wpedantic -std=c99 $^ -o $@

clean:
	rm -rf zeit
