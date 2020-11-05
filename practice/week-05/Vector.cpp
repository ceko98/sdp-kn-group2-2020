#include <vector>
#include <iostream>

template <class T>
class Vector{
  private:
    T *data;
    int size;

  public:
    class VectorIterator {
      private:
        friend class Vector;

        // int current;
        // T *array;
        // TODO variables ???

        VectorIterator(int start, T *array)
          : current(start), array(array)
        {};

      public:
        T& operator*() {
          // TODO
          // return array[current];
        }
        bool operator == (const VectorIterator &it) const {
          // TODO
          // return current == it.current;
        }
        bool operator != (const VectorIterator &it) const {
          // TODO
          // return current != it.current;
        }
        VectorIterator& operator++() {
          // TODO
          // current++;
          // return *this;
        }
    };

    VectorIterator begin() {
      // TODO
      // return VectorIterator(0, data);
    }
    VectorIterator end() {
      // TODO
      // return VectorIterator(size, data);
    }

    Vector() : size(0) {
      data = new T[64];
    }

    void insertAt(T element, int position){
      for(int i = size; i > position; i--) {
        data[i] = data[i - 1];
      }
      data[position] = element;
      size++;
    }

    void pushBack(T element) {
      data[size++] = element;
    }

    T& getAt(int position) {
      return data[position];
    }
    int getSize() {
      return this->size;
    }

    ~Vector() {
      delete [] data;
    }
};

int main() {
  Vector<int> a;
  a.pushBack(1);
  a.pushBack(2);
  a.pushBack(3);
  a.pushBack(4);

  for(int i = 0; i < 4; i++) {
    std::cout << a.getAt(i) << " ";
  }
  std::cout << std::endl;

  for(Vector<int>::VectorIterator it = a.begin(); it != a.end(); ++it){
    std::cout << *it << std::endl;
  }

  for (int x : a) {
    std::cout << x << " ";
  }

  return 0;
}