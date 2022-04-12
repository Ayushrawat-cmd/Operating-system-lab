// SJF preemptive scheduling
#include<bits/stdc++.h>
using namespace std;
class process
{
	public:
    	int PRO,WT,AT,BT,TAT;
};

process * a;

int main()
{
    int n,*temp;
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
	cin>>n;
	a = new process[n+1]; // dynamically initialise the memory of class object a
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
	cout<<"Your input is:-"<<endl;
	cout<<"Process Id\tArrival Time\tBurst Time\n";
    for(int i=0; i<n; i++){
		cout<<a[i].PRO<<"\t\t"<<a[i].AT<<"\t\t"<<a[i].BT<<endl;
	}
    // we initialize the burst time
    // of a process with the maximum
    a[n].BT=INT_MAX;
    // loop will be execute until all the process
    // complete so we use count!= number of 
    // the process
    for(t=0;count!=n;t++)
    {
        // for finding min burst
        // it is useful 
        short_P=n;
        for(int i=0;i<n;i++)
        {
            if(a[i].BT<a[short_P].BT && (a[i].AT<=t && a[i].BT>0))
            {
                short_P=i;
            }
            
        }
        
        a[short_P].BT=a[short_P].BT-1;
        
        // if any process is completed
        if(a[short_P].BT==0)
        {
            // one process complete
            count++;
            a[short_P].WT=t+1-a[short_P].AT-temp[short_P];
            a[short_P].TAT=t+1-a[short_P].AT;
            
            // total calculation
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