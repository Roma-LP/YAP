.586P ; ��������� ������ � ����������� ���� �������
.MODEL FLAT, STDCALL ; ������� ������ ������ FLAT ��� ������(�������� � 32 ������ ���������) 
includelib kernel32.lib ;������� ��� ����������� ���������  kernel32.lib ������� ���������� ������� ExitProcess
includelib user32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, :DWORD, : DWORD, :DWORD

.STACK 4096

.CONST 
pupa dd 1,2,1,1,2,1,1 ; ������ ���������� 
.DATA
myBytes BYTE 10h,20h,30h,40h ; 
myWords WORD 8Ah,3Bh,44h,5Fh,99h
myDoubles DWORD 1,2,3,4,5,6
myPointer DWORD myDoubles
MB_OK EQU 0
STR1 DB"���������� �.�. 1-6",0
STR2 DB "��������� : " 
b dd 0,0
HW   DD ?
.CODE

main PROC
START :
mov ESI,0 ;������ esi
mov EAX,myDoubles[ESI] ; ������� ����� ��������� �� esi � eax 
mov EDX,[myDoubles + ESI] ;������� ����� ��������� �� esi + myDoubles � edx 


mov EAX,0
mov esi ,offset pupa
mov ECX,7 ; 7 ������ � ecx
CYRCLE:
add eax,[esi] ; 
add esi, 4
loop CYRCLE; ��������� �������� �� ��������� ecx 7 
mov ECX,7
mov ebx,0 
mov esi ,offset pupa
CYRC:
add ebx,[esi] ; ���������� �������� esi
jz xym ; ���������� �������� � 0 ( ���� =0 �� � xym)
add esi, 4
mov ebx,0
loop CYRC
mov ebx,1
jmp en ; ���� goto
xym:
mov ebx,0
en: 
add b,ebx
add b,'0'
INVOKE  MessageBoxA,HW,  OFFSET STR2,OFFSET str1 , MB_OK ; ������ ���������� ������� MessageBoxA HW ���������� ����	OFFSET ���������� � ��������� MB_OK ���������� ������ 


	push - 1
	call ExitProcess

main ENDP

end main