global strcspn:function
	
section .text

strcspn:
	xor rcx, rcx
	xor r10, r10
loop:
	mov r9b, [rdi]
	
	cmp r9b, 0
	je end
	
	cmp r9b, [rsi]
	je end
	
	jmp start_loop2

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
	inc r10
	jmp loop

end:
	mov rax, r10
	ret
	
endNotFound:	
	mov rax, 0
	ret
