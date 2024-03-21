.section .data
	value1:
		.int 1 
	value2:
		.short 2
	value3:
		.byte 3

.section .text    
   
.global _start   
 _start:      
     	nop
     	movl $100,%ecx
	movl %ecx,value2
	movw $20,value2

	 
     	movl $1, %eax  
     	movl $0, %ebx  
     	int $0x80  
