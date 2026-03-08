#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define COUNT 100
int main(int argc, char* argv[]){
	char buf[COUNT];	
	if(argc != 3){
		printf("few args \n");
		exit(-1);
	}

	int fd1 = open(argv[1],O_RDONLY);

	if ( fd1 < 0 )
	{
		printf("failed to open\n");
		exit(-2);
	}


	int reads;

	int fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0644);    	
	if (fd2 < 0) {
    		printf("failed to open destination file\n");
    		close(fd1);
	    	exit(-4);
	}

	while( (reads= read(fd1,buf,COUNT)) > 0 ){
		if(write(fd2,buf,reads) != reads)
		{
			printf("failed to write\n");
			exit(-3);
		}
	}

	close(fd1);	
	close(fd2);
	return 0;
}

