all: gpio.c
	sdcc -mstm8 -I../include -c ./gpio.c
	sdcc -mstm8 -I../include -c ./clk.c
	sdcclib libstm8-extended.lib gpio.rel clk.rel
