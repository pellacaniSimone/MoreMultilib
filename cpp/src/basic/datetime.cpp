#include "datetime.h"


void timedate_handling() {
  time_t current_time = time(nullptr);
  tm* local_time = localtime(&current_time);
  cout << "Data e ora corrente: " << put_time(local_time, "%Y-%m-%d %H:%M:%S") << endl;
  int hours_left = 23 - local_time->tm_hour;
  int minutes_left = 59 - local_time->tm_min;
  int seconds_left = 59 - local_time->tm_sec;
  cout << "Ore mancanti alla mezzanotte: " << hours_left
            << " ore, " << minutes_left << " minuti e "
            << seconds_left << " secondi." << endl;
}