global strpbrk:function
	
section .text

strpbrk:
	xor rcx, rcx
loop:
	mov r9b, [rdi]
	
	cmp r9b, 0
	je endNotFound
	
	cmp r9b, [rsi]
	je end
	
	jmp start_loop2
	inc rdi
	jmp loop

start_loop2:
	mov rcx, 1
	jmp loop2
loop2:
	cmp BYTE[rsi + rcx], 0
	je increm
	cmp r9b, [rsi + rcx]
	je end
	inc rcx
	jmp loop2

increm:
	inc rdi
	jmp loop

end:
	mov rax, rdi
	ret
endNotFound:	
	mov rax, 0
	ret
