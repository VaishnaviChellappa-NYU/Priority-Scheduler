#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf(1, "Usage: nice <pid> <value>\n");
        exit();
    }

    int pid = atoi(argv[1]);
    int value = (argc == 3) ? atoi(argv[2]) : atoi(argv[1]);
    int old_value = nice(pid, value);

    if(old_value == -1) {
        printf(1, "Failed to set nice value. Check PID or value range.\n");
    } else {
        printf(1, "PID: %d, Old Nice Value: %d\n", pid, old_value);
    }
    exit();
}
