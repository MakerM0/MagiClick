################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware/subsys/LCD_show/ST7735S/ST7735_test.c \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware/subsys/LCD_show/ST7735S/lcd.c \
D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware/subsys/LCD_show/ST7735S/lcd_init.c 

C_DEPS += \
./subsys/LCD_show/ST7735S/ST7735_test.d \
./subsys/LCD_show/ST7735S/lcd.d \
./subsys/LCD_show/ST7735S/lcd_init.d 

OBJS += \
./subsys/LCD_show/ST7735S/ST7735_test.o \
./subsys/LCD_show/ST7735S/lcd.o \
./subsys/LCD_show/ST7735S/lcd_init.o 


# Each subdirectory must supply rules for building sources it contributes
subsys/LCD_show/ST7735S/ST7735_test.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware/subsys/LCD_show/ST7735S/ST7735_test.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DLOG -DDEBUG=1 -DCONFIG_ZTEST -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/LCD_show/ST7735S/lcd.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware/subsys/LCD_show/ST7735S/lcd.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DLOG -DDEBUG=1 -DCONFIG_ZTEST -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
subsys/LCD_show/ST7735S/lcd_init.o: D:/WorkShop/github_proj/wch/wch-wristband-master/firmware/Demo_Firmware/subsys/LCD_show/ST7735S/lcd_init.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -DCONFIG_RISCV -DLOG -DDEBUG=1 -DCONFIG_ZTEST -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\StdPeriphDriver\inc" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\HAL" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\BLE" -I"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\BLE\profile" -isystem"../../boards" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\LCD_show\GC9107" -isystem"D:\WorkShop\github_proj\wch\wch-wristband-master\firmware\Demo_Firmware\subsys\LCD_show\UGUI" -isystem"../../LIB" -isystem"../../drivers" -isystem"../../include" -isystem"../../kernel" -isystem"../../subsys" -isystem"../../soc" -isystem"../../StdPeriphDriver" -isystem"../src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

