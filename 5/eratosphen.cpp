#include <iostream>
#include <math.h>

using namespace std;

void del(int* mas, int index, int& size)
{
    for (int i = index; i < size; i++)
    {
        mas[i] = mas[i + 1];
    }
    size--;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int limit,u;
    cout << "Введите максимум : "; cin >> limit;
    u = limit;
    limit--;
    int* arr = new int[limit];
    for (int i = 0; i < limit; ++i)
    {
        arr[i] = i + 2;
        cout << arr[i] << ' ';
    }   cout << endl;
    bool work = true;
    auto* p = arr;
    int trash{};
    while (work)
    {
        for (int i = trash + 1; i < limit; i++)
        {
            if (arr[i] % *p == 0)
            {
                del(arr, i, limit);
            }
        }
        if (*p > sqrt(limit))
        {
            work = false;
        }
        p++;
        trash++;
    }
    cout << "Простые числа в заданнном промежутке [0;" << u << "): ";
    for (int i = 0; i < limit; i++)
    {
        cout << arr[i] << ' ';
    }
    delete[]arr;
    system("pause");
    return 0;
    
}