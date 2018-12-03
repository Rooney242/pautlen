global _offset_msA, _offset_msB, _offset_msC, _ms_A, _ms_B, _ms_C, _msA, _BmsA, _CmsA, _msB, _CmsB, _msC

segment .data

_offset_msA dd 0
_offset_msB dd 4
_offset_msC dd 8

segment .bss
;NO sabemos que es esto
__esp resd 4
; Class A
_ms_A resd 2
; Class B
_ms_B resd 4
; Class C
_ms_C resd 6

segment .text

_msA:
	push dword 2
	call print_int
	add esp,4
	call print_endofline
	mov eax 2
	ret

_BmsA:
	push dword 5
	call print_int
	add esp,4
	call print_endofline
	mov eax, 5
	ret

_msB:
	push dword 4
	call print_int
	add esp,4
	call print_endofline
	mov eax 4
	ret

_CmsA:
	push dword 9
	call print_int
	add esp,4
	call print_endofline
	mov eax 9
	ret

_CmsB:
	push dword 8
	call print_int
	add esp,4
	call print_endofline
	mov eax 8
	ret

_msC:
	push dword 7
	call print_int
	add esp,4
	call print_endofline
	mov eax 7
	ret

_no_defined_method:
	push dword 0
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
	mov dword [_ms_A], _msA			

	mov dword [_ms_B], _BmsA		
	mov dword [_ms_B+4], _msB			

	mov dword [_ms_C], _CmsA		
	mov dword [_ms_C+4], _CmsB		
	mov dword [_ms_C+8], _msC		
