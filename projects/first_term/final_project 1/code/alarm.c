#include "alarm.h"
#define timeOfAlarm 500000
void high_pressure_detected(void)
{
	Set_Alarm_actuator(1);
	Delay(timeOfAlarm);
	Set_Alarm_actuator(0);
	Delay(timeOfAlarm);

}
