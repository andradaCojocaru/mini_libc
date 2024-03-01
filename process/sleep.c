#include <unistd.h>
#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec req = { seconds, 0 }, rem = { 0, 0 };
    int ret_val;
    do {
        ret_val = nanosleep(&req, &rem);
        req = rem;
    } while (ret_val && errno == EINTR);
    return 0;
}