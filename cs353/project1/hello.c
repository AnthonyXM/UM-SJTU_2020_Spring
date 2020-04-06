#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int init_hello_module(void) {
	printk("init_hello_module\n");
	return0;
}

void exit_hello_module(void) {
	printk("exit_hello_module\n");
}

MODULE_LICENSE("GPL");
module_init(init_hello_module);
module_exit(exit_hello_module);
