/************************************************************
Author: Maria Vinokur
Date: 19/4
Title: Circular Buffer Header File
Description: Header file of Circular Buffer 
HRD30
*************************************************************/

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>  /* size_t  */
#include <aio.h>     /* ssize_t */

typedef struct circular_buffer cbuff_ty;

/* Creates circular buffer with max capacity of size                            O(1)  */
cbuff_ty *CBuffCreate(const size_t capacity);

/* Destroys circular buffer                                                     O(1)  */
void CBuffDestroy(cbuff_ty *buffer);

/* Shows how much free space the circular buffer has                            O(1)  */
size_t CBuffFreeSpace(const cbuff_ty *buffer);

/* Return capacity                                                              O(1)  */
size_t CBuffCapacity(const cbuff_ty *buffer);

/* Reads from circular buffer and writes to read_buffer n bytes,
 returns the number of bytes successfuly read                                   O(n)  */
ssize_t CBuffRead(cbuff_ty *buffer, void *read_buffer, size_t n);

/* Reads from write_buffer and writes to circular buffer n bytes,
 returns the number of bytes successfuly written                                O(n)  */
ssize_t CBuffWrite(cbuff_ty *buffer,const void *write_buffer, size_t n);

/* return 1 if CBuff is empty, otherwise 0                                      O(1)  */
int CBuffIsEmpty(const cbuff_ty *buffer);

#endif

