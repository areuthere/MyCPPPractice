#pragma once
#include <iostream>
using namespace std;

namespace not_following
{
namespace principles
{
struct Document;
struct IMachine
{
    virtual void print(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
    virtual void scan(Document &doc) = 0;
};

struct MFP : IMachine
{
    void print(Document &doc) override;
    void fax(Document &doc) override;
    void scan(Document &doc) override;
};

} // namespace principles

} // namespace not_following
