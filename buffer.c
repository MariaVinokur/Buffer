/************************************************************
Author: Maria Vinokur
Date: 19/4
Title: Circular Buffer Header File
Description: Header file of Circular Buffer 
HRD30
*************************************************************/

#include "buffer.h"
#include <stdlib.h>	/*  size_t, malloc, free          */
#include <assert.h> /*  assert                        */



struct circular_buffer
{
	size_t capacity;
	size_t free_bytes;
	char *ptr_write;
	char *ptr_read;
	char items[1];
}; 

cbuff_ty *CBuffCreate(const size_t capacity)
{
	cbuff_ty *buffer = NULL;
	
	if(0 == capacity)
	{
		return NULL;
	}
	
	buffer = malloc(sizeof(cbuff_ty) + capacity);
	if(NULL == buffer)
	{
		return NULL;
	}
	
	buffer -> capacity = capacity;
	buffer -> free_bytes = capacity;
	buffer -> ptr_read = buffer -> items;
	buffer -> ptr_write = buffer -> items;
	
	return (buffer);
}

ssize_t CBuffWrite(cbuff_ty *buffer,const void *write_buffer, size_t n)
{
	ssize_t i = 0;
	char *ptr_buff_write = (char *)write_buffer;
	char *ptr_end = buffer -> items + buffer -> capacity;
	
	assert(buffer);
	assert(write_buffer);
	
	for(i = 0; (size_t)i < n && (size_t)i < buffer -> free_bytes; ++i)
	{
		if(ptr_end == buffer -> ptr_write)
		{
			buffer -> ptr_write = buffer -> items;
		}

		*(buffer -> ptr_write) = *ptr_buff_write;
		++(buffer -> ptr_write);
		++ptr_buff_write;
	}	
	
	buffer -> free_bytes -= i;
	
	return i;
}

ssize_t CBuffRead(cbuff_ty *buffer, void *read_buffer, size_t n)
{
	ssize_t i = 0;
	char *ptr_buff_read = (char *)read_buffer;
	char *ptr_end = buffer -> items + buffer -> capacity;
	
	assert(buffer);
	assert(read_buffer);
	
	for(i = 0; (size_t)i < n && (size_t)i < (buffer -> capacity - buffer -> free_bytes); ++i)
	{
		if(ptr_end == buffer -> ptr_read)
		{
			buffer -> ptr_read = buffer -> items;
		}
		
		*ptr_buff_read = *(buffer -> ptr_read);
		++(buffer -> ptr_read);
		++ptr_buff_read;
	}	

	buffer -> free_bytes += i;
	
	return i;
	
}

void CBuffDestroy(cbuff_ty *buffer)
{
	assert(buffer);
	
	if(buffer != NULL)
	{
		free(buffer);
	}
}

size_t CBuffFreeSpace(const cbuff_ty *buffer)
{
	return (buffer -> free_bytes);
}

size_t CBuffCapacity(const cbuff_ty *buffer)
{
	return (buffer -> capacity);
}

int CBuffIsEmpty(const cbuff_ty *buffer)
{
	return (buffer -> free_bytes == buffer -> capacity);
}


