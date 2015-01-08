all: gpio.c
	sdcc -mstm8 -I../include -c ./gpio.c
	sdcc -mstm8 -I../include -c ./clk.c
	sdcclib stm8.lib gpio.rel clk.rel
