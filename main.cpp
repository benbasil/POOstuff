#include <iostream>
#include "data.h"
#include <string.h>
using namespace std;


class Angajat {
public:
    Angajat(string name, unsigned int idNumber, string position, unsigned int salary); //constructori
    Angajat(const Angajat&);
    Angajat();

    string getName();       //set-eri + get-eri
    string getPosition();
    int getSalary();
    void getdataAngajare();

    string setName(string);
    string setPosition(string);
    void setSalary(unsigned int);
    void setDataAngajare(int, int, int);

    friend class Data; // Am creat o alta clasa numita Data in care pot salva data de angajare a fiecarui angajat;

    friend istream& operator >> (istream& stream, Angajat& angajat);  //citire / afisare;
    friend ostream& operator << (ostream& stream, Angajat& angajat);

    friend bool operator == (Angajat&, Angajat&); //operatori;
    friend bool operator != (Angajat&, Angajat&); //operatorii == respectiv != afiseaza pe ecran daca cei doi angajati ocupa acelasi rol in companie;
    Angajat operator++(int); // operatorii ++ si -- adauga respectiv scad din salariu numar introdus;
    Angajat operator--(int);

private:
    string name;
    unsigned int idNumber;
    string position;
    int unsigned salary;
    Data dataAngajare = Data();
};



Angajat::Angajat(std::string name, unsigned int idNumber, string position, unsigned int salary) {
    this->name = name;
    this->idNumber = idNumber;
    this->position = position;
    this->salary = salary;
    this->dataAngajare = dataAngajare;
}

Angajat::Angajat(const Angajat& angajat) {
    name = angajat.name;
    idNumber = angajat.idNumber;
    position = angajat.position;
    salary = angajat.salary;
}

Angajat::Angajat() {
    name = "";
    idNumber = NULL;
    position = "";
    salary = NULL;
}



string Angajat::getName() {
    return this->name;
}

string Angajat::getPosition(){
    return this->position;
}
int Angajat::getSalary() {
    return this->salary;
}

void Angajat::getdataAngajare(){
    cout<<"Data de angajare a lefegiului "<<this->name<<" este "<<this->dataAngajare;
}


string Angajat::setName(string name) {
    this->name = name;
}

string Angajat::setPosition(string position) {
     this->position = position;
}

void Angajat::setSalary(unsigned int salary) {
    this->salary = salary;
}
void Angajat::setDataAngajare(int zi, int luna, int an){
    this->dataAngajare = Data(zi, luna, an);
}

std::istream& operator >> (std::istream& stream, Angajat& angajat) {
    stream >> angajat.name >> angajat.idNumber >> angajat.position >> angajat.salary;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Angajat& angajat) {
    stream << angajat.name <<" | " << angajat.idNumber <<" | "<< angajat.position <<" | "<< angajat.salary<<" RON"<<endl;
    return stream;
}

bool operator == (Angajat& firstAngajat, Angajat& secondAngajat) {

    if ((firstAngajat.getPosition().compare(secondAngajat.getPosition())) == 0)
        cout << "Cei doi angajati "<< firstAngajat.getName()<<" si "<< secondAngajat.getName()<<" nu au aceeasi pozitie in companie."<<endl;
    else
        cout << "Cei doi angajati "<< firstAngajat.getName()<<" si "<< secondAngajat.getName()<<" au aceeasi pozitie in companie."<<endl;
}


bool operator != (Angajat& firstAngajat, Angajat& secondAngajat) {

    if ((firstAngajat.getPosition().compare(secondAngajat.getPosition())) != 0)
        cout << "Cei doi angajati "<< firstAngajat.getName()<<" si "<< secondAngajat.getName()<<" nu au aceeasi pozitie in companie."<<endl;
    else
        cout << "Cei doi angajati "<< firstAngajat.getName()<<" si "<< secondAngajat.getName()<<" au aceeasi pozitie in companie."<<endl;
}


Angajat Angajat::operator++(int raiseSalary){
    this->salary += raiseSalary;
    return *this;
}

Angajat Angajat::operator--(int decreaseSalary){
    this->salary -= decreaseSalary;
    return *this;
}
int main() {
    string a = "cacat";
    Angajat angj1 = Angajat("Cristian Pantilie",12,"Inginer Software",6000); //Nume, IDnumber, Pozitie in firma, salariu;
    Angajat angj2 = Angajat("Ionut Vasu", 01, "Sef de Departament", 10000);
    Angajat angj3 = Angajat("Victor Larry", 14,"Inginer Software", 5000);
    Angajat angj4 = Angajat(angj1);
    Data data1 = Data(23,10,2016);

    cout<<angj4;
    cout<<angj1.getName()<<endl;
    cout<<angj1.getSalary()<<endl;
    cout<<angj1<<endl<<endl<<endl;

    cout<<angj2<<endl<<endl<<endl;

    cout<<angj3<<endl<<endl<<endl;

    (angj1 == angj2);
    (angj1 == angj3);
    (angj1 != angj2);
    (angj1 != angj3);

    cout<<endl;
    angj1.setDataAngajare(21,04,2015);
    angj2.setDataAngajare(11,5,2020);
    angj3.setDataAngajare(03,12,2019);

    angj1.getdataAngajare();
    angj2.getdataAngajare();
    angj3.getdataAngajare();
    cout<<endl<<endl<<endl<<"----------------------------"<<endl;
    cout<<"Operatori:"<<endl;
    angj1.operator++(2000);
    cout<<angj1.getSalary()<<endl;
    angj1.operator--(3000);
    cout<<angj1.getSalary()<<endl;

    return 0;
}
