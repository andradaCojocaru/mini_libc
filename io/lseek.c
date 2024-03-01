// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/mman.h>

off_t lseek(int fd, off_t offset, int whence)
{

	off_t ret_val = syscall(__NR_lseek, fd, offset, whence);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
