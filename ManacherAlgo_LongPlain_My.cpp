#include <bits/stdc++.h>
using namespace std;

string transform(string s) 
{
    string ans = "#";
    for (char c : s) {
        ans += c;
        ans += "#";
    }
    return ans;
}

string Manacher_LongPalin(string s)
{
   //string s;
    //cin >> s;
    string temp = transform(s);
    int n = temp.size();

    vector<int> p(n, 0);
    int left = 0, right = 0;
    int maxLen = -1;
    int centre = 0;

    for (int i = 0; i < n; i++) 
    {
        int k = 0;

        if (i < right) 
        {
            int j = left + right - i; 
            p[i]=p[j];
        }
        else
        {
            k=right-i;
        }

        while (i - k - 1 >= 0 && i + k + 1 < n && 
                temp[i - k - 1] == temp[i + k + 1]) 
        {
            k++;
        }

        p[i] = k;

        if (i + k > right) {
            left = i - k;
            right = i + k;
        }

        if (p[i] > maxLen) {
            maxLen = p[i];
            centre = i;
        }
    }

    // Recover starting index in original string
    int start = (centre - maxLen) / 2;
    return  s.substr(start, maxLen);
}

int32_t main() 
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string tempans=Manacher_LongPalin(s);
    cout<<tempans<<endl;
    
    

    return 0;
}
