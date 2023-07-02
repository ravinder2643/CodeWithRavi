#include<iostream>
using namespace std;

int main() {
int num;
int i;
int c=0;
cout<<"enter any number"<<endl;
cin>>num;

for (int i=1; i<=num; i++){
  if (num%i==0){
    c++;
  }
}
if (c==2){
    cout<<"prime number";
}
else{
cout<<"number is not prime";
}
}

