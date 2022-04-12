#include<bits/stdc++.h>
using namespace std;
class job{
    public:
        int AT,WT,TAT,BT,PRO;
};
bool sort_by_at(job x, job y){
    return x.AT<y.AT;
}
int main(){
    job *a;
    int n,*temp;
    int i=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
	cin>>n;
	a = new job[n+1]; // dynamically initialise the memory of class object a
	temp = new int[n];
    cout<<"Enter the process id, arrival time, burst time respectively,"<<n<<" times\n";
    for(int i=0;i<n;i++)
    {
		cin>>a[i].PRO>>a[i].AT>>a[i].BT;
        // copying the burst time in
        // a temp array for the further use
        // in calculation of WT
        temp[i]=a[i].BT;
    }
    sort(a, a+n,sort_by_at);
    while(i!=n){
        if(a[i].AT<=t){
            t+=a[i].BT;
            a[i].WT = t-a[i].BT-a[i].AT;
            a[i].TAT = a[i].WT+a[i].BT;
            // total calculation
            total_WT+=a[i].WT;
            total_TAT+=a[i].TAT;
            i++;
        }
        else{
            t++;
        }
    }
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    // printing of the answer
	cout<<endl<<"Final Result::"<<endl;
    cout<<"Process Id\tWaiting Time\tTurn Around Time\n";
    for(int i=0;i<n;i++)
    {
		cout<<a[i].PRO<<"\t\t"<<a[i].WT<<"\t\t"<<a[i].TAT<<endl;
    }
    printf("Avg waiting time of the process is %.2f\n",Avg_WT);
    printf("Avg turn around time of the process %.2f\n",Avg_TAT);

}