
.section .text    
   
.global _start   
 _start:      
     	nop
	#8bit，无符号数：0～255，有符号数 -128~127
	#比较两个数，把大的那个放入％bl寄存器中
	movb $0x81,%ah  #1000 0001 129或-127
	movb $0x1f,%al  #0001 1111 31
	cmp %ah,%al
	
	sete %ch
	clc
	stc
	cmc
	testl $0x4,%eax #00000000 00000000 0000000 00000100
exit:  	movl $1, %eax   
     	int $0x80  
