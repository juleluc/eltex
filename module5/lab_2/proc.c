#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
 
#define SIZE_MESSAGE 10
#define PROC_MODE 0
static int len, temp;
static char *msg;

 
ssize_t read_proc(struct file *filp, char *buf, size_t count, loff_t *offp ) {
    ssize_t rv = 0;
    if(count > temp) {
        count = temp;
    }
    temp = temp - count;
    if(copy_to_user(buf, msg, count)){
        rv = -EFAULT;
    }
    if(count == 0)
        temp = len;
    rv = count;    
    return rv;
}
 
ssize_t write_proc(struct file *filp, const char *buf, size_t count, loff_t *offp) {
    ssize_t rv = 0;
    if(copy_from_user(msg, buf, count)){
        rv = -EFAULT;
    }
    len = count;
    temp = len;
    rv = count;
    return rv;
}
 
static const struct proc_ops proc_fops = {
    proc_read: read_proc,
    proc_write: write_proc,
};
 
void create_new_proc_entry(void) { //use of void for no arguments is compulsory now
    proc_create("wocao", PROC_MODE, NULL, &proc_fops);
    msg = kmalloc(SIZE_MESSAGE * sizeof(char), GFP_KERNEL);
}
 
int proc_init (void) {
    create_new_proc_entry();
    return 0;
}
 
void proc_cleanup(void) {
    remove_proc_entry("wocao", NULL);
    kfree(msg);
}
 
MODULE_LICENSE("Rivers of blood");
MODULE_AUTHOR("Turtugeshev");
module_init(proc_init);
module_exit(proc_cleanup);