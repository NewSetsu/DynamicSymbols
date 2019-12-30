#include "dynamic_symbols.h"

using namespace std;

int main()
{
    Init();

    std::string point_type = "POSITION";
    std::string point_x = "X";

    auto new_point = STRUCT_OBJECT_POOL->CreateStructObject(point_type);
    auto new_point_x = new_point->GetMember(point_x);

    new_point->SetMembers(new_point_x, DOUBLE_OBJECT_POOL->CreateDoubleObject(1));

    std::cout << new_point->ClassInfo();
    std::cout << new_point_x->ClassInfo();

    Destory();

    return 0;
}