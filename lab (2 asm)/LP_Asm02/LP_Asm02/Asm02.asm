.586P																; ������� ������ (��������� Pentium)
.MODEL FLAT, STDCALL 												; ������ ������, ������� ������ ������ , ���������� � �������
includelib kernel32.lib 											; ������������: ����������� � kerne132 	
includelib user32.lib
																		
ExitProcess PROTO : DWORD 											; �������� ������� ��� ���������� �������� Windows	
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD 				; �������� API-������� ��ssag����� 	
																		
.STACK 4096 														; ��������� ����� ������� 4 ��������� 	
																		
.CONST 																; ������� �������� 	
																		
.DATA 																; ������� ������	
MB_OK   EQU  0 														; EQU ���������� ���������	
STR1    DB   "��� ������ ���������", 0 								; ������, ������ ������� ������ + ������� ���	
STR2    DB   "��������� = "											; ������, ������ ������� ������ 
number_2    DD   2
number_1    DD   3
HW      DD ? 															; ������� ����� ������ 4 �����, ������������������ 	
																		
.CODE 																; ������� ���� 	
																		
main PROC 															; ����� ����� main 	
START :																; ����� 													
		
		mov eax, number_1
		add number_2,eax
		add number_2, '0'

		INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK			
					
	push - 1 														; ��� �������� �������� Windows(�������� ExitProcess)	
	call ExitProcess 												; ��� ����������� ����� ������� Windows 																			
main ENDP 															; ����� ���������		
																		
end main															; ����� ������ main 	
