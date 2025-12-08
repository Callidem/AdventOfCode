// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string line, sAux;
    int topoDest, topoOrig;
    int cont = 0;
    int stackCount = 9;
    fstream arq("input.txt");
    stack<char> cranes[stackCount];
    /*
        [D]
    [N] [C]
    [Z] [M] [P]/
    cranes[0].push('Z');
    cranes[0].push('N');

    cranes[1].push('M');
    cranes[1].push('C');
    cranes[1].push('D');

    cranes[2].push('P');
    */


        cranes[0].push('R');
        cranes[0].push('N');
        cranes[0].push('F');
        cranes[0].push('V');
        cranes[0].push('L');
        cranes[0].push('J');
        cranes[0].push('S');
        cranes[0].push('M');

        cranes[1].push('P');
        cranes[1].push('N');
        cranes[1].push('D');
        cranes[1].push('Z');
        cranes[1].push('F');
        cranes[1].push('J');
        cranes[1].push('W');
        cranes[1].push('H');

        cranes[2].push('W');
        cranes[2].push('R');
        cranes[2].push('C');
        cranes[2].push('D');
        cranes[2].push('G');

        cranes[3].push('N');
        cranes[3].push('B');
        cranes[3].push('S');

        cranes[4].push('M');
        cranes[4].push('Z');
        cranes[4].push('W');
        cranes[4].push('P');
        cranes[4].push('C');
        cranes[4].push('B');
        cranes[4].push('F');
        cranes[4].push('N');

        cranes[5].push('P');
        cranes[5].push('R');
        cranes[5].push('M');
        cranes[5].push('W');

        cranes[6].push('R');
        cranes[6].push('T');
        cranes[6].push('N');
        cranes[6].push('G');
        cranes[6].push('L');
        cranes[6].push('S');
        cranes[6].push('W');

        cranes[7].push('Q');
        cranes[7].push('T');
        cranes[7].push('H');
        cranes[7].push('F');
        cranes[7].push('N');
        cranes[7].push('B');
        cranes[7].push('V');

        cranes[8].push('L');
        cranes[8].push('M');
        cranes[8].push('H');
        cranes[8].push('Z');
        cranes[8].push('N');
        cranes[8].push('F');
/*
        for(int i = 0; i < 9; i++){
            cout << "Pilha " << i << endl;
            while(!cranes[i].empty()){
                cout << cranes[i].top() << " " << endl;
                cranes[i].pop();
            }
        }*/
    stack <char> stkAux;
    int k = 1;
    if (arq.is_open())
    {
        while (!arq.eof())
        {
            int amount, origin, dest;
            stringstream ss;
            getline(arq, line);
            cout << "Linha " << k << endl;
            k++;
            ss << line;
            cout << line << endl;
            ss >> line;
            // cout << line;
            ss >> amount;
            ss >> line;
            ss >> origin;
            ss >> line;
            ss >> dest;
            cout << "Amount: " << amount << endl;
            cout << "Origin: " << origin << endl;
            cout << "Dest: " << dest << endl;
            origin--;
            dest--;

            for (int i = 0; i < amount; i++)
            {
                if (!cranes[origin].empty())
                {
                    stkAux.push(cranes[origin].top());
                    cranes[origin].pop();
                }
            }
            while(!stkAux.empty()){
                cranes[dest].push(stkAux.top());
                stkAux.pop();
            }
        }
        arq.close();
    }

    /*for (int i = 0; i < 9; i++)
    {
        cout << "Pilha " << i << endl;
        while (!cranes[i].empty())
        {
            cout << cranes[i].top() << " " << endl;
            cranes[i].pop();
        }
    }*/
    for (int i = 0; i < stackCount; i++)
    {
        if (!cranes[i].empty())
            cout << cranes[i].top();
    }
}