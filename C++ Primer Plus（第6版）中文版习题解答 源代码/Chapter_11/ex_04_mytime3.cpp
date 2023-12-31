// mytime3.cpp  -- implementing Time methods
#include "mytime3.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}
/* 以下以以友元函数形式实现的操作符重载函数，实现较为简单，只需要在原有函数的基础上
将成员函数使用饿私有数据成员，替换成为新添加参数的对象成员即可，因为是友元函数的形式
因此，该函数可以访问所有的数据成员和成员方法。
*/
Time operator+(const Time & s, const Time & t)
{
    Time sum;
    sum.minutes = s.minutes + t.minutes;
    sum.hours = s.hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time & s, const Time & t)
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = s.minutes + 60 * s.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time operator*(const Time & s, double mult)
{
    Time result;
    long totalminutes = s.hours * mult * 60 + s.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
