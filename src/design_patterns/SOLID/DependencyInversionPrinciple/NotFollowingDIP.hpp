#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace not_following
{
namespace principles
{
enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct Relationships
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }
};

struct Research // high-level
{
    Research(const Relationships &relationships)
    {
        auto &relations = relationships.relations;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == "John" && rel == Relationship::parent)
            {
                cout << "John has a child called " << second.name << endl;
            }
        }
    };
};
} // namespace principles

} // namespace not_following
