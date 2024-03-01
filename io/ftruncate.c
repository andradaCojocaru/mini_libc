// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
    if (length < 0) {
        errno = EINVAL;
        return -1;
    }


	int ret_val = syscall(__NR_ftruncate, fd, length);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
