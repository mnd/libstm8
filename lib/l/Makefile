CC=sdcc
LD=sdld
CFLAGS += -I../../include
OBJECTS = gpio.rel clk.rel usart.rel lcd.rel adc.rel tim.rel dma.rel

.PHNOY: all clean

all: $(OBJECTS)
	sdcclib ../stm8.lib $(OBJECTS)

%.rel: %.c
	$(CC) -mstm8 $(CFLAGS) -c $<

clean:
	rm -f *~ *.asm *.cdb *.lk *.lst *.map *.rel *.rst *.sym
