extern __errno_location
global	ft_read

section	.text

ft_read:
	push	rbp
	mov	rbp, rsp

	call	__errno_location
	mov	r8, rax	
	mov	rax, 0
	syscall
	neg	rax
	mov	[r8], rax
	cmp	rax, 0
	jb	exit
	mov	rax, -1
	
exit:
	pop	rbp
	ret
