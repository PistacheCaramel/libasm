section .text
global ft_strcpy

ft_strcpy:
	;Prologue
	push	rbp
	mov	rbp, rsp

	;Instruction fonction
	mov	rax, rdi
	
	loop:
		;Instructions loop
		cmp rdi, 0; Check if first argument is not NULL
		jz exit
		cmp rsi, 0; Check if second argument is not NULL
		jz exit
		cmp byte [rsi] , 0
		jz exit
		mov r8, [rsi] ; Load the data
		mov [rdi], r8 ; Copy of the data

		inc rsi ; inc of the adress of the src
		inc rdi ; inc of the address of the dest
		jmp loop
		
	
	exit:
		;Epilogue
		pop	rbp
		ret
