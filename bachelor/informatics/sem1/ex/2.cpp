#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, ".65001");
    bool f = false;
    int a,b;
    cin >> a;
    if (a!=0)
    {
        cin >> b;
        while (b!=0 && !f){
            if (b>a){
                a = b;
            } else {
                f=true;
            }
            cin >> b;
        }
        if (f==true){
            cout << "Последовательность не упорядочена" << endl;
        } else {
            cout << "Последовательность упорядочена" << endl;
        }
    }
    
    return 0;
}