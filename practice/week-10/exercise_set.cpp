#include <set>
#include <string>
#include <iostream>

class Person
{
private:
    std::string first;
    std::string last;
    int age;
public:
    Person(int age, std::string first, std::string last)
        : age(age), first(first), last(last)
    {};

    bool operator<(const Person& other) const
    {
        return this->age >= other.age;
    }

    int getAge() const { return age; }
};

int main()
{
    std::set<int> s;
    s.insert(10);
    s.insert(11);
    s.insert(12);
    s.insert(13);
    s.insert(10);

    for (auto element : s)
    {
        std::cout << element << std::endl;
    }
    
    std::set<Person> s_person;
    Person a(12, "ivan", "ivanov");
    s_person.insert(a);
    s_person.insert(a);

    return 0;
}
