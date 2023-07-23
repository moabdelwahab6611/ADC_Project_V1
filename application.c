/* 
 * File     : application.c
 * Author   : Mohamed Ahmed Abdel Wahab
 * LinkedIn : https://www.linkedin.com/in/mohamed-abdel-wahab-162413253/
 * Github   : https://github.com/moabdelwahab6611
 * Created on May 21, 2023, 5:38 PM
 */

/**************************Includes-Section*****************************/
#include "application.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"
/***********************************************************************/

/***********************************************************************/
uint16 adc_result_1, adc_result_2, adc_result_3, adc_result_4;
        
adc_config_t adc1 =
{
    .ADC_InterruptHandler = NULL,
    .acquisition_time = ADC_12_TAD,
    .adc_channel = ADC_CHANNEL_AN0,
    .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    .result_format = ADC_RESULT_RIGHT,
    .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};
/***********************************************************************/

/***********************Main Function-Section***************************/
int main() 
{ 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    
    while(1)
    {   
       ret =  ADC_GetConversion_Blocking(&adc1, ADC_CHANNEL_AN0, &adc_result_1);
       ret =  ADC_GetConversion_Blocking(&adc1, ADC_CHANNEL_AN1, &adc_result_2);
       ret =  ADC_GetConversion_Blocking(&adc1, ADC_CHANNEL_AN2, &adc_result_3);
       ret =  ADC_GetConversion_Blocking(&adc1, ADC_CHANNEL_AN3, &adc_result_4);
    }
    return (EXIT_SUCCESS);
}
/***********************************************************************/

/*************************Functions-Section*****************************/
void application_intialize(void)
{
    Std_ReturnType ret = E_NOT_OK;   
    ret = ADC_Init(&adc1);
    ecu_layer_intialize();
}
/***********************************************************************/