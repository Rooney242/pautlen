;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	global _msbA,  _msbB, _BmsbA, _msbC, _CmsbA, _CmsbB, _no_defined_method, _mcA, _mcB, _mcC,  _set_offsets, _create_ms_table, _offset_msbA, _offset_msbB,  _offset_msbC,  _offset_aia, _offset_aib, _offset_aic, _msA, _msB, _msC, _aca, _acb, _acc


segment .data
	msg_error_indice_vector     db "Indice de vector fuera de rango", 0
	msg_asignacion     db "Asignacion", 0
	msg_f2     db "Llamada a f2", 0
	__auxfloat dd 0.0
	__auxint dd 0.0
; SET METODOS SOBREESCRIBIBLES OFFSET
; SE ESTÁ SUPONIENDO LA LINEALIZACIÓN  A B C D
; RESPECTO A MÉTODOS SOBREESCRIBIBLES CADA UNA TIENE 2 DE NOMBRES RESPECTIVAMENTE 
; (ms)A1 (ms)A2 (m2)B2 (ms)B2 (ms)C1 (ms)C2 (ms)D1 (ms)D2
	_offset_msbA dd 0    ; ESTO SE DEBE ESCRIBIR CUANDO SE ESCRIBA LA TABLA DE SÍMBOLOS Y SE ENCUENTRE UN MÉTODO SOBREESCRIBIBLE
	_offset_msbB dd 4
	_offset_msbC dd 8

; SET ATRIBUTOS INSTANCIA OFFSET
; SE ESTÁ SUPONIENDO LA LINEALIZACIÓN  A B C D
; RESPECTO ATRIBUTOS DE INSTANCIA CADA UNA TIENE 2 DE NOMBRES RESPECTIVAMENTE 
; (ai)A1 (ai)A2 (ai)B2 (ai)B2 (ai)C1 (ai)C2 (ai)D1 (ai)D2
; DEBEN PRESERVAR UNA POSICIÓN (4 bytes) PARA EL PUNTERO A LA TABLA DE MÉTODOS SOBREESCRIBIBLES
	_offset_aia dd 4 ; 4+0      ; ESTO SE DEBE ESCRIBIR CUANDO SE ESCRIBA LA TABLA DE SIMBOLOS Y SE ENCUENTRE UN ATRIBUTO DE INSTANCIA
	_offset_aib dd 8 ; 4+4
	_offset_aic dd 12 ; 4+8
	
segment .bss
	__esp resd 4
; Class A
	_msA resd 1
; Class B
	_msB resd 2
; Class C
	_msC resd 3
; LOS ATRIBUTOS DE CLASE
	_aca resd 1
	_acb resd 1
	_acc resd 1
segment .text
	;global main



; Es necesario malloc y free por el instanceof y el del
	extern malloc, free
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float

; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
; En Class A
_msbA:
	push dword 2
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class B
_msbB:
	push dword 4
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C
_msbC:
	push dword 7
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class B se sobreescirbe 
_BmsbA:
	push dword 5
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C se sobreescirbe 
_CmsbA:
	push dword 9
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C se sobreescirbe 
_CmsbB:
	push dword 8
	call print_int
	add esp,4
	call print_endofline
	ret
_no_defined_method:
	push dword 0
	call print_int
	add esp,4
	call print_endofline
	ret
; LOS MÉTODOS NO SOBREESCRIBIBLES
_mcA:
	push dword 1
	call print_int
	add esp,4
	call print_endofline
	ret
_mcB:
	push dword 3
	call print_int
	add esp,4
	call print_endofline
	ret
_mcC:
	push dword 7
	call print_int
	add esp,4
	call print_endofline
	ret
; SET OFFSETS SE HA IMPLEMENTADO EN ESTE EJEMPLO EN data
_set_offsets:
; ESTA HECHO COMO PARTE DEL SEGMENT .data
	ret
; CREATE MS TABLE
_create_ms_table:
	mov dword [_msA], _msbA		
; B SOBRE ESCRIBE msA
	mov dword [_msB], _BmsbA		
	mov dword [_msB+4], _msbB		
; C SOBRE ESCRIBE msA
	mov dword [_msC], _CmsbA		
; C SOBRE ESCRIBE msB
	mov dword [_msC+4], _CmsbB		
	mov dword [_msC+8], _msbC
	ret