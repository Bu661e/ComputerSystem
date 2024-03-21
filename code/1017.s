	.file	"1017.c"
	.section	.rodata
.LC0:
	.string	"AoLiGei!"
.LC1:
	.string	"Enjoy!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$20, 24(%esp)
	movl	$-5, 28(%esp)
	movl	24(%esp), %eax
	cmpl	28(%esp), %eax
	jle	.L2
	movl	$.LC0, (%esp)
	call	puts
	jmp	.L3
.L2:
	movl	$.LC1, (%esp)
	call	puts
.L3:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
