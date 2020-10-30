#include <iostream>
#include <assert.h>
#include "stack.h"

#define NOT_REACHED assert(false && "Execution should not reach here")

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib_with_stack(int n)
{
    FMIStack<std::pair<int, int>> my_stack;
    my_stack.push(std::make_pair(n, -1));

    while (!my_stack.empty())
    {
        auto& peek = my_stack.peek();
        if (peek.second == -1)
        {
            switch (peek.first)
            {
                case 0:
                case 1:
                    peek.second = peek.first;
                    break;
                default:
                    int curr_n = peek.first;
                    my_stack.push(std::make_pair(curr_n - 1, -1));
                    my_stack.push(std::make_pair(curr_n - 2, -1));
            }
        }
        else {
            if (peek.first == n)
            {
                return peek.second;
            }
            auto last_pair = peek;
            my_stack.pop();
            if (my_stack.peek().second != -1)
            {
                int add_data = my_stack.peek().second;
                my_stack.pop();
                my_stack.peek().second = add_data + last_pair.second;
            }
            else
            {
                auto second_to_last_pair = my_stack.peek();
                my_stack.peek() = last_pair;
                my_stack.push(second_to_last_pair);
            }
        }
        
    }

    NOT_REACHED;
}

int main()
{
    std::cout << fib_with_stack(6) << "\n";
    return 0;
}