#include "BMS_Sensordata_Sender.h"

void GenerateSenderData(BatteryParameters *ptr_BatteryParam){
	for(int index = 0; index < NUM_OF_READINGS; index++){
		ptr_BatteryParam->temperature[index] = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
		ptr_BatteryParam->soc[index] = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
	}
}

void DisplaySenderData(status *ptr_Status, BatteryParameters BatteryParam){
	*ptr_Status = NOT_OK;
	int index = 0;
	for(index = 0; index < NUM_OF_READINGS; index++){
		printf("\nTemperature value is %.f, and StateOfCharge value is %.f",BatteryParam.temperature[index],BatteryParam.soc[index]);
	}
	*ptr_Status = OK;
}

status SendBatteryParameters(void){
	BatteryParameters BatteryParam;
	status operationStatus = NOT_OK;
	GenerateSenderData(&BatteryParam);
	DisplaySenderData(&operationStatus, BatteryParam);
	return operationStatus;
}
