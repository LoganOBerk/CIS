INCLUDE irvine32.inc

; Reverse a string using stack operations
; Myname: Logan Berk
; date: 1/30/2025

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
    str1 BYTE 'Logan Berk', 0    ; Original string
lenStr DWORD SIZEOF str1 - 1 ; String length excluding null terminator

.code
reverseString PROC
    mov ecx, lenstr         ;load length of string to counter register
    mov esi, OFFSET str1    ;load address of str1 to esi
    push_stack:
        mov ax, [esi]       ;load first char to 16 bit register
        inc esi             ;move to next address location
        push ax             ;push the first char onto stack
    loop push_stack         ;repeat the proccess until ecx is 0

    mov ecx, lenstr         ;load length of string to counter register
    mov esi, OFFSET str1    ;load address of str1 to esi
    pop_stack:              
        pop ax              ;pop char off the stack
        mov [esi], ax       ;take the first value of esi and replace it with the new char
        inc esi             ;move to next address location
    loop pop_stack          ;repeat until ecx is 0, aka all chars are replaced

    mov BYTE PTR [esi], 0   ;add null terminator at the end

    ret
reverseString ENDP

main PROC
    mov edx, OFFSET str1     ; Load original string address
    call WriteString         ; Display original string
    call Crlf                ; Print newline
    
    call reverseString       ; Reverse the string
    
    mov edx, OFFSET str1     ; Load reversed string address
    call WriteString         ; Display reversed string
    INVOKE ExitProcess,0
main ENDP
END main


    