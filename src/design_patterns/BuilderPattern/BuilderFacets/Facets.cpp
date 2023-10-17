#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "Person.hpp"
#include "PersonAddressBuilder.hpp"
#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"
using namespace following::patterns;

int main__()
{
    Person p = Person::create()
                   .lives()
                   .at("123 London Road")
                   .with_postcode("SW1 1GB")
                   .in("London")
                   .works()
                   .at("PragmaSoft")
                   .as_a("Consultant")
                   .earning(10e6);

    cout << p << endl;
    getchar();
    return 0;
}
