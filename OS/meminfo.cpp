#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    cout<<"Kernel version :"<<endl;
    system("cat /proc/sys/kernel/osrelease");
    cout<<"Memory Configuration :"<<endl;
    system("cat /proc/meminfo | awk 'NR==1{print$2}'");
    cout<<"Free Memory :"<<endl;
    system("cat /proc/meminfo | awk 'NR==2{print$2}'");
    cout <<"Used Memory :\n";
    system("cat /proc/meminfo | awk '{ if (NR==1) a=$2; if(NR==2) b=$2 }END {print a-b} '");
    
    return 0;
}