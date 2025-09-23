#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int head;
    cin>>head;
    vector<int>visited(n);
    int seek_time=0;
    for(int i=0; i<n; i++){
        int mini = INT_MAX;
        int idx = -1;
        int diff;
        for(int j=0; j<n; j++){
            if(!visited[j]){
                diff = abs(head-arr[j]);
                if(diff<mini){
                    mini =diff;
                    idx = j;
                }
            }
        }
        seek_time += mini;
        head = arr[idx];
        visited[idx]=true;
    }
    cout<<"Total Seek Time: "<<seek_time<<endl;
}
