#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
	{
	int c;
	cout<<"Enter your choice"<<endl;
	cin>>c;
	
	switch(c){
	case 1:
		fork();
		cout<<"Parent and child execute same program same code\n";
		break;
	case 2:
		pid_t pid;
		pid=fork();
		if(pid==0){
			cout<<"Process id: "<<getpid()<<endl;
			execlp("/bin/ls","ls",NULL);
		}
		else if(pid>0)
		{
			cout<<"Process id: "<<getpid()<<endl;
			cout<<"\nChild Complete\n";
		}
		break;
	case 3:
		pid_t cid;
		cid=fork();
		if(cid==0)
		{
			cout<<"Process id: "<<getpid()<<endl;
			execlp("/bin/ls","ls",NULL);
		}
		else if(cid>0)
		{
			wait(NULL);
			cout<<"Process id: "<<getpid()<<endl;
			cout<<"Parent waited for child"<<endl;
			cout<<"\nChild Complete\n";
		}
		break;
	default:
		cout<<"Wrong choice"<<endl;
	}
return 0;
}

