 .section .text    
   
 .global _start   
 _start:      
     nop
     movl $4, %eax  
     movl $1, %ebx  
     movl $5, %ecx  
     movl $13, %edx  
     movl %eax,%ebx
    
   
     movl $1, %eax  
     int $0x80  
