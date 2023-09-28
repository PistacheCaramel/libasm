
section .txt
global ft_strcmp

ft_strcmp:
	;Prologue
	push	rbp
	mov	rbp, rsp

	;Instructions function
	mov	rax, 0	

	loop:
		;Instructions loop
		cmp	rdi, 0 ; Check if first argment addr is not null
		jz	exit
		cmp	rsi, 0 ; Check if second argment addr is not null
		jz	exit
		mov	rax, [rdi]
		sub	rax, [rsi]
		cmp	rax, 0
		jz	exit
		inc	rdi
		inc	rsi
		jmp	loop

	exit:
	pop	rbp
	ret
