all:
	gcc src/main.c src/menu.c src/cave.c src/samus.c src/subproblems.c -o dist/main
run:
	dist/main
generate:
	gcc generator/generate.c -o generator/generate
generate_run:
	generator/generate
clean:
	rm dist/main
clean_exec:
	rm dist/main.exe