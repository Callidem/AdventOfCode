// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool contains(int low1, int high1, int low2, int high2){
    if( (low1 >= low2) && (high1 <= high2) ) return true;
    if( (low2 >= low1) && (high2 <= high1) ) return true;    
    return false;
}




int main(){
    string line, sAux;
    int low1, low2, high1, high2;
    int cont = 0;
    fstream arq("input.txt");


    if (arq.is_open()){
        while (!arq.eof()){
            arq >> low1;
            getline(arq, line, '-');
            arq >> high1;
            getline(arq, line, ',');
            arq >> low2;
            getline(arq, line, '-');
            arq >> high2;
            
            if(contains(low1, high1, low2, high2)) {
                cont++;
                cout << "Low1: " << low1 << endl;
                cout << "/High1: " << high1 << endl;
                cout << "Low2: " << low2 << endl;
                cout << "/High2: " << high2 << endl;
            }
        }
        arq.close();
    }

    cout << "Total de sobreposicoes: " << cont << endl;
}