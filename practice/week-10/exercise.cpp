#include <map>
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

// struct MyCompare
// {
//     // when a < b
//     bool operator()(const Person &a, const Person &b) const
//     {
//         return a.getAge() < b.getAge();
//     }
// };


int main()
{
    std::map<int, std::string> m({ {1, "ceco"}, {2, "aa" } });
    m[1] = "asdf";
    m[2] = "asdfgfg";
    m[45] = "pewo";

    // 1 < 5; 10 < 4;

    std::cout << m[1] << std::endl;

    std::map<Person, std::string> m_person;
    Person a(12, "ivan", "ivanov");
    m_person[a] = "ivan";

    std::cout << m_person[a] << std::endl;
    return 0;
}

/*
    2 -> "asdf"
    3 -> "asdfgfg"
    25 -> "asdf"
    
    25 -> Person()
*/