.section .data

	value:
		.int 0x87654321
.section .text    
   
.global _start   
 _start:      
     	nop
	movl $0x0804807e,%eax
	subl $1,%eax
loop:	incl %ebx
	jmp loop
	#jmp *%eax
	#jmp *0x08048092
	jmp exit
	incl %eax
	jmp *exit
	movl 1,%eax
	

exit:  movl $1, %eax   
     	int $0x80  
