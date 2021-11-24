#include <iostream>
#include <exception>
using namespace std;
template<typename DataType, size_t mx, size_t my>
class Image {
   DataType* img;
   size_t tmx = mx;
   size_t tmy = my;
public:
    Image()
    {
        img = new int[mx * my]();
    }
    
    virtual ~Image()
    {
        delete [] img;
    }
    DataType get(size_t x, size_t y) {
       
            if (x >= mx || y >= my || x < 0 || y < 0) {
                throw 993;
            }
        
        return img[y * mx + x];
    }
    void set(size_t x, size_t y, DataType color) {
       
            if (x >= mx || y >= my || x < 0 || y < 0) {
                throw 993;
            }
        
         img[y * mx + x] = color;
    }
    
    friend bool operator ==(Image& arrInt, Image& arrInt2)
    {
        return (arrInt.tmx == arrInt2.tmx && arrInt.tmy == arrInt2.tmy);
    }
    void show();
};
template<typename DataType, std::size_t mx, std::size_t my>
void Image<DataType, mx, my>::show()
{
    for (int i = 0; i < my; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            cout << img[i * mx + j] << " ";
        }
        cout << endl;
    }
}

int main() {

    Image <int, 8, 8> img1;
    Image <int, 8, 8> img2;
    if (img1 == img2)
        cout << "(((((" << endl;
    try {
        img1.set(3, 4, 245);
        img2.set(3, 3, 124);
    }
    catch (int error) {
        cout << error << endl;
    }
    try {
        img1.get(4, 4);
        img2.get(3, 3);
    }
    catch (int error) {
        cout << error << endl;
    }

    img1.show();
    cout << endl;
    img2.show();
    return 0;
}