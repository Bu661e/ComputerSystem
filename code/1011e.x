.section .text    
   
.global _start   
 _start:      
     	nop
     	
	movl $0xffffffff,%eax
	jmp exit
	movl $5,%eax

exit:  	movl $1, %eax   
     	int $0x80  
