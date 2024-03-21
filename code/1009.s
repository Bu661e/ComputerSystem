.section .text   
   
.global _start   
 _start:      
     	nop
     	movl $0x08048056,%ebx
	movl $2,%ecx
	movw (%ebx,%ecx),%ax
	movl $4,%ecx
	movw (%ebx,%ecx),%ax
	

     	movl $1, %eax  
     	movl $0, %ebx  
     	int $0x80  
