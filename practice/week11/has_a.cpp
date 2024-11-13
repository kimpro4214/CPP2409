#include <iostream>
#include <string>

using namespace std;

class Date {
    int year, month, day;
public:
    //기본 인자 추가
    Date() {year = 0; month = 0; day = 0;}

    Date(int y, int m, int d) { year = y; month=m; day=d; }

    
    void Print() {
        cout << year << "." << month << "." << day <<endl;
    }
};

class Person {
    string name;
    Date birth;
public:
    Person(string n, const Date& d) { name = n; birth = d; }
    void Print() {
        cout << name << ":";
        birth.Print();
        cout << endl;
    }
};
int main()
{
    Date d{ 1998, 3, 1 };
    Person p{ "김철수", d };
    p.Print();
    return 0;
}
