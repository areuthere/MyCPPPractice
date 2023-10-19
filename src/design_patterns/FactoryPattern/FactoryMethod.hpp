#pragma once
#include <iostream>
#include <memory>
using namespace std;

namespace following
{
namespace patterns
{
class Beverage
{
public:
    virtual void prepare(size_t volume) = 0;
    virtual ~Beverage() = default;
};

class Coffee : public Beverage
{
public:
    void prepare(size_t volume) override
    {
        cout << "preparing a coffee" << endl;
    }
};

class Tea : public Beverage
{
public:
    void prepare(size_t volume) override
    {
        cout << "preparing a Tea" << endl;
    }
};

class Juice : public Beverage
{
public:
    void prepare(size_t volume) override
    {
        cout << "preparing a juice" << endl;
    }
};

class IBeverageFactory
{
public:
    virtual unique_ptr<Beverage> createBeverage(string drink_name) = 0;
    virtual ~IBeverageFactory() = default;
};

class BeverageFactory : public IBeverageFactory
{
public:
    unique_ptr<Beverage> createBeverage(string drink_name) override
    {
        unique_ptr<Beverage> drink;
        if (drink_name == "tea")
            drink = make_unique<Tea>();
        else if (drink_name == "coffee")
            drink = make_unique<Coffee>();
        else
            drink = make_unique<Juice>();
        return drink;
    }
};
} // namespace pattern

} // namespace following
