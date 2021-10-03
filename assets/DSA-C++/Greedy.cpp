//Fractional Knapsack using greedy method

#include<iostream>
using namespace std;

int main()
{
    int n,W,temp,c=0;
    cout<<"Enter the no. of values and weights: ";
    cin>>n;
    cout<<"Enter the Knapsack Capacity: ";
    cin>>W;
    double v[n],w[n],ratio[n],profit=0;
    cout<<"Enter the values: "<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Enter the weights: "<<endl;
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        ratio[i]=v[i]/w[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=v[j];
                v[j]=v[i];
                v[i]=temp;

                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w[i]<=W)
        {
            c++;
            profit+=v[i];
            W-=w[i];
            w[i]=0;
        }
    }
    if(W!=0)
    {
        profit+=(v[c]*(W/w[c]));
    }
    cout<<"maximum profit: "<<profit<<endl;
    return 0;
}

/*
INPUT
Enter the no. of values and weights: 4
Enter the Knapsack Capacity: 60
Enter the values:
280
100
120
Enter the weights:
40
10
20

OUTPUT
maximum profit: 440

*/
