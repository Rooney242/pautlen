segment .data
	msg_div_cero	db "Error division por 0", 0
	msg_vector	db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_m resd 1
	_d1 resd 1
	_c1 resd 1
	_c2 resd 1
	_c3 resd 1
	_vector_int resd 4
	_Vobjs resd 3
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float,scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern malloc, free, ld_float
	extern  _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1, _offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1
_main_factorial@o2:
	push ebp
	mov ebp, esp
	sub esp, 8
	push 24
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msC
	lea eax, [ebp-8]
	push dword eax
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword 9999
	lea eax, [ebp-8]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	lea eax, [ebp-8]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword 111111
	lea eax, [ebp-8]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	lea eax, [ebp-8]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword 100
	lea eax, [ebp-4]
	push dword eax
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	lea eax, [ebp-4]
	push dword eax
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword 333
	lea eax, [ebp+8]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	lea eax, [ebp+8]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	lea eax, [ebp-4]
	push dword eax
	lea eax, [ebp-8]
	push dword eax
	pop dword eax
	mov eax, [eax]
	mov dword esp, ebp
	pop dword ebp
	ret
; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
main:
	mov dword [__esp] , esp
	call _create_ms_table
	push 24
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msC
	push dword _c1
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword 99
	push dword _c1
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword _c1
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _c1
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msA1]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _c1
	pop eax
	push dword [eax]
	call _main_factorial@o2
	add esp, 4
	push dword eax
	pop dword eax
	mov dword [_c2], eax
	push dword _c1
	pop dword eax
	mov dword ebx, [eax]
	push dword [eax]
	call free
	add esp, 4
	push dword _c2
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push 32
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msD
	push dword _d1
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push 24
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msC
	push dword _d1
	pop dword ebx
	mov dword ecx, [_offset_aiD2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword _d1
	pop dword ebx
	mov dword ecx, [_offset_aiD2]
	lea ecx, [ebx+ecx]
	push ecx
	push dword _c1
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov [eax], ebx
	push dword 99
	push dword _c1
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword 20
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword _m
	push dword 0
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jg near _mayor_1
	push 0
	jmp near _fin_mayor_1
_mayor_1:
	push 1
_fin_mayor_1:
	pop eax
	cmp eax, 0
	je near _fin_si_1
	push dword 0
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	push dword 2
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jg near _mayor_2
	push 0
	jmp near _fin_mayor_2
_mayor_2:
	push 1
_fin_mayor_2:
	push dword 22
	call print_int
	add esp, 4
	call print_endofline
_fin_sino_2:
_inicio_while_3:
	push dword _m
	push dword 0
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jge near _mayor_igual_3
	push 0
	jmp near _fin_mayor_igual_3
_mayor_igual_3:
	push 1
_fin_mayor_igual_3:
	pop eax
	cmp eax, 0
	je near _fin_while_3
	push dword _m
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	push dword 1
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	sub eax, edx
	push dword eax
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	jmp near _inicio_while_3
_fin_while_3:
	jmp near _fin_sino_1
_fin_si_1:
	push dword 1
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	push dword -11
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jl near _menor_4
	push 0
	jmp near _fin_menor_4
_menor_4:
	push 1
_fin_menor_4:
	push dword -11
	call print_int
	add esp, 4
	call print_endofline
_fin_sino_4:
_fin_sino_1:
	push dword 0
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
_inicio_while_5:
	push dword _m
	push dword 3
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jle near _menor_igual_5
	push 0
	jmp near _fin_menor_igual_5
_menor_igual_5:
	push 1
_fin_menor_igual_5:
	pop eax
	cmp eax, 0
	je near _fin_while_5
	push dword _m
	push dword 10
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	imul edx
	push dword eax
	push dword _m
	pop dword eax
	mov dword eax , [eax]
	cmp eax,0
	jl near error_vector
	cmp eax, 3
	jg near error_vector
	mov dword edx, _vector_int
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword _m
	pop dword eax
	mov dword eax , [eax]
	cmp eax,0
	jl near error_vector
	cmp eax, 3
	jg near error_vector
	mov dword edx, _vector_int
	lea eax, [edx + eax*4]
	push dword eax
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	push dword 1
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	add eax, edx
	push dword eax
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	jmp near _inicio_while_5
_fin_while_5:
	push dword 2
	pop dword eax
	cmp eax,0
	jl near error_vector
	cmp eax, 3
	jg near error_vector
	mov dword edx, _vector_int
	lea eax, [edx + eax*4]
	push dword eax
	push dword _m
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov [eax], ebx
	push dword _m
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword 999999999
	call print_int
	add esp, 4
	call print_endofline
	push 16
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msB
	push dword 0
	pop dword eax
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push 24
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msC
	push dword 1
	pop dword eax
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push 32
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msD
	push dword 2
	pop dword eax
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword 0
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
_inicio_while_6:
	push dword _m
	push dword 2
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jle near _menor_igual_6
	push 0
	jmp near _fin_menor_igual_6
_menor_igual_6:
	push 1
_fin_menor_igual_6:
	pop eax
	cmp eax, 0
	je near _fin_while_6
	push dword _m
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	pop dword eax
	mov dword eax , [eax]
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msA1]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _m
	pop dword eax
	mov dword eax , [eax]
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov dword ebx, [ebx]
	mov dword ecx, [_offset_msA2]
	lea ecx, [ebx+ecx]
	mov ecx, [ecx]
	call ecx
	push dword _m
	push dword 1
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	add eax, edx
	push dword eax
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	jmp near _inicio_while_6
_fin_while_6:
	push dword 0
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
_inicio_while_7:
	push dword _m
	push dword 2
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	cmp eax, edx
	jle near _menor_igual_7
	push 0
	jmp near _fin_menor_igual_7
_menor_igual_7:
	push 1
_fin_menor_igual_7:
	pop eax
	cmp eax, 0
	je near _fin_while_7
	push dword _m
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _m
	pop dword eax
	mov dword eax , [eax]
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	mov dword ebx, [eax]
	push dword [eax]
	call free
	add esp, 4
	push dword _m
	push dword 1
	pop dword edx
	pop dword eax
	mov eax, dword [eax]
	add eax, edx
	push dword eax
	push dword _m
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	jmp near _inicio_while_7
_fin_while_7:
	push dword _c2
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _c2
	push dword 2
	pop dword eax
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov [eax], ebx
	push 24
	call malloc
	add esp, 4
	push eax
	mov dword [eax], _msC
	push dword _c3
	pop dword eax
	pop dword ebx
	mov [eax], ebx
	push dword 2
	pop dword eax
	cmp eax,0
	jl near error_vector
	cmp eax, 2
	jg near error_vector
	mov dword edx, _Vobjs
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	push dword _c3
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	pop dword ebx
	mov dword ebx, [ebx]
	mov [eax], ebx
	push dword _c3
	pop dword ebx
	mov dword ecx, [_offset_aiC2]
	lea ecx, [ebx+ecx]
	push ecx
	pop eax
	push dword [eax]
	call print_int
	add esp, 4
	call print_endofline
	push dword _c3
	pop dword eax
	mov dword ebx, [eax]
	push dword [eax]
	call free
	add esp, 4
	push dword _c2
	pop dword eax
	mov dword ebx, [eax]
	push dword [eax]
	call free
	add esp, 4
	push dword _d1
	pop dword ebx
	mov dword ecx, [_offset_aiD2]
	lea ecx, [ebx+ecx]
	push ecx
	pop dword eax
	mov dword ebx, [eax]
	push dword [eax]
	call free
	add esp, 4
	push dword _d1
	pop dword eax
	mov dword ebx, [eax]
	push dword [eax]
	call free
	add esp, 4
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
