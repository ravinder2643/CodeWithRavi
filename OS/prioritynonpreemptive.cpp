#include<iostream>
using namespace std;
int main(){
    int n, i, j;
    string name [5];
    cout<<"Enter the number of process you want:";
    cin>>n;


    int arr_t[n];
    int prior[n];
    string arr[n];
    int wait[n];
    int com[n];

    for(i=0;i<n;i++){
        cout<<"Enter the process name:"<<i+1<<endl;
        cin>>name[i];
        cout<<"Enter the "<<"P"<<i+1<<"priority:";
        cin>>prior[i];
        cout<<"Enter the brust time of P"<<i+1<<endl;
        cin>>arr_t[i];
         
    }
    //assuming that higher number having higher priority
    int temp;
    int tempp;
    string tempc;
    for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(prior[i]<prior[j]){
temp=arr_t[i];
tempc=arr[i];
tempp=prior[i];
arr_t[i]=arr_t[j];
arr[i]=arr[j];
prior[i]=prior[j];
arr_t[j]=temp;
arr[j]=tempc;
prior[j]=tempp;
}
}
    }

int sum=0;
wait[0]=0;
for(int i=1;i<n;i++){
wait[i]=arr_t[i-1]+wait[i-1];
sum+=wait[i];
}
com[0]= arr_t[0];
int sum_c=arr_t[0];
for(int i=1;i<n;i++){
com[i]=com[i-1]+arr_t[i];
sum_c+=com[i];
}
cout<<"PROCESSES ARE SORTED ACC TO PRIORITY NUMBER!!"<<endl;
cout<<endl;
cout<<"PROCESS NAME\t"<<"PRIORITY NO.\t"<<"BURST TIME\t"<<"WAITING TIME\t"<<"COMPLETION TIME"<<endl;
for(int k=0;k<n;k++){

    cout<<prior[k]<<"\t\t"<<arr_t[k]<<"\t\t"<<name[k]<<"\t\t"<<wait[k]<<"\t\t"<<com[k]<<endl;
}
cout<<endl;
cout<<"AVERAGE WAITING TIME: "<<sum/n<<endl;
cout<<"AVERAGE COMPLETION TIME: "<<sum_c/n<<endl;



}