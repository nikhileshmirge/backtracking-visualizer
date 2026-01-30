#include<iostream>
#include<vector>
#include<cstring>
#include<thread>
#include<chrono>

using namespace std;

void pause(int ms = 25){
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printGrid(vector<vector<char>>& grid){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char>>& grid, int row, int col, char ch){
    for(int i=0; i<9; i++){
        if(grid[row][i] == ch) return false;
    }
    for(int i=0; i<9; i++){
        if(grid[i][col] == ch) return false;
    }
    int r=(row/3)*3; int c=(col/3)*3;
    for(int ro=r; ro<r+3; ro++){
        for(int co=c; co<c+3; co++){
            if (grid[ro][co] == ch) return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<char>>& grid, int row, int col){
    if(row >= 9){
        return true;
    }
    if(col >= 9){
        return sudokuSolver(grid, row+1, 0);
    }
    if(grid[row][col] != '.'){
        return sudokuSolver(grid, row, col+1);
    }
    for(int i=1; i<=9; i++){
        char dig='0'+i;
        if(isSafe(grid, row, col, dig)){
            grid[row][col]=dig;
            clearScreen();
            printGrid(grid);
            pause(40);

            if(sudokuSolver(grid, row, col+1)) return true;
            grid[row][col]='.';
            clearScreen();
            printGrid(grid);
            pause(40);
        }
    }
    return false;
}


int main(){
    vector<vector<char>> grid(9, vector<char>(9)); 
    for(int i = 0; i < 9; i++){
        string row;
        cin >> row;
        for(int j = 0; j < 9; j++){
            grid[i][j] = row[j];
        }
    }

    if(sudokuSolver(grid, 0, 0)){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<"|"<<grid[i][j]<<"|";
            }
            cout<<endl<<"---------------------------"<<endl;
        }
    }
    else{
        cout<<"there is no possible solution for this";
    }
    return 0;
}
