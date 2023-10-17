#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;

namespace not_following
{
namespace principles
{
class Notes
{
    public:
    string m_title;
    vector<string> m_enteries;

    Notes(const std::string& title):m_title(title),m_enteries{}{}
    void add_entry(const string &entry)
    {
        static int i = 1;
        m_enteries.push_back(to_string(++i) + " " + entry);
    }
    void save(const string &filepath)
    {
        ofstream file(filepath, std::ofstream::out);
        file << m_title << endl;
        for (auto entry : m_enteries)
        {
            file << entry << endl;
        }
        file.close();
    }
};
} // namespace principles
} // namespace not_following
