################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/MAX30105.cpp \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/heartRate.cpp \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/sensor_max30102.cpp 

C_SRCS += \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/spo2_algorithm.c 

C_DEPS += \
./subsys/sensor/max30102/spo2_algorithm.d 

OBJS += \
./subsys/sensor/max30102/MAX30105.o \
./subsys/sensor/max30102/heartRate.o \
./subsys/sensor/max30102/sensor_max30102.o \
./subsys/sensor/max30102/spo2_algorithm.o 

CPP_DEPS += \
./subsys/sensor/max30102/MAX30105.d \
./subsys/sensor/max30102/heartRate.d \
./subsys/sensor/max30102/sensor_max30102.d 


# Each subdirectory must supply rules for building sources it contributes
subsys/sensor/max30102/MAX30105.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/MAX30105.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DDEBUG=1 -DLOG -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/sensor/max30102/heartRate.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/heartRate.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DDEBUG=1 -DLOG -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/sensor/max30102/sensor_max30102.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/sensor_max30102.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DDEBUG=1 -DLOG -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/sensor/max30102/spo2_algorithm.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/sensor/max30102/spo2_algorithm.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DCLK_OSC32K=0 -DDEBUG=1 -DLOG -DCONFIG_ZTEST -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\LCD_show\pages" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\LCD_show\manager" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

