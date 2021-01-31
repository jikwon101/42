	global _ft_strlen
	section .text
_ft_strlen:
	mov rax, 0x0
	cmp rdi, 0
	jz _end
	_start_loop:
		cmp byte [rdi + rax], 0x0
		jz _end_loop
		inc rax
		jmp _start_loop
	_end_loop:
	ret

_end:
	ret



