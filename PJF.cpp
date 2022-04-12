// priority scheduling 
#include<bits/stdc++.h>
using namespace std; 
class job{
    public:
        int AT,BT,PRO,PR,WT,TAT;
};
int main(){
    job *a;
    int n,*temp;
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
	cin>>n;
	a = new job[n+1]; // dynamically initialise the memory of class object a
	temp = new int[n];
    cout<<"Enter the process id, arrival time, priroity, burst time respectively,"<<n<<" times\n";
    for(int i=0;i<n;i++)
    {
		cin>>a[i].PRO>>a[i].AT>>a[i].PR>>a[i].BT;
        // copying the burst time in
        // a temp array for the further use
        // in calculation of WT
        temp[i]=a[i].BT;
    }
    cout<<"Your input is:-"<<endl;
	cout<<"Process Id\tArrival Time\tPriority\tBurst Time\n";
    for(int i=0; i<n; i++){
		cout<<a[i].PRO<<"\t\t"<<a[i].AT<<"\t\t"<<a[i].PR<<"\t\t"<<a[i].BT<<endl;
	}
    a[n].PR = INT_MAX;
    for(int t=0; count<n; t++){
        short_P = n;
        for(int i=0; i<n; i++){
            if(a[i].PR<a[short_P].PR and (a[i].BT>0 and a[i].AT<=t)){
                short_P = i;
            }
        }
        a[short_P].BT--;
        if(a[short_P].BT == 0){
            count++;
            a[short_P].WT = t+1-a[short_P].AT-temp[short_P];
            a[short_P].TAT = temp[short_P]+a[short_P].WT;

            total_WT+=a[short_P].WT;
            total_TAT+=a[short_P].TAT;
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