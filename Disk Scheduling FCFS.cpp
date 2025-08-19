#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int head;
    cin>>head;
    int h=head;
    int seek_op = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != h){
            seek_op += abs(head - arr[i]);
            head = arr[i];
        }

    }

    cout<<seek_op<<endl;
}
