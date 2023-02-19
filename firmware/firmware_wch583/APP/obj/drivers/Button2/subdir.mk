################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/Button2/Button2.cpp 

OBJS += \
./drivers/Button2/Button2.o 

CPP_DEPS += \
./drivers/Button2/Button2.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Button2/Button2.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/drivers/Button2/Button2.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\StdPeriphDriver\inc" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\HAL" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE" -I"D:\WorkShop\PROJ\MagicButton\2.0\github\MagiClick\firmware\firmware_wch583\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

