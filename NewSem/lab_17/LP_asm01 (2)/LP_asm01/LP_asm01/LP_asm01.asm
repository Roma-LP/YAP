.586
.model flat, stdcall
includelib kernel32.lib

ExitProcess PROTO : dword

.stack 4096

.data
	min sdword ?

.const
	array sdword -1, 32, 46, 15, 24, -13, 2, 9, 15, 0

.code

getmin PROC a : dword, l : dword
	mov esi, a
	mov ecx, l
	mov eax, [esi]
Start:
	cmp [esi], eax
	jl Lower
	jmp Next
Lower: 
	mov eax, [esi]
Next:
	add esi, 4
	loop Start
	ret
getmin ENDP

main PROC
	invoke getmin, offset array, lengthof array
	mov min, eax
	push 0
	call ExitProcess
main ENDP

end main