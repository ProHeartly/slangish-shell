#include <stdio.h>
#include <stdlib.h>

// reference: https://brennan.io/2015/01/16/write-a-shell-in-c/

#define SLSH_READLINE_BUFSIZE 1024 // buffer size

// THIS DOES WHAT IT SAYS!! just reading line aka takes input from user

char *slsh_read_line(void) {
    int bufsize = SLSH_READLINE_BUFSIZE;
    int pos = 0; // tracks current position that we are reading

    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "slangish-shell: allocation error.\n");
        exit(EXIT_FAILURE);
    } // handeling error :p

    while (1) {
        c = getchar();

        // if we get EOF, replace with a null and return
        if (c == EOF || c == '\n') {
            buffer[pos] = '\0';
            return buffer;
        } else {
            buffer[pos] = c;
        }
        pos++;

        // if we get more than buffer than we reallocate!
        if (pos >= bufsize) {
            bufsize += SLSH_READLINE_BUFSIZE;
            buffer = realloc(buffer, bufsize);

            if (!buffer) {
                fprintf(stderr, "slangish-shell: allocation error.\n");
                exit(EXIT_FAILURE);
            } // handeling errorrr
        }
    }
}


void the_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("Slangish.Sh > ");
        line = slsh_read_line();
        status = false;
    } while (status);
}

int main() {
    printf("Heyyy! Welcome to slangish-shell \n\n\n\n");
    the_loop();
    return EXIT_SUCCESS;
}