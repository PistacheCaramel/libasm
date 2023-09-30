
section	.text
global	ft_write

ft_write:

	push	rbp
	mov	rbp, rsp

	mov	rax, 1
	syscall
	cmp	rax, 0
	jge	exit
	neg	rax
	mov	rdi, rax
	mov	rax, 0x3d
	syscall
	mov	rax, -1

	
	exit:
		pop	rbp
		ret
