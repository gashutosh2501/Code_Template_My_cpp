#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=1e9+7;
 
int fast_power(int a,int b)
{
    int ans=1;
    while(b>0)
    {
         if(b%2!=0)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
 
    }
   
    return ans;
 
}
 
int32_t main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<fast_power(a,b)%mod<<endl;;
 
 
    }
 
    
 
    return 0;
}
