section .text   
   
global _start   
 _start:      
        nop
	nop
	nop
     	mov ecx,0x08048054
	mov eax,[ecx]
	

     	mov eax,0x1  
     	int 0x80  
