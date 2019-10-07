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
-a : List all entries including those starting with a dot.
-l : List in long format (ownership,user and groupe IDs, date/time, file size, name).
-R : Recursively list directories encountered.
-r : List in a reverse order.
-t : Sorted by time modified before sorting the operands by lexicographical order.
```
***

stat, lstat - функции, которые возвращают информацию о файле file_name и заполняют буфер buf. lstat идентична stat, но в случае символьных сылок она возвращает информацию о самой ссылке, а не о файле, на который она указывает. В случае успеха возвращается ноль. При ошибке возвращается -1
```
int stat(const char *file_name, struct stat *buf);
int lstat(const char *file_name, struct stat *buf);
```
Эти функции возвращают структуру stat, которая содержит следующие поля:
```
struct stat {
    dev_t         st_dev;      /* устройство */
    ino_t         st_ino;      /* inode */
    mode_t        st_mode;     /* режим доступа */
    nlink_t       st_nlink;    /* количество жестких ссылок */
    uid_t         st_uid;      /* идентификатор пользователя-владельца */
    gid_t         st_gid;      /* идентификатор группы-владельца */
    dev_t         st_rdev;     /* тип устройства */
                               /* (если это устройство) */
    off_t         st_size;     /* общий размер в байтах */
    blksize_t     st_blksize;  /* размер блока ввода-вывода */
                               /* в файловой системе */
    blkcnt_t      st_blocks;   /* количество выделенных блоков */
    time_t        st_atime;    /* время последнего доступа */
    time_t        st_mtime;    /* время последней модификации */
    time_t        st_ctime;    /* время последнего изменения */
};
```
Указанные далее макросы POSIX проверяют, является ли файл:
```
S_ISLNK(mode) - символьной ссылкой
S_ISREG(mode) - обычным файлом
S_ISDIR(mode) - каталогом
S_ISCHR(mode) - символьным устройством
S_ISBLK(mode) - блочным устройством
S_ISFIFO(mode) - каналом FIFO
S_ISSOCK(mode) - сокетом
```
Описанные ниже флаги определены для поля st_mode:
```
S_IFMT	0170000	битовая маска для полей типа файла
S_IFSOCK	0140000	сокет
S_IFLNK	0120000	символьная ссылка
S_IFREG	0100000	обычный файл
S_IFBLK	0060000	блочное устройство
S_IFDIR	0040000	каталог
S_IFCHR	0020000	символьное устройство
S_IFIFO	0010000	канал FIFO
S_ISUID	0004000	бит setuid
S_ISGID	0002000	бит setgid (смотри ниже)
S_ISVTX	0001000	бит принадлежности (смотри ниже)
S_IRWXU	00700	маска для прав доступа пользователя
S_IRUSR	00400	пользователь имеет право чтения
S_IWUSR	00200	пользователь имеет право записи
S_IXUSR	00100	пользователь имеет право выполнения
S_IRWXG	00070	маска для прав доступа группы
S_IRGRP	00040	группа имеет права чтения
S_IWGRP	00020	группа имеет права записи
S_IXGRP	00010	группа имеет права выполнения
S_IRWXO	00007	маска прав доступа всех прочих (не находящихся в группе)
S_IROTH	00004	все прочие имеют права чтения
S_IWOTH	00002	все прочие имеют права записи
S_IXOTH	00001	все прочие имеют права выполнения
```
