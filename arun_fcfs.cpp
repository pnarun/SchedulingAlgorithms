#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

int main()
{
    cout<<"C++ Program to implement FIRST COME FIRST SERVE Algorithm."<<endl;
    int n;
    cout<<"Enter number of processes : ";
    cin>>n;
    int arr[n],bur[n],ord[n];
    for(int i=0;i<n;i++)
    {
        cout<<endl<<"Enter following details for process "<<(i+1)<<endl;
        cout<<"Arrival time : ";
        cin>>arr[i];
        cout<<"Burst time : ";
        cin>>bur[i];
        ord[i]=(i+1);
    }
    cout<<endl<<"______________________________________"<<endl;
    cout<<"| Process | Arrival Time | Burst Time |"<<endl;
    cout<<"|_________|______________|____________|"<<endl;
    for(int i=0;i<n;i++)
        cout<<"|P"<<left<<setw(8)<<ord[i]<<"|"<<left<<setw(14)<<arr[i]<<"|"<<left<<setw(12)<<bur[i]<<"|"<<endl;
    cout<<"|_________|______________|____________|"<<endl;
    cout<<endl<<"The order in which the processes are executes is : "<<endl;
    for(int i=0;i<n;i++)
        cout<<"P"<<ord[i]<<" ";
    cout<<endl;
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0]=0;
    for(int i=1;i<n;i++ )
        wt[i]=bur[i-1]+wt[i-1] ;
    for (int  i=0; i<n; i++)
    {
        tat[i]=bur[i]+wt[i];
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
    cout<<endl<<"Average waiting time = "<< (float)total_wt / (float)n<<endl;
    cout<< "Average turn around time = "<< (float)total_tat / (float)n<<endl;
    cout<<endl<<endl;
    return 0;
}
