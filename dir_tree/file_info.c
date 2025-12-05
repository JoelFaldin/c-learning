#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    char *filename;
    struct stat fs;
    int r;

    if (argc < 2) {
        fprintf(stderr, "Specify a filename\n");
        exit(1);
    }

    filename = argv[1];
    printf("Info for file '%s'\n", filename);
    r = stat(filename, &fs);

    if (r == -1) {
        fprintf(stderr, "Error reading '%s' file.\n", filename);
        exit(1);
    }

    // printf("Media ID: %lu\n", fs.st_dev);
    // printf("Inode #%lu\n", fs.st_ino);
    // printf("Type and mode: %u\n", fs.st_mode);
    // printf("Hard links = %lu\n", fs.st_nlink);
    // printf("Owner id: %u\n", fs.st_uid);
    // printf("Group id: %u\n", fs.st_gid);
    // printf("Device id: %lu\n", fs.st_rdev);
    // printf("File size: %lu\n", fs.st_size);
    // printf("Block size: %lu\n", fs.st_blksize);
    // printf("Allocated blocks: %lu\n", fs.st_blocks);
    // printf("Access: %s", ctime(&fs.st_atime));
    // printf("Modification: %s", ctime(&fs.st_mtime));
    // printf("Changed: %s", ctime(&fs.st_ctime));
    
    printf("Type and mode: %X\n", fs.st_mode);

    if (S_ISREG(fs.st_mode)) {
        printf("%s is a regular file!\n", filename);
    } else if (S_ISDIR(fs.st_mode)) {
        printf("%s is a directory!\n", filename);
    } else {
        printf("%s is some other type of file\n", filename);
    }

    return 0;
}