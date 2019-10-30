#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

int main(int argc ,char* argv[]){
	int pidx=0,pidy=0,pidz=0;
	printf("create main process %d\n",getpid());
	printf("process %d create process %d\n",getpid(),pidx=fork());
	printf("process %d create process %d\n",getpid(),pidy=fork());
	printf("process %d create process %d\n",getpid(),pidz=fork());
	
	
	int status;
	//printf("PROcess %d has child %d %d %d\n",getpid(),pidx,pidy,pidz);    
	if(pidz==0){
		printf("process %d exit its child process 0 0 0\n",getpid());
	}
	else if(pidy==0){
                waitpid(pidz,&status,0);
		printf("process %d exit its child process 0 0 %d\n",getpid(),pidz);
	}
	else if(pidx==0){
                waitpid(pidy,&status,0);
		waitpid(pidz,&status,0);
		printf("process %d exit its child process 0 %d %d\n",getpid(),pidy,pidz);
	}
	else{
		waitpid(pidx,&status,0);
		waitpid(pidy,&status,0);
                waitpid(pidz,&status,0);
		printf("process %d exit its child process %d %d %d\n",getpid(),pidx,pidy,pidz);
		
	}
	exit(0);
}

