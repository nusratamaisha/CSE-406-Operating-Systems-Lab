#include<bits/stdc++.h>
using namespace std;

struct Process{
    int pid;
    int priority;
    int arrt;
    int bt;
    int ct;
    int tat;
    int wt;
    bool done;
};

int main(){
    int n;
    cout<<"enter number of process:";
    cin>>n;

    Process p[20];

    for(int i = 0; i<n; i++){
        cout<<"enter priority score, arrival time, burst time for process"<<i+1<<":\n";
        cin>>p[i].priority>>p[i].arrt>>p[i].bt;
    }
    int time=0, finished=0;
    double totatTat=0.0, totalWt=0.0;
    while(finished<n){
        int index = -1;
        int highest_p=INT_MAX;

        for(int i=0; i<n; i++){
            if(!p[i].done && p[i].arrt<=time){
                if(p[i].priority < highest_p){
                    highest_p = p[i].priority;
                    index = i;
                }
            }
        }
        if(index!= -1){
            time += p[index].bt;
            p[index].ct = time;
            p[index].tat = p[index].ct - p[index].arrt;
            p[index].wt = p[index].tat - p[index].bt;
            finished++;
            p[index].done = true;
            totatTat += p[index].tat;
            totalWt += p[index].wt;
        }
        else{
            time++;
        }
    }
    cout<<"\nProcess id \t priority \t arrival \t burst \t\t completed \t turnaround \t waiting\n";
    for(int i=0; i<n; i++){
        cout<<"   p"<<i+1<<"\t\t";
        cout<<"    "<<p[i].priority<<"\t\t";
        cout<<"    "<<p[i].arrt<<"\t\t";
        cout<<"  "<<p[i].bt<<"\t\t";
        cout<<"    "<<p[i].ct<<"\t\t";
        cout<<"    "<<p[i].tat<<"\t\t";
        cout<<"   "<<p[i].wt<<"\t\t";
        cout<<"\n";
    }
}
