#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> lps(string s) {
    int n = s.length();
    vector<int> lps1(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps1[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps1[len - 1];  // go back to previous possible prefix
            } else {
                lps1[i] = 0;
                i++;
            }
        }
    }
    return lps1;
}

vector<int> z_string(string s)
{
    vector<int> z(s.length());
    z[0]=0;
    int r=0;
    int l=0;
    for(int i=1;i<s.length();i++)
    {
        if(i<=r)
        {
            z[i]=min(r-i+1,z[0+i-l]);

        }
        while(s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }

    }
    return z;

}

int32_t main() 
{
    string s;
    cin >> s;

    vector<int> result = lps(s);
    vector<int> result2 = z_string(s);

    for(int x:result2)
    {
        cout<<x<<' ';
    }
    cout<<endl;

    for(int x:result)
    {
        cout<<x<<' ';
    }

    return 0;
}
