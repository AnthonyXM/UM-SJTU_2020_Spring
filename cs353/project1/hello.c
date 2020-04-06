#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init hello_init(void) {
	printk(KERN_INFO "init_hello_module\n");
	return 0;
}

static void __exit hello_exit(void) {
	printk(KERN_INFO "exit_hello_module\n");
}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);
