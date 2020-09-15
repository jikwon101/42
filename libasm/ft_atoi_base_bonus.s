	global _ft_atoi_base
	section .text
_ft_atoi_base:
	mov rax, 1
	call _check_space
	call _check_sign
	push rax  			;save sign
	call _read_num
	mov r12, rax
	pop rax
	mul r12
	ret

_check_space:
	mov rax, 1 			;sign
	mov rcx, 0x0 		;count str  
	_start_loop1:
		mov dl, byte [rdi + rcx]
		inc rcx 
		cmp dl, ' '
		jz _start_loop1
		cmp dl, 9 		; 9 ~ 13 = { \t, \f, \v, \r, \n }
		jb _end_loop1
		cmp dl, 13
		ja _end_loop1
		jmp _start_loop1
	_end_loop1:
	sub rcx, 1
	ret 

_check_sign:
	_start_loop:
		mov dl, byte [rdi + rcx]
		inc rcx
		cmp dl, '+'
		jz _start_loop
		cmp dl, '-'
		jne _end_loop		
		call _set_minus
		jmp _start_loop
	_end_loop:
	sub rcx, 1
	ret

_set_minus:
	mov rdx, -1
	mul rdx
	ret

_read_num:
	mov rax, 0x0
	push rcx
	call _ft_baselen				;move base_len to r12
	pop rcx
	_start_loop3:
		mov dl, 0
		mov dl, byte [rdi + rcx]
		cmp dl, 0x0
		jz _end_loop3
		push r12
		call _find_base				;move base_num to r13
		pop r12
		cmp r13, -1
		jz _end_loop3
		mul r12
		add rax, r13
		inc rcx
		jmp _start_loop3
	_end_loop3:
	ret

_ft_baselen:
	mov r12, 0x0
	_start_loop4 : 
		cmp byte [rsi + r12], 0x0
		jz _end_loop4
		inc r12
		jmp _start_loop4
	_end_loop4:
	ret

_find_base:
	mov r14, 0					;count base index
	mov r13, -1
	_start_loop5:
		cmp r14, r12			;r12 = base_len
		jae _end_loop5
		mov bl, byte [rsi + r14]
		mov r13, r14
		cmp bl, dl
		jz _end_loop5
		mov r13, -1
		inc r14
		jmp _start_loop5
	_end_loop5:
	ret

