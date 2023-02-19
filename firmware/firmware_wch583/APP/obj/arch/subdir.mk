################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/arch/startup_CH583.S 

OBJS += \
./arch/startup_CH583.o 

S_UPPER_DEPS += \
./arch/startup_CH583.d 


# Each subdirectory must supply rules for building sources it contributes
arch/startup_CH583.o: D:/WorkShop/PROJ/MagicButton/2.0/github/MagiClick/firmware/firmware_wch583/arch/startup_CH583.S
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common  -g -x assembler -I"../../ach" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

