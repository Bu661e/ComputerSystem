	.file	"1020.c"
	.section	.rodata
.LC0:
	.string	"true\n"
.LC1:
	.string	"%s"
.LC2:
	.string	"false"
.LC3:
	.string	"a=%d\n"
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

	movl	$1, 24(%esp)
	movl	$.LC0, 28(%esp)
	cmpl	$0, 24(%esp)
	setg	%al
	addl	$1, 24(%esp)
	testb	%al, %al
	je	.L2
	cmpl	$1, 24(%esp)
	setle	%al
	addl	$1, 24(%esp)
	testb	%al, %al
	je	.L2
	movl	$.LC1, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	jmp	.L3
.L2:
	movl	$.LC2, (%esp)
	call	puts
.L3:
	movl	$.LC3, %eax
	movl	24(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
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
