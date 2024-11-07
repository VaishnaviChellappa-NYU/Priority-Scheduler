#include "types.h"
#include "stat.h"
#include "user.h"

void calculate_primes(int pid, int nice_value, int max_primes) {
    // Set the nice value for the current process
    nice(pid, nice_value);

    int count = 0;
    int n = 2;

    printf(1, "Child PID: %d, Nice Value: %d\n", pid, nice_value);

    while (count < max_primes) {
        int is_prime = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf(1, "PID: %d, Nice Value: %d, Prime: %d\n", pid, nice_value, n);
            count++;
        }
        n++;

        // Introduce a delay to simulate work
        if (count % 10 == 0) {
            sleep(1);
        }
    }
    exit();
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf(1, "Usage: %s <pid> <nice_value>\n", argv[0]);
        exit();
    }

    int pid = fork();
    if (pid == 0) {
        int nice_value = atoi(argv[2]); // Convert nice value from string to integer
        int max_primes = 50; // Limit to 50 primes per process
        calculate_primes(getpid(), nice_value, max_primes);
    } else if (pid > 0) {
        wait();
    } else {
        printf(1, "Fork failed\n");
    }

    exit();
}
