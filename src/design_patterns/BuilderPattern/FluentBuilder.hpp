#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


namespace following
{
namespace patterns
{

class HTMLBuilder;

class HTMLElement
{
    friend class HTMLBuilder;
    string mName, mText;
    vector<HTMLElement> mChildrens;
    HTMLElement(string const &name, string const &text) : mName(name), mText(text)
    {
    }

public:
    string str(int indent) const
    {
        ostringstream oss;
        oss << string(" ", indent * 2) << "<" << mName << ">" << endl;
        if (!mText.empty())
            oss << string(" ", indent * 2) << string(" ", 2) << mText << endl;
        for (auto child : mChildrens)
            oss << child.str(indent + 1);
        oss << string(" ", indent) << "</" << mName << ">" << endl;
        return oss.str();
    }
};

class HTMLBuilder
{
    HTMLElement root;

public:
    HTMLBuilder(string const &name) : root(name, "")
    {
    }
    HTMLBuilder &add_child(string const &name, string const &text)
    {
        HTMLElement child(name, text);
        root.mChildrens.emplace_back(child);
        return *this;
    }
    string str() const
    {
        return root.str(0);
    }
    HTMLElement build()
    {
        return root;
    }
};

} // namespace patterns
} // namespace following
