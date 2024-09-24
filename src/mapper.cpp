#include <iostream>
#include <string>

/*
1 id, 
2 name, 
3 host_id, 
4 host_name, 
5 neighbourhood_group, 
6 neighbourhood,
7 latitude,
8 longitude, 
9 room_type,
10 price,
*/
bool extract_price(const std::string& line, std::string& price)
{
    // regex too heavy
    bool inside_str = false;
    int zpt = 0;
    std::string::const_iterator it_start = line.begin();
    while( it_start != line.end() && zpt < 9)
    {
        if('\"' == *it_start)
        {
            inside_str = !inside_str;
        }
        if( ',' == *it_start && !inside_str)
        {
            zpt++;
        }
        it_start++;
    }
    if ( 9 != zpt )
    {
        return false; // empty
    }
    std::string::const_iterator it_end = it_start;
    while( it_end != line.end() && ',' != *it_end)
    {
        it_end++;
    }
    price.assign(it_start, it_end);
    return true;
}

int main(int argc, char ** argv)
{
    std::string line, price;

    while (std::getline(std::cin, line))
    {
        if(extract_price(line, price))
        {
            std::cout << price << std::endl;
        }
    }
    return 0;
}