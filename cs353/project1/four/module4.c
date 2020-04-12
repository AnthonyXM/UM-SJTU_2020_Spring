#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

#include <linux/seq_file.h>
#include <linux/slab.h> // for kzalloc and kfree
#include <linux/uaccess.h> //for copy_from_user
#include <linux/sched.h>

static char *str = NULL;
 
static int module4_proc_show(struct seq_file *m, void *v) {
    seq_printf(m, "Currently written: %s\n", str);
    return 0;
}

static ssize_t module4_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *f_pos) {
    char *temp = kzalloc((count+1), GFP_KERNEL);
    if(!temp) return -1;
    if(copy_from_user(temp, buffer, count)) {
        kfree(temp);
        return EFAULT;
    }
    kfree(str);
    str = temp;
    return count;
}
 
static int module4_proc_open(struct inode *inode, struct file *file) {
    return single_open(file, module4_proc_show, NULL);
}

static struct file_operations module4_fops = {
    .open    = module4_proc_open,
	.read    = seq_read,
	.write   = module4_proc_write,
    .release = single_release,
    .llseek  = seq_lseek,
};
 
static int __init module4_init(void) {
	struct proc_dir_entry* module4_dir = proc_mkdir("module4_dir", NULL);
    struct proc_dir_entry* entry;
    entry = proc_create("module4", 0666, module4_dir, &module4_fops);
    if(!entry) {
		printk(KERN_INFO "Cannot create file!\n");
		return -1;
	}
	printk(KERN_INFO "Module 4 loaded.\n");
    return 0;
}
 
static void __exit module4_exit(void)
{
    remove_proc_entry("module4", NULL);
    kfree(str);
	printk(KERN_INFO "Module 4 removed.\n");
}

MODULE_LICENSE("GPL"); 
module_init(module4_init);
module_exit(module4_exit);