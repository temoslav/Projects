#include <iostream>

using namespace std;

class DynamicIntArray {
public:
    //Поля
    int* begin;
    int size = 0;
    int count = 0;
    
    //Конструкторы
    DynamicIntArray(DynamicIntArray const &array) {
        begin = new int[array.size];
        size = array.size;
        count = array.count;
        for (int i = 0; i < size; i++) {
            begin[i] = array.begin[i];
        }
    }
    
    DynamicIntArray(int size) : size(size) {
        begin = new int[size];
    }
    
    //Деструкторы
    ~DynamicIntArray() {
        delete[] begin;
    }
    
    //Методы
    void addElement(int element) {
        if (count < size) {
            if (element >= -100 && element <= 100) {
                count ++;
                begin[count - 1] = element;
            } else {
                cout << "ERROR: Element does not belong to [-100; 100] range" << endl;
            }
        } else {
            cout << "ERROR: Array is full, reached max number of elements "
            << size
            << endl;
        }
    }
    
    int getElement(int index) {
        if (index >= 0 && index < size) {
            return begin[index];
        }
        return 0;
    }
    
    void show() {
        for (int i = 0; i < count; i++) {
            cout << begin[i] << " ";
        }
        cout << "\n";
    }
    
    void pushBack(int element) {
        if (count == size) {
            resize(size * 2);
        }
        addElement(element);
    }
    
    void resize(int newSize) {
        int* newArray = new int[newSize];
        for(int i = 0; i < newSize; i++) {
            if (i < size) {
                newArray[i] = begin[i];
            } else {
                newArray[i] = 0;
            }
        }
        begin = newArray;
        size = newSize;
        if (size < count) {
            count = size;
        }
    }
    
    //Операторы
    DynamicIntArray& operator+=(const DynamicIntArray& array) {
        for (int i = 0; i < size; i++) {
            if (i < array.size) {
                begin[i] += array.begin[i];
            } else {
                break;
            }
        }
        return *this;
    }
    
    DynamicIntArray& operator-=(const DynamicIntArray& array) {
        for (int i = 0; i < size; i++) {
            if (i < array.size) {
                begin[i] -= array.begin[i];
            } else {
                break;
            }
        }
        return *this;
    }

};

int main() {
    //Проверка конструктора размера и добавления элементов
    DynamicIntArray array1 = DynamicIntArray(3);
    array1.addElement(3);
    array1.addElement(2);
    array1.addElement(1);
    array1.show();
    //Проверка конструктора копирования и ресайза
    DynamicIntArray array2 = DynamicIntArray(array1);
    array2.show();
    array2.resize(10);
    array2.show();
    array2.resize(2);
    array2.show();
    for(int i = 0; i < 15; i++ ) {
        array2.addElement(40);
    }
    array2.show();
    array2.resize(16);
    for(int i = 0; i < 15; i++ ) {
        array2.addElement(40);
    }
    array2.show();
    //Проверка добавления в конец массива
    for(int i = 0; i < 15; i++) {
        array2.pushBack(60);
    }
    array2.show();
    
    //Проверка операторов сложения и вычитания
    array2 += array1;
    array2.show();
    array2 -= array1;
    array2.show();
    
    //Проверка выхода за границы
    array2.pushBack(1000);
    array2.pushBack(-1000);
    return 0;
}
