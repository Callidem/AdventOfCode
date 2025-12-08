// reading a texHt file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Pos{
    public:
        int x;
        int y;

        Pos(int a, int b){
            x = a;
            y = b;
        }
};

int main(){
    
    fstream arq("input.txt");
    char dir;
    string line;
    int xH, yH, xT, yT, mov;
    vector<Pos> hPos;
    vector<Pos> tPos;
    
    while(!arq.eof()){
        arq >> dir;
        arq >> mov;
        for (int i = 0; i < mov; i++){
            cout << "A" << endl;
            switch (dir){
            case 'U':
                yH++;
                break;
            case 'L':
                xH--;
                break;
            case 'R':
                xH++;
                break;
            case 'D':
                yH--;
                break;
            }
            cout << "B" << endl;
            if((abs(xH - xT) || abs(yH - yT))  > 1 ) tPos.push_back(hPos[hPos.size() - 1]);
            hPos.push_back(Pos(xH, yH));
            
        }
    }
    cout << "Posicoes de T (" << tPos.size() << " no total):" << endl;
    for(int i = 0; i < tPos.size(); i++){
        cout << "(" << tPos[i].x << "," << tPos[i].y << endl;
    }
}