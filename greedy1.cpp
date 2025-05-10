#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstras(vector<vector<pair<int,int>>>& adj, int vertices){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    pq.push({0,0});
    vector<int>distance(vertices, INT_MAX);
    distance[0]=0;

    while(!pq.empty()){
        int old_dist = pq.top().first;
        int old_node = pq.top().second;
        pq.pop();

        for(auto i: adj[old_node]){
            int curr_dist = i.first;
            int curr_node = i.second;

            if(old_dist+curr_dist < distance[curr_node]){
                distance[curr_node] = old_dist+curr_dist;
                pq.push({distance[curr_node], curr_node});
            }
        }
    }
    return distance;
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

    vector<int>ans = dijkstras(adj,vertices);
    
    cout<<"Djkstras Answer:"<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
}