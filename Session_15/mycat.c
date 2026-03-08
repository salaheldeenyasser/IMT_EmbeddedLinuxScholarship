#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define COUNT 100
int main(int argc, char* argv[]){

	
	char* buf[COUNT];
	char* Path = argv[1];	
	
	if(argc != 2){
		printf("few args \n");
		exit(-1);
	}

	int fd = open(Path,O_RDONLY);

	if ( fd < 0 )
	{
		printf("failed \n");
		exit(-2);
	}


	
	int reads;
       	while((reads = read(fd,buf,COUNT))>0){
		if(write(1,buf,reads) < 0)
		{
			printf("failed \n");
			exit(-3);
		}
	}
	
	close(fd);

	return 0;
}
