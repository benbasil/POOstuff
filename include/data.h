#ifndef DATA_H
#define DATA_H
#include <iostream>

using namespace std;
class Data{
public:

    Data(int zi, int luna, int an);
    Data(const Data&);
    Data();

    friend istream& operator >> (istream& stream, Data& data);
    friend ostream& operator << (ostream& stream, Data& data);
private:
    int zi;
    int luna;
    int an;
};

#endif // DATA_H
