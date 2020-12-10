#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

class Person
{
public: // temporary solution
    std::string first;
    std::string last;
    int age;

public:
    Person(int age, std::string first, std::string last)
        : age(age), first(first), last(last){};

    bool operator==(const Person& other) const
    {
        return age == other.age
            && first == other.first
            && last == other.last;
    }
};

size_t hashString(std::string s)
{
    size_t seed = 0;
    for (auto c : s)
    {
        seed
         += 37 + 17 * c;
    }
    return seed;
    // 2^32;
}

// struct MyHash
// {
//     // when a < b
//     bool operator()(const Person &a, const Person &b) const
//     {
//         // hashing
//         return 0;
//     }
// };

void hash_combine(size_t &seed, size_t value)
{
    seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <>
struct std::hash<Person>
{
    // от boost библиотеката

    size_t operator()(const Person &a) const
    {
        size_t seed = 0;

        size_t h_age = std::hash<int>()(a.age);
        size_t h_first = std::hash<std::string>()(a.first);
        size_t h_last = std::hash<std::string>()(a.last);

        hash_combine(seed, h_age);
        hash_combine(seed, h_first);
        hash_combine(seed, h_last);
        return seed;
    }
};

int main()
{
    std::string a = "hello there";  // 19107
    std::string b = "hello theree"; // =/= 19107

    size_t stringHash = std::hash<std::string>()(a);
    size_t stringHash2 = std::hash<std::string>()(b);
    std::cout << hashString(a) << std::endl;
    std::cout << stringHash << std::endl;
    std::cout << stringHash2 << std::endl;

    std::unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);

    Person p1(12, "ivan", "ivanov");
    Person p2(13, "ceco", "asdasf");

    std::unordered_set<Person> s_person;
    s_person.insert(p1);
    s_person.insert(p2);

    std::unordered_map<std::string, Person> unordered_m;
    // unordered_m["asdf"] = Person();

    return 0;
}

/*
    O(1);


*/

/*
    arr[1000];
    index = 8615655752587911362 % 1000 // 0 - 999
    arr[index] = p1;
    index = hash(p1) % .... // О(1)

    // 2000
    arr[index] -> vector / list
    arr[index].push_back(p2)    // average O(1)
*/