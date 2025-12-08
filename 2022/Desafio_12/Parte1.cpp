// reading a texHt file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    
    fstream arq("input.txt");
    int totalSignalStrength = 0;
    queue<string> inst;
    queue<int> values;
    int reg = 1;
    while(!arq.eof()){
        string i;
        int V;
        arq >> i;
        inst.push(i);
        //cout << "i:" << i; 
        if(i != "noop"){
            arq >> V;
            //cout << " / v:" << V;
            values.push(V);
        }
        //cout << endl;
    }
    int cycle = 0, div = 20;
    while(!inst.empty()){
        if(inst.front() == "noop") {
            cycle++;
            if(cycle % div == 0){
                //cout << "div:" << div << endl;
                //cout << "ciclo:" << cycle << " / reg:" << reg << endl;
                totalSignalStrength += cycle * reg;
                cout << "Signal strength: " << cycle * reg << endl;
                div += 40;
            }
        }
        else if(inst.front() == "addx") {
            for(int i = 0; i < 2; i++) {
                cycle++;
                //cout << "cycle:" << cycle << endl;
                if(cycle % div == 0){
                    //cout << "div:" << div << endl;
                    //cout << "ciclo:" << cycle << " / reg:" << reg << endl;
                    totalSignalStrength += cycle * reg;
                    cout << "Signal strength: " << cycle * reg << endl;
                    div += 40;
                }
            }
            //cout << "valor antes de somar: " << values.front() << endl;
            reg += values.front();
            values.pop();
        }
        inst.pop();
    }
    cout << "Resposta: " << totalSignalStrength << endl;
}