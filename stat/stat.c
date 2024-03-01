// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int ret_val = syscall(__NR_stat, path, buf);
	errno = ret_val < 0 ? -ret_val : 0;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}
