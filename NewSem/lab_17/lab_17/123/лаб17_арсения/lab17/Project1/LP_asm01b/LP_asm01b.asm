.586

.model flat,stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
GetStdHandle PROTO : DWORD
SetConsoleTitleA PROTO: DWORD
;includelib A:\\education\\2k1s\\Labs\\LP\\lab17\\Project1\\Debug\\LP_asm01a.lib
includelib C:\\¡√“”\\ﬂœ\\lab_17\\lab17\\\Project1\\\Debug\\LP_asm01a.lib
getmin PROTO, pArray: PTR sdword,
			 countOfElements: sdword

getmax PROTO, pArray: PTR sdword,
			  countOfElements: sdword

WriteConsoleA PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

printConsole PROTO pstr: dword, _size: dword

intToString PROTO number: sdword, pstr: dword 


.stack 4096


.const

	consoletitle db 'LAB 17---', 0

	
.data
consolehandle dd 0h 
array sdword 10 dup(-1)
min sdword  0
iResult sdword 0
strResult dword 40 dup(0)

.code

printConsole PROC  pstr: dword, _size: dword
push eax
INVOKE GetStdHandle, -11
INVOKE WriteConsoleA, eax, pstr, _size, 0, 0 
pop eax
ret
printConsole ENDP

intToString PROC number: sdword, pstr: dword
push eax
push ebx
push ecx
push edi
push esi

mov edi, pstr
mov esi, 0
mov eax, number
cdq
mov ebx, 10
idiv ebx
test eax, 80000000h
jz plus
neg eax
neg edx
mov cl, '-'
mov [edi], cl
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
		mov ecx, esi
write:
		pop bx
		add bl, '0'
		mov [edi],bl
		inc edi
		loop write


pop esi
pop edi
pop ecx
pop ebx
pop eax
ret
intToString ENDP 
main PROC
	mov array, -4
	mov array+4, -3
	mov array+8, -2
	mov array+12, -1
	mov array+16, -1
	mov array+20, -5
	mov array+24, -6
	mov array+28, -7
	mov array+32, -9
	mov array+36, -5
	INVOKE getmin, ADDR array,  lengthof array
	mov min, eax
	INVOKE getmax, ADDR array,  lengthof array
	mov iResult, eax
	mov eax, min
	sub iResult, eax
	INVOKE SetConsoleTitleA, ADDR consoletitle
	INVOKE intToString, iResult, ADDR strResult
	INVOKE printConsole, ADDR strResult, sizeof strResult
	push 0
	call ExitProcess

	 

	
main ENDP

end main
