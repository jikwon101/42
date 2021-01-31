	global _ft_list_size:
	section .text
_ft_list_size:
	mov rax, 0
	cmp rdi, 0x0
	jz _end_function
	mov rcx, rdi			;first list
	_start_loop:
		cmp rcx, 0x0		;stop loop if list is null
		jz _end_loop
		inc rax
		add rcx, 8			;next list
		mov rcx, [rcx]
		jmp _start_loop
	_end_loop:
	ret

_end_function:
	ret
