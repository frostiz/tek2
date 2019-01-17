global strcasecmp:function
	
	section .text
strcasecmp:
	xor rcx, rcx
loop:
	mov r8b, [rdi + rcx] 	; a
	mov r9b, [rsi + rcx] 	; b
	
	cmp r8b, 65 		; compare a avec 'A'
	jge check1		; si a >= 'A' -> go to check1
	cmp r9b, 65		; compare b avec 'A'
	jge check2		; si b >= 'A' -> go to check2

	cmp r8b, 0 		; check end of string
	je end
	cmp r9b, 0
	je end
	
	jmp compare		; sinon compare
	jmp loop

check1:
	cmp r8b, 90 		; compare a avec 'Z'
	jle c_upper1 		; si a <= 'Z' -> met en minuscule
	jg recheck1		; si a > 'Z' -> recheck1

recheck1:
	cmp r9b, 65		; compare b avec 'A'
	jge check2 		; si b >= 'A' -> check2
	jl compare
	
c_upper1:
	add r8b, 32 		; le convertis en min
	jmp check1 		; jmp dans recheck1

check2:
	cmp r9b, 90		; compare b avec 'Z'
	jle c_upper2		; si b <= 'Z' -> met en minuscule
	jg compare 		; sinon rejump et compare
	
c_upper2:
	add r9b, 32
	jmp compare

compare:
	cmp r8b, r9b
	je incr
	jne end
end:	
	sub r8b, r9b
	movsx rax, r8b
	ret
incr:
	inc rcx
	jmp loop
