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
```
struct dirent *readdir(DIR *dirp);
```
