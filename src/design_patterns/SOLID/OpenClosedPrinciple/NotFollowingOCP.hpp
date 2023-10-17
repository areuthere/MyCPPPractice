#pragma once

#include <vector>
#include <string>
using namespace std;

namespace not_following
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
    Product(string name, Size size, Color color,Weight weight) : m_name(name), m_size(size), m_color(color), m_weight(weight)
    {
    }
    string m_name;
    Size m_size;
    Color m_color;
    Weight m_weight;
};

class ProductFilter
{
public:
    typedef vector<Product*> Items;
    Items filter_by_color(const Items& products, const Product::Color color)
    {
        Items items;
        for(auto product : products)
        {
            if(product->m_color == color)
                items.push_back(product);
        }
        return items;
    }
    Items filter_by_size(const Items& products, const Product::Size size)
    {
        Items items;
        for(auto product : products)
        {
            if(product->m_size == size)
                items.push_back(product);
        }
        return items;
    }
    Items filter_by_color_and_size(const Items& products, const Product::Color color, const Product::Size size)
    {
        Items items;
        for(auto product : products)
        {
            if((product->m_size == size) && (product->m_color == color) )
                items.push_back(product);
        }
        return items;
    }
};

} // namespace principles

} // namespace not_following
