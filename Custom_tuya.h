
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

	void writeByte(uint8_t data) {
		 Serial.write(data);
	}
	
	void sendMessage(std::string data, std::string value, std::string b) {
		int i = 0;
		uint8_t sum = 0;
		while (i < data.length()) {
			const char hex[2] = {data[i++], data[i++]};
			
			ESP_LOGD("custom", "data %d", data.c_str());
			uint8_t d = strtoul(hex, NULL, 16);
			sum += d;
			writeByte(d);
		}
		
    std::stringstream ss;
    ss << setfill('0') << setw(atoi(b.c_str())) << std::hex << atoi(value.c_str());
    value = ss.str();
    
  i = 0;  
		while (i < value.length()) {
			const char hex[2] = {value[i++], value[i++]};
					ESP_LOGI("custom", "value %d", value.c_str());
			uint8_t d = strtoul(hex, NULL, 16);
			sum += d;
			writeByte(d);
		}
		
		writeByte(sum);
	}
