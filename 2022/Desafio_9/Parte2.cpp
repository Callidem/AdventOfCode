// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int left(vector<string> grid, int i, int j){
    int aux = 0;
    for (int x = j-1; x >= 0; x--){
        aux++;
        if (grid[i][x] >= grid[i][j]) break;
    }
    //cout << " Esq:" << aux;
    return aux;
}

int right(vector<string> grid, int i, int j){
    int aux = 0;
    for (int x = j+1; x < grid[i].size(); x++) {
        aux++;
        if (grid[i][x] >= grid[i][j]) break;
    }
    //cout << " Dir:" << aux;
    return aux;
}
int top(vector<string> grid, int i, int j){
    int aux = 0;
    for (int x = i - 1; x >= 0; x--){
        aux++;
        if (grid[x][j] >= grid[i][j]) break;
    }
    //cout << " Top:" << aux;
    return aux;
}
int bottom(vector<string> grid, int i, int j){
    int aux = 0;
    for (int x = i + 1; x < grid.size(); x++){
        aux++;
        if (grid[x][j] >= grid[i][j]) break;
    }
    //cout << " Bot:" << aux;
    return aux;
}

int scenicScore(vector<string> grid, int i, int j){
    return top(grid, i, j) * left(grid, i, j) * bottom(grid, i, j) * right(grid, i, j);
}

int main(){
    string line, sAux;
    int fSize = 0;
    vector<string> grid;
    fstream arq("input.txt");

    while (!arq.eof()){
        getline(arq, line);
        grid.push_back(line);
    }
    
    int tallT = 0, sScore;
    cout << tallT << endl;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[i].size(); j++){
            //cout << "Arvore(" << i << "," << j <<"):"; 
            sScore = scenicScore(grid, i, j);
            if(sScore > tallT) {
                tallT = sScore;
            //    cout << tallT << endl;
            }
            //cout << endl;
        }
    }

    cout << "Melhor arvore " << tallT << endl;
}