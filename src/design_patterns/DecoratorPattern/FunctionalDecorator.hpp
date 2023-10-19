#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <sstream>
#include <functional>
using namespace std;


//Drawback of this pattern is that Decorated object of circle
//cannot use its member function moveCenter as it is not part of Shape interface

namespace following
{
namespace patterns
{

class Logger1
{
    const function<void()>& func;
    public:
    Logger1(function<void()> const& func):func(func){}
    void operator()()
    {
        cout << "Start function" << endl;
        func();
        cout << "End Function" << endl;
    }
};

template<typename T>
class Logger2
{
    const T& func;
    public:
    Logger2(T const& func):func(func){}
    void operator()()
    {
        cout << "Start function" << endl;
        func();
        cout << "End Function" << endl;
    }
};

template<typename Func>
auto make_logger2(Func func)
{
    return Logger2<Func>(func);
}


} // namespace patterns

} // namespace following
