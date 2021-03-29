include ../../py/mkenv.mk

CROSS_COMPILE ?= arm-none-eabi-

BOARD ?= tomato
BOARD_DIR ?= boards/$(BOARD)

include ../../py/mkenv.mk
include $(BOARD_DIR)/mpconfigboard.mk

# Qstr definitions (must come before including py.mk)
QSTR_DEFS = qstrdefsport.h

# MicroPython feature configurations
MICROPY_ROM_TEXT_COMPRESSION ?= 1

# Include py core make definitions
include $(TOP)/py/py.mk

GIT_SUBMODULES = lib/nuc970_bsp

INC += -I.
INC += -I$(TOP)
INC += -I$(BUILD)
INC += -I$(BOARD_DIR)

# NUC970 paths
INC += -I../../lib/nuc970_bsp/Driver/Include



CFLAGS  = -mcpu=arm926ej-s -marm -mlittle-endian -mfloat-abi=soft -fmessage-length=0 -fsigned-char -g3 -std=gnu11 -nostdlib -MMD -MP -c  $(INC)
LDFLAGS = -nostdlib $(addprefix -T,../../lib/nuc970_bsp/Driver/Source/GCC.ld) -Map=$@.map --cref
LIBS    = $(shell $(CC) $(CFLAGS) -print-libgcc-file-name)

# Tune for Debugging or Optimization
ifeq ($(DEBUG),1)
CFLAGS += -O0 -ggdb
else
CFLAGS  += -Os -DNDEBUG
LDFLAGS += --gc-sections
CFLAGS  += -fdata-sections -ffunction-sections
endif


SRC_ASM = \
	../../lib/nuc970_bsp/Driver/Source/Startup_GCC.S    \
	../../lib/nuc970_bsp/Driver/Source/startup_NUC970.s \
	../../lib/nuc970_bsp/Driver/Source/sys_nuc970.S     \

ASM_FLAGS   = -mcpu=arm926ej-s -marm -mlittle-endian -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -ggdb -x assembler-with-cpp
ASM_COMPILE = arm-none-eabi-gcc

%.o: %.S
	$(ASM_COMPILE) $(ASM_FLAGS) -MT"$(@).o" -c -o "$@" "$<"

# Each subdirectory must supply rules for building sources it contributes
Startup_GCC.o: ../../lib/nuc970_bsp/Driver/Source/Startup_GCC.S
	$(ASM_COMPILE) $(ASM_FLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

# Each subdirectory must supply rules for building sources it contributes
startup_NUC970.o: ../../lib/nuc970_bsp/Driver/Source/startup_NUC970.s
	$(ASM_COMPILE) $(ASM_FLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

# Each subdirectory must supply rules for building sources it contributes
sys_nuc970.o: ../../lib/nuc970_bsp/Driver/Source/sys_nuc970.S
	$(ASM_COMPILE) $(ASM_FLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"


SRC_C = \
	main.c      \
	uart_core.c \

# Build all the drivers, because YOLO
SRC_C += \
	../../lib/nuc970_bsp/Driver/Source/2d.c            \
	../../lib/nuc970_bsp/Driver/Source/jpegcodec.c     \
	../../lib/nuc970_bsp/Driver/Source/sys.c           \
	../../lib/nuc970_bsp/Driver/Source/adc.c           \
	../../lib/nuc970_bsp/Driver/Source/lcd.c           \
	../../lib/nuc970_bsp/Driver/Source/sys_ebi.c       \
	../../lib/nuc970_bsp/Driver/Source/can.c           \
	../../lib/nuc970_bsp/Driver/Source/mtp.c           \
	../../lib/nuc970_bsp/Driver/Source/system_nuc970.c \
	../../lib/nuc970_bsp/Driver/Source/cap.c           \
	../../lib/nuc970_bsp/Driver/Source/pwm.c           \
	../../lib/nuc970_bsp/Driver/Source/sys_timer.c     \
	../../lib/nuc970_bsp/Driver/Source/crypto.c        \
	../../lib/nuc970_bsp/Driver/Source/rtc.c           \
	../../lib/nuc970_bsp/Driver/Source/sys_uart.c      \
	../../lib/nuc970_bsp/Driver/Source/etimer.c        \
	../../lib/nuc970_bsp/Driver/Source/sc.c            \
	../../lib/nuc970_bsp/Driver/Source/uart.c          \
	../../lib/nuc970_bsp/Driver/Source/fmi.c           \
	../../lib/nuc970_bsp/Driver/Source/scuart.c        \
	../../lib/nuc970_bsp/Driver/Source/usbd.c          \
	../../lib/nuc970_bsp/Driver/Source/gpio.c          \
	../../lib/nuc970_bsp/Driver/Source/sdh.c           \
	../../lib/nuc970_bsp/Driver/Source/wwdt.c          \
	../../lib/nuc970_bsp/Driver/Source/i2c.c           \
	../../lib/nuc970_bsp/Driver/Source/spi.c           \
	../../lib/nuc970_bsp/Driver/Source/i2s.c           \


# Provde stdlib stuff:
SRC_C += lib/libc/string0.c

# More mpy bits
SRC_C += \
	lib/utils/printf.c          \
	lib/utils/stdout_helpers.c  \
	lib/utils/pyexec.c          \
	lib/mp-readline/readline.c  \


# 	$(BUILD)/_frozen_mpy.c \
# 	modutime.c \
# 	modmachine.c \
# 	mphalport.c \
# 	samd_isr.c \
# 	samd_soc.c \
# 	tusb_port.c \
# 	lib/libc/string0.c \
# 	lib/libm/ef_sqrt.c \
# 	lib/libm/fmodf.c \
# 	lib/libm/math.c \
# 	lib/libm/nearbyintf.c \
# 	lib/mp-readline/readline.c \
# 	lib/tinyusb/src/class/cdc/cdc_device.c \
# 	lib/tinyusb/src/common/tusb_fifo.c \
# 	lib/tinyusb/src/device/usbd.c \
# 	lib/tinyusb/src/device/usbd_control.c \
# 	lib/tinyusb/src/portable/microchip/samd/dcd_samd.c \
# 	lib/tinyusb/src/tusb.c \
# 	lib/utils/gchelper_native.c \
# 	lib/utils/printf.c \
# 	lib/utils/pyexec.c \
# 	lib/utils/stdout_helpers.c \


# List of sources for qstr extraction
# SRC_QSTR += modutime.c modmachine.c

OBJ += $(PY_CORE_O)
OBJ += $(addprefix $(BUILD)/, $(SRC_C:.c=.o))

all: $(BUILD)/firmware.bin


$(BUILD)/firmware.elf: $(OBJ) Startup_GCC.o

	$(ECHO) "LINK $@"
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

$(BUILD)/firmware.bin: $(BUILD)/firmware.elf
	$(Q)$(OBJCOPY) -O binary $^ $(BUILD)/firmware.bin

$(BUILD)/firmware.uf2: $(BUILD)/firmware.bin
	$(Q)$(PYTHON) $(UF2CONV) -b $(TEXT0) -c -o $@ $<

include $(TOP)/py/mkrules.mk


