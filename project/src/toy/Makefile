#makefile configuration
COMMON_ONJECTS =
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC	       = msp430-elf-gcc
AS             = msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o WDInterruptHandler.o led.o switches.o buzzer.o main.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


load: main.elf
	msp430loader.sh main.elf


clean:
	rm -f *.o *.elf
