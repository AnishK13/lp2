#include<bits/stdc++.h>
using namespace std;

void recursive_dfs(int start, map<int,vector<int>>& adj, vector<int>& recursive_dfs_ans, vector<bool>& vis){
    vis[start]=1;
    recursive_dfs_ans.push_back(start);
    for(auto i: adj[start]){
        if(!vis[i]){
            recursive_dfs(i,adj,recursive_dfs_ans,vis);
        }
    }
}

void dfs(int start, map<int,vector<int>>& adj, vector<int>& dfs_ans){
    stack<int>st;
    vector<bool>vis(INT_MAX,false);
    st.push(start);
    vis[start]=true;
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        dfs_ans.push_back(curr);

        for(int i=adj[curr].size()-1;i>=0;i--){ 
            int num = adj[curr][i];
            if(!vis[num]){
                vis[num]=true;
                st.push(num);
            }
        }
        
    }
}


void bfs(int start, int nodes, map<int,vector<int>>& adj, vector<int>& ans){
    queue<int>q;
    vector<bool>vis(INT_MAX,false);
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        int curr=q.front();
        for(auto i: adj[curr]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
        q.pop();
        ans.push_back(curr);
    }
}

int main()
{
    int nodes,edges,u,v;
    cout<<"Enter number of nodes: ";
    cin>>nodes;
    map<int,vector<int>>adj;
    cout<<"Enter number of edges: ";
    cin>>edges;

    cout<<"Enter routes as u v"<<endl;
    while(edges--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"Adjaceny List is: "<<endl;
    for(auto i: adj){
        cout<<i.first<<"-> ";
        for(auto j: i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int>ans;
    vector<int>dfs_ans;
    vector<int>recursive_dfs_ans;

    int start;
    cout<<"Enter starting node: ";
    cin>>start;

    bfs(start, nodes,adj,ans);
    cout<<"BFS Traversal is: "<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }

    dfs(start,adj,dfs_ans);
    cout<<"DFS Traversal is: "<<endl;
    for(auto i: dfs_ans){
        cout<<i<<" ";
    }

    vector<bool>vis(INT_MAX,false);
    recursive_dfs(start, adj, recursive_dfs_ans, vis);
    cout<<"Recursive DFS Traversal is: "<<endl;
    for(auto i: recursive_dfs_ans){
        cout<<i<<" ";
    }
}