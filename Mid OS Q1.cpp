#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,pair<string, int>>>v;
    for(int i=0; i<n; i++){
        int arrt, bt;
        string pid;
        cin>>pid>>arrt>>bt;
        v.push_back({arrt, {pid, bt}});
    }
    vector<int>ct(n), tat(n),wt(n), visited(n);
    int total = 0;
    int time = 0;
    cout<<"pid\tat\tbt\tct\ttat\twt\n";
    while(total < n){
        int idx = -1;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            if(v[i].first<=time && !visited[i]){
                if(v[i].second.second<mini){
                    mini=v[i].second.second;
                    idx=i;

                }
                else if(v[i].second.second == mini && v[i].first<v[idx].first){
                    idx = i;
                }
            }
        }
        if(idx == -1){
            time++;
        }
        else{
            time += v[idx].second.second;
            ct[idx] = time;
            tat[idx] = ct[idx] - v[idx].first;
            wt[idx] = tat[idx] - v[idx].second.second;
            total++;
            visited[idx]=true;
            cout<<v[idx].second.first<<"\t"<<v[idx].first<<"\t"<<v[idx].second.second<<"\t"<<ct[idx]<<"\t"<<tat[idx]<<"\t"<<wt[idx]<<endl;
        }
    }

}
