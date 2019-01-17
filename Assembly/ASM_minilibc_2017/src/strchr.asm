global strchr:function
	
section .text
strchr:
	cmp rdi, 0
	je endNotFound
	mov rcx, 0
loop:
	mov r9b, [rdi]
	cmp r9b, 0
	je endNotFound
	cmp r9b, sil
	je end
	add rdi, 1
	jne loop
end:	
	mov rax, rdi
	ret

endNotFound:
	mov rax, 0
	ret
