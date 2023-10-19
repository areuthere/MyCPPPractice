#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <sstream>
using namespace std;

namespace following
{
namespace patterns
{

class SubSystemOne
{
public:
	void MethodOne(){ std::cout << "SubSystem 1" << std::endl; };
};

// Subsystem 2
class SubSystemTwo
{
public:
	void MethodTwo(){ std::cout << "SubSystem 2" << std::endl; };
};

// Subsystem 3
class SubSystemThree
{
public:
	void MethodThree(){ std::cout << "SubSystem 3" << std::endl; }
};


// Facade
class Facade
{
public:
    Facade()
    {
	pOne = new SubSystemOne();
	pTwo = new SubSystemTwo();
	pThree = new SubSystemThree();
    }

    void MethodA()
    {
	std::cout << "Facade::MethodA" << std::endl;
	pOne->MethodOne();
	pTwo->MethodTwo();
    }

    void MethodB()
    {
	std::cout << "Facade::MethodB" << std::endl;
	pTwo->MethodTwo();
	pThree->MethodThree();
    }

private:
    SubSystemOne *pOne;
    SubSystemTwo *pTwo;
    SubSystemThree *pThree;
};


} // namespace patterns

} // namespace following
