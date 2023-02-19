################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/sensor/SHT30/Adafruit_SHT31.cpp \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/sensor/SHT30/sensor_SHT30.cpp 

OBJS += \
./subsys/sensor/SHT30/Adafruit_SHT31.o \
./subsys/sensor/SHT30/sensor_SHT30.o 

CPP_DEPS += \
./subsys/sensor/SHT30/Adafruit_SHT31.d \
./subsys/sensor/SHT30/sensor_SHT30.d 


# Each subdirectory must supply rules for building sources it contributes
subsys/sensor/SHT30/Adafruit_SHT31.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/sensor/SHT30/Adafruit_SHT31.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/sensor/SHT30/sensor_SHT30.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/subsys/sensor/SHT30/sensor_SHT30.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

