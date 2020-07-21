#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

int main()
{
    int n,q;
    cout<<"C++ Program to implement ROUND ROBIN Algorithm."<<endl;
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
    cout<<endl<<"Enter quantum time : ";
    cin>>q;
    cout<<endl<<"______________________________________"<<endl;
    cout<<"| Process | Arrival Time | Burst Time |"<<endl;
    cout<<"|_________|______________|____________|"<<endl;
    for(int i=0;i<n;i++)
        cout<<"|P"<<left<<setw(8)<<ord[i]<<"|"<<left<<setw(14)<<arr[i]<<"|"<<left<<setw(12)<<bur[i]<<"|"<<endl;
    cout<<"|_________|______________|____________|"<<endl;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(ord[j],ord[j+1]);
                swap(arr[j],arr[j+1]);
                swap(bur[j],bur[j+1]);
            }
        }
    }
    int wt[n],te[n],rt[n];
    cout<<endl<<"The order in which the processes are executes is : "<<endl;
    int j=0;
    int ts=0;
    for(int i=0;i<n;i++)
    {
        rt[i]=bur[i];
        wt[i]=0;
        te[i]=0;
    }
    while(j<=n)
    {
        j++;
        for(int i=0;i<n;i++)
        {
            if(rt[i]==0)
                continue;
            if(rt[i]>q)
            {
                cout<<"P"<<i+1<<" ";
                ts=ts+q;
                rt[i]=rt[i]-q;
                te[i]=te[i]+1;
            }
            else
            {
                cout<<"P"<<i+1<<" ";
                wt[i]=ts-te[i]*q;
                ts=ts+rt[i];
                rt[i]=rt[i]-rt[i];
            }
        }
    }
    cout<<endl;
    int total_wt=0,total_tat=0;
    for(int i=0;i<n;i++)
    {
        wt[i]=wt[i]-arr[i];
        total_wt=total_wt+wt[i];
    }
    int tat[n];
    for (int i=0;i<n;i++)
    {
        tat[i]=bur[i]+wt[i];
        total_tat = total_tat + tat[i];
    }

    cout<<endl<<"Average waiting time = "<< (float)total_wt / (float)n<<endl;
    cout<<"Average turn around time = "<< (float)total_tat / (float)n<<endl;
    cout<<endl<<endl;
    return 0;
}

