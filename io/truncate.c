// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int ret_val = syscall(__NR_truncate, path, length);
	
	errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
