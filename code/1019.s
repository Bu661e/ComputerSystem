.section .data
	values:
		.int 10,-20,30,-40,50,60
.section .text    
   
.global _start   
 _start:      
     	nop

     	xorl %eax,%eax 	//置0
	movl $0,%edi	//置0
readvalue:
	movl values(,%edi,4),%ebx
	addl %ebx,%eax
	addl $0x1,%edi 	
	cmp $0x6,%edi #只执行6次
	jz exit	
	jmp readvalue
	
	movl $6,%ecx
	xorl %edi,%edi
	xorl %eax,%eax
loopvalue:
	movl values(,%edi,4),%ebx
	addl %ebx,%eax
	incl %edi
	loop loopvalue
	

exit:  	movl $1, %eax   
     	int $0x80  
