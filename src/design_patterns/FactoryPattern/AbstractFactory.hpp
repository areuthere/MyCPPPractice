#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <optional>
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

class IHeatingMethod
{
    virtual void heat() = 0;

public:
    virtual ~IHeatingMethod() = default;
};

class ICoolingMethod
{
    virtual void cool() = 0;

public:
    virtual ~ICoolingMethod() = default;
};

class HotCoffee : public Beverage, public IHeatingMethod
{
    virtual void heat() override
    {
        cout << "Heat but do not boil" << endl;
    }

public:
    void prepare(size_t volume) override
    {
        heat();
        cout << "preparing a coffee of " << volume << " ml" << endl;
    }
};

class HotTea : public Beverage, public IHeatingMethod
{
    virtual void heat() override
    {
        cout << "Heat by boiling" << endl;
    }

public:
    void prepare(size_t volume) override
    {
        heat();
        cout << "preparing a tea of " << volume << " ml" << endl;
    }
};

class ColdTea : public Beverage, public ICoolingMethod
{
    virtual void cool() override
    {
        cout << "Cold at 4degree " << endl;
    }

public:
    void prepare(size_t volume) override
    {
        cool();
        cout << "preparing a tea of " << volume << " ml" << endl;
    }
};

class ColdCoffee : public Beverage, public ICoolingMethod
{
    virtual void cool() override
    {
        cout << "Cold at 2degree " << endl;
    }

public:
    void prepare(size_t volume) override
    {
        cool();
        cout << "preparing a coffee of " << volume << " ml" << endl;
    }
};

class ColdJuice : public Beverage, public ICoolingMethod
{
    virtual void cool() override
    {
        cout << "Cool by refrigerating" << endl;
    }

public:
    void prepare(size_t volume) override
    {
        cool();
        cout << "preparing a juice of " << volume << " ml" << endl;
    }
};

class IBeverageFactory
{
public:
    virtual unique_ptr<Beverage> make(string drink_name) = 0;
    virtual ~IBeverageFactory() = default;
};

class ColdBeverageFactory : public IBeverageFactory
{
public:
    unique_ptr<Beverage> make(string drink_name) override
    {
        unique_ptr<Beverage> drink;
        if (drink_name == "coffee")
            drink = make_unique<ColdCoffee>();
        else if (drink_name == "tea")
            drink = make_unique<ColdTea>();
        else
            drink = make_unique<ColdJuice>();
        return drink;
    }
};

class HotBeverageFactory : public IBeverageFactory
{
public:
    unique_ptr<Beverage> make(string drink_name) override
    {
        unique_ptr<Beverage> drink;
        if (drink_name == "tea")
            drink = make_unique<HotTea>();
        else if (drink_name == "coffee")
            drink = make_unique<HotCoffee>();
        return drink;
    }
};


class BeverageFactory
{
    static map<string, unique_ptr<IBeverageFactory>> factoryMap;

public:
    unique_ptr<Beverage> createBeverage(string drink_name, string hot_cold)
    {
        return factoryMap[hot_cold]->make(drink_name);
    }
};

map<string, unique_ptr<IBeverageFactory>> BeverageFactory::factoryMap{{"cold", make_unique<HotBeverageFactory>()},
                                                                      {"hot", make_unique<ColdBeverageFactory>()}};
} // namespace patterns

} // namespace following
