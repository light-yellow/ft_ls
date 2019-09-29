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
Функция opendir() открывает поток каталога и возвращает указатель на структуру типа DIR, которая содержит информацию о каталоге.
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
