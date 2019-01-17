global strncmp:function
	
	section .text
strncmp:
	mov rcx, 0
loop:	
	cmp rcx, rdx
	je return_zero
	mov r10b, [rsi]
	cmp [rdi], r10b		
	jg return_one
	jl return_minus_one
	je check_zero
	jmp increment
	
return_one:
	mov r9b, [rsi]
	mov r11b, [rdi]
	sub r11b, r9b
	movsx rax, r11b
	ret

return_minus_one:
	mov r9b, [rsi]
	mov r11b, [rdi]
	sub r11b, r9b
	movsx rax, r11b
	ret
	
return_zero:
	mov rax, 0
	ret
	
check_zero:
	cmp BYTE[rsi], 0
	je return_zero
	jne increment

increment:
	inc rdi
	inc rsi
	inc rcx
	jmp loop
