################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Users/hpi/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./iis_mcu.o" \
"./main.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-Wl,-T"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/energia/linker.cmd" \
-lmsp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main \
-lmsp432r_MSP-EXP432P401R_core \
-l:msp432p4xx_driverlib.a \
-lstdc++ \
-lgcc \
-lm \
-lnosys \
-lc \
-Wl,--end-group \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
iis_mcu.out \

EXE_OUTPUTS__QUOTED += \
"iis_mcu.out" \

BIN_OUTPUTS += \
iis_mcu.bin \

BIN_OUTPUTS__QUOTED += \
"iis_mcu.bin" \


# All Target
all: $(OBJS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "iis_mcu.out" secondary-outputs

dependents:
	-cd C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_core/Debug && $(MAKE) clean all
	-cd C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main/Debug && $(MAKE) clean all

# Tool invocations
iis_mcu.out: $(OBJS) $(GEN_CMDS) C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_core/Debug/libmsp432r_MSP-EXP432P401R_core.a C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main/Debug/libmsp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main.a
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"C:/Users/hpi/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1.exe" -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4fg.h\" -DBOARD_MSP_EXP432P401R -Dxdc__nolocalstring=1 -D__MSP432P401R__ -DCORE_VERSION=5252 -DF_CPU=48000000L -DENERGIA_MSP_EXP432P401R -DENERGIA_ARCH_MSP432R -D_DEFAULT_SOURCE -DENERGIA=23 -DARDUINO=10610 -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map,"iis_mcu.map" -nostartfiles -Wl,--gc-sections -L"C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main/Debug" -L"C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_core/Debug" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/kernel/tirtos/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/cores/msp432r" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/energia" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/kernel" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/kernel/tirtos/builds/MSP_EXP432P401R/energia/" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/kernel/tirtos/packages" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/cores/msp432r/ti/runtime/wiring/msp432" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/cores/msp432r/ti/runtime/wiring/msp432/variants/MSP_EXP432P401R" -L"C:/Users/hpi/AppData/Local/Energia15/packages/energia/hardware/msp432r/5.29.0/system/source/ti/devices/msp432p4xx/driverlib/gcc" -Wl,--undefined,main -Wl,--undefined,_printf_float -Wl,--undefined,_scanf_float -Os -specs=nano.specs -specs=rdimon.specs -specs=nosys.specs -Wl,--check-sections -o"iis_mcu.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

iis_mcu.bin: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: GNU Objcopy Utility'
	"C:/Users/hpi/AppData/Local/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/bin/arm-none-eabi-objcopy.exe" -O binary $(EXE_OUTPUTS__QUOTED) "iis_mcu.bin"
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "iis_mcu.o" "main.o" 
	-$(RM) "iis_mcu.d" "main.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:
C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_core/Debug/libmsp432r_MSP-EXP432P401R_core.a:
C:/Users/hpi/workspace_v11/msp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main/Debug/libmsp432r_MSP-EXP432P401R_PDLS_EXT3_Basic-main.a:

-include ../makefile.targets

