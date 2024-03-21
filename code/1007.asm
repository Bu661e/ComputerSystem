section .text   
   
global _start   
 _start:      
     	
     	mov ecx,[0x08048056]
	

     	mov eax,0x1  
     	
     	int 0x80  
