#include "data.h"

Data::Data (int zi, int luna, int an){
    this->zi = zi;
    this->luna = luna;
    this->an = an;
}

Data::Data(const Data& data){
    zi = data.zi;
    luna = data.luna;
    an = data.an;
}
Data::Data(){}

std::istream& operator >> (std::istream& stream, Data& data) {
    stream >> data.zi >> data.luna >> data.an;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Data& data) {
    stream << data.zi <<'.'<< data.luna <<'.'<< data.an <<endl;
    return stream;
}
