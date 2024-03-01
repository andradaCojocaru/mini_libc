// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    void *block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    mem_list_add(block, size);

    return block;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    void *block = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    mem_list_add(block, total_size);
	
    return block;
}

void free(void *ptr)
{
	struct mem_list *item = mem_list_find(ptr);
	if (item == NULL) {
		;
	} else {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->prev = NULL;
        item->next = NULL;

        munmap(item->start, item->len);
		munmap(item, sizeof(struct mem_list));
    }
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    struct mem_list *item = mem_list_find(ptr);
	void *new_ptr = malloc(size);
    if (item == NULL || new_ptr == NULL) {
        return NULL;
    }

    memcpy(new_ptr, ptr, (size > item->len) ? item->len : size);
    mem_list_del(ptr);
    mem_list_add(new_ptr, size);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(nmemb * size);
    }

    size_t old_size = mem_list_find(ptr)->len;
    void *new_ptr = malloc(nmemb * size);

    if (new_ptr == NULL) {
        return NULL;
    }

    memcpy(new_ptr, ptr, old_size > nmemb * size ? nmemb : old_size * size);
    free(ptr);

    return new_ptr;
}
