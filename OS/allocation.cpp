
#include<iostream>
using namespace std;

int  totalProcess, totalBlock, blockSize[50], processSize[50], allocation[50], flag;

void input(){
    cout << "Enter Number of Memory Block: ";
    cin >> totalBlock;
    for (int i = 1; i <= totalBlock; i++) {
    cout << "Enter Memory Size for Block [" << i << "]: ";
    cin >> blockSize[i];
    allocation[i] = i;
    }
    cout << "\nEnter Number of Process: ";
    cin >> totalProcess;
    for (int i = 1; i <= totalProcess; i++) {
    cout << "Enter Memory Size for Process [" << i << "]: ";
    cin >> processSize[i];
    }
}

void bestFit(){
    int temp, temp1;
    for (int y = 1; y <= totalBlock; y++) {
        for (int z = y; z <= totalBlock; z++) {
            if (blockSize[y] > blockSize[z]) {
                temp = blockSize[y];
                blockSize[y] = blockSize[z];
                blockSize[z] = temp;
                temp1 = allocation[y];
                allocation[y] = allocation[z];
                allocation[z] = temp1;
            }
        }
    }
}

void worstFit(){
    for (int y = 1; y <= totalBlock; y++) {
        int temp, temp1;
        for (int z = y; z <= totalBlock; z++) {
            if (blockSize[y] < blockSize[z]) {
                temp = blockSize[y];
                blockSize[y] = blockSize[z];
                blockSize[z] = temp;
                temp1 = allocation[y];
                allocation[y] = allocation[z];
                allocation[z] = temp1;
            }
        }
    }
}

void output(){
    for (int i = 1; i <= totalProcess; i++) {
        flag = 1;
        for (int j = 1; j <= totalBlock; j++) {
            if (processSize[i] <= blockSize[j]) {
                cout << "\nProcess [" << i << "] of Size " << processSize[i] << "KB allocated at Memory Block " << allocation[j];
                blockSize[j] = blockSize[j] - processSize[i];
                break;
            } else {
                flag++;
            }
        }
        if (flag > totalBlock) {
            cout << "\nProcess [" << i << "] of Size " << processSize[i] << "KB can't be allocated";
        }
    }
}
int main() {
    cout << "It is a program to implement First Fit, Best Fit, Worst Fit\n";

    input();
    cout << "\nSelect your Choice from the menu:\n\t1. First Fit\n\t2. Best Fit\n\t3. Worst Fit\n\tEnter Choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Memory Allocation Using First Fit\n";
            break;
        case 2:
            cout << "Memory Allocation Using Best Fit\n";
            bestFit();
            break;
        case 3:
            cout << "Memory Allocation Using Worst Fit\n";
            worstFit();
            break;
        default:
            cout << "Wrong Choice!";
    }
    output();
}