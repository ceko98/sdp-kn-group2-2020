#include <iostream>
#include <string>
#include <set>

using namespace std;

class Person
{
public:
    string first;
    string last;
    int age;
public:
    Person(int age)  : age(age) {};
};

template <>
struct std::less<Person>
{
    bool operator()(const Person &a, const Person &b)
    {
        return a.age < b.age;
    }
};

int main()
{
    set<Person> s;
    Person a(2);
    Person b(3);
    s.insert(a);
    
    return 0;
}