.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib LP_asm01d.lib

ExitProcess PROTO : dword
GetStdHandle PROTO : dword									
WriteConsoleA PROTO : dword, : dword, : dword, : dword, : dword	
SetConsoleTitleA PROTO: dword	

EXTRN getmin : proc
EXTRN getmax : proc

.stack 4096

.data
	min sdword ?
	max sdword ?
	dif sdword ?
	result byte 4 dup(0)
	consoleHandle dword 0h
	
.const
	array sdword -1, 32, 56, 15, 24, -13, 2, 9, 45, 0
	consoleTitle	byte		'LP_asm01', 0
	text			byte		'getmax - getmin = ', 0							
	handleOutput	sdword		-11

.code

GetDifference PROC pstr : dword, presult : sdword
    mov eax, presult
	mov edi, pstr
    mov esi, 0
    cdq
    mov ebx, 10
    idiv ebx
    test eax, 80000000h
    jz plus
    neg eax
    neg edx
    mov cl, '-'
    mov[edi], cl
    inc edi
plus:
    push dx
    inc esi
    test eax, eax
    jz fin
    cdq
    idiv ebx
    jmp plus
fin:
    mov ecx ,esi
write:
    pop bx
    add bl,'0'
    mov [edi], bl
    inc edi
    loop write
    ret
GetDifference ENDP

main PROC
	invoke SetConsoleTitleA, offset consoleTitle		
	invoke GetStdHandle, handleOutput			        
	mov consoleHandle, eax	

	push lengthof array
	push offset array
	call getmin
	mov min, eax
	push lengthof array
	push offset array
	call getmax
	mov max, eax

	invoke WriteConsoleA, consoleHandle, offset text, sizeof text, 0, 0
    mov eax, max
	sub eax, min
    mov dif, eax
	invoke GetDifference, offset result, dif
	invoke WriteConsoleA, consoleHandle, offset result, sizeof result, 0, 0	

	push 0
	call ExitProcess
main ENDP

end main