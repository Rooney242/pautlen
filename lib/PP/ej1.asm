segment .data
	msg_div_cero	db "ERROR: DIVISOR ES CERO", 0
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float,scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:
	mov dword [__esp] , esp
	push dword 8
	pop dword eax
	mov dword [_x], eax
	push dword _y
	call scan_int
	add esp, 4
	push dword [_x]
	push dword [_y]
	pop dword edx
	pop dword eax
	mov edx, [edx]
	mov eax, [eax]
	add eax, edx
	push dword eax
	pop dword eax
	mov dword [_z], eax
	push dword [_z]
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword 7
	push dword [_y]
	pop dword edx
	pop dword eax
	mov edx, [edx]
	add eax, edx
	push dword eax
	pop dword eax
	mov dword [_z], eax
	push dword [_z]
	pop eax
	push dword [eax]
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
