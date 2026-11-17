#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;

struct Car {
    char brand[30];
    char serial[20];
    char regNumber[20];
    int year;
};

void createFile(const char* filename, int n) {
    FILE* f = fopen(filename, "wb");
    if (!f) { cout << "Ошибка открытия файла!\n"; return; }
    
    Car c;
    for (int i = 0; i < n; i++) {
        cout << "\nМашина " << i + 1 << ":\n";
        cout << "Марка: "; cin >> c.brand;
        cout << "Серийный номер: "; cin >> c.serial;
        cout << "Рег. номер: "; cin >> c.regNumber;
        cout << "Год выпуска: "; cin >> c.year;
        fwrite(&c, sizeof(Car), 1, f);
    }
    fclose(f);
    cout << "Файл сформирован.\n";
}

void printFile(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) { cout << "Ошибка открытия файла!\n"; return; }
    
    Car c;
    cout << "\n--- Содержимое файла ---\n";
    while (fread(&c, sizeof(Car), 1, f)) {
        cout << c.brand << " | " << c.serial << " | " << c.regNumber << " | " << c.year << endl;
    }
    fclose(f);
}

void deleteFirstThree(const char* filename) {
    FILE* f = fopen(filename, "rb");
    FILE* temp = fopen("temp.dat", "wb");
    if (!f || !temp) { cout << "Ошибка открытия файла!\n"; return; }

    Car c;
    int skipped = 0;
    while (fread(&c, sizeof(Car), 1, f)) {
        if (skipped < 3) { skipped++; continue; }
        fwrite(&c, sizeof(Car), 1, temp);
    }
    fclose(f); fclose(temp);
    remove(filename);
    rename("temp.dat", filename);
    cout << "Удалено " << skipped << " записей.\n";
}

void addAfterRegNumber(const char* filename, const char* targetReg) {
    FILE* f = fopen(filename, "rb");
    FILE* temp = fopen("temp.dat", "wb");
    if (!f || !temp) { cout << "Ошибка открытия файла!\n"; return; }

    Car c, newCar;
    bool added = false;
    
    cout << "\nВведите данные новой машины:\n";
    cout << "Марка: "; cin >> newCar.brand;
    cout << "Серийный номер: "; cin >> newCar.serial;
    cout << "Рег. номер: "; cin >> newCar.regNumber;
    cout << "Год выпуска: "; cin >> newCar.year;

    while (fread(&c, sizeof(Car), 1, f)) {
        fwrite(&c, sizeof(Car), 1, temp);
        if (strcmp(c.regNumber, targetReg) == 0) {
            fwrite(&newCar, sizeof(Car), 1, temp);
            added = true;
        }
    }
    fclose(f); fclose(temp);
    remove(filename);
    rename("temp.dat", filename);
    
    if (added) cout << "Машина добавлена.\n";
    else cout << "Рег. номер не найден!\n";
}

int main() {
    setlocale(LC_ALL, ".65001");
    const char* filename = "cars.dat";
    int n;

    cout << "Введите количество машин: "; cin >> n;
    createFile(filename, n);
    printFile(filename);

    cout << "\nУдаляем 3 машины из начала...\n";
    deleteFirstThree(filename);
    printFile(filename);

    char targetReg[20];
    cout << "\nВведите рег. номер машины, после которой добавить новую: ";
    cin >> targetReg;
    addAfterRegNumber(filename, targetReg);
    printFile(filename);

    return 0;
}