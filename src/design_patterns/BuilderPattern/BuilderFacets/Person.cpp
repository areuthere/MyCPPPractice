#include "Person.hpp"
#include "PersonBuilder.hpp"

namespace following
{
namespace patterns
{

PersonBuilder Person::create()
{
    return PersonBuilder{};
}
} // namespace patterns
} // namespace following
