.section .data
	value1:
		.int 10
.section .text    
   
.global _start   
 _start:      
     	nop
     	movl value1,%eax
	movl $value1,%edi

	leal value1,%esi 	#leal指令，将value1的地址放到寄存器中
	movl $1,%edx
	leal 5(%edx, %edx, 2), %eax
	#假设%edx的值为x, 这行代码会将%eax的值设置为”3x+5″.
	

     	movl $1, %eax   
     	int $0x80  
