#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person
{
public:
    string first;
    string last;
    int age;
public:
    Person(int age)  : age(age) {};
    bool operator<(const Person& other) const
    {
        return age < other.age;
    }
};

// template <>
// struct std::less<Person>
// {
//     bool operator()(const Person &a, const Person &b)
//     {
//         return a.age < b.age;
//     }
// };

int main()
{
    map<Person, int> mp;
    Person a(2);
    Person b(3);
    mp[a] = 2;
    mp[b] = 3;
    cout << mp[a] << endl;
    return 0;
}