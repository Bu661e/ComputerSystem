.section .text   
   
.global _start   
 _start:      
     	nop
     	movl $0x08048056,%ecx
	movw (%ecx),%ax
	
	

     	movl $1, %eax  
     	movl $0, %ebx  
     	int $0x80  
