#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define FILENAME "anna.txt"
#define DEFAULT_SIZE 4096

int main() {
    int fd[2];
    pid_t pid;
    size_t br;
    char *s;
    
    pipe(fd);
    pid = fork();
    if (pid) { // parent
        close(fd[0]);
        if (pid == -1) {
            // error handling
        }
        FILE *fp;
        s = (char*) malloc(DEFAULT_SIZE);
        fp = fopen(FILENAME, "r");
        // TODO: read in file content
        do {
            br = fread(s, DEFAULT_SIZE, 1, fp);
            if (write(fd[1], s, br) != br) {
                // error handling
            }
        } while (br == DEFAULT_SIZE);
        fclose(fp);
        // must close pipe
    } else { // child
        close(fd[1]);
        s = (char*) malloc(DEFAULT_SIZE);
        do {
            br = read(fd[0], s, DEFAULT_SIZE);
            int nw = 0;
            for (int i=0; i < br; i++) {
                if (s[i] == ' ') {
                    nw++;
                }
            }
        } while (br == DEFAULT_SIZE);
        // must close pipe
    }
}
