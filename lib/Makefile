all: gpio.c
	sdcc -mstm8 -I../include -c ./gpio.c
	sdcc -mstm8 -I../include -c ./clk.c
	sdcc -mstm8 -I../include -c ./usart.c
	sdcc -mstm8 -I../include -c ./lcd.c
	sdcclib stm8.lib gpio.rel clk.rel usart.rel lcd.rel

clean:
	rm -f *~ *.asm *.cdb *.lk *.lst *.map *.rel *.rst *.sym
