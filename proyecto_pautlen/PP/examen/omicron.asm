segment .data
	msg_div_cero	db "Error division por 0", 0
	msg_vector	db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_main_x2 resd 1
	_main_x1 resd 0
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
