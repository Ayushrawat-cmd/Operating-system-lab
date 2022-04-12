//banker algo for multiple resource instances to avoid the deadlock
#include<bits/stdc++.h>
using namespace std;
int main(){
    int pro, res;
    cout<<"Enter the number of processes:- ";
    cin>>pro;
    cout<<"\nEnter the number of resources:- ";
    cin>>res;
    int alloc[pro][res], max_req[pro][res],avail[res], need[pro][res];
    cout<<"\nEnter the Allocation matrix:- \n";
    for(int i=0; i<pro; i++){
        for(int j=0; j<res; j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"\nEnter the max request matrix:- \n";
    for(int i=0; i<pro; i++){
        for(int j=0; j<res; j++){
            cin>>max_req[i][j];
            if(max_req[i][j] - alloc[i][j]<=0)
                need[i][j] = 0;
            else
                need[i][j] =max_req[i][j] - alloc[i][j];
        }
    }
    cout<<"\nEnter the availability of the resources:- \n";
    for(int i=0; i<res; i++){
        cin>>avail[i];
    }
    int done =0, safe ;
    vector<int>safe_sequence; // take the safe sequence in it
    
    cout<<"\nYour input is:- \n";
    cout<<"\nThe allocated resource table is:-\n";
    for(int i=0; i<pro; i++){
        for(int j=0; j<res; j++){
            cout<<"\t"<<alloc[i][j];
        }
        cout<<endl;
    }
    cout<<"\nThe maximum request table is:- \n";
    for(int i=0; i<pro; i++){
        for(int j=0; j<res; j++){
            cout<<"\t"<<max_req[i][j];
        }
        cout<<endl;
    }
    cout<<"\nThe available vector is:- \n";
    for(int j=0; j<res; j++){
        cout<<"\t"<<avail[j];
    }

    // below loop check wether there is initially 0 int need matrix    
    for(int i =0; i<pro; i++){
        int zeroes = 0;
        for(int j =0; j<res; j++){
            if(need[i][j] == 0){
                zeroes++;
            }
        }
        if(zeroes == res){
            for(int j=0; j<res; j++){
                    // need[i][j] = 0;
                    avail[j]+=alloc[i][j];
                }
            cout<<"\nProcess "<<i<<" is executing...\n";
            cout<<"\nAvailaible vector:- ";
            for(auto j:avail){
                cout<<"\t"<<j;
            }
            cout<<endl;
            safe_sequence.push_back(i);
            done++;
        }
    }

    // Below do while loop check wether the system is safe or not and if its safe then what is the safe sequence
    do{
        safe = 0;
        for(int i=0; i<pro; i++){
            int flag = 0;
            int zeroes = 0;
            for(int j=0; j<res; j++){
                if(need[i][j] == 0){
                    zeroes++;
                }
                if(need[i][j]>avail[j] or zeroes == res){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                for(int j=0; j<res; j++){
                    need[i][j] = 0;
                    avail[j]+=alloc[i][j];
                }
                cout<<"\nProcess "<<i<<" is executing...\n";
                cout<<"\nAvailaible vector:- ";
                for(auto j:avail){
                    cout<<"\t"<<j;
                }
                cout<<endl;
                safe_sequence.push_back(i);
                done++;
                safe = 1;
            }
        }
    }while(done!=pro and safe==1);
    if(done<pro){
        cout<<"\n\tSystem is in unsafe state";
    }
    else{
        cout<<"\nSystem is in safe state and safe sequence is:- \n";
        for(int i=0; i<pro; i++){
            cout<<"\t"<<safe_sequence[i];
        }
    }
    return 0;
}