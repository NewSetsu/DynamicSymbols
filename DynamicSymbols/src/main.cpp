#include "dynamic_symbols.h"
#include "utils/timer.h"

using namespace std;

int main()
{
    Init();

    auto int_arr = ARRAY_OBJECT_POOL()->CreateNewArray(_MEM_POOL_::GetIntArrID());
    
    // 一维数组
    for (int i = 0; i < 5; i++)
    {
        int_arr->PushBack(INT_OBJECT_POOL()->CreateIntObject(i));
    }

    cout << int_arr->ClassInfo();

    auto x1 = int_arr->GetArrUnit(0);
    x1->VarAssign(INT_OBJECT_POOL()->CreateIntObject(99));
    cout << x1->ClassInfo();
    cout << int_arr->GetArrUnit(0)->ClassInfo();

    // 二维数组
    auto int_arr_arr_id = ARRAY_OBJECT_POOL()->RegAnArray(int_arr);
    auto int_arr_arr = ARRAY_OBJECT_POOL()->CreateNewArray(int_arr_arr_id);

    for (int i = 0; i < 7; i++)
    {
        int_arr_arr->PushBack(ARRAY_OBJECT_POOL()->CreateNewArray(_MEM_POOL_::GetBoolArrID()));
    }

    cout << int_arr_arr->ClassInfo();

    return 0;
}