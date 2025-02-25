#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

void * alligned_malloc(size_t num_bytes,size_t align);
void alligned_free(void *ptr);


void * alligned_malloc(size_t num_bytes , size_t align)
{

    void *ptr = NULL,*p=NULL;
    if(0 == align)
        return NULL;

    ptr = malloc(num_bytes + sizeof(uint16_t)+(align -1 ));

    if(ptr)
    {
	 /*Getting aligned pointer*/

	 p = (void *)((uintptr_t )ptr + sizeof(uint16_t) + (align -1 ) & ~(align -1 ));
	 *((uint16_t *)(p) - 1) = (uint16_t)((uint8_t *)p - (uint8_t *)ptr);
    }
    
    return p;

}

void alligned_free(void *ptr)
{
   void *p = NULL;

   if(NULL == ptr)
       return;

   uint16_t offset = *((uint16_t*)(ptr) - 1);
   p = (void *)((uint8_t *)ptr - offset);

   free(p);
}



int main()
{

    void *p = alligned_malloc(100,4);
    printf("sizeof uintptr_t : %lu \n",sizeof(uintptr_t));
    printf("aligned malloc return %p \n",p);

    alligned_free(p);

    return 0;
}
