#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");
    srand(time(0)); // Рандомайзер чисел чтоб не повторялось при повторном запуске(Использует время как seed(Как в майне))

    int N, K;
    cout << "Введите реальную длину массива: ";
    cin >> N;

    if (N <= 0 || N > 90) // можно изменить по желанию(Но чтоб было М-4, иначе места под новые 4 числа не останется)
    {
        cout << "Некорректный размер массива!" << endl;
        return 1;
    }

    int M[100]; // Тоже можно изменить по желанию

    cout << "Введите начальный индекс K (от 0 до " << N - 1 << "): ";
    cin >> K;

    // --- 1. ФОРМИРОВАНИЕ ИСХОДНОГО МАССИВА ---
    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++)
    {
        M[i] = rand() % 100; // Случайные числа от 0 до 99
        cout << M[i] << " ";
    }
    cout << endl;

    cout << "Вывод по кольцу ВЛЕВО (от K до K-1):\n";
    int current = K;
    for (int i = 0; i < N; i++)
    {
        cout << M[current] << " ";
        current = (current - 1 + N) % N; //кольцо влево
    }
    cout << endl;

    for (int i = N; i > 0; i--) // сдвиг чтоб освободить 0 индекс
    {
        M[i] = M[i - 1];
    }
    M[0] = 111;
    N++;
    K++;

    M[N] = 222;
    M[N + 1] = 333;
    M[N + 2] = 444;
    N += 3;

    cout << "Массив после добавления элементов: ";
    for (int i = 0; i < N; i++) {
        cout << M[i] << " ";
    }
    cout << endl;

    int newK = K % N; 
    
    cout << "Вывод по кольцу ВПРАВО (от K до K+1): ";
    current = newK;
    for (int i = 0; i < N; i++) {
        cout << M[current] << " ";
        current = (current + 1) % N; //кольцо вправо
    }
    cout << endl;

    return 0;
}