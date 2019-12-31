#include "dynamic_symbols.h"

using namespace std;

int main()
{
    Init();

    std::string point_type = "POSE";

    auto new_point = STRUCT_OBJECT_POOL->CreateStructObject(point_type);

    std::cout << new_point->ClassInfo();

    Destory();

    return 0;
}