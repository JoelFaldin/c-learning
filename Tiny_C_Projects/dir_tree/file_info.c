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

    // if (S_ISREG(fs.st_mode)) {
    //     printf("%s is a regular file!\n", filename);
    // } else if (S_ISDIR(fs.st_mode)) {
    //     printf("%s is a directory!\n", filename);
    // } else {
    //     printf("%s is some other type of file\n", filename);
    // }

    if (S_ISBLK(fs.st_mode)) {
        printf("block special\n");
    } else if (S_ISCHR(fs.st_mode)) {
        printf("character special\n");
    } else if (S_ISDIR(fs.st_mode)) {
        printf("directory\n");
    } else if (S_ISFIFO(fs.st_mode)) {
        printf("named pipe or socket\n");
    } else if (S_ISREG(fs.st_mode)) {
        printf("regular file\n");
    } else if (S_ISLNK(fs.st_mode)) {
        printf("symbolic link\n");
    } else {
        printf("type unknown\n");
    }
    
    printf("Owner permissions:\n");
    if (fs.st_mode & S_IRUSR) {
        printf("read\n");
    }
    if (fs.st_mode & S_IWUSR) {
        printf("write\n");
    }
    if (fs.st_mode & S_IXUSR) {
        printf("execute\n");
    }

    putchar('\n');

    printf("Group permissions:\n");
    if (fs.st_mode & S_IRGRP) {
        printf("read\n");
    }
    if (fs.st_mode & S_IWGRP) {
        printf("write\n");
    }
    if (fs.st_mode & S_IXGRP) {
        printf("execute\n");
    }

    putchar('\n');

    printf("Other permissions:\n");
    if (fs.st_mode & S_IROTH) {
        printf("read\n");
    }
    if (fs.st_mode & S_IWOTH) {
        printf("write\n");
    }
    if (fs.st_mode & S_IXOTH) {
        printf("execute\n");
    }

    putchar('\n');

    return 0;
}