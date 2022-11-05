#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_READINGS			50
#define TEMP_MIN			      0
#define TEMP_MAX			      45
#define SOC_MIN				   20
#define SOC_MAX				   80

typedef struct{
   float temperature[NUM_OF_READINGS];
   float soc[NUM_OF_READINGS];
}BatteryParameters;

typedef enum{
	OK,
	NOT_OK
}status;

void GenerateSenderData(BatteryParameters *ptr_BatteryParam);
void DisplaySenderData(status *ptr_operationStatus_en, BatteryParameters BatteryParam);
status SendBatteryParameters(void);