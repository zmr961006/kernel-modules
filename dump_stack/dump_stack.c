/*************************************************************************
	> File Name: dump_stack.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 12时45分59秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/init.h>
#include<linux/kprobes.h>
#include<asm/traps.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("dump_stack");

static int __init test(void){
    
    printk("look this \n");
    dump_stack();
    printk("look down \n");

    return 0;
}

static void __exit test_out(void){
    
    printk("byby\n");

}

module_init(test);
module_exit(test_out);

