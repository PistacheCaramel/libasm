
section	.text
global ft_strlen

ft_strlen:
	;Prologue
	push	rbp
	mov	rbp, rsp

	;Instructions fonction
	mov rax, 0 ; Retour de la fonction set a 0
	loop:
		;Instructions loop
		cmp rdi, 0 ;Comparaison
		jz exit
		cmp byte [rdi], 0 ;Comparaison
		jz exit
		inc rax ; J'incremente le compte
		inc rdi ; J'incremente l'addresse
		jmp loop
	
	exit:
	;Epilogue
	pop	rbp
	ret
