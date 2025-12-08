// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool left(vector<string> grid, int i, int j){
    for(int x = 0; x < j; x++){// comparar com arvores da esq e dir
        if(grid[i][x] >= grid[i][j]) return false;// se achar uma mais alta ou de mesmo tamanho, retorna falso
    }   
    return true;
}

bool right(vector<string> grid, int i, int j){
    for(int x = j+1; x < grid[i].size(); x++){// comparar com arvores da esq e dir
        if(grid[i][x] >= grid[i][j]) return false;// se achar uma mais alta ou de mesmo tamanho, retorna falso
    }   
    return true;
}
bool top(vector<string> grid, int i, int j){
    for(int x = 0; x < i; x++){// comparar com arvores da mesma coluna
        if(grid[x][j] >= grid[i][j]) return false;
    }
    return true;
}

bool bottom(vector<string> grid, int i, int j){
    for(int x = i+1; x < grid.size(); x++){// comparar com arvores da mesma coluna
        if(grid[x][j] >= grid[i][j]) return false;
    }
    return true;
}

bool visible(vector<string> grid, int i, int j){
    if (right(grid, i, j) || left(grid, i, j) || top(grid, i, j) || bottom(grid, i, j)) return true;
    return false;
}

int main(){
    string line, sAux;
    int fSize = 0;
    vector<string> grid;
    fstream arq("input.txt");

    while(!arq.eof()){
        getline(arq, line);
        grid.push_back(line);
    }

    int tallT = 0;
    tallT += 4 * grid.size() - 4;
    cout << tallT << endl;
    for(int i = 1; i < grid.size() - 1; i++){
        for(int j = 1; j < grid[i].size() - 1; j++){
            if(visible(grid, i, j)) tallT++;
        }
    }
    
    cout << "Arvores visiveis " << tallT << endl;
}