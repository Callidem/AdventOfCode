// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int exponencial(int base, int exp)
{
    if (exp == 0) {
        cout << "Exp é zero" << endl;
        return 1;
    }
    int resultado = base;
    for(int i = 1; i < exp/2; i++){
        resultado *= base;
    }
    resultado *= resultado;
    if(exp % 2 != 0) resultado *= base;
    
    return resultado;

}

int main()
{
    int base, exp;
    cout << "Digite a base: " << endl;
    cin >>  base;
    cout << "Digite o expoente: " << endl;
    cin >> exp;
    int resultado = exponencial(base, exp);
    cout << "O exponencial de " << base << " na base " << exp << " eh " << resultado << endl;
}