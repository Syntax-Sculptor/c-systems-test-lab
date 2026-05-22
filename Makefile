all: systems_test_lab

systems_test_lab:
	mkdir -p build
	gcc src/main.c -I ext/unity -o build/systems_test_lab

clean:
	rm -rf build/