#include <bits/stdc++.h>
using namespace std;
template<typename T>


class Graph 
{
	map < T, list<pair<T, int>>>mp; //Adj. List
	map<T, bool>visited;
    map<T,T> parent;// Maintaing a parent to backtrack to any node 
    
    


public:
	void AddEdge(T x, T y, int w) {
		mp[x].push_back({y, w});
		mp[y].push_back({x, w});
	}

	void Dijkstras(T scr, T des) {
		map<T, int>distance;
		set < pair<int, T> >s;

		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}

		distance[scr] = 0;
        parent[scr]=-1;
		s.insert({0, scr});

		while (!s.empty()) {

			pair<int, T> f = *(s.begin());
			s.erase(s.begin());

            int dist = f.first;
			T node = f.second;
			

			/*

				For Every element of this mp[node] that is going
				to be represented as child do the ttask.


				what is the type of mp[node]:

				mp[node] is a list of pair<T,int>

				and since we are saying for every element of this list
				 do the task

				hence type of this child will be pair<T,int>
				as very element of the list is a pair.

			*/

			for (pair<T, int> child : mp[node]) 
            {
                
				//This is an egde weight of node to child
				int edgeweight = child.second;
				if (distance[child.first] > dist + edgeweight) 
                {
					auto f = s.find({distance[child.first], child.first});
					if (f != s.end()) {
						s.erase(f);
					}
					//Insert thee node with new value.
                    //Distance[child.first] means distance[v]
					distance[child.first] = dist + edgeweight;
                    parent[child.first]=node;
					s.insert({distance[child.first], child.first});
				}
                
                
			}
		}

		// for (auto x : mp) {
		// 	cout << "Distance of " << x.first << " from " << scr << " : " << distance[x.first] << endl;
		// }
        if(distance[des]==INT_MAX)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
       
        else
        {
            vector<T> result;
            cout<<distance[des]+1<<endl;
            for(T it=des;it!=-1;it=parent[it])
            {
                result.push_back(it);

            }
            reverse(result.begin(),result.end());
            for(T num: result)
            {
                cout<<num<<" ";
            }
        }
        
        
	}

};
#define int long long

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;

    Graph<int> gr;

    while(m--)
    {
        int a,b;
        int c=1;
        cin>>a>>b;
        gr.AddEdge(a,b,c);

    }
    gr.Dijkstras(1,n);


        
    return 0;
}
