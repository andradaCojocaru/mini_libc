// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	size_t src_len = strlen(source) + 1; 
    memcpy(destination, source, src_len);

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t src_len = strlen(source); 
    memcpy(destination, source, len);

	if (src_len >= len) {
		memcpy(destination, source, len);
	} else {
		memcpy(destination, source, src_len);
		memset(destination + src_len, 0, len - src_len);
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t dest_len = strlen(destination);
	strcpy(destination + dest_len, source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t dest_len = strlen(destination);
    strncpy(destination + dest_len, source, len);
    destination[dest_len + len] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && (str1[i] == str2[i])) {
        i++;
    }

    return str1[i] - str2[i];
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	char str1_substr[len + 1];
    char str2_substr[len + 1];
    strncpy(str1_substr, str1, len);
    strncpy(str2_substr, str2, len);
    str1_substr[len] = '\0';
    str2_substr[len] = '\0';

    return strcmp(str1_substr, str2_substr);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	if (str == NULL) {
		return NULL;
	}

	while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *last = NULL;
	if (str == NULL) {
		return last;
	}

	while (*str != '\0') {
        if (*str == c) {
            last = (char *)str;
        }
        str++;
    }

	return last;
}

char *strstr(const char *haystack, const char *needle)
{
	char* ptr_haystack = (char *)haystack;
	size_t needle_len = strlen(needle);

	if (haystack == NULL) {
		return NULL;
	}

    while (*ptr_haystack) {
        if (strncmp(ptr_haystack, needle, needle_len) == 0) {
            return ptr_haystack;
		}
        ptr_haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char* ptr_haystack = (char *)haystack;
	size_t needle_len = strlen(needle);
	char *last = NULL;

	if (haystack == NULL) {
		return last;
	}

    while (*ptr_haystack) {
        if (strncmp(ptr_haystack, needle, needle_len) == 0) {
            last = ptr_haystack;
		}
        ptr_haystack++;
    }

    return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *psrc = (char *)source; 
	char *pdest = destination; 
	
	for (size_t i = 0; i < num; i++) {
		pdest[i] = psrc[i]; 
	} 

	return pdest;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *psrc = (char *)source; 
	char *pdest = destination; 

	for (size_t i = 0; i < num; i++) {
		pdest[i] = psrc[i];
	} 

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char* p1 = (char *)ptr1;
    char* p2 = (char *)ptr2;

	size_t i = 0;
    while (i < num && (p1[i] != p2[i])) {
		i++;
    }

	return p1[i] - p2[i];
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *psrc = source; 
	for (size_t i = 0; i < num; i++) {
		psrc[i] = (unsigned char)value; 
	} 

	return psrc;
}
