#include <stdio.h>
#include <unistd.h>



// notes:
// the max value that can be assigned to a file descriptor is 1023 = OPEN_MAX - 1
int main() {
    int fd_nm = 1023;
    // Duplicate stdout (1) to fd_nm
    if (dup2(1, fd_nm) < 0) {
        perror("dup2");
        return 1;
    }

    // Write to file descriptor 1088
    //dprintf(1000, "This is output from descriptor 1088\n");

    write(fd_nm, "c", 1);
    return 0;
}

