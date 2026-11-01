#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[7];

    for(int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    int max_z = a[0];
    int max_index = 0;
    int max_count = 1; 

    int min_z = a[0];
    int min_index = 0;
    int min_count = 1; 

    for(int i = 1; i < 7; i++)
    {
        if (a[i] > max_z) 
        {
            max_z = a[i];
            max_index = i;
            max_count = 1; // сброс счётчика
        }
        else if (a[i] == max_z) 
        {
            max_count++; // увеличение счётчика
        }

        if (a[i] < min_z) 
        {
            min_z = a[i];
            min_index = i;
            min_count = 1;
        }
        else if (a[i] == min_z) 
        {
            min_count++;
        }
    }

    cout << "max = " << max_z 
         << " Индекс: " << max_index 
         << " Номер: " << max_index + 1 
         << " Количество: " << max_count << endl;

    cout << "min = " << min_z 
         << " Индекс: " << min_index 
         << " Номер: " << min_index + 1 
         << " Количество: " << min_count << endl;

    return 0;
}