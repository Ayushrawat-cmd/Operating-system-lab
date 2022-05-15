// Direction is towards the highest value 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int head,tracks;
    cout<<"Enter the initial head position:- ";
    cin>>head;
    cout<<"Enter the number of tracks:- ";
    cin>>tracks;
    int n;
    cout<<"Enter the number of requests:- ";
    cin>>n;
    cout<<"Enter "<<n<<" reference requests:- \n";
    vector<int> rq(n);
    int ans = tracks-1;
    for(int i =0;i <n; i++){
        cin>>rq[i];
    }
    for(int i=head; i<tracks; i++){
        if(find(rq.begin(),rq.end(),i)!=rq.end()){
            rq.erase(remove(rq.begin(),rq.end(), i));
        }
    }
    ans+=tracks-1-head;
    for(int i =0; i<tracks; i++){
        if(find(rq.begin(),rq.end(),i)!=rq.end()){
            rq.erase(remove(rq.begin(),rq.end(), i));
        }
        if(rq.empty()){
            ans+=i;
            break;
        }
    }
    cout<<"Total head movements are:- "<<ans;
    return 0;
}