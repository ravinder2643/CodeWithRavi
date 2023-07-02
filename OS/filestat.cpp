#include<iostream>
#include<cstdlib>   
#include<cstring>
#include<sys/stat.h>
using namespace std;

int main(int argc, char* argv[])
{
    struct stat s1;
    if (stat(argv[0],& s1)<0){
cout<<"invalid:";

    }
    
        

     else{
    cout << "Owner access permissions and file access time :\n"<<s1.st_uid;

    

    cout<<"ID"<<s1.st_uid<<"\n";
    cout<<"Access Time"<<s1.st_atime<<"\n";
    cout<<"mode"<<s1.st_mode<<"\n";
    cout<<"File size"<<s1.st_blksize<<"\n";
    cout<<"Group Id"<<s1.st_gid<<"\n";


    

     }



    return 0;
}
