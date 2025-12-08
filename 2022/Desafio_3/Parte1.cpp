// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char letraRepetida(string line){
    char repetido = '0';
    bool stop = false;
    for(int i = 0; i < line.size()/2; i++){
        for(int j = line.size()/2; j < line.size(); j++){
            if(line[i] == line[j]){
                repetido = line[i];
                stop = true;
                break;
            }
        }
        if (stop == true) break;
    }
    return repetido;
}

bool contains(char *types, char verif){
    for(int i = 0; i < 300; i++){
        if(types[i] == verif){
            return true;
        }
    }
    return false;
}

int main(){
    string line;
    int sum = 0;
    char repetido;
    int qte = 0;
    char types[300];

    ifstream arq("input.txt");
    if (arq.is_open()){
        while (getline(arq, line)){
            qte++;
            if(!line.empty()){
                repetido = letraRepetida(line);
                cout << line << endl;
                cout << "Repetido: " << repetido;
                if (repetido > 40 and repetido < 91){
                    sum += repetido - 38;
                    cout << "/ Valor: " << repetido - 38 << endl;
                }
                else if(repetido > 60 and repetido < 123){
                    sum += repetido - 96;
                    cout << "/ Valor: " << repetido - 96 << endl;
                }
                else cout << "/ Valor: " << repetido << endl;
            }
        }
        arq.close();
    }
    cout << "Qte = " << qte << endl;
    cout << "A prioridade final eh  " << sum << endl;
}