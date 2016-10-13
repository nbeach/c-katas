all: clean compile check

clean:
	rm -f ../out/test

compile:
	gcc test_setup.c ../src/*.c -o ../out/test `pkg-config --cflags --libs check`

check:
	../out/test
