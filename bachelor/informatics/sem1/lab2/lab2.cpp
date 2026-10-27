#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");
    
    int N = 13;
    double sum = 0.0;
    
    for (int n = 1; n <= N; ++n)
	{
        double fact = 1.0;
        for (int i = 2; i <= n; ++i) 
		{
            fact *= i;
        }
        
        double an = log(fact) / (n * n);
        
        sum += an;
    }
    
    cout << "Сумма 13 членов ряда равна: " << sum << endl;
    
    return 0;
}