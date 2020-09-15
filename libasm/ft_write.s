	global _ft_write
	section .text
extern ___error
_ft_write:
	mov rax, 0x2000004			;syscall num for write function
	syscall
	jc error					;carry flag = 1 if there is error BSD variant
	ret

error : 
	push rax
	call ___error				;return errono
	mov r12, rax
	pop rax
	mov [r12], rax				;save errono
	mov rax, -1
	ret



