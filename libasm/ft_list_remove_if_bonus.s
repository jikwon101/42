	global _ft_list_remove_if
	section .text
	extern _free

_ft_list_remove_if:			;rdi = &begin, rsi = ref, rdx = cmp, rcx = free
	cmp rdi, 0
	jz _return 	

	mov r8, 0x0				;r8 = previous list
	mov r9, [rdi]			;r9 = current list

	_start_loop:
		cmp r9, 0			;stop loop if current list is null
		jz _end_loop

		mov r13, r9			;r13 = next list
		add r13, 8
		mov r13, [r13]

		_0:					
		call _check_data	;cmp data with ref
		cmp rax, 0			;set next list if data does not eual
		jne _4

		_1:
		mov r15, [r9]		;set next list if data is null
		cmp r15, 0
		jz _4
		call _free_data		

		_2:
		call _free_list
		_3:
		call _next_list		;set next list when list is freed
		_4:					
		mov r8, r9
		mov r9, r13
		jmp _start_loop
	_end_loop:
	ret

_check_data:
	push rsi
	push rdi
	push rdx
	push rcx
	push r8
	push r9
	push r13
	push r10

	mov rdi, [r9]			;rdi = char *, rsi = ref_data
	call rdx
	
	pop r10
	pop r13
	pop r9
	pop r8
	pop rcx
	pop rdx
	pop rdi
	pop rsi

	ret

_next_list:
	cmp r8, 0				;r8 = previous list
	jz _begin
	cmp r8, 0
	jne _not_begin

	_begin:					;if list if the begin list
		mov r8, 0
		mov r9, r13
		mov [rdi], r13
		jmp _start_loop
	_not_begin:
		mov [r8 + 8], r13
		mov r9, r13
		jmp _start_loop
	ret

_free_data:
	push rdi
	push rsi
	push rdx
	push rcx
	push r9
	push r8
	push r13
	push r10

	mov rdi, [r9]			;rdi = char *
	call rcx
	pop r10
	pop r13
	pop r8
	pop r9
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	ret

_free_list:
	push rdi
	push rsi
	push rdx
	push rcx
	push r8
	push r13

	mov rdi, r9				;rdi = t_list *
	call _free

	pop r13
	pop r8
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	ret

_return:
	ret
