#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdint.h>

class FOO
{
public:
    FOO(/* args */);
    ~FOO();

    FOO& get_copy_as_reference()
    {
        return *this;
    }
};


int main(int argc, char** argv) {
    std::cout << "int64_t size is: " << sizeof(int64_t) << ". " <<
        "Minimal value: " << std::numeric_limits<int64_t>::min() << ". " <<
        "Maximum value: " << std::numeric_limits<int64_t>::max() << ". " << std::endl;

    std::cout << "uint64_t size is: " << sizeof(uint64_t) << ". " <<
        "Minimal value: " << std::numeric_limits<uint64_t>::min() << ". " <<
        "Maximum value: " << std::numeric_limits<uint64_t>::max() << ". " << std::endl;



    system("pause");
}

