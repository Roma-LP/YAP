.586P																; ������� ������ (��������� Pentium)
.MODEL FLAT, STDCALL 												; ������ ������, ������� ������ ������ , ���������� � �������
includelib kernel32.lib 											; ������������: ����������� � kerne132 	
includelib user32.lib
																		
ExitProcess PROTO : DWORD 											; �������� ������� ��� ���������� �������� Windows	
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD 				; �������� API-������� ��ssag����� 	
																		
.STACK 4096 														; ��������� ����� ������� 4 ��������� 	
																		
.CONST 																; ������� �������� 	
			arr  dd 1,2,3,4,5,6,7									; ������ ���������� 
			arr2 dd 1,2,3,4											; ������ ���������� 
															
.DATA 																; ������� ������	
			MB_OK   EQU  0 											; EQU ���������� ���������	

			myBytes   BYTE 10h,20h,30h,40h  
			myWords   WORD 8Ah,3Bh,44h,5Fh,99h
			myDoubles DWORD 1,2,3,4,5,6
			myPointer DWORD myDoubles
		
			HW      DD ? 											; ������� ����� ������ 4 �����, ������������������ 	
																		
.CODE 																; ������� ���� 	
			
				
main PROC 															; ����� ����� main 	
START :																; ����� 													
		
			mov ESI,0												; ������ esi
			mov EDX,0												; ������ edx
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
				jz  zero											; ���������� � 0 ( ���� == 0 �� � xym) 
				add esi,4
				mov eax,0
			loop povtor2
				mov ebx,1;
				 jmp kon
			zero:
				mov ebx,0
			kon:
				add ebx,0
					
					


	push - 1 														; ��� �������� �������� Windows(�������� ExitProcess)	
	call ExitProcess 												; ��� ����������� ����� ������� Windows 																			
main ENDP 															; ����� ���������		
																		
end main															; ����� ������ main 	
