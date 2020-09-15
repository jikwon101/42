	global _ft_strcpy
	section .text
_ft_strcpy :				 	;rdi = char *dst, rsi = const char *src
	cmp rsi, 0
	jz _end
	cmp rdi, 0
	jz _end
	mov rcx, 0x0
	_start_loop:
		cmp byte [rsi + rcx], 0x0
		jz _end_loop
		mov dl, byte [rsi + rcx]
		mov byte [rdi + rcx], dl
		mov rax, rdi
		inc rcx;
		jmp _start_loop
	_end_loop:
	mov byte [rdi + rcx], 0
	mov rax, rdi
	ret

_end:
	mov rax, 0
	ret
