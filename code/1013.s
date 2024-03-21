.section .data

	value:
		.int 0x87654321
.section .text    
   
.global _start   
 _start:      
     	nop
	pushl $0x88888888
	#pushw $0x66666666
     
	movl $0x12345678,%ebx
	push %ebx
	#pushl %ebx

	pushw %bx
	pushw value
	push $value
	#pushb %ah 

	popl %ebx
	popl %eax
	popw %cx
		
	

     	movl $1, %eax   
     	int $0x80  
