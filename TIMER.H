
#if !defined(__TIMER_H)
#define  __TIMER_H

#include <ctime>


class Timer  {
  private:
    tm  tidspunkt;
  public: 
    void hent(int& time, int& min, int& sek);
};


void Timer::hent(int& ti, int& mi, int& se)  {
   __time64_t  tid;
   _time64(&tid);
   _localtime64_s(&tidspunkt, &tid);
   ti = tidspunkt.tm_hour;
   mi = tidspunkt.tm_min;
   se = tidspunkt.tm_sec;
}

#endif
