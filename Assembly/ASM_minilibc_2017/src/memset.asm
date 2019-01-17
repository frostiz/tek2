global memset:function
	
section .text
memset:
	mov rcx, 0
	mov r9, rdi
	cmp r9, 0
	je end
loop:
	cmp rcx, rdx
	je end
	mov [rdi], rsi 
	add rdi, 1
	inc rcx
	jne loop
end:
	mov rax, r9
	ret
