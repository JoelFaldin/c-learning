# Directory tree

Exercises and programs related to file/directory information.

1. Print file details:

```
gcc dir_tree/file_info.c
./a.out ./a.out
```

Result: Lots of information about the file. You can change the parameter to use another file.

2. Print files in a directory and details about them:

```
gcc dir_tree/read_dir.c
./a.out
```

Result: Directories and files present on the dir. Also, their size and time of creation.

3. Get current workind dir:

```
gcc dir_tree/getcwd.c
./a.out
```

Result: Absolute path to c-learning directory.

4. Change current working dir:

```
gcc dir_tree/changecwd.c
./a.out
```

Result: Directory before change and after change