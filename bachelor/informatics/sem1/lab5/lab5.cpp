#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a, b;
    cout << "Введите количество строк и столбцов: ";
    cin >> a >> b;

    int** matr = new int*[a];
    for (int i = 0; i < a; i++)
    {
        matr[i] = new int[b];
    }
    cout << "Введите элементы матрицы (построчно):";
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> matr[i][j];
        }
    }

    cout << "Ваша матрица:" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << matr[i][j] << "\t"; // \t - для ровных столбцов
        }
        cout << endl;
    }

    int max = -100000; 
    bool f = false;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            int cur = matr[i][j];
            int cnt = 0;

            for (int r = 0; r < a; r++)
            {
                for (int c = 0; c < b; c++)
                {
                    if (matr[r][c] == cur)
                    {
                        cnt++;
                    }
                }
            }

            if (cnt > 1)
            {
                if (!f || cur > max)
                {
                    max = cur;
                    f = true;
                }
            }
        }
    }

    if (f)
    {
        cout << "Максимальный из повторяющихся элементов: " << max << endl;
    } else
    {
        cout << "Повторяющихся элементов нет" << endl;
    }

    for (int i = 0; i < a; i++) delete[] matr[i];
    delete[] matr;

    return 0;
}