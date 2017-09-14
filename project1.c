#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    FILE *fp;
    
    fp = fopen("anna.txt", "r");
    // TODO: read in file content
    
    fclose(fp);
}
