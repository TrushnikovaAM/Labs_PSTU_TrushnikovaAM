#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");
    double a, b, c;
    
    cin >> a >> b >> c;
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Бесконечно много решений" << endl;
            } else {
                cout << "Нет решений" << endl;
            }
        } else {
            double x = -c / b;
            cout << "x = " << x << endl;
        }
    } 
    else {
        double D = b * b - 4 * a * c; // Дискриминант
        
        if (D > 0) {
            double x1 = (-b + sqrt(D)) / (2 * a);
            double x2 = (-b - sqrt(D)) / (2 * a);
            cout << "Два корня:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } 
        else if (D == 0) {
            double x = -b / (2 * a);
            cout << "x = " << x << endl;
        } 
        else {
            cout << "Нет корней" << endl;
        }
    }
    
    return 0;
}