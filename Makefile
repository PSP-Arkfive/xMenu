PSPSDK=$(shell psp-config --pspsdk-path)
ARKSDK ?= ../ark-dev-sdk

TARGET = XMENU
CFLAGS = -O2 -g0 -Wall -static
CXXFLAGS = $(CFLAGS) -fno-exceptions
ASFLAGS = $(CFLAGS)
INCDIR = include $(ARKSDK)/include
LIBDIR = $(ARKSDK)/libs
LIBS = -lmini2d -lpng -lz -lpspgu -lpspgum -lstdc++ -lpspsystemctrl_user
LDFLAGS = #-Tlinkfile.static -Wl,--gc-sections
EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = xMenu
PSP_EBOOT_ICON = resources/ICON0.PNG
PSP_EBOOT_PIC1 = resources/PIC1.PNG

OBJS = \
		main.o \
		src/debug.o \
		src/common.o \
		src/submenu.o \
		src/menu.o \
		src/entry.o \
		src/controller.o \
		src/text.o


all: $(TARGET).prx

include $(PSPSDK)/lib/build.mak
