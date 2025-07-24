#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    bool done = false;
};

int main() {
    int n;
    cout<<"Enter the number of Processes:";
    cin>>n;
    cout<<"Take input for Process ID, Arrival Time, Burst Time"<<endl;
    vector<Process>p;
    for(int i = 0; i < n; i++) {
        Process temp;
        cout<<"For Process "<<i+1<<":\n";
        cin>>temp.pid>>temp.arrival>>temp.burst;
        p.push_back(temp);
    }
    int time = 0;
    int completed = 0;
    while (completed<n) {
        int idx = -1;
        int min_burst = 1e9;
        for (int i=0; i<n; i++) {
            if (!p[i].done && p[i].arrival <= time && p[i].burst < min_burst) {
                min_burst= p[i].burst;
                idx= i;
            }
        }

        if (idx != -1) {
            time += p[idx].burst;
            p[idx].completion = time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].done = true;
            completed++;
        }
        else {
            time++;
        }
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &proc : p) {
        cout<<"P"<<proc.pid<<"\t"<<proc.arrival<<"\t"<<proc.burst <<"\t"<<proc.completion<<"\t"<<proc.turnaround<<"\t"<<proc.waiting<<"\n";
    }
    return 0;
}

/*
        {1, 0, 3}
        {2, 1, 2}
        {3, 2, 1}
        {4, 3, 4}
        {5, 0, 2}
*/
