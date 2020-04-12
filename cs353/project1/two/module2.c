#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

static int int_param;
module_param(int_param, int, 0644);

static char* char_param;
module_param(char_param, charp, 0644);

static int array_param[10];
static int array_length;
module_param_array(array_param, int, &array_length, 0644);

static int __init module2_init(void) {
	int i = 0;
	printk(KERN_INFO "Module 2 loaded.\n");
	printk(KERN_INFO "Int param: %d.\n", int_param);
	printk(KERN_INFO "Char param: %s.\n", char_param);
	for(i = 0; i < array_length; i++) {
		printk(KERN_INFO "Array[%d] = %d.\n", i, array_param[i]);
	}
	return 0;
}

static void __exit module2_exit(void) {
	printk(KERN_INFO "Module 2 removed.\n");
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module 2");
MODULE_AUTHOR("AnthonyXM");

module_init(module2_init);
module_exit(module2_exit);
