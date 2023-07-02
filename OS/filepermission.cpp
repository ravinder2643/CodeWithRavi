#include<iostream>
#include<cstdlib>   
#include<cstring>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Owner access permissions and file access time :\n";
    char s[200] = "";
    strcat(s, "ls -l ");
    strcat(s, argv[1]);
    strcat(s, " | awk '{print $1,$6,$7,$8}'");
    system(s);

    return 0;
}
