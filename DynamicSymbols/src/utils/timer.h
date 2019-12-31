#pragma once
#include <chrono>

/*!
     * \class ChronoTimer
     * \brief 使用chrono库的一个简单计时器
     * \author chengx
     * \date 2019.12.09
     */
class ChronoTimer final
{
public:
    ChronoTimer() :
        m_time(std::chrono::steady_clock::now())
    {
    }

    // 记录初始时间
    void Restart()
    {
        m_time = std::chrono::steady_clock::now();
    }

    // 返回间隔时间，单位ms
    const uint64_t GetDurationMS()
    {
        std::chrono::steady_clock::duration tmp_duration =
            std::chrono::steady_clock::now() - m_time;
        return std::chrono::duration_cast<std::chrono::milliseconds>(tmp_duration).count();
    }

private:
    std::chrono::steady_clock::time_point m_time;
};