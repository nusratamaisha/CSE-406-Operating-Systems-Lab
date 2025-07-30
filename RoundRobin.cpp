#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;
    int arrt, bt, rt;
    int ct, tat, wt;
    bool completed;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for P" << p[i].pid << ": ";
        cin >> p[i].arrt;
        cout << "Enter Burst Time for P" << p[i].pid << ": ";
        cin >> p[i].bt;
        p[i].rt = p[i].bt;
        p[i].completed = false;
    }
    cout << "Enter Time Quantum: ";
    cin >> quantum;
    queue<int>q;
    vector<bool>inQueue(n, false);
    int time= 0, completed= 0;
    for (int i= 0; i< n; i++) {
        if (p[i].arrt== 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }
    while (completed < n) {
        if (q.empty()) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && p[i].arrt <= time) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }
        int idx = q.front();
        q.pop();

        int exec_time = min(quantum, p[idx].rt);
        time += exec_time;
        p[idx].rt -= exec_time;

        for (int i= 0; i < n; i++) {
            if (!inQueue[i] && p[i].arrt <= time) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].arrt;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;
            completed++;
        }
        else {
            q.push(idx);
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& process : p) {
        cout << "P" << process.pid << "\t" << process.arrt << "\t" << process.bt << "\t" << process.ct<< "\t" << process.tat << "\t" << process.wt << "\n";
    }
}
