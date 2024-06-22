#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int val, int n) {
    for(int i = 0; i < n; i++) {
        if(board[row][i] == val)
            return false;
        if(board[i][col] == val)
            return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>>& board) {
    int n = board[0].size();

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {

            if(board[row][col] == 0) {

                for(int val = 1; val <= 9; val++) {
                    
                    if(isSafe(board, row, col, val, n)) {
                        board[row][col] = val;

                        bool nextPossible = solve(board);
                        if(nextPossible) {
                            return true;
                        }
                       else {
                        board[row][col] = 0;
                       }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main() {
    vector<vector<int>> board( {{8,0,0,0,0,0,0,0,0},
                                {0,0,3,6,0,0,0,0,0},
                                {0,7,0,0,9,0,2,0,0},
                                {0,5,0,0,0,7,0,0,0},
                                {0,0,0,0,4,5,7,0,0},
                                {0,0,0,1,0,0,0,3,0},
                                {0,0,1,0,0,0,0,6,8},
                                {0,0,8,5,0,0,0,1,0},
                                {0,9,0,0,0,0,4,0,0}});
    bool check = solve(board);
    if(check)
    for(int i = 0; i < board.size(); i++) {
        if(i%3 == 0 && i != 0)
            cout<<endl;
        for(int j = 0; j < board[0].size(); j++) {
            if(j%3 == 0 && j != 0)
                cout<<" ";
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    else
    cout<<"Solution not possible :("<<endl;
    return 0;
}