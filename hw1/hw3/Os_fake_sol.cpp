#include<bits/stdc++.h>
#include <sys/shm.h>
using namespace std;
int main(){
	string s;
	int key,shmid=0;
	int *shm;
	cin >> key;
	shmid=shmget(key,sizeof(int),0);
	shm=(int*)shmat(shmid,NULL,0);
	
	string temp;
	for(int i=0;i<100;i++){
		cin>>temp;
		if(*shm==0)
			cout<<"Scissor"<<endl;
		else if(*shm==1)
			cout<<"Stone"<<endl;
		else
			cout<<"Paper"<<endl;
        	cin>>temp;
    	}
}
