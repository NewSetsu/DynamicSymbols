#include "dynamic_symbols.h"
#include "utils/timer.h"

using namespace std;

int main()
{
    Init();

    // 实验证明，使用内存池快了 3 倍以上
    ChronoTimer new_timer;
    for (int i = 0; i < 1000000; i++)
    {
        auto p = new IntObject[10];
        delete []p;
    }
    cout << "no pool using time: " << new_timer.GetDurationMS() << "ms \r\n";

    new_timer.Restart();
    for (int i = 0; i < 10000000; i++)
    {
        auto p = INT_OBJECT_POOL->CreateIntObject(i);
        p->Erase();
    }
    cout << "mem pool using time: " << new_timer.GetDurationMS() << "ms \r\n";
    Destory();

    return 0;
}