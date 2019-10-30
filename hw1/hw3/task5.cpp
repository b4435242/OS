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
		cout<<((*shm)+1)%3<<endl;
                cin>>temp;
        }
}
