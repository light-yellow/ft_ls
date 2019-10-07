# ft_ls

Директория - файл, состоящий из специальных записей dirent, которые содержат данные о файлах в директории:
```
struct dirent {
  ino_t          d_ino;       /* inode number */
  off_t          d_off;       /* offset to the next dirent */
  unsigned short d_reclen;    /* length of this record */
  unsigned char  d_type;      /* type of file; not supported
                                 by all file system types */
  char           d_name[256]; /* filename */
};
```
***
Функция opendir() открывает поток директории и возвращает указатель на структуру типа DIR, которая содержит информацию о директории.
```
struct DIR {
    struct dirent ent;
    struct _WDIR *wdirp;
};
typedef struct DIR DIR;
DIR *opendir(const char *name);
```
***
Функция readdir() возвращает следующую структуру dirent считанную из файла-директории.
При достижении конца списка файлов в директории или возникновении ошибки возвращает NULL.
```
struct dirent *readdir(DIR *dirp);
```

To iterate through the entries in a directory, you need to call readdir, passing it a DIR * that was returned from opendir. This will return a dirent * from which you can read the name of the directory entry.

The function will return NULL when all entries have been read.

Объяви структуру со всеми нужными полями (имя файла, права и тд). При чтении каталога заполняй массив с этими структурами, увеличивая его размер при необходимости. Для сортировки используй qsort.

***
Algorithm: In program used two structures: the first stores input data from the console and folders to bypass in the case of the -R flag. Sorting is implemented by the merge method. The second structure is used when opening a folder. A linked list of structures2 is created containing detailed information about the files depending on the flags. Further, the data from structure 2 are sent to the output. To speed up the program, all data from one folder is displayed in one write.
***

# Usage
```
./ft_ls [-AadfGlorRStT] [arg] ...
```
# Options
```
-A : List all entries including those starting with a dot except . and ..
-a : List all entries including those starting with a dot.
-d : Directories are listed as plain files (not searched recursively)
-f : Output is not sorted.
-G : Enable colors.
-l : List in long format (ownership,user and groupe IDs, date/time, file size, name).
-o : List in long format, but omits group ID.
-R : Recursively list directories encountered.
-r : List in a reverse order.
-S : Sort files by size.
-T : When used with -l option, display complete time information of the file (from year to minute).
-t : Sorted by time modified before sorting the operands by lexicographical order.
```
