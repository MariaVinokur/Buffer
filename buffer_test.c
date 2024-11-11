/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 	*
 *	Title			: Buffer Data Structure WS								*	
 *	Author			: Maria Vinokur									   	*	
 *	Description  	: A header file containing declarations for the funcs	*
 *					  used in impl of Buffer data structure					*
 *																			*
 *																			*
 *	HRD30	Infinity Labs R&D		   										*
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 	*/

#include <stdio.h>  /*  printf, puts  */
#include <assert.h> /*  assert  */
#include <string.h> /*  strlen, strcmp */
#include "circular_buffer.h"

#define CAPACITY 7


int main(void)
{
	cbuff_ty *my_buff = NULL;
	char *str1 = "mash";
	char str3[6];
	char str4[7] = "abcde";

	char str5[10];
	char *str6 = "sh\0abcd";
	char *str7 = "ma";
	
	char *str8 = str3;
	char *str9 = str5;
	
	unsigned int i = 0; 
	
	my_buff = CBuffCreate(CAPACITY);
	
	if(NULL != my_buff)
	{
		puts("CREATE IS WORKING");
	}
	
	CBuffWrite(my_buff, str1, 5);
	
	if(CBuffFreeSpace(my_buff) == CAPACITY - 5)
	{
		puts("FREE SPACE AFTER WRITE WORKING");
	}
	
	CBuffRead(my_buff, str3, 2);
	
	for(i = 0; i < 2 && *str7 == *str8; ++i)
	{
		++str8;
		++str7;
	}
	
	if(i == 2)
	{
		puts("READ WORKING");
	}

	CBuffWrite(my_buff, str4, 4);
	
	if(CBuffFreeSpace(my_buff) == 0)
	{
		puts("FREE SPACE AFTER WRITE WITH CIRCLE WORKING");
	}
	
	CBuffRead(my_buff, str5, 7);
	
	for(i = 0; i < 7 && *str6 == *str9; ++i)
	{
		++str6;
		++str9;
	}
	
	if(i == 7)
	{
		puts("READ IN CIRCLE WORKING");
	}
	
	if(CBuffFreeSpace(my_buff) == CAPACITY)
	{
		puts("READ IN CIRCLE2 WORKING");
	}
	
	
	if(CBuffIsEmpty(my_buff))
	{
		puts("EMPTY WORKING");
	}
	
	if(CBuffCapacity(my_buff))
	{
		puts("CAPACITY WORKING");
	}
	
	return 0;
}

