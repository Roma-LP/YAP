.586
.model flat, stdcall
includelib kernel32.lib

getmin PROTO : dword, : dword
getmax PROTO : dword, : dword

.stack 4096

.const

.data

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

getmax PROC a : dword, l : dword
	mov esi, a
	mov ecx, l
	mov eax, [esi]
Start:
	cmp [esi], eax
	jg Greater
	jmp Next
Greater: 
	mov eax, [esi]
Next:
	add esi, 4
	loop Start
	ret
getmax ENDP

end