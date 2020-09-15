	global _ft_strdup
	section .text
	extern _malloc

_ft_strdup:						;rdi = char *
	cmp rdi, 0x0
	jz _error
	call _s_strlen
	push rdi
	inc rax 		
	mov rdi, rax
	call _malloc
	cmp rax, 0x0
	jz _error
	pop rdi
	push rsi
	mov rsi, rdi
	mov rdi, rax
	call _s_strcpy
	pop rsi
	ret


_s_strlen:
	mov rax, 0x0
	_start_loop1:
		cmp byte [rdi + rax], 0x0
		jz _end_loop1
		inc rax
		jmp _start_loop1
	_end_loop1:
	ret

_s_strcpy:							;rdi = char *dst, rsi = const char *src
	mov rcx, 0x0
	_start_loop2:
		cmp byte [rsi + rcx], 0x0
		jz _end_loop2
		mov dl, byte [rsi + rcx]
		mov byte [rdi + rcx], dl
		mov rax, rdi
		inc rcx
		jmp _start_loop2
	_end_loop2:
	mov dl, byte [rsi + rcx]
	mov byte [rdi + rcx], dl
	mov rax, rdi
	ret

_error:
	mov rax, 0x0
	ret
