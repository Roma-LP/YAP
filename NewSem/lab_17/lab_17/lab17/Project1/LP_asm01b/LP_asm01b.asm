; LP_asm01b.exe
.586

.model flat,stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
GetStdHandle PROTO : DWORD
SetConsoleTitleA PROTO: DWORD
includelib libucrt.lib
includelib C:\БГТУ\ЯП\lab_17\lab17\Project1\Debug\LP_asm01a.lib
getmin PROTO, pArray: PTR sdword,
			 countOfElements: sdword

getmax PROTO, pArray: PTR sdword,
			  countOfElements: sdword

WriteConsoleA PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

printConsole PROTO pstr: dword, _size: dword

intToString PROTO number: sdword, pstr: dword 


.stack 4096


.const

	consoletitle db 'LAB 17', 0

	
.data
consolehandle dd 0h 
array sdword 1 dup(1,-2,-3,-4,-5,-6,-7,-8,-9,-10)
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
cdq						; знак распространили с eax на edx 
mov ebx, 10				; десятичная система счисления
idiv ebx				; aex = eax/ebx, остаток -> edx
test eax, 80000000h		; результат отрицательный ?
jz plus					; если положительный на plus
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
