extern	malloc
extern ft_strcpy
extern ft_strlen
global ft_strdup

section .text

ft_strdup:
	push	rbp
	mov	rbp, rsp

	mov	r8, rdi ;save the address of the string
	b1:
	call	ft_strlen ;calculate the size of the string
	inc	rax ;for the null byte
	b2:
	mov 	rdi, rax ;save the size of the string
	mov	rsi, 1
	call	malloc	;allocate memory
	b3:
	cmp	rax, 0
	je	exit
	mov	rdi, rax
	mov	rsi, r8
	b4:
	call	ft_strcpy

exit:
	pop	rbp
	ret
