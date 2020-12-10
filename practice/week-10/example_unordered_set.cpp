#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Person
{
public:
    string first;
    string last;
    int age;
public:
    Person(int age)  : age(age) {};
    bool operator==(const Person& other) const 
    {
        return this->age == other.age
            && this->first == other.first
            && this->last == other.last;
    }
};


template <>
struct std::hash<Person>
{
    size_t hash_combine(size_t& seed, size_t value)
    {
        seed ^= value + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    size_t operator()(const Person &a) const
    {
        size_t seed = 0;
        size_t h1 = std::hash<int>()(a.age);
        size_t h2 = std::hash<string>()(a.first);
        size_t h3 = std::hash<string>()(a.last);
        hash_combine(seed, h1);
        hash_combine(seed, h2);
        hash_combine(seed, h3);
        return seed;
    }
};

int main()
{
    unordered_set<Person> s;
    Person a(2);
    Person b(3);
    s.insert(a);
    
    return 0;
}