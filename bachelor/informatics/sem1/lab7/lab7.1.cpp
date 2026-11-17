#include <iostream>
#include <string>
#include <sstream>
#include <clocale>
using namespace std;

int countElements(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) count++;
    }
    return count;
}

int countElements(const string& str) {
    stringstream ss(str);
    string word;
    int count = 0;
    while (ss >> word) {
        if (word.length() > 1 && word.front() == word.back()) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL,".65001");
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nКоличество отрицательных элементов в массиве: " 
         << countElements(arr, n) << endl;
    
    delete[] arr;

    cin.ignore(); 

    string text;
    cout << "\nВведите строку: ";
    getline(cin, text);

    cout << "Количество слов, начинающихся и заканчивающихся на одну букву: " 
         << countElements(text) << endl;

    return 0;
}