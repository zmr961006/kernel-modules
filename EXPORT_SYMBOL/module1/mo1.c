/*************************************************************************
	> File Name: mo1.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月10日 星期二 17时27分05秒
 ************************************************************************/


#include<linux/module.h>
#include<linux/slab.h>
#include<linux/mm.h>
#include<linux/list.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("some thing about EXPORT_SYMBOLY");

static int test1(void){
    printk("HI i am in test1\n");
    return 0;
}
EXPORT_SYMBOL(test1);

static int __init test_module(void){
    printk("i am the first module\n");
    test1();
    return 0;
}


static void __exit test_out(void){
    printk("module1 is goon\n");
}

module_init(test_module);
module_exit(test_out);

