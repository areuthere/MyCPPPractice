#pragma once
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace following
{
namespace patterns
{

class Tag
{
    string str(size_t index) const
    {
        ostringstream ss;
        ss << string(" ",index) << "<" << name;
        for (const auto &att : attributes)
            ss << " " << att.first << "=\"" << att.second << "\"";
        if (children.size() == 0 && text.length() == 0)
        {
            ss << "/>" << std::endl;
        }
        else
        {
            ss << ">" << std::endl;
            if (text.length())
                ss << text << std::endl;
            for (const auto &child : children)
                ss << child.str(index+1);
            ss << string(" ",index) << "</" << name << ">" << std::endl;
        }
        return ss.str();
    }
public:
    string name, text;
    vector<Tag> children;
    vector<pair<string, string>> attributes;
    friend std::ostream &operator<<(std::ostream &os, const Tag &tag)
    {
        os << tag.str(0);
        return os;
    }

protected:
    Tag(const std::string &name, const std::string &text) : name{name}, text{text}
    {
    }
    Tag(const std::string &name, const std::vector<Tag> &children) : name{name}, children{children}
    {
    }
};


struct P : Tag
{
    explicit P(const std::string &text) : Tag{"p", text}
    {
    }

    P(std::initializer_list<Tag> children) : Tag("p", children)
    {
    }
};

struct IMG : Tag
{
    explicit IMG(const std::string &url) : Tag{"img", ""}
    {
        attributes.emplace_back(make_pair("src", url));
    }
};


} // namespace patterns
} // namespace following
