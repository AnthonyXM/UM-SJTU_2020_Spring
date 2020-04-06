obj-m:=hello.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd)
clean:
	rm*.o *.ko *.mod.c modules.order
