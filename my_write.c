#include <sys/stat.h>
#include "apue.h"

#define DEFULT 4096

char buf[] = "c";

/* take in path, size */
int main(int argc, char* argv[]){
	int fd;
	if((fd = creat(argv[1], FILE_MODE)) < 0)
		err_sys("creat error");
	
	int size = DEFULT;
	int c;
	if((c = getopt(argc, argv, "s:")) != -1){
		if(c == 's')
			size = atoi(optarg);
	}

	int write_bytes;
	while((write_bytes = write(fd, buf, 1) > 0)){
		off_t currpos;
		if((currpos = lseek(fd, 0, SEEK_CUR)) > size - 1)
			break;
	}
	
	close(fd);
}
