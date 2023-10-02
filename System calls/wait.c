#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pid,status,exitch;
	if((pid=fork())==-1){
		perror("Error\n");
		exit(0);
	}
	if(pid==0){
		sleep(1);
		printf("Child process\n");
		exit(0);}
	printf("Parent process\n");
	if((exitch=wait(&status))==-1){
		perror("During wait()");
		exit(0);
	}
	printf("Parent exiting\n");
	exit(0);
}
