zeit: zeit.c
	gcc -Wall $^ -o $@

clean:
	rm -rf zeit
