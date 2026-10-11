#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    cout << "-----------Вариант 21-----------" << endl;
    cout << "Задание 1:" << endl;
    float a_f = 100.0f, b_f = 0.001f;

    float a4_f    = pow(a_f, 4);                 // a^4
    float a3b_f   = 4 * pow(a_f, 3) * b_f;       // 4a^3 b
    float a2b2_f  = 6 * a_f * a_f * b_f * b_f;   // 6a^2 b^2
    float ab3_f   = 4 * a_f * pow(b_f, 3);       // 4ab^3
    float b4_f    = pow(b_f, 4);                 // b^4

    float u_f   = pow(a_f - b_f, 4) - (a4_f - a3b_f + a2b2_f);
    float d_f = b4_f - ab3_f;
    float res_f      = u_f / d_f;

    cout << "Числитель float:    " << u_f << endl;
    cout << "Знаменатель float: " << d_f << endl;

    cout << fixed << setprecision(10);
    cout << "float:  " << res_f << endl;

    double a_d = 100.0, b_d = 0.001;

    double a4_d    = pow(a_d, 4);
    double a3b_d   = 4 * pow(a_d, 3) * b_d;
    double a2b2_d  = 6 * a_d * a_d * b_d * b_d;
    double ab3_d   = 4 * a_d * pow(b_d, 3);
    double b4_d    = pow(b_d, 4);

    double u_d   = pow(a_d - b_d, 4) - (a4_d - a3b_d + a2b2_d);
    double d_d = b4_d - ab3_d;
    double res_d      = u_d / d_d;

    cout << "Числитель double:    " << u_d << endl;
    cout << "Знаменатель double:  " << d_d << endl;

    cout << "double: " << res_d << endl;
    cout << "Как мы видим, результаты сильно отличаются из-за разной точности хранения вещественных чисел" << endl;
    cout << "Задание 2:" << endl;

    int n, m, r;

    // 1) n++ - m
    n = 5; m = 3;
    r = n++ - m;
    cout << "1) n++ - m = " << r
         << "  (n было 5, стало " << n << ", m = " << m << ")" << endl;

    // 2) m-- > n
    n = 5; m = 3;
    bool r2 = (m-- > n);
    cout << "2) m-- > n = " << r2
         << "  (m было 3, стало " << m << ", n = " << n << ")" << endl;

    // 3) n-- > m
    n = 5; m = 3;
    bool r3 = (n-- > m);
    cout << "3) n-- > m = " << r3
         << "  (n было 5, стало " << n << ", m = " << m << ")" << endl;

    return 0;
}
/* Математически числитель в первом задании должен быть (a^4 - 4a^3b + 6a^2b^2 - 4ab^3 + b^4) - (a^4 - 4a^3b + 6a^2b^2) = b^4 - 4ab^3
=> он должен быть равен знаменателю 
=> результат математически должен быть равен 1
Но из-за того, что float хранит примертно 7 значащих цифр,
а double хранит около 15-16 значащих цифр, значения могут сильно измениться
например результат от double почти равен 1, в то время как результат от float далёк от 1 потому что значительно потерялась точность */