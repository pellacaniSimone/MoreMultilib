#include "datetime.h"

void timedate_handling() {
    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);
    printf("Data e ora corrente: %04d-%02d-%02d %02d:%02d:%02d\n", 
           currentTime.tm_year + 1900, currentTime.tm_mon + 1, currentTime.tm_mday,
           currentTime.tm_hour, currentTime.tm_min, currentTime.tm_sec);
    
    int hours_remaining = 23 - currentTime.tm_hour;
    int minutes_remaining = 59 - currentTime.tm_min;
    int seconds_remaining = 59 - currentTime.tm_sec;

    printf("Ore mancanti alla mezzanotte: %d ore, %d minuti e %d secondi.\n", 
           hours_remaining, minutes_remaining, seconds_remaining);
}