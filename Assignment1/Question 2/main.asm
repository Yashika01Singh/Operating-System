    extern c

    global  B
    section .bss
	    var resb 8
        var2 resb 8
    section .text
        


B:
    
    
    mov r8 , 8

    loop :
    push rdi
    mov [var],dil
	push var
    mov rax, 1
	mov rdi, 1
	pop rsi
    mov rdx,1  
	syscall
    pop rdi
    shr rdi ,8
    dec r8 
    cmp r8 , 0
    jne loop


    mov r8 , c
    pop rcx
    push r8
    ret


