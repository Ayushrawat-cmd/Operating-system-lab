#include<bits/stdc++.h>
using namespace std;
vector<int>wait;
void waiting_time(int n,int process[],int burst[], int arrival[]){
    int sum = burst[0];
    cout<<"Process Id\tWaiting Time\n";
    for(int i=0; i<n; i++){
        if(i == 0){
            cout<<process[i]<<"\t\t"<<arrival[i]<<endl;
            wait.push_back(arrival[i]);
        }
        else{
            cout<<process[i]<<"\t\t"<<sum-arrival[i]<<endl;
            wait.push_back(sum-arrival[i]);
            sum+=burst[i];
        }
    }
    int mean_time = 0;
    for(int i =0; i<wait.size(); i++){
        mean_time += wait[i];
    }
    cout<<"Average waiting time:- "<<(float)mean_time/(float)n<<endl;
}
void Turn_around(int n,int process[],int burst[]){
    int sum=0;
    cout<<"Process Id\tTurnaround Time\n";
    for(int i =0; i<n; i++){
        cout<<process[i]<<"\t\t"<<wait[i]+burst[i]<<endl;
        sum+=wait[i]+burst[i];
    }
    cout<<"Average Turnaround time:- "<<(float)sum/(float)wait.size()<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of processes:: ";
    cin>>n;
    int process[n],arrival_time[n],burst_time[n];
    cout<<"Enter the process id, arrival time, burst time respectively,"<<n<<" times\n";
    for(int i =0; i<n; i++){
        cin>>process[i]>>arrival_time[i]>>burst_time[i];
    }
    cout<<"\nWaiting Time:- \n";
    waiting_time(n,process, burst_time,arrival_time);
    cout<<"\nTurn-around Time:- "<<endl;
    Turn_around(n,process, burst_time);
}