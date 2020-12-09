#ifndef dc_fcntl_h
#define dc_fcntl_h


int dc_open(const char *path, int oflag, ...);
int dc_open_error(void (*handler)(const char *, int), const char *path, int oflag, ...);


#endif
