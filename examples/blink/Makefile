CC=sdcc
LD=sdld
CFLAGS += -I../../include
LDFLAGS += -L../../lib/ -lstm8-extended
OBJECTS=blink.ihx

.PHONY: all clean flash

all: $(OBJECTS)

clean:
	rm -f *~ *.asm *.cdb *.lk *.lst *.map *.rel *.rst *.sym
distclean: clean
	rm -f $(OBJECTS)

flash: $(OBJECT).ihx
	stm8flash -cstlink -pstm8l150 -w $(OBJECT).ihx

%.ihx: %.c
	$(CC) -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $<
