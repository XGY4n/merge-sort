#include<bits/stdc++.h>
using namespace std;
void msort(int *a,int l,int mid ,int r)
{
    int temp[r-l+1];
    int f1=l;
    int f2=mid+1;
    for(int i=l;i<=r;i++)
    {
        temp[i-l]=a[i];
    }
    for(int i=l;i<=r;i++)
    {
        if(f1>mid)
        {
            a[i]=temp[f2-l];
            f2++;
        }
        else if(f2>r)
        {
            a[i]=temp[f1-l];
            f1++;
        }
        else if(temp[f2-l]>temp[f1-l])
        {
            a[i]=temp[f1-l];
            f1++;
        }
        else
        {
            a[i]=temp[f2-l];
            f2++;
        }
    }
}
void cut(int *a,int l,int r)
{
    if(r==l)
    {
        return ;

    }
    else
    {
        int mid=(r+l)/2;
        cut(a,l,mid);
        cut(a,mid+1,r);
        msort(a,l,mid,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=1;
    int r=n;
    cut(a,l,r);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}