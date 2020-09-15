	global _ft_strcmp
	section .text

_ft_strcmp :
	mov rax, 0
	cmp rdi, 0
	jz _end_function
	cmp rsi, 0
	jz _end_function
	mov r12, 0x0			;count rdi
	mov r13, 0x0			;count rsi
	mov rcx, 0x0
	mov rdx, 0x0
	_start_loop : 
		mov dl, byte [rdi + r12]
		mov cl, byte [rsi + r13]
		cmp dl, cl
		jnz _end_loop
		inc r12
		inc r13
		cmp dl, 0x0			;return if it is \0
		jz _end_loop
		cmp cl, 0x0			;return if it is \0
		jz _end_loop
		jmp _start_loop
	_end_loop :
	mov r12, rcx
	mov rax, rdx
	sub rax, r12
	ret

_end_function:
	ret
