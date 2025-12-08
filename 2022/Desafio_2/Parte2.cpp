// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int pedraPapelTesoura(string line){
    int resultado = 0;
    // 1 for Rock, 2 for Paper, and 3 for Scissors
    // 0 if you lost, 3 if the round was a draw, and 6 if you won
    // X lose, Y draw, and Z win.
    // A for Rock, B for Paper, and C for Scissors
    switch(line[0]){
        case 'A':
            switch (line[2]) {
                case 'X':
                    resultado = 3 + 0;
                    break;
                case 'Y':
                    resultado = 1 + 3;
                    break;
                case 'Z':
                    resultado = 2 + 6;
                    break;
            }
            break;
        case 'B':
            switch (line[2]){
                case 'X':
                        resultado = 1 + 0;
                        break;
                case 'Y':
                        resultado = 2 + 3;
                        break;
                case 'Z':
                        resultado = 3 + 6;
                        break;
            }
        break;

        case 'C':
            switch (line[2]) {
                case 'X':
                    resultado = 2 + 0;
                    break;
                case 'Y':
                    resultado = 3 + 3;
                    break;
                case 'Z':
                    resultado = 1 + 6;
                    break;
            }
        break;
    }
    return resultado;
}

int main(){
    string line;
    int sum = 0;
    ifstream arq("input.txt");
    if (arq.is_open()){
        while (getline(arq, line)){
            sum += pedraPapelTesoura(line);
        }
        arq.close();
    }

    cout << "A pontuacao final eh " << sum << endl;
}