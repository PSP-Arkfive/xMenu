TARGET = XMENU
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
INCDIR = include external/include
LIBDIR = external/libs
LIBS = -lstdc++ -lpng -lmini2d -lz -lpspgu -lpspgum -lpspsystemctrl_user
LDFLAGS =
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

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
