#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n){
    int oldrow = row;
    int oldcol = col;

    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    col=oldcol;
    row=oldrow;

    while(col>=0 && row>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row--;
    }

    col = oldcol;
    row = oldrow;

    while(col>=0 && row<n){
        if(board[row][col]=='Q') return false;
        col--;
        row++;
    }

    return true;
}

void normal(int col, vector<string>& board, vector<vector<string>>& normal_ans, int n){
    if(col==n){
        normal_ans.push_back(board);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            normal(col+1, board, normal_ans, n);
            board[row][col]='.';
        }
    }
}


void branch_bound(int col, int n, vector<string>& board, vector<vector<string>>& branch_bound_ans, 
            vector<int>& leftrow, vector<int>& upperdiag, vector<int>& lowerdiag){
    if(col==n){
        branch_bound_ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(leftrow[row]==0 && upperdiag[row+col]==0 && lowerdiag[row-col+n-1]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            upperdiag[row+col]=1;
            lowerdiag[row-col+n-1]=1;
            branch_bound(col+1,n,board,branch_bound_ans,leftrow,upperdiag,lowerdiag);
            board[row][col]='.';
            leftrow[row]=0;
            upperdiag[row+col]=0;
            lowerdiag[row-col+n-1]=0;
        }
    }
}

int main()
{
    int n=5;
    string s(n,'.');
    vector<string>board(n,s);
    vector<vector<string>>branch_bound_ans;
    vector<vector<string>>normal_ans;
    vector<int> leftrow(n,0), upperdiag(2*n-1, 0), lowerdiag(2*n-1, 0);
    
    branch_bound(0, n, board, branch_bound_ans, leftrow, upperdiag, lowerdiag);
    cout<<"Branch and Bound answer: "<<endl;
    for(auto i: branch_bound_ans){
        for(auto j: i){
            cout<<j<<endl;
        }
        cout<<endl;
        cout<<"-----------"<<endl;
        cout<<endl;
    }

    normal(0, board, normal_ans, n);
    cout<<"Normal answer: "<<endl;
    for(auto i: normal_ans){
        for(auto j: i){
            cout<<j<<endl;
        }
        cout<<endl;
        cout<<"-----------"<<endl;
        cout<<endl;
    }
}