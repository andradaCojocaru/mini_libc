// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long ret_val = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return (void *)ret_val;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long ret_val = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return (void *)ret_val;
}

int munmap(void *addr, size_t length)
{
	int ret_val = syscall(__NR_munmap, addr, length);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
