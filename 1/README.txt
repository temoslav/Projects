 Для класса Image реализовать:


class Image {
  int* img;
  int mx,int my;
public:
  Image(int tmx, int tmy):mx(tmx),my(tmy){
    img = new int[mx*my]();
  }
  vitual ~Image(); // Реализовать
  int get(int x,int y) {
    return img[y*my+x];
  } // Добавить обработку ошибок при помощи исключений - выбрасывать целочисленное исключение при выходе за границы массива
  int set(int x,int y,int color) { // Добавить обработку ошибок при помощи исключений  - выбрасывать целочисленное исключение при выходе за границы массива
    img[y*my+x]=color;
  }
  Image operator=(const Image& v)                                          // Реализовать для варианта  1
  friend std::ostream& operator<<(std::ostream& out, const Image &d1);     // Реализовать  для варианта 2
  friend bool operator ==(Image &arrInt, Image &arrInt2 ); // Реализовать  // Реализовать  для варианта 3
};

2. Реализовать перегрузку одной из операций
3. Реализовать функцию main и показать использование класса Image