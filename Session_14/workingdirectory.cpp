#include <iostream>
#include <unistd.h>
int main(){
	char fs[100];
	getcwd(fs, sizeof(fs));
	std::cout<<fs<<std::endl;}
