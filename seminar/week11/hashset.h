#ifndef FMI_HASH_SET_H_
#define FMI_HASH_SET_H_

#include <functional>

// Hash set
// Set - множество, т.е. съвкупност от неповтарящи се елементи
// Hash set - представяне на множество, като за запазването на елементите
// и определянето на позициите им използваме hash функции
// Hash map / hash set - имплементират чрез масиви
// HashSet<T> => не е T[], a std::list<T*>[]
// масив от списъци / bucket-и

template <typename T>
class HashSet
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node** buckets;
    int capacity;
    int size;
    std::function<int(const T&)> hashFunction;

    void clear();
    void copy(const HashSet<T>& other);
    Node*& find(const T& data)
    {
        int hash = hashFunction(data);
        int i = hash % capacity;

        Node** it = &(buckets[i]);

        while (*it != nullptr && (*it)->data != data)
        {
            it = &((*it)->next);
        }

        return *it;
    }
public:
    HashSet(const std::function<int(const T&)>& hashFunc, int capacity = 11)
        : hashFunction(hashFunc), size(0), buckets(nullptr)
    {
        this->capacity = (capacity < 1) ? 11 : capacity;
        buckets = new Node*[this->capacity];

        for (int i = 0; i < this->capacity; ++i)
        {
            buckets[i] = nullptr;
        }
    }

    HashSet(const HashSet<T>& other)
        : hashFunction(other.hashFunction),
        buckets(nullptr),
        size(other.size),
        capacity(other.capacity)
    {
        copy(other);
    }

    HashSet<T>& operator=(const HashSet<T>& other)
    {
        if (this != &other)
        {
            clear();
            copy(other);
        }

        return *this;
    }

    ~HashSet()
    {
        clear();
    }

    // добавяме елементи
    bool emplace(const T& data);
    // премахваме елементи
    bool remove(const T& data);
    // проверяваме дали елемент е в множеството
    bool contains(const T& data);
    // проверка дали множеството е празно
    bool empty() { return size == 0; }
    int getSize() { return size; }
};


template <typename T>
bool HashSet<T>::emplace(const T& data)
{
    Node*& it = find(data);

    if (it != nullptr)
    {
        // it->data = data;
        return false;
    }

    // it == nullptr
    // data не присъства в никоя клетка в bucket-а
    // it е псевдоним на последната променлива в bucket-а, тя съдържа nullptr
    it = new Node();
    it->data = data;
    it->next = nullptr;
    ++size;
    return true;
}

template <typename T>
bool HashSet<T>::remove(const T& data)
{
    Node*& it = find(data);

    if (it == nullptr)
    {
        return false;
    }

    // it != nullptr
    // it е псевдоним на клетката, която съдържа data
    Node* tmp = it;
    it = it->next;
    delete tmp;
    --size;
    return true;
}

template <typename T>
bool HashSet<T>::contains(const T& data)
{
    Node*& it = find(data);

    return it != nullptr;
}

template <typename T>
void HashSet<T>::clear()
{
    for (int i = 0; i < capacity; ++i)
    {
        Node* it = buckets[i];
        while (it != nullptr)
        {
            Node* tmp = it;
            it = it->next;
            delete tmp;
        }
    }

    delete[] buckets;
    buckets = nullptr;
}

template <typename T>
void HashSet<T>::copy(const HashSet<T>& other)
{
    this->capacity = other.capacity;
    this->hashFunction = other.hashFunction;

    for (int i = 0; i < other; ++i)
    {
        Node* it = other.buckets[i];
        while (it != nullptr)
        {
            this->emplace(it->data);
            it = it->next;
        }
    }
}

#endif // FMI_HASH_SET_H_