

__asm void my_strcpy(const char *src, char *dst){
	
loop
				LDRB r2, [r0] 
					ADDS r0, #1 
				STRB r2, [r1] 
					ADDS r1, #1 
				CMP r2, #0 
				BNE loop 
	
}

__asm void my_capitalize(char *str)
{
cap_loop
	LDRB r1, [r0] 
	CMP r1, #'a'-1 
	BLS cap_skip 
	CMP r1, #'z' 
	BHI cap_skip 
	SUBS r1,#32 
	STRB r1, [r0] 
cap_skip
	ADDS r0, r0, #1 
	CMP r1, #0 
	BNE cap_loop 
	BX lr 
}



__asm void my_lowercase(char *str)
{
low_loop 
	LDRB r1,[r0] 
	CMP r1,#'A' 
	BLS low_skip 
	CMP r1, #'Z' 
	BHS low_skip  
	ADDS r1, #32 
	STRB r1,[r0] 
low_skip 
	ADDS r0, r0, #1 
	CMP r1,#0 
	BNE low_loop 
	BX lr 
} 

__asm void first_last(char *str)
{
fl_main
	LDRB r1,[r0]
	SUBS r0, r0, #1
	LDRB r2,[r0]
	CMP r2, 0x00
	BEQ fl_null
	ADDS r0, r0, #1
	
  	
	CMP r1,#'A' 
	BLS fl_skip 
	CMP r1, #'z' 
	BHS fl_skip  
	 
	 
 

fl_loop
	ADDS r0, r0, #1 
	CMP r1,#0 
	BNE fl_main
	BX lr
	  
	
fl_skip
	CMP r1, ' '
	BEQ fl_add
	SUBS r0, r0, #1
	LDRB r1,[r0]
	SUBS r1,#32 
	STRB r1, [r0] 
	
	BX lr
	
fl_add
	ADDS r0, r0, #1
	B fl_main
	
fl_null
	ADDS r0, r0, #1
	LDRB r1,[r0]
	SUBS r1,#32 
	STRB r1, [r0]
	ADDS r0, r0, #1
	b fl_main
	
	
	
	
	


}



/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(void){	
const char a[] = "Hello world!!";
char b[20];
my_strcpy(a, b);
my_capitalize(b);
my_lowercase(b);
first_last(b);
while (1);
	
}


