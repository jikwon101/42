	global _ft_list_push_front
	section .text
	extern _malloc

_ft_list_push_front:			;rdi = t_list **begin_list, rsi = void *data
	cmp rdi, 0
	jz _end
	mov r8, [rdi]
	cmp r8, 0
	jz _first_list
	call _create_elem
	mov [rax + 8], r8			;new list->next =  [rdi]
	mov [rax], rsi				;new list->data = rsi
	mov [rdi], rax				;[rdi] = new_list
	jmp _end

_first_list:
	call _create_elem
	mov [rdi], rax				;[rdi] = new_list
	mov [rax], rsi				;new_list->data = rsi
	mov qword [rax + 8], 0x0	;new_list->next = NULL
	jmp _end

_create_elem:
	push rdi
	push rsi
	push r8
	push rsp

	mov rdi, 16					;t_list **(8byte) + void *(8byte) = 16bybte
	mov rax, 0
	call _malloc				;malloc 1 of t_size *

	pop rsp
	pop r8
	pop rsi
	pop rdi

	cmp rax, 0					;if malloc does not succeed stpp function
	jz _end
	ret

_end:
	ret
