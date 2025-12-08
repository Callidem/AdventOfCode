#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main (void){
    
    ifstream arq;
    arq.open("input.txt");
    
    string line;
    int sum = 0;

    while(!arq.eof()){
        getline(arq, line);
        for(int i = 0; i < line.size(); i++){//primeiro numero
            if(line[i] > 47 && line[i] < 58) {
                sum += 10*(line[i] - 48);
                cout << "Somando: " << line[i] << endl;
                break;
            }
        }
        for(int i = line.size(); i >= 0; i--){//ultimo numero
            if(line[i] > 47 && line[i] < 58) {
                sum += line[i] - 48;
                cout << "Somando: " << line[i] << endl;
                break;
            }
        }
    }
    cout << sum;

    cin >> sum;
}