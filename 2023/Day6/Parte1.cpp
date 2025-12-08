#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main (void){

    //Time:        48     93     84     66
    //Distance:   261   1192   1019   1063
    
    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int sum = 0, nAux;
    
    stringstream sAux;

    vector<int> times, dists;

    getline(arq, line);
    sAux << line;
    sAux >> line;
    
    while(!sAux.eof()){
        sAux >> nAux;
        times.push_back(nAux);
    }

    
    getline(arq, line);
    sAux.clear();
    sAux << line;
    sAux >> line;
    
    while(!sAux.eof()){
        sAux >> nAux;
        dists.push_back(nAux);
    }

    cout << "times: " << endl;
    for(int i = 0; i < times.size(); i++){
        cout << times[i] << endl;
    }

    cout << "dists: " << endl;
    for(int i = 0; i < dists.size(); i++){
        cout << dists[i] << endl;
    }
    

    sum = 1;
    for(int i = 0; i < times.size(); i++){
        nAux = 0;
        for(int j = 0; j < times[i]; j++){
            if(dists[i] < (j * (times[i] - j))) nAux++;
        }
        sum *= nAux;
    }

    cout << sum;
}