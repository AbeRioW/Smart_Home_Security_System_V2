#ifndef __CO2_H
#define __CO2_H

#include "stdint.h"

void CO2_Init(void);
void CO2_ProcessData(void);
float CO2_GetConcentration(void);

#endif
