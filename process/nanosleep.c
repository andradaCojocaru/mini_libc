#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *requested_time, struct timespec *remaining){

    int ret_val = syscall(__NR_nanosleep, requested_time, remaining);
    errno = ret_val < 0 ? -ret_val : errno;
	ret_val = ret_val < 0 ? -1 : ret_val;
	return ret_val;
}