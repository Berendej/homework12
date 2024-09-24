#include <iostream>
#include <string>

// 152 696
int main(int argc, char ** argv)
{
    double count = 0;
    double avg = 0.0;
    double current;
    std::string line;
    while (std::getline(std::cin, line))
    {
        try
        {
            current = stod(line);
            count += 1.0;
            avg = avg + (current-avg)/count;
        }
        catch(...)
        {
            std::cout << count << " wrong input " << line << std::endl;
        }
    }
    std::cout << avg << std::endl;
    return 0;
}