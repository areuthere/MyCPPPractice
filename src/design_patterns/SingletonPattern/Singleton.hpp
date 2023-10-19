#pragma once
namespace following
{
namespace patterns
{

class Singleton
{
    Singleton() = default;
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
};

} // namespace patterns


} // namespace following
