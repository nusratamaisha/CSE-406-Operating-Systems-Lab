
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
    string dir;
    cin>>dir;
    int seek_time=0;
    int idx;
    for(int i=0; i<n; i++){
        if(head==arr[i]){
            idx=i;
            break;
        }
    }
    if(dir == "left"){
        for(int i=idx-1; i>=0; i--){
            seek_time+=abs(head-arr[i]);
            head = arr[i];
        }
        for(int i=n-1; i>idx; i--){
            seek_time+=abs(head-arr[i]);
            head = arr[i];
        }
    }
    else if(dir == "right"){
        for(int i=idx+1; i<n; i++){
            seek_time+=abs(head-arr[i]);
            head = arr[i];
        }
        for(int i=0; i<idx; i++){
            seek_time+=abs(head-arr[i]);
            head = arr[i];
        }

    }
    cout<<seek_time<<endl;
}
