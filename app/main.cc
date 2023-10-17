// #define FMT_HEADER_ONLY // may need this line

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "BuilderPattern/BuilderFacets/Person.hpp"
#include "BuilderPattern/BuilderFacets/PersonAddressBuilder.hpp"
#include "BuilderPattern/BuilderFacets/PersonBuilder.hpp"
#include "BuilderPattern/BuilderFacets/PersonJobBuilder.hpp"
using namespace following::patterns;

int main()
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
