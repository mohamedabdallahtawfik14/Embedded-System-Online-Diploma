#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "alarm.h"
volatile int threshold = 20;
volatile int pressure;
int main (){
	
	GPIO_INITIALIZATION();
	ledInit();
	while (1)
	{
		//Implement your Design 
		pressure = getPressureVal();
		if(pressure > threshold)
		{
			high_pressure_detected();
		}
		Delay(500000);
	}

}
