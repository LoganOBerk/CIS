INCLUDE irvine32.inc

; Expression Calculation and using the Irvine Library
; Myname: Logan Berk
; date: 1/30/2025

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data

str1 BYTE "My name is: Logan Berk", 0ah, 0dh
.code
main PROC

mov eax,8000h
mov ebx,2000h
mov ecx,1000h
mov edx,5000h

add eax, ebx; update eax to the sum of eax(8000h) and ebx(2000h) /// expected result 10000h in eax
add ecx, edx; update ecx to the sum of ecx(1000h) and edx(5000h) /// expected result 6000h in ecx
sub eax,ecx; update eax to the difference of eax(which is now 10000h) and ecx (which is now 6000h) /// expected result 4000h in eax

;final expected eax = 4000h, ebx = 2000h, ecx = 6000h, edx = 5000h
call dumpregs

mov edx, offset str1

call writestring



INVOKE ExitProcess,0
main ENDP
END main