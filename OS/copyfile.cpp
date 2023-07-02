#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(int argc,char* argv[]) {
    char a[1000000];
    int n;
    int src = open(argv[1], O_RDONLY);
    int dstn = open(argv[2], O_WRONLY | O_CREAT);

    if (src < 0){
        cout<<"\nSource File cannot be opened.\n";
        exit(1);
    }
    if (dstn < 0){
        cout << "\nTarget File cannot be opened/created.\n";
        exit(2);
    }
    while ((n = read(src, a, 100)) > 0)
            write(dstn, a, n);

    write(dstn, "\0", 1);

    if (n < 0)
            cout << "\nFile could not read the content.\n";
    else
        cout<<"File was successfully copied.\n";

    close(src);
    close(dstn);

    return 0;
}