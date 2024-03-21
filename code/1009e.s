.section .data
	value1:
		.int 400
	
	values:
		.int 400,15,20,25,30,35,40,45,50,55,60
		
.section .text    
   
.global _start   
 _start:      
     	nop
     	movl $1,%edi
	movl $4,%ebx
	movl $2,%edi
	movl value1,%ecx
	movl values,%eax
	movw values,%cx
	movb values,%ch

	movl values(, %edi, 4),%eax
	movl values(%edi,%ebx,1),%eax
	#movl values(,%edi,3),%eax
	# base_address(offset_address,index,size)
	# base_address+offset_address+index*size
	# 其中offset_address和index的值必须为寄存器
	# 如果其中的任何值为0，可以忽略，但必须有逗号作为占位符	
	

     	movl $1, %eax  
     	movl $0, %ebx
     	int $0x80  
