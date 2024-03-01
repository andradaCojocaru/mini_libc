// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int ret_val = syscall(__NR_fstat, fd, st);
	errno = ret_val < 0 ? -ret_val : 0;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
