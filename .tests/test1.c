#include <stdio.h>
#include <unistd.h>

int main() {
    // Duplicate stdout (1) to 1088
    if (dup2(1, 1099) < 0) {
        perror("dup2");
        return 1;
    }

    // Write to file descriptor 1088
    //dprintf(1000, "This is output from descriptor 1088\n");
    write(1099, "c", 1);
    return 0;
}

