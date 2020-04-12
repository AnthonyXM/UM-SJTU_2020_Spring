#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init module1_init(void) {
	printk(KERN_INFO "Module 1 loaded.\n");
	return 0;
}

static void __exit module1_exit(void) {
	printk(KERN_INFO "Module 1 removed.\n");
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module 1");
MODULE_AUTHOR("AnthonyXM");

module_init(module1_init);
module_exit(module1_exit);
