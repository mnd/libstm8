CC=sdcc
LD=sdld
CFLAGS += -I../../include
LDFLAGS += -L../../lib/ -lstm8.lib
OBJECTS=lcd.ihx

.PHONY: all clean flash distclean

all: $(OBJECTS)

distclean:
	rm -f *~ *.asm *.cdb *.lk *.lst *.map *.rel *.rst *.sym

clean: distclean
	rm -f $(OBJECTS)

flash: $(OBJECT).ihx
	stm8flash -cstlink -pstm8l150 -w $(OBJECT).ihx

%.ihx: %.c
	$(CC) -lstm8 -mstm8 --std-sdcc99 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $<
