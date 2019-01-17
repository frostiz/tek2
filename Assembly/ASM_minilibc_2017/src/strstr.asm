global strstr:function
	
section .text

strstr:
	xor rcx, rcx
	cmp BYTE[rsi], 0
	je end
start:
	mov r11b, [rdi]
	cmp r11b, 0
	je endNotFound
	cmp r11b, [rsi]
	je go_loop
	inc rdi
	jmp start

go_loop:
	mov rcx, 1
loop:
	mov r9b, [rdi + rcx]
	mov r10b, [rsi + rcx]

	cmp r10b, 0
	je end
	cmp r9b, 0
	je inc_start
	
	cmp r9b, r10b
	jne checkend
	inc rcx
	jmp loop

checkend:
	cmp r10b, 0
	je end
	jmp inc_start
	
end:
	mov rax, rdi
	ret

inc_start:
	cmp BYTE[rdi], 0
	je endNotFound
	inc rdi
	jmp strstr

endNotFound:
	mov rax, 0
	ret
