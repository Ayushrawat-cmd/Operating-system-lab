#include<bits/stdc++.h>
using namespace std;
map<int,int>wait;
bool sortbysec(const pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
    return (a.second.second < b.second.second);
}
bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b){
    return a.second>b.second;
}
  
void modify_wait_time(vector<int>process,vector<int>arrival_time, vector<int>burst_time ){
    vector<pair<int,pair<int,int>>>pr;
    map<int,int>wait_help;
    map<int,int>wait_help1;
    
    for(int i =0; i<process.size(); i++){
        pr.push_back(make_pair(arrival_time[i],make_pair(process[i],burst_time[i])));
        wait_help[process[i]] = arrival_time[i];
        wait_help1[process[i]] = burst_time[i];
    }
    sort(pr.begin(), pr.end());
    vector<pair<int,int>>ready;
    for(int i =0; i<process.size(); i++){
        int j = i;
        while(pr[j].first == pr[i+1].first){
            i++;
        }
        sort(pr.begin()+j, pr.end()-(pr.size()-i-1), sortbysec);

    }
    int cpu = 0;
    for(int i=0; i<pr.size(); i++){
        
        if(i == 0){
            int ix = i;
            cpu += pr[ix].second.second;
            while(pr[i+1].first<=pr[ix].second.second){
                i++;
                ready.push_back(make_pair(pr[i].second.first,pr[i].second.second));
            }
            sort(ready.begin(),ready.end(),sortbysecdesc);
            wait[pr[ix].second.first] = pr[ix].second.second - pr[ix].first - pr[ix].second.second;
        }
        else{
            cpu+=wait_help1[ready[ready.size()-1].first];
            wait[ready[ready.size()-1].first] = cpu - wait_help[ready[ready.size()-1].first] - wait_help1[ready[ready.size()-1].second];
            ready.pop_back();
            int ix = i;
            // cout<<cpu<<" ";
            while(pr[i].first<=cpu){
                ready.push_back(make_pair(pr[i].second.first,pr[i].second.second));
                i++;
            }
            sort(ready.begin(),ready.end(),sortbysecdesc);
            // cout<<i;
        }
    }
    for(int pro = ready.size()-1; pro>=0; pro--){
        cpu += wait_help1[ready[pro].first];
        wait[ready[pro].first] = cpu - wait_help[ready[pro].first] - ready[pro].second ;
    }
    cout<<"Process Id\tWaiting Time\n";
    int mean_time = 0;
    for(auto i:wait){
        cout<<i.first <<"\t\t"<<i.second<<endl;
        mean_time += i.second;
    }
    cout<<"Average waiting time:- "<<(float)mean_time/(float)wait.size()<<endl;
}
void turn_around_time(vector<int>process,vector<int>burst_time){
    int sum=0;
    cout<<"Process Id\tTurnaround Time\n";
    for(int i =0; i<process.size(); i++){
        cout<<process[i]<<"\t\t"<<wait[process[i]]+burst_time[i]<<endl;
        sum+=wait[process[i]]+burst_time[i];
    }
    cout<<"Average Turnaround time:- "<<(float)sum/(float)wait.size()<<endl;
}
int main(){
    vector<int>arrival_time,burst_time,process;
    int arr,burst,pro;
    int n;
    cout<<"Enter the number of processes:: ";
    cin>>n;
    cout<<"Enter the process id, arrival time, burst time respectively,"<<n<<" times\n";
    int flag = 0;
    for(int i =0; i<n; i++){
        cin>>pro>>arr>>burst;
        process.push_back(pro);arrival_time.push_back(arr); burst_time.push_back(burst);
        if(arrival_time[i]!=arrival_time[i-1] and i>0){
            flag = 1;
        }
    }
    cout<<"\nWaiting Time:- \n";
    modify_wait_time(process,arrival_time,burst_time);
    cout<<"\nTurn-around Time:- "<<endl;
    turn_around_time(process,burst_time);
    return 0;
}