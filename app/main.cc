#include "DecoratorPattern/FunctionalDecorator.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <MyVector.hpp>
using namespace std;

using namespace following::patterns;

class A
{
    string str;

public:
    A()
    {
        str = "";
        cout << "Default constructor is called" << endl;
    }
    A(string str) : str(str)
    {
        cout << "Normal constructor of A is called" << endl;
    }
    A(A const& obj)
    {
        this->str = obj.str;
        cout << "copy constructor for A is called" << endl;
    }
    A(A const&& obj)
    {
        str = std::move(obj.str);
        cout << "move constructor for A is called" << endl;
    }
    void func(A const &b)
    {
        cout << b.str << endl;
    }
};


int main()
{
    //make_logger2([](){cout << "I am a function call" << endl;})();
    //vector<A> vec;
    // A a("hello");
    // //vec.push_back("hello hiiiii"s);
    // int* p = new int[15]{20};
    // p[13] = 1;
    // for(int i=0;i<15;++i)
    //     cout << p[i]<< endl;
    // delete[] p;
    //A *ptr = new A[20];
    MyVector<int> v(15);
    cout << v.size() << " " << v.capacity() << endl;
    v.push_back(10);
    cout << v.size() << " " << v.capacity() << endl;
    v.pop_back();
    cout << v.size() << " " << v.capacity() << endl;
    return 0;
}
