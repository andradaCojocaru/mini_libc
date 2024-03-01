/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int ret_val = syscall(__NR_close, fd);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
