	global _ft_list_sort
	section .text
	extern _ft_list_size


_ft_list_sort:
	cmp rdi, 0				;if ;&begin = NULL , ends function
	jz _end_function
	mov r8, [rdi]			;if begin = NULL, ends function
	cmp r8, 0
	jz _end_function
	push rdi 				;save addr of begin list
	mov rdi, [rdi]  		;begin list
	call _ft_list_size		
	pop rdi
	mov r8, rax				;r8 = size of list
	_start_loop:			;run loop as much as the size of list
		cmp r8, 0
		jz _end_loop
		push rdi
		push rsi
		push r8
		call _main_cmp
		pop r8
		dec r8
		pop rsi
		pop rdi
		jmp _start_loop
	_end_loop:
	ret

_main_cmp :
	mov r14, rsi			;cmp function
	mov r10, [rdi]			;r10 = begin list
	mov r11, r10			;r11 = next list = [r10 + 8]
	add r11, 8	
	mov r11, [r11]
	mov r9, 0				;r9 = previous list

	_start_loop2:
		cmp r11, 0x0		;if next list is NULL, stop loop
		jz _end_loop2
		
		push rsi			;save &cmp function
		push rdi			;save &begin
		push r14
		push r11
		push r10
		push r9

		mov rdi, [r10]		;rdi = addr of data of current list
		mov rsi, [r11]		;rdi = addr of data of next list
		call r14			;call cmp function
		
		pop r9
		pop r10
		pop r11
		pop r14
		pop rdi
		pop rsi
		
		cmp rax, 0			;rax = the diffrences btw two dataes
		jg _switch			;if rax is positive, need to be switched
		
		mov r9, r10			;if rax is negative, doesnt need. 
		mov r10, r11		;set the next addr to be checked
		add r11, 8
		mov r11, [r11]
		jmp _start_loop2
	_end_loop2:
	ret

_switch:
	cmp r9, 0				;if r9 is NULL, it means r10 is the begin list.
	jz _begin_list
	push r10
	
	mov [r9 + 8], r11	
	
	mov r13, r11			;r13 = temporaily save the next list of r11
	add r13, 8
	mov r13, [r13]

	mov [r10 + 8], r13
	mov [r11 + 8], r10


	mov r9, r11				;set the next addr to be checked
	pop r10
	mov r11, r10
	add r11, 8
	mov r11, [r11]
	
	jmp _start_loop2

	
_begin_list:
	push r10
	mov [rdi], r11

	mov r13, r11			;r13 = temporaily save the next list of r11
	add r13, 8
	mov r13, [r13]

	mov [r10 + 8], r13
	mov [r11 + 8], r10

	mov r9, r11				;set the next addr to be checked
	pop r10
	mov r11, r10
	add r11, 8
	mov r11, [r11]
	jmp _start_loop2

_end_function:
	ret

