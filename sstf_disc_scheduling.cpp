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
    vector<int>rq(n);
    for(int i =0;i <n; i++){
        cin>>rq[i];
    }
    int ans =0;
    int completed = 0;
    while (completed!=n){
        int small=INT_MAX;
        int idx = -1;
        for(int i =0; i<rq.size(); i++){
            if(small>abs(head-rq[i])){
                idx = i;
                small = abs(head-rq[i]);
            }
        }   
        if(idx!=-1){
            ans+= abs(head-rq[idx]);
            head = rq[idx];
            rq.erase(rq.begin()+idx);
            
            completed++;
        }
    }
    cout<<"Total head movements are:- "<<ans;
    
    return 0;
}