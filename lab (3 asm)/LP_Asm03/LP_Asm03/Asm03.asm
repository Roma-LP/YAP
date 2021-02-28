.586P																; система команд (процессор Pentium)
.MODEL FLAT, STDCALL 												; модель памяти, Плоская модель памяти , соглашение о вызовах
includelib kernel32.lib 											; компановщику: компоновать с kerne132 	
includelib user32.lib
																		
ExitProcess PROTO : DWORD 											; прототип функции для завершения процесса Windows	
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD 				; прототип API-функции МеssagеВохА 	
																		
.STACK 4096 														; вьдепение стека объемом 4 мегабайта 	
																		
.CONST 																; сегмент констант 	
			arr  dd 1,2,3,4,5,6,7									; массив переменных 
			arr2 dd 1,2,3,4											; массив переменных 
															
.DATA 																; сегмент данных	
			MB_OK   EQU  0 											; EQU определяет константу	

			myBytes   BYTE 10h,20h,30h,40h  
			myWords   WORD 8Ah,3Bh,44h,5Fh,99h
			myDoubles DWORD 1,2,3,4,5,6
			myPointer DWORD myDoubles
		
			HW      DD ? 											; двойное слово длиной 4 байта, неинициапицировано 	
																		
.CODE 																; сегмент кода 	
			
				
main PROC 															; точка входа main 	
START :																; метка 													
		
			mov ESI,0												; очищаю esi
			mov EDX,0												; очищаю edx
			mov EAX,myDoubles[ESI+4]								
			mov EDX,[myDoubles + ESI]								 

			mov esi, offset arr										; c-1
			mov eax, 0
			mov ecx, 7
			povtor:
				add eax, [esi]
				add esi, 4
			loop povtor

			mov esi, offset arr2
			mov eax, 0
			mov ecx, 4
			povtor2:
				add eax, [esi]
				jz  zero											; сравнивает с 0 ( если == 0 то в xym) 
				add esi,4
				mov eax,0
			loop povtor2
				mov ebx,1;
				 jmp kon
			zero:
				mov ebx,0
			kon:
				add ebx,0
					
					


	push - 1 														; код возврата процесса Windows(параметр ExitProcess)	
	call ExitProcess 												; так завершается любой процесс Windows 																			
main ENDP 															; конец процедуры		
																		
end main															; конец модуля main 	
