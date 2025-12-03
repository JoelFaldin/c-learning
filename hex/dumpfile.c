#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int options;

#define BSIZE 16
#define ABBR 1
#define OCT 2
#define set_abbr() options |= ABBR
#define test_abbr() ((options & ABBR) == ABBR)
#define set_oct() options |= OCT
#define test_oct() ((options & OCT) == OCT)


void line_out(int offset, int length, unsigned char *data) {
    int a;

    if (!test_abbr()) {
        if (test_oct()) {
            printf("%05o ", offset);
        } else {
            printf("%05X ", offset);
        }
    }

    for (a = 0; a < length; a++) {
        if (test_oct()) {
            printf(" %03o", *(data + a));
        } else {
            printf(" %02X", *(data + a));
        }


        if ((a + 1) % 8 == 0 && !test_abbr()) {
            putchar(' ');
        }
    }

    putchar(' ');

    if (length < BSIZE) {
        for ( ; a <BSIZE; a++) {
            if (test_oct()) {
                printf("    ");
            } else {
                printf("   ");
            }

            if ((a + 1) % 8 == 0) {
                putchar(' ');
            }
        }
    }

    if (!test_abbr()) {
        putchar(' ');

        for (a = 0; a < length; a++) {
            if (*(data + a) >= ' ' && *(data + a) <= '~') {
                putchar(*(data + a));
            } else {
                putchar(' ');
            }
        }
    }

    putchar('\n');
}

void help(void) {
    puts("dumpfile - output file's raw data");
    puts("Format: dumpfile filename [options]");
    puts("Options:");
    puts("-a abbreviated output");
    puts("-o output octal instead of hex");
    puts("-h display this text");
    
    exit(1);
}

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    char bff[256];
    int r;

    if (argc < 2) {
        puts("Format: dumpfile filename [options]");
        exit(1);
    }

    options = 0;
    while ((r = getopt(argc, argv, "aosh")) != -1) {
        switch (r)
        {
        case 'a':
            set_abbr();
            break;
        case 'o':
            set_oct();
            break;
        case 'h':
            help();
            break;
        case '?':
            printf("Switch '%c' is invalid\n", r);
            break;
        default:
            puts("Unknown option.");
        }
    }

    if (argv[2] != NULL) {
        filename = argv[2];
    } else {
        filename = argv[1];
    }
    // printf("Arg 1: %s\n", argv[0]);
    // printf("Arg 2: %s\n", argv[1]);
    // printf("Arg 3: %s\n", argv[2]);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    unsigned char buffer[BSIZE];
    int ch, index, offset, length;

    index = 0;
    offset = 0;

    while (!feof(fp)) {
        ch = fgetc(fp);

        if (ch == EOF) {
            if (index != 0) {
                line_out(offset, index, buffer);
            }

            break;
        }

        buffer[index] = ch;
        // printf("Offset: %d\n", offset);
        // printf("BSIZE: %d\n", BSIZE);
        // printf("Buffer: %c\n", buffer[index]);
        index++;
        
        if (index == BSIZE) {
            line_out(offset, BSIZE, buffer);
            offset += BSIZE;
            index = 0;
        }
    }
    
    return 0;
}