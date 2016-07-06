################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include header/IRremote/examples/JVCPanasonicSendDemo/subdir.mk
-include header/IRremote/examples/IRtest2/subdir.mk
-include header/IRremote/examples/IRtest/subdir.mk
-include header/IRremote/examples/IRsendDemo/subdir.mk
-include header/IRremote/examples/IRrelay/subdir.mk
-include header/IRremote/examples/IRrecvDump/subdir.mk
-include header/IRremote/examples/IRrecvDemo/subdir.mk
-include header/IRremote/examples/IRrecord/subdir.mk
-include header/IRremote/subdir.mk
-include arduino/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
Radar.elf \

EEP += \
Radar.eep \

FLASH_IMAGE += \
Radar.hex \


# All Target
all: Radar

# Tool invocations
Radar: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"D:\BDSoftMgrData\arduino\arduino-1.6.5-r5\hardware\tools\avr/bin/avr-size" -A "D:/workspace/Radar/Release/Radar.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"D:\BDSoftMgrData\arduino\arduino-1.6.5-r5\hardware\tools\avr/bin/avr-ar" rcs  "D:/workspace/Radar/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

Radar.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"D:\BDSoftMgrData\arduino\arduino-1.6.5-r5\hardware\tools\avr/bin/avr-gcc" -Os -Wl,--gc-sections -mmcu=atmega328p  -o "D:/workspace/Radar/Release/Radar.elf"   $(LINK_OBJ) $(AR)  "D:/workspace/Radar/Release/arduino.ar" "-LD:/workspace/Radar/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

Radar.eep: $(ELF)
	@echo 'Create eeprom image'
	"D:\BDSoftMgrData\arduino\arduino-1.6.5-r5\hardware\tools\avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "D:/workspace/Radar/Release/Radar.elf" "D:/workspace/Radar/Release/Radar.eep"
	@echo 'Finished building: $@'
	@echo ' '

Radar.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"D:\BDSoftMgrData\arduino\arduino-1.6.5-r5\hardware\tools\avr/bin/avr-objcopy" -O ihex -R .eeprom  "D:/workspace/Radar/Release/Radar.elf" "D:/workspace/Radar/Release/Radar.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) Radar
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
