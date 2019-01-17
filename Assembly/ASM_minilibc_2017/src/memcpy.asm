global memcpy:function
	
section .text
memcpy:
	xor rcx, rcx
loop:
	cmp rcx, rdx
	je end
	mov r10b, [rsi + rcx]
	mov [rdi + rcx], r10b
	inc rcx
	jne loop
end:
	mov rax, rdi
	ret
