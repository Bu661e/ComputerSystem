.section .text   
   
.global _start   
 _start:      
     	nop
     	movl $0x08048056,%ebx
	movl $2,%ecx
	movw (%ebx,%ecx,0x2),%ax
	movl $0x0402402c,%ecx
	movw (,%ecx,0x2),%ax
	#movw (%ecx,0x2),%ax
	

     	movl $1, %eax  
     	movl $0, %ebx  
     	int $0x80  
