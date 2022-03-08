#include <iostream>
#include <ctime>
#include <cstdint>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Задача 1
int nod(int a1, int b1)
{
    while (b1) b1 ^= a1 ^= b1 ^= a1 %= b1;
    return a1;
}

// Задача 2
int ReverseNumber(int number)
{
    int n = 0;
    while (number)
    {
        n = 10 * n + number % 10;
        number /= 10;
    }

    return n;
}

// Задача 3
size_t func(int* arr, size_t sz, int n1)
{
    for (size_t i = 0; i < sz; i++)
        if (arr[i] == n1)
        {
            sort(&arr[i + 1], &arr[sz]);
            return i + 1;
        }
    return sz;
}

void coutArr(int* arr, size_t sz)
{
    for (size_t i = 0; i < sz; ++i)
    {
        cout << arr[i] << " ";
    } cout << "\n";
}

int* createArr(size_t sz)
{
    int* arr = new int[sz];
    for (size_t i = 0; i < sz; ++i)
    {
        arr[i] = rand() % 20 - 10;
    } return arr;
}

// Задача 4
void rnd_m(int* arr3, int min, int max, int count)
{
    srand(time(NULL));
    for (int i = 0; i < count; ++i)
        arr3[i] = min + rand() % (max - min + 1);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Задача 1.\n"; // Задача 1
    int a1, b1;
    cout << "Введите 1-ое число:\n1-ое число = "; cin >> a1;
    cout << "\nВведите 2-ое число:\n2-ое число = "; cin >> b1;
    cout << "\nНаибольший общий делитель этих 2-х чисел = " << nod(a1, b1) << "\n\n\n";


    cout << "Задача 2.\n"; // Задача 2
    const int arr1 = 4;
    int n[arr1];

    for (int i = 0; i < arr1; i++)
    {
        cout << "Введите значение:\nВводимое значение = ";
        cin >> n[i];
        cout << "Возвращаемое значение = " << ReverseNumber(n[i]) << "\n\n";
    }


    cout << "\nЗадача 3.\n"; // Задача 3
    srand(static_cast<unsigned>(time(nullptr)));

    size_t sz = 0;
    cout << "Введите длинну массива:\nДлинна массива = ";
    cin >> sz;
    cout << endl;
    cout << "Принятый массив:\n";
    int* arr2 = createArr(sz);
    coutArr(arr2, sz);

    int n1 = 0;
    cout << endl;
    cout << "Введите число 'N' из принятого массива:\nВыбранное число 'N' из принятого массива = ";
    cin >> n1;

    size_t posN = func(arr2, sz, n1);
    cout << "Номер позиции числа 'N' из принятого массива = " << posN << "\n\n";
    cout << "Отсортированная часть массива справа от числа 'N':\n";
    coutArr(arr2, sz);
    delete[] arr2;
    cout << "\n\n";


    cout << "Задача 4.\n"; // Задача 4
    const int count {20};
    int arr3[count]{}, A, B;
    cout << "Введите число начала диапазона:\nЧисло A = "; cin >> A;
    cout << "\nВведите число конца диапазона:\nЧисло B = "; cin >> B;
    cout << endl << "Случайные числа в массиве из указанного диапазона: \n";
    rnd_m (arr3, A, B, count);
    for (int i = 0; i < count; ++i) cout << arr3[i] << " ";
    cout << "\n\n";
    
    return 0;
}