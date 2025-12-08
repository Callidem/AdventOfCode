// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char letraRepetida(string line)
{
    char repetido = '0';
    bool stop = false;
    for (int i = 0; i < line.size() / 2; i++)
    {
        for (int j = line.size() / 2; j < line.size(); j++)
        {
            if (line[i] == line[j])
            {
                repetido = line[i];
                stop = true;
                break;
            }
        }
        if (stop == true)
            break;
    }
    return repetido;
}

bool contains(string types, char verif)
{
    for (int i = 0; i < types.size(); i++)
    {
        if (types[i] == verif)
        {
            return true;
        }
    }
    return false;
}

char verifTrio(string line1, string line2, string line3) {
    for( int i = 0; i < line1.size(); i++){
        cout << "Char verif: " << line1[i] << endl;
        if (contains(line2, line1[i]) && contains(line3, line1[i])) return line1[i];
    }
    return '0';    
}

int main()
{
    string line1, line2, line3;
    int sum = 0;
    char repetido;
    int qte = 0;

    ifstream arq("input.txt");
    if (arq.is_open())
    {
        while (getline(arq, line1))
        {
            qte++;
            getline(arq, line2);
            getline(arq, line3);
            repetido = verifTrio(line1, line2, line3);
            cout << qte << " Repetido: " << repetido;
            if (repetido > 40 and repetido < 91)
            {
                sum += repetido - 38;
                cout << "/ Valor: " << repetido - 38 << endl;
                }
                else if (repetido > 60 and repetido < 123)
                {
                    sum += repetido - 96;
                    cout << "/ Valor: " << repetido - 96 << endl;
                }
                else
                    cout << "/ Valor: " << repetido << endl;
        }
        arq.close();
    }
    cout << "Qte = " << qte << endl;
    cout << "A prioridade final eh  " << sum << endl;
}