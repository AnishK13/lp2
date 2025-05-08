#include<bits/stdc++.h>
using namespace std;

void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, 
  vector<int> &leftrow, vector<int> &upperdiag, vector<int> &lowerdiag){
    if(col==n){
      ans.push_back(board);
      return;
    }

    for(int row=0; row<n; row++){
      if(leftrow[row]==0 && upperdiag[row-col + n-1]==0 && lowerdiag[row+col]==0){
        board[row][col]='Q';
        leftrow[row]=1;
        upperdiag[row-col + n-1]=1;
        lowerdiag[row+col]=1;
        solve(col+1, n, board, ans, leftrow, upperdiag, lowerdiag);
        board[row][col]='.';
        leftrow[row]=0;
        upperdiag[row-col + n-1]=0;
        lowerdiag[row+col]=0;
      }
    }
}


int main(){
    int n=4;
    vector<vector<string>>ans;
    string s(n,'.');
    vector<string>board(n,s);
    vector<int> leftrow(n,0), upperdiag(2*n-1,0), lowerdiag(2*n-1,0);
    solve(0,n,board,ans,leftrow,upperdiag,lowerdiag);
    cout<<"ans size: "<<ans.size()<<endl;
    for(auto i: ans){
      for(auto j: i){
        cout<<j<<endl;
      }
      cout<<endl;
    }
  
}