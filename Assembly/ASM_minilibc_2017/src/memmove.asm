global memmove:function
	
section .text
memmove:
	mov r9, rdi
	sub r9, rsi
	cmp r9, 0
	jge decrem
increm:
	xor rcx, rcx
loop_increm:	
	cmp rcx, rdx
	je end
	mov r10b, [rsi + rcx]
	mov [rdi + rcx], r10b
	inc rcx
	jmp loop_increm
	
decrem:
	dec rdx
loop_decrem:	
	cmp rdx, 0
	jl end
	mov r10b, [rsi + rdx]
	mov [rdi + rdx], r10b
	dec rdx
	jmp loop_decrem
end:
	mov rax, rdi
	ret
