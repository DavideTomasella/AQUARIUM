#ifndef Timer_h
#define Timer_h

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <esp_log.h>

static void timer_isr(void* arg);
char Timer_Tick(unsigned char t);
void Clear_Timer_Tick(unsigned char t);
void init_timer(int timer_period_us);

#endif /* Timer_h */