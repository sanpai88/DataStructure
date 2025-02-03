#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMORY_POOL_SIZE 1024 * 1024  // 1 MB

// Define a simple memory block structure
typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

#define BLOCK_SIZE sizeof(Block)

void *memory_pool = NULL;
Block *free_list = NULL;

// Initialize the memory pool
void initialize_memory_pool() {
    memory_pool = sbrk(MEMORY_POOL_SIZE);
    free_list = (Block *)memory_pool;
    free_list->size = MEMORY_POOL_SIZE - BLOCK_SIZE;
    free_list->free = 1;
    free_list->next = NULL;
}

// Split a block into two smaller blocks
void split_block(Block *block, size_t size) {
    Block *new_block = (Block *)((char *)block + BLOCK_SIZE + size);
    new_block->size = block->size - size - BLOCK_SIZE;
    new_block->free = 1;
    new_block->next = block->next;

    block->size = size;
    block->free = 0;
    block->next = new_block;
}

// Allocate memory using our custom malloc
void *my_malloc(size_t size) {
    Block *current = free_list;
    while (current != NULL) {
        if (current->free && current->size >= size) {
            if (current->size > size + BLOCK_SIZE) {
                split_block(current, size);
            } else {
                current->free = 0;
            }
            return (char *)current + BLOCK_SIZE;
        }
        current = current->next;
    }
    return NULL;
}

// Free allocated memory
void my_free(void *ptr) {
    if (ptr == NULL) return;

    Block *block = (Block *)((char *)ptr - BLOCK_SIZE);
    block->free = 1;

    // Merge adjacent free blocks
    Block *current = free_list;
    while (current != NULL) {
        if (current->free && current->next && current->next->free) {
            current->size += BLOCK_SIZE + current->next->size;
            current->next = current->next->next;
        }
        current = current->next;
    }
}

int main() {
    initialize_memory_pool();

    void *ptr1 = my_malloc(100);
    void *ptr2 = my_malloc(200);

    printf("ptr1 : %p \n",ptr1);
    printf("ptr2 : %p \n",ptr2);
    my_free(ptr1);
    my_free(ptr2);

    return 0;
}

