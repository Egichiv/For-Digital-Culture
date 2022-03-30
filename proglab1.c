#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned long lines_total(FILE *file) {
    unsigned long lines_count = 1;
    char rn;
    while ((rn = fgetc(file)) != EOF) {
        if (isspace(rn)) {
            if (rn == '\n') {
                lines_count = lines_count + 1;
            }
        }
    }
    return lines_count;
}

unsigned long bytes_total(FILE *file) {
    unsigned long bytes_count = 0;
    char rn;
    while((rn = fgetc(file)) != EOF) {
        bytes_count = bytes_count + 1;
    }
    return bytes_count;
}

unsigned long words_total(FILE *file) {
    unsigned long words_count = 0;
    char rn;
    char prevrn = "\0";
    while((rn = fgetc(file)) != EOF) {
        if((isspace(rn) == 0)) {
            if (prevrn == '\0' || isspace(prevrn)) {
                words_count = words_count + 1;
            }
        }
        prevrn = rn;
    }
    return words_count;
}

int main(int argc, char *argv[]) {
    if (argc >= 3) {
        FILE *needed_file;
        needed_file= fopen(argv[argc - 1], "r");
        if (needed_file != NULL) {
            if ((strcmp(argv[1], "-b")) == 0) {
                printf("There are %lu bytes in file", bytes_total(needed_file));
            }
            else if ((strcmp(argv[1], "-w")) == 0) {
                printf("There are %lu words in file", words_total(needed_file));
            }
            else if ((strcmp(argv[1], "-l")) == 0) {
                printf("There are %lu lines in file", lines_total(needed_file));
            }
            else {
                printf("Strange command");
                return 3;
            }
        }
        else {
            printf("Couldn't open the file");
            return 2;
        }
        return 0;
    }
    else {
        printf("There should be at least 3 arguments, not %d\n", argc);
        return 1;
    }
}
