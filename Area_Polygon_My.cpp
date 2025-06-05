#include <bits/stdc++.h>
#define int long long 

using namespace std;

int orientation(int x1,int y1,int x2,int y2,int x3,int y3)
{
    // int p1p2=(y2-y1)/(x2-x1);// for refernce of diff as numerator *LCM of denomiator
    // int p2p3=(y3-y2)/(x3-x2);//for refernce off diff
    int diff = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);

    if(diff < 0) return 1; // LEFT
    else if(diff == 0) return 2; // TOUCH
    else return 3; // RIGHT
}

// Fix: General function to check if point (x, y) lies on segment (x1, y1)-(x2, y2)
bool onSegment(int x1, int y1, int x2, int y2, int x, int y) {
    return x >= min(x1, x2) && x <= max(x1, x2) &&
           y >= min(y1, y2) && y <= max(y1, y2);
}

bool intersection(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int p1p2_p3 = orientation(x1,y1,x2,y2,x3,y3);
    int p1p2_p4 = orientation(x1,y1,x2,y2,x4,y4);
    int p3p4_p1 = orientation(x3,y3,x4,y4,x1,y1);
    int p3p4_p2 = orientation(x3,y3,x4,y4,x2,y2);

    // General case
    if (((p1p2_p3 == 1 && p1p2_p4 == 3) || (p1p2_p3 == 3 && p1p2_p4 == 1)) &&
        ((p3p4_p1 == 1 && p3p4_p2 == 3) || (p3p4_p1 == 3 && p3p4_p2 == 1)))
        return true;

    // Special colinear cases
    if (p1p2_p3 == 2 && onSegment(x1, y1, x2, y2, x3, y3)) return true;
    if (p1p2_p4 == 2 && onSegment(x1, y1, x2, y2, x4, y4)) return true;
    if (p3p4_p1 == 2 && onSegment(x3, y3, x4, y4, x1, y1)) return true;
    if (p3p4_p2 == 2 && onSegment(x3, y3, x4, y4, x2, y2)) return true;

    return false;
}

int area(int x1,int y1,int x2,int y2)
{
    
    int ans=(x1*y2)-(x2*y1);//cross product of two vector gives area
    
    return ans;

}


int32_t main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> verti(n);
    for(int i=0;i<n;i++)
    {
        
        cin >> verti[i].first >> verti[i].second;
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        int x1=verti[i].first;
        int y1=verti[i].second;

        int x2=(verti[(i+1)%n].first);
        int y2=(verti[(i+1)%n].second);
        result+=area(x1,y1,x2,y2);
    }
    cout<<abs(result)<<endl;

   

    return 0;
}



