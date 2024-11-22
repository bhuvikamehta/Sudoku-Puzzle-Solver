#include <iostream>
#include<cmath>
using namespace std;

void boardPrint(int board[][9],int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<< board[i][j]<<" ";
        }
        cout <<endl;
    }
    cout<<endl;
}

bool isValidAns(int board[][9], int row, int col, int ans, int n){
    //check in row
    for (int i=0; i<n; i++){
        if (board[row][i]==ans){
            return false;
        }
    }
    //check in column 
    for (int i=0;i<n;i++){
        if (board[i][col]==ans){
            return false;
        }
    }
    // number ka box check
    int rootOfn = sqrt(n);
    int initialRow = row - (row%rootOfn);
    int initialCol = col - (col%rootOfn);

    for (int i=initialRow; i< (initialRow+rootOfn); i++){
        for (int j=initialCol; j< (initialCol+rootOfn);j++){
            if (board[i][j]==ans){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int board[][9], int row, int col, int n){
    if (row==n){ // if at the end of sudoku board
       boardPrint(board,n);
       return true;
    }

    if (col==n){ // if at the end of row
        return sudokuSolver(board,row+1,0,n);
    }

    if (board[row][col] != 0){ //case if the box is filled
        return sudokuSolver(board, row,col+1,n);
        // return true;
    }

    for(int ans=1;ans<=9;ans++){
        if(isValidAns(board, row, col, ans,n)){
            board[row][col]=ans;
            bool nextAns = sudokuSolver(board,row,col+1,n);
            if (nextAns){
                return true;
            }
            // if not true then backtrakcing
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int n=9;
    int board[9][9] = {
        {0, 0, 7, 1, 0, 0, 0, 6, 0},
        {1, 0, 5, 2, 0, 8, 0, 0, 0},
        {6, 0, 0, 0, 0, 7, 1, 2, 0},
        {3, 1, 2, 4, 0, 5, 0, 0, 8},
        {0, 0, 6, 0, 9, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 1},
        {0, 0, 1, 0, 0, 4, 9, 8, 6},
        {8, 0, 3, 9, 0, 6, 0, 0, 0},
        {0, 6, 0, 0, 8, 2, 7, 0, 3},
    };
    if(!sudokuSolver(board, 0,0,n)){
        cout<<"no solution exists for the given puzzle"<<endl;
    }

    return 0;
}
