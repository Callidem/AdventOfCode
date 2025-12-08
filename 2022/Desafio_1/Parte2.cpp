// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;
    int sum, first, second, third;
    sum = first = second = third = 0;

    ifstream arq("input.txt");
    if (arq.is_open())
    {
        while (getline(arq, line))
        {
            if (!line.empty())
            {
                sum += stoi(line);
            }
            else
            {
                if (sum > first){
                    third = second;
                    second = first;
                    first = sum;
                    
                }
                else if(sum > second){
                    third = second;
                    second = sum;
                    
                }
                else if(sum > third) {
                    third = sum;
                }
                sum = 0;
            }
        }
        arq.close();
    }

    cout << "O maior numero eh " << first + second + third << endl;
}