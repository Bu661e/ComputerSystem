.section .data

	values:
		.int 10,15,20,25,30,35,40,45,50,55,60
		
.section .text    
   
.global _start   
 _start:      
     	nop
     	movl values,%eax
	movl $values,%edi
	#leal values,%edi 
	#leal指令，将values的地址放到寄存器中
	movl $1,%edx
	leal 5(%edx, %edx, 2), %eax
	#假设%edx的值为x, 上面这行会将%eax的值设置为”3x+5″.
	movl $100,4(%edi)
	movl $1,%edi
	movl values(,%edi,4),%ebx
	
	
	

     	movl $1, %eax   
     	int $0x80  
