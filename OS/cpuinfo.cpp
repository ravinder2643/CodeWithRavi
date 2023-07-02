#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    //system("cat /proc/cpuinfo");
    system("cat /proc/kernel/osrelease");
    system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'");
    return 0;
}