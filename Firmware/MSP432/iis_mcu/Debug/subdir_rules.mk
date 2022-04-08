################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-227413873:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-227413873-inproc

build-227413873-inproc: ../iis_mcu.ino
	@echo 'Building file: "$<"'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: "$<"'
	@echo ' '

iis_mcu.cpp: build-227413873 ../iis_mcu.ino
main.cpp: build-227413873

%.o: ./%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/Users/hpi/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4fg.h\" -DBOARD_MSP_EXP432P401R -Dxdc__nolocalstring=1 -D__MSP432P401R__ -DCORE_VERSION=5252 -DF_CPU=48000000L -DENERGIA_MSP_EXP432P401R -DENERGIA_ARCH_MSP432R -D_DEFAULT_SOURCE -DENERGIA=23 -DARDUINO=10610 -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/cores/msp432r/ti/runtime/wiring/" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/cores/msp432r/ti/runtime/wiring/msp432" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/kernel/tirtos/packages/ti/sysbios/posix" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/kernel/tirtos/packages" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/energia" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source/ti/devices/msp432p4xx/driverlib" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source/ti/devices/msp432p4xx/inc" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source/ti/devices/msp432p4xx/" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source/third_party/CMSIS/Include" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/cores/msp432r" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/variants/MSP_EXP432P401R" -I"C:/Users/hpi/workspace_v11/iis_mcu" -I"C:/Energia/energia-1.8.10E23/libraries/PDLS_EXT3_Basic-main/src" -I"C:/Users/hpi/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/arm-none-eabi/include" -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  -fno-rtti -fno-threadsafe-statics -fno-exceptions $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


