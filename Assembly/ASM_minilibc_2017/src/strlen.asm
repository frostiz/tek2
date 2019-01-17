global strlen:function
	
section .text
strlen:	
	mov rcx, 0
loop:
	cmp BYTE[rdi + rcx], 0
	je end
	inc rcx
	jne loop
end:
	mov rax, rcx
	ret
