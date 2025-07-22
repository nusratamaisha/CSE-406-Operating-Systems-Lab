#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    int pid[4]={1, 2, 3, 4};
    int arr_t[4]={0, 1, 2, 3};
    int bt[4]={3, 2, 1, 4};
    */
    int pid[4], arr_t[4], bt[4];
    cout<<"Take input for Process ID, Arrival Time, Burst Time"<<endl;
    for(int i=0; i<4; i++){
        cout<<"For Process "<<i+1<<":\n";
        cin>>pid[i]>>arr_t[i]>>bt[i];
    }

    int ct[4]={}, tat[4]={}, wt[4]={};
    ct[0]=bt[0];
    int sum=0;
    for(int i=1;i<4; i++){
        ct[i]=bt[i]+ct[i-1];
    }


    for(int i=0; i<4; i++){
        tat[i] = ct[i] - arr_t[i];
        wt[i] = tat[i]-bt[i];
    }

    cout<<"Completion Time\n";
    for(int i=0;i<4; i++){
        cout<< ct[i]<<" ";
    }

    cout<<"\nTurn Around Time\n";
    for(int i=0;i<4; i++){
        cout<< tat[i]<<" ";
    }

    cout<<"\nWaiting Time\n";
    for(int i=0;i<4; i++){
        cout<< wt[i]<<" ";
        sum+=wt[i];
    }
    cout<<"\nAverage Waiting Time:"<<sum/4<<endl;
}
