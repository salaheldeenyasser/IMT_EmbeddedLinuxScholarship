#include <stdio.h>
#include <unistd.h>

#define COUNT 100
#define LINELENGTH 1024
int main(int argc, char* argv[])
{
	char buf[COUNT];
	char line[LINELENGTH];
	size_t readByte;
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

	char command[1];
	command[0] = NULL;
	while(scanf("%s", command[0]) != EOF){
		switch(command[0]){
		case ' ':
			
			
		default:
			printf("invalid command \n");
			exit(-4);
		}
		
	}
	
	close(fd);

	return 0;
}	

