.586

.model flat,stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
getmin PROTO, pArray: PTR sdword,
			 countOfElements: sdword

getmax PROTO, pArray: PTR sdword,
			  countOfElements: sdword

.stack 4096

.const

.data

.code
getmax PROC, pArray: PTR sdword,
			 countOfElements: sdword

	push ebx
	push ecx
	push esi
	mov ecx, countOfElements 

	mov esi, pArray
	
	mov ebx,  -2147483648

	CYCLE:
	mov eax, [esi]
	cmp eax, ebx

	jg isGreater
	jmp isLess

	isGreater: 
	mov ebx, eax
	isLess:
	add esi, 4
	loop CYCLE

	mov eax, ebx
	pop esi
	pop ecx
	pop ebx
	ret
	getmax ENDP

getmin PROC, pArray: PTR sdword,
			 countOfElements: sdword,

	push ebx
	push ecx
	push esi
	mov ecx, countOfElements ; выполняет роль счетчика цикла
	mov esi, pArray
	
	mov ebx, 2147483647

	CYCLE:
	mov eax, [esi]
	cmp eax, ebx
	
	jl isLess

	jmp isGreater

	isLess: 
	mov ebx, eax
	isGreater:
	add esi, 4
	loop CYCLE

	mov eax, ebx
	pop esi
	pop ecx
	pop ebx
	ret
	getmin ENDP
	
END