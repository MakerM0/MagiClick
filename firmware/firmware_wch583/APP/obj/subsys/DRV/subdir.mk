################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/DRV/DRV.cpp 

OBJS += \
./subsys/DRV/DRV.o 

CPP_DEPS += \
./subsys/DRV/DRV.d 


# Each subdirectory must supply rules for building sources it contributes
subsys/DRV/DRV.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware_0205\ -\ 副本/subsys/DRV/DRV.cpp
	@	@	riscv-none-embed-g++ -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DDEBUG=1 -DLOG -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware_0205 - 副本\subsys\BLE\profile" -isystem"../../boards" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

