# This is a Makefile to build PDCurses with the required settings.
# This build process is intended for the Windows operating system.

EXEC = libpdcurses_windows.a

# Where are the headers
INCLUDE_DIR = include
INCLUDES := -I$(INCLUDE_DIR)

# Where are the sources
SRC_DIR = src
SRCS := $(sort $(shell find $(SRC_DIR) -name '*.c'))

# IMPORTANT - Defining "PDC_WIDE" with "-D" allows PDCurses to work with emojis, special chars, etc.
DEFINES = -DPDC_WIDE

# Build object files from the sources
COMPILE_FLAGS = -c

all: objs lib clean

objs:
	$(CC) $(COMPILE_FLAGS) $(INCLUDES) $(DEFINES) $(SRCS)

lib: objs
	ar rcs $(EXEC) *.o

clean: objs
	rm *.o
