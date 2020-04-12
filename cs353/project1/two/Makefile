obj-m:=module2.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd)
clean:
	rm *.o *.ko *.mod.c Module.symvers modules.order -f
