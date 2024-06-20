#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; // 17

    mstack.pop();

    std::cout << mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

  
    std::cout << "MutantStack`s args: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl; // 5 3 5 737 0

    std::stack<int> s(mstack);
    std::cout << "std::stack`s args: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl; // 0 737 5 3 5

    std::cout << "MutantStack`s biggest arg: " << *std::max_element(mstack.begin(), mstack.end()) << std::endl;

    return 0;
}