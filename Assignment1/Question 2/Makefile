run :
	nasm -f elf64  main.asm
	gcc A.c C.c  main.o -o A -no-pie
	./A

clear:
	rm main.o A