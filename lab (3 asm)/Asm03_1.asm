.586P ; опрделяет работу с процессором типа пентиум
.MODEL FLAT, STDCALL ; сегмент модели памяти FLAT тип памяти(работает с 32 битным регистром) 
includelib kernel32.lib ;команда для подключения библиотек  kernel32.lib команда содержащая функцию ExitProcess
includelib user32.lib

ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, :DWORD, : DWORD, :DWORD

.STACK 4096

.CONST 
pupa dd 1,2,1,1,2,1,1 ; массив переменных 
.DATA
myBytes BYTE 10h,20h,30h,40h ; 
myWords WORD 8Ah,3Bh,44h,5Fh,99h
myDoubles DWORD 1,2,3,4,5,6
myPointer DWORD myDoubles
MB_OK EQU 0
STR1 DB"Островский А.Ю. 1-6",0
STR2 DB "Результат : " 
b dd 0,0
HW   DD ?
.CODE

main PROC
START :
mov ESI,0 ;очищаю esi
mov EAX,myDoubles[ESI] ; копирую адрес указателя из esi в eax 
mov EDX,[myDoubles + ESI] ;копирую адрес указателя из esi + myDoubles в edx 


mov EAX,0
mov esi ,offset pupa
mov ECX,7 ; 7 байтов в ecx
CYRCLE:
add eax,[esi] ; 
add esi, 4
loop CYRCLE; проверяет является ли значаение ecx 7 
mov ECX,7
mov ebx,0 
mov esi ,offset pupa
CYRC:
add ebx,[esi] ; присваиваю значение esi
jz xym ; сравнивает значкник с 0 ( если =0 то в xym)
add esi, 4
mov ebx,0
loop CYRC
mov ebx,1
jmp en ; типа goto
xym:
mov ebx,0
en: 
add b,ebx
add b,'0'
INVOKE  MessageBoxA,HW,  OFFSET STR2,OFFSET str1 , MB_OK ; макрос вызывающий функцию MessageBoxA HW дескриптор окна	OFFSET записывает в заголовок MB_OK количество кнопок 


	push - 1
	call ExitProcess

main ENDP

end main