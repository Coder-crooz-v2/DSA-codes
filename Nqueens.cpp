#include <bits/stdc++.h>
using namespace std;
void solve(int col, vector<vector<int>>& answer, vector<vector<int>>& board, int n, vector<int> row, vector<int> udiag, vector<int> ldiag) {
	if(col == n) {
		vector<int> temp;
		for(int i = 0; i < board.size(); i++) {
			for(int j = 0; j < board[0].size(); j++) {
				temp.push_back(board[i][j]);
			}
		}
		answer.push_back(temp);
		return;
	}
	for(int r = 0; r < n; r++) {
		if(row[r] == 0 && udiag[r+col] == 0 && ldiag[n-1+col-r] == 0) {
			board[r][col] = 1;
			row[r] = 1;
			udiag[col+r] = 1;
			ldiag[n-1+col-r] = 1;
			solve(col+1, answer, board, n, row, udiag, ldiag);
			board[r][col] = 0;
			row[r] = 0;
			udiag[col+r] = 0;
			ldiag[n-1+col-r] = 0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int> (n, 0));
	vector<vector<int>> answer;
	vector<int> row(n, 0);
	vector<int> udiag(2*n-1, 0);
	vector<int> ldiag(2*n-1, 0);
	solve(0, answer, board, n, row, udiag, ldiag);
	for(auto i: answer) {
        for(auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
	return answer;
}
int main() {
    vector<vector<int>> board = nQueens(4);
    return 0;
}