global rindex:function
	
section .text
rindex:
	cmp rdi, 0
	je endNotFound
	xor rcx, rcx

go_to_end:
	mov r9b, [rdi]
	cmp r9b, 0
	je start_dec
	inc rdi
	inc rcx
	jmp go_to_end

start_dec:
	cmp rcx, 0
	jle end
	dec rdi
	dec rcx
	jmp loop_dec
loop_dec:
	cmp rcx, 0
	jle end
	mov r9b, [rdi]
	cmp r9b, sil
	je end
	dec rdi
	dec rcx
	jmp loop_dec
end:
	cmp rcx, 0
	jle end2
	mov rax, rdi
	ret

rend:
	mov rax, rdi
	ret

end2:
	cmp  [rdi], sil
	je rend
	mov rax, 0
	ret
	
endNotFound:
	mov rax, 0
	ret
