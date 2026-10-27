#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    double a = 0.1;
    double b = 1.0;
    int k = 10;                 
    double step = (b - a) / k;  
    double eps = 0.0001;        
    int n = 40;                 

    cout << "-------------------------------------------------------------" << endl;
    cout << "   X   |    SN (n=40)   |   SE (точность)  |   Y (точное)   " << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (double x = a; x <= b + step / 2.0; x += step) 
    {
        double sn = 0.0;
        double an = x; 
        
        for (int i = 0; i < n; ++i) {
            sn += an;
            // Рекуррентная формула: a_{i+1} = a_i * (-x^2) * (2i+1)/(2i+3)
            an = an * (-x * x) * (2 * i + 1) / (2 * i + 3);
        }

        double se = 0.0;
        double ae = x; 
        int i = 0;
        
        while (fabs(ae) >= eps) {
            se += ae;
            ae = ae * (-x * x) * (2 * i + 1) / (2 * i + 3);
            i++;
        }

        double y = atan(x);

        cout << fixed << setprecision(4) 
             << setw(5) << x << " | "
             << setw(14) << sn << " | "
             << setw(16) << se << " | "
             << setw(14) << y << endl;
    }
    
    cout << "-------------------------------------------------------------" << endl;
    return 0;
}