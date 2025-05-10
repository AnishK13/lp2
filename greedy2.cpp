#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> prims(vector<vector<pair<int,int>>> adj, int vertices){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,0});

    vector<bool>vis(vertices, false);
    vector<int>parent(vertices,-1);
    vector<pair<int,int>>ans;

    while(!pq.empty()){
        int old_dist = pq.top().first;
        int old_node = pq.top().second;
        pq.pop();

        if(!vis[old_node]){
            vis[old_node]=true;
            
            if(parent[old_node] != -1){
                ans.push_back({old_node, parent[old_node]});
            }

            for(auto i: adj[old_node]){
                int curr_dist = i.first;
                int curr_node = i.second;
                
                if(!vis[curr_node]){
                    pq.push({curr_dist, curr_node});
                    parent[curr_node] = old_node;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int edges, vertices;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;

    vector<vector<pair<int,int>>> adj(vertices);
    while(edges--){
        int source,dest,dist;
        cout<<"Enter source: ";
        cin>>source;
        cout<<"Enter destination: ";
        cin>>dest;
        cout<<"Enter distance: ";
        cin>>dist;
        adj[source].push_back({dist,dest});
        adj[dest].push_back({dist,source});
    }
    // cout<<endl;
    // cout<<"Adjacency list is: ";
    // for(int i=0;i<vertices;i++){
    //     cout<<i<<"-> ";
    //     for(auto j: adj[i]){
    //         cout<<j.first<<" "<<j.second<<", ";
    //     }
    //     cout<<endl;
    // }

    vector<pair<int,int>>ans = prims(adj,vertices);
    
    cout<<"Prims Answer:"<<endl;
    for(auto i: ans){
        cout<<i.first<<" "<<i.second<<", ";
    }
}