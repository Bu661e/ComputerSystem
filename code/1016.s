
.section .text    
   
.global _start   
 _start:      
     	nop
	#8bit，无符号数：0～255，有符号数 -128~127
	#比较两个数，把大的那个放入％bl寄存器中
	movb $0x81,%ah  #1000 0001 129或-127
	movb $0x1f,%al  #0001 1111 31
	cmp %ah,%al
	#ja moval  #把这两个数看成无符号数比较大小 above
	jg moval #把这两个数看成有符号数比较大小 great
	mov %ah,%bl
	jmp exit
moval:	mov %al,%bl

exit:  	movl $1, %eax   
     	int $0x80  
