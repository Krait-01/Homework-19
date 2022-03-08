#include <iostream>
#include <ctime>
#include <cstdint>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;

// ������ 1
int nod(int a1, int b1)
{
    while (b1) b1 ^= a1 ^= b1 ^= a1 %= b1;
    return a1;
}

// ������ 2
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

// ������ 3
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

// ������ 4
void rnd_m(int* arr3, int min, int max, int count)
{
    srand(time(NULL));
    for (int i = 0; i < count; ++i)
        arr3[i] = min + rand() % (max - min + 1);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "������ 1.\n"; // ������ 1
    int a1, b1;
    cout << "������� 1-�� �����:\n1-�� ����� = "; cin >> a1;
    cout << "\n������� 2-�� �����:\n2-�� ����� = "; cin >> b1;
    cout << "\n���������� ����� �������� ���� 2-� ����� = " << nod(a1, b1) << "\n\n\n";


    cout << "������ 2.\n"; // ������ 2
    const int arr1 = 4;
    int n[arr1];

    for (int i = 0; i < arr1; i++)
    {
        cout << "������� ��������:\n�������� �������� = ";
        cin >> n[i];
        cout << "������������ �������� = " << ReverseNumber(n[i]) << "\n\n";
    }


    cout << "\n������ 3.\n"; // ������ 3
    srand(static_cast<unsigned>(time(nullptr)));

    size_t sz = 0;
    cout << "������� ������ �������:\n������ ������� = ";
    cin >> sz;
    cout << endl;
    cout << "�������� ������:\n";
    int* arr2 = createArr(sz);
    coutArr(arr2, sz);

    int n1 = 0;
    cout << endl;
    cout << "������� ����� 'N' �� ��������� �������:\n��������� ����� 'N' �� ��������� ������� = ";
    cin >> n1;

    size_t posN = func(arr2, sz, n1);
    cout << "����� ������� ����� 'N' �� ��������� ������� = " << posN << "\n\n";
    cout << "��������������� ����� ������� ������ �� ����� 'N':\n";
    coutArr(arr2, sz);
    delete[] arr2;
    cout << "\n\n";


    cout << "������ 4.\n"; // ������ 4
    const int count {20};
    int arr3[count]{}, A, B;
    cout << "������� ����� ������ ���������:\n����� A = "; cin >> A;
    cout << "\n������� ����� ����� ���������:\n����� B = "; cin >> B;
    cout << endl << "��������� ����� � ������� �� ���������� ���������: \n";
    rnd_m (arr3, A, B, count);
    for (int i = 0; i < count; ++i) cout << arr3[i] << " ";
    cout << "\n\n";
    
    return 0;
}