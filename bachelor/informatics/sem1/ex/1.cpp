#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    bool f = false;
    int n,a,i=1;
    cin >> n;
    while (i<=n && !f){
        cin >> a;
        if (a==0){
            i+=1;
        } else {
            f=true;
        }
    }
    if (f==true){
        if (a>0){
            cout << "Раньше положительные числа" << endl;
        } else {
            cout << "Раньше отрицательные числа" << endl;
        }
    } else {
        cout << "Все числа равны нулю" << endl;
    }
    return 0;
}