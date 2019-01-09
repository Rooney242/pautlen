segment .data
	msg_div_cero	db "Error division por 0", 0
	msg_vector	db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_main_x2 resd 1
	_main_x1 resd 0
	_main_y1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float,scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern malloc, free, ld_float
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:
	mov dword [__esp] , esp
	push _main_x1
	call scan_int
	add esp, 4
	push _main_x2
	call scan_int
	add esp, 4
	push dword 3
	push dword _main_x1
	pop dword edx
	pop dword eax
	mov edx, dword [edx]
	add eax, edx
	push dword eax
	push dword _main_x2
	pop dword edx
	pop dword eax
	mov edx, dword [edx]
	add eax, edx
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	push dword _main_x1
	push dword _main_x2
	pop dword edx
	pop dword eax
	mov edx, dword [edx]
	mov eax, dword [eax]
	cmp eax, edx
	je near _igual_1
	push 0
	jmp near _fin_igual_1
_igual_1:
	push 1
_fin_igual_1:
	pop dword eax
	mov dword [_main_y1], eax
	push dword _main_y1
	push dword _main_y1
	pop eax
	push dword [eax]
	call print_boolean
	add esp, 4
	call print_endofline
	push dword _main_x1
	push dword _main_x2
	pop dword edx
	pop dword eax
	mov edx, dword [edx]
	mov eax, dword [eax]
	cmp eax, edx
	je near _igual_2
	push 0
	jmp near _fin_igual_2
_igual_2:
	push 1
_fin_igual_2:
	pop eax
	cmp eax, 0
	je near _fin_si_0
	push dword 1
	call print_int
	add esp, 4
	call print_endofline
	jmp near _fin_sino_3
_fin_si_3:
	push dword 0
	call print_int
	add esp, 4
	call print_endofline
_fin_sino_3:
fin:
	mov dword esp, [__esp]
	ret
error_div_cero:
	push dword msg_div_cero
	call print_string
	add esp, 4
	call print_endofline
	ret
error_vector:
	push dword msg_vector
	call print_string
	add esp, 4
	call print_endofline
	ret
