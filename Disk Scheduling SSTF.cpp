#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cin>>n>>head;

    vector<int> requests(n);
    for (int i = 0; i < n; i++) {
        cin>>requests[i];
    }
  
    vector<bool> visited(n, false);
    int totalSeek = 0;
    int currentHead = head;

    for (int i = 0; i < n; i++) {
        int idx=-1;
        int minDist=INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance=abs(currentHead - requests[j]);
                if (distance<minDist) {
                    minDist=distance;
                    idx=j;
                }
            }
        }

        visited[idx]=true;
        totalSeek+=minDist;
        currentHead=requests[idx];
    }

    cout<<totalSeek<<endl;
}
