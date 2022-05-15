#include<bits/stdc++.h>
using namespace std;
int main(){
    int head;
    cout<<"Enter the initial head position:- ";
    cin>>head;
    int n;
    cout<<"Enter the number of requests:- ";
    cin>>n;
    cout<<"Enter "<<n<<" reference requests:- \n";
    int rq[n];
    for(int i =0;i <n; i++){
        cin>>rq[i];
    }
    int ans =0;
    for(int i =0; i<n; i++){
        ans+=abs(rq[i]-head);
        head = rq[i];
    }
    cout<<"Total number of head movements are:- "<<ans;
}