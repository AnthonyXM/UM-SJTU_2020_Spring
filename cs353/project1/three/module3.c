#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

int len, temp;
char* msg;

static ssize_t module3_proc_open(struct file* file, char __user* buffer, size_t count,loff_t* f_pos) {
	if(count > temp)
		count = temp;
	temp = temp - count;
	copy_to_user(buffer, msg, count);
	if(count==0)
		temp = len;
	return count;
}

static const struct file_operations module3_proc_fops = {
	.read = module3_proc_open
};

static int __init module3_init(void) {
	struct proc_dir_entry* entry;
	entry = proc_create("module3", 0444, NULL, &module3_proc_fops);
	if(!entry) {
		printk(KERN_INFO "Cannot create file!\n");
		return -1;
	}
	msg = "This is the read-only text in module3.\n";
	len = strlen(msg);
	temp = len;
	printk(KERN_INFO "Module 3 loaded.\n");
	return 0;
}

static void __exit module3_exit(void) {
	remove_proc_entry("module3", NULL);
	printk(KERN_INFO "Module 3 removed.\n");
}

MODULE_LICENSE("GPL");
module_init(module3_init);
module_exit(module3_exit);