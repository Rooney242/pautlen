segment .data
	msg_error_indice_vector   	db "Indice de vector fuera de rango", 0
	msg_error_division	     	db "Error division por 0", 0
segment .bss
	__esp resd 1
	_c1 resd 1
segment .text
	global main
	extern scan_int, print_int, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
extern malloc, free
extern  _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1, 	_offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1

main:
	mov dword [__esp], esp
	call _create_ms_table
	push dword 1111
	call print_int
	add esp,4
	call print_endofline

	call _BmsA1

	jmp near fin
fin_error_division: 
	push dword msg_error_division
	call print_string
	add esp, 4
	call print_endofline 
	jmp near fin
fin_indice_fuera_rango: 
	push dword msg_error_indice_vector
	call print_string
	add esp, 4
	call print_endofline 
	jmp near fin
fin: 
	mov esp, [__esp]
	ret
