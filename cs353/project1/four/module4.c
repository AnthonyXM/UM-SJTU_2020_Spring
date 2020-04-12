#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/slab.h>

int len, temp;
char* msg;

static ssize_t module4_proc_open(struct file *filp,char __user *buf,size_t count,loff_t *offp ) 
{
	if(count > temp)
		count = temp;
	temp = temp - count;
	raw_copy_to_user(buf,msg, count);
	if(count==0)
		temp = len;
	return count;
}

static ssize_t module4_proc_write(struct file *filp,const char __user *buf,size_t count,loff_t *offp ) {
	char *tmp = kzalloc((count+1), GFP_KERNEL);
	if(!tmp)
		return -ENOMEM;
	if(raw_copy_from_user(tmp, buf, count))
	{
		kfree(tmp);
		return EFAULT;
	}
	kfree(msg);
	msg = tmp;
	return count;
}

static const struct file_operations module4_proc_fops = {
	.read = module4_proc_open,
	.write = module4_proc_write
};

static int __init module4_proc_init(void) {
	struct proc_dir_entry* entry;
	entry = proc_create("module4", 0666, NULL, &module4_proc_fops);
	if(!entry) return -1;
	else {
		msg = "123\n";
		len = strlen(msg);
		temp = len;
		printk(KERN_INFO "Module 4 loaded.\n");
		return 0;
	}
}

static void __exit module4_proc_exit(void) {
	remove_proc_entry("module4", NULL);
	printk(KERN_INFO "Module 4 removed.\n");
}

MODULE_LICENSE("GPL");
module_init(module4_proc_init);
module_exit(module4_proc_exit);
