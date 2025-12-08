#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main (void){
    vector <string> mapa;
    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int i = 0;
    while(!arq.eof()){
        getline(arq, line);
        mapa.push_back(line);
        //cout << mapa[i] << endl;
        i++;
    }

    for(int i = 0; i < mapa.size(); i++){
        for(int j = 0; j < mapa[i].size(); j++){
            if(mapa[i][j] != '.'){
                if(i > 0){
                    if(mapa[i - 1][j] != '.' && mapa[i - 1][j] < 48 && mapa[i - 1][j] > 57) ;
            }
        }
    }


}