
section .text
global ft_strcmp

ft_strcmp:
	;Prologue
	push	rbp
	mov	rbp, rsp

	;Instructions function
	mov	rax, 0	
	cmp	rdi, 0 ; Check if first argment addr is not null
	jz	exit
	cmp	rsi, 0 ; Check if second argment addr is not null
	jz	exit

	loop:
		cmp	byte [rdi], 0
		jz	equz
		nequz:
			;Instructions loop
			b1:
			mov	al, [rdi]
			mov	bl, [rsi]
			sub	rax, rbx
			b2:
			cmp	rax, 0
			jnz	exit
			inc	rdi
			inc	rsi
			jmp	loop
	
	equz:
		cmp	byte [rsi], 0
		jnz	nequz
	exit:
	pop	rbp
	ret
