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
	
	movl $0x12345678,%ecx
	movl %ecx,value1	
	movb value2,%al
	movl $2,%ecx
	movl value1(,%ecx,1),%edx

	 
     	movl $1, %eax  
     	movl $0, %ebx  
     	int $0x80  
