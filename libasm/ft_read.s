	global _ft_read
	section .text
extern ___error
_ft_read:
	mov rax, 0x2000003		;syscall num for read function
	syscall
	jc error
	ret
error:
	push rax
	call ___error
	mov r12, rax
	pop rax
	mov [r12], rax
	mov rax, -1
	ret
	
