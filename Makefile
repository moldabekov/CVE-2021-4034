all:
	gcc -shared -o payload.so -fPIC payload.c
	gcc patch.c -o patch

clean:
	rm -rf ./temp ./patch ./payload.so ./GCONV_PATH=.
