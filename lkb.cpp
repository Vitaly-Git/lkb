#include <iostream>
#include "DataRecord.hpp"

int main(){

    DataRecord dr("Title 1", "Content 11");
    DataRecord dr2("Title 2", "Content 22");

    std::cout << dr << "\n";
    std::cout << dr2 << "\n";

    return 0;
}