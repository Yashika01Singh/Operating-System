default:
	@echo program 1 using fork
	gcc q1_01.c -o q1_01 
	./q1_01

	@echo program 2 using thread
	gcc q1_02.c -pthread -o q1_02
	./q1_02

preprocess_1:
	gcc -E q1_01.c -o q1_01.i
compile_1 :
	gcc -S q1_01.i -o q1_01.s
assemble_1:
	gcc -c q1_01.s -o q1_01.o 
link_1:
	gcc q1_01.o -o q1_01
run_1:
	./q1_01
make_1:
	gcc -E q1_01.c -o q1_01.i
	gcc -S q1_01.i -o q1_01.s
	gcc -c q1_01.s -o q1_01.o
	gcc q1_01.o -o q1_01 
	./q1_01


clear:
	rm q1_01.i q1_01.s q1_01.o q1_01
	rm q1_02.i q1_02.s q1_02.o q1_02
	
preprocess_2:
	gcc -E q1_02.c -pthread -o q1_02.i
compile_2 :
	gcc -S q1_02.i -pthread -o q1_02.s
assemble_2:
	gcc -c q1_02.s -pthread -o q1_02.o 
link_2:
	gcc q1_02.o -pthread -o q1_02
run_2:
	./q1_02
make_2:
	gcc -E q1_02.c -pthread -o q1_02.i
	gcc -S q1_02.i -pthread -o q1_02.s
	gcc -c q1_02.s -pthread -o q1_02.o
	gcc q1_02.o -pthread -o q1_02 
	./q1_02

	
	
	



