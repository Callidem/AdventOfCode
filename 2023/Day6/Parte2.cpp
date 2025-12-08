#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getValue(string line){
    int nAux;
    stringstream sAux, sAux2;

    sAux << line;
    sAux >> line;

    while(!sAux.eof()){
        sAux >> nAux;
        sAux2 << nAux;
    }
}

int main (void){

    //Time:        48     93     84     66
    //Distance:   261   1192   1019   1063
    
    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int sum = 0, 
    long long time, dist;

    getline(arq, line);
    
    
    while(!sAux.eof()){
        sAux >> nAux;
        sAux2 << nAux;
    }
        //cout << sAux2.str() << endl;
    sAux2 >> time;
    cout << "time: " << endl;
    cout << time << endl;


    sAux.str("");
    sAux2.str("");
    
    getline(arq, line);
    sAux << line;
    sAux >> line;
    
    while(!sAux.eof()){
        sAux >> nAux;
        cout << nAux << endl;
        sAux2 << nAux;
        cout << sAux2.str() << endl;
    }
    cout << sAux2.str() << endl;

    sAux2 >> dist;
    cout << "dist: " << endl;
    cout << dist << endl;
    

    sum = 1;
    nAux = 0;
    for(int j = 0; j < time; j++){
        if(dist < (j * (time - j))) nAux++;
    }
    sum *= nAux;

    cout << sum;

}