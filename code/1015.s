
.section .text    
   
.global _start   
 _start:      
     	nop
	#8bit，无符号数：0～255，有符号数 -128~127
	movb $0x81,%ah  #1000 0001 129或-127
	movb $0x1f,%al  #0001 1111 31
	cmp %ah,%al	#%al-%ah
	cmp %al,%ah	#%ah-%al

	
	movb $0x8f,%ah #1000 1111 143或-114
	movb $0x1,%al #0000 0001  1
	cmp %ah,%al
	cmp %al,%ah

exit:  	movl $1, %eax   
     	int $0x80  
