global strcmp:function
	
section .text
strcmp:
	mov rcx, 0

	mov r10b, [rsi]
	cmp [rdi], r10b		
	jg return_one
	jl return_minus_one
	je check_zero
	jmp increment
	
return_one:
	mov r9b, [rdi]
	mov r11b, [rsi]
	sub r9b, r11b
	movsx rax, r9b
	ret
	
	sub r9, r11
	mov rax, r9
	ret

return_minus_one:
	mov r9b, [rsi]
	mov r11b, [rdi]
	sub r9b, r11b
	movsx rax, r9b
	ret
	
	sub r9, r11
	mov rax, r9
	ret
	
return_zero:
	mov rax, 0
	ret
	
check_zero:
	cmp BYTE[rsi], 0
	je return_zero
	jne increment

increment:
	add rdi, 1
	add rsi, 1
	jmp strcmp
