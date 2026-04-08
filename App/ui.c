#include "ui.h"

void main_ui(void)
{
	  DHT11_Data_t dht_data;
    char display_buf[32],display_buf1[32];
    
    if(DHT11_READ_DATA(&dht_data) == 0)
    {
      sprintf((char*)display_buf, "Temp: %d.%dC", dht_data.temp_int, dht_data.temp_dec);
			sprintf((char*)display_buf1, "Humidity: %d.%d%%",dht_data.humidity_int, dht_data.humidity_dec); 				
      //OLED_Clear();
      OLED_ShowString(0, 0, (uint8_t*)display_buf, 8, 1);
			OLED_ShowString(0, 8, (uint8_t*)display_buf1, 8, 1);
      OLED_Refresh();
    }
}