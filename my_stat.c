#include "apue.h"

int main(int argc, char* argv[])
{
	struct stat buf;
	stat(argv[1], &buf);
	char result[3];
	if(S_IRUSR&buf.st_mode)
		result[0] = 'r';
	else
		result[0] = '-';
	if(S_IWUSR&buf.st_mode)
		result[1] = 'w';
	else
		result[1] = '-';
	if(S_IXUSR&buf.st_mode)
		result[2] = 'x';
	else
		result[2] = '-';
	printf("%s", result);
	
}
