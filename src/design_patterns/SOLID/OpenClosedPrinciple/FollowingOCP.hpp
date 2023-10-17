#pragma once

#include <string>
#include <vector>
using namespace std;

namespace following
{
namespace principles
{
class Product
{
public:
    enum class Size
    {
        small,
        medium,
        large
    };
    enum class Color
    {
        green,
        red,
        orange
    };
    enum class Weight
    {
        light,
        medium,
        heavy
    };
    Product(string name, Size size, Color color, Weight weight)
        : m_name(name), m_size(size), m_color(color), m_weight(weight)
    {
    }
    string m_name;
    Size m_size;
    Color m_color;
    Weight m_weight;
};

template <class T>
class Specification
{
public:
    virtual bool is_satisfied(T *value) const = 0;
    virtual ~Specification() = default;
};

template <class T>
class Filter
{
public:
    virtual vector<T *> filter(vector<T *> input, const Specification<T> &specification) = 0;
    virtual ~Filter() = default;
};

class ColorSpecification : public Specification<Product>
{
    Product::Color m_color;

public:
    explicit ColorSpecification(Product::Color color) : m_color(color)
    {
    }
    virtual bool is_satisfied(Product *value) const override
    {
        return value->m_color == m_color;
    }
};

class SizeSpecification : public Specification<Product>
{
    Product::Size m_size;

public:
    explicit SizeSpecification(Product::Size size) : m_size(size)
    {
    }
    virtual bool is_satisfied(Product *value) const override
    {
        return value->m_size == m_size;
    }
};

template <class T>
class AndSpecification : public Specification<T>
{
    const Specification<T> &m_spec1;
    const Specification<T> &m_spec2;

public:
    AndSpecification(const Specification<Product> &spec1, const Specification<Product> &spec2)
        : m_spec1(spec1), m_spec2{spec2}
    {
    }
    virtual bool is_satisfied(T *value) const override
    {
        return m_spec1.is_satisfied(value) && m_spec2.is_satisfied(value);
    }
};

template <class T>
AndSpecification<T> operator&&(const Specification<T> &spec1, const Specification<T> &spec2)
{
    return {spec1, spec2};
}

class ProductFilter : public Filter<Product>
{
public:
    typedef vector<Product *> Items;
    Items filter(Items input, const Specification<Product> &specification) override
    {
        Items result;
        for (auto product : input)
        {
            if (specification.is_satisfied(product))
                result.push_back(product);
        }
        return result;
    }
};
} // namespace principles

} // namespace following
