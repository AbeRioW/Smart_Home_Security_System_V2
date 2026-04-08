#include "ui.h"
#include "co2.h"

void main_ui(void)
{
	  DHT11_Data_t dht_data;
    char display_buf[32],display_buf1[32], display_buf2[32], display_buf3[32];
    
    if(DHT11_READ_DATA(&dht_data) == 0)
    {
      sprintf((char*)display_buf, "Temp: %d.%dC", dht_data.temp_int, dht_data.temp_dec);
		sprintf((char*)display_buf1, "Humidity: %d.%d%%",dht_data.humidity_int, dht_data.humidity_dec); 		
      //OLED_Clear();
      OLED_ShowString(0, 0, (uint8_t*)display_buf, 8, 1);
		OLED_ShowString(0, 8, (uint8_t*)display_buf1, 8, 1);
    }
    
    // 显示CO2浓度
    float co2_val = CO2_GetConcentration();
    sprintf((char*)display_buf2, "CO2: %.3f mg/m3", co2_val);
    OLED_ShowString(0, 16, (uint8_t*)display_buf2, 8, 1);
    
    // 显示MQ5数值
    uint32_t mq5_value = ADC1_ReadValue();
    sprintf((char*)display_buf3, "MQ5: %u", (unsigned int)mq5_value);
    OLED_ShowString(0, 24, (uint8_t*)display_buf3, 8, 1);
    
    OLED_Refresh();
}