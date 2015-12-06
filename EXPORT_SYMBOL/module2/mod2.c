/*************************************************************************
	> File Name: mod2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月10日 星期二 17时37分23秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/list.h>
#include<linux/types.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("something about SYMOBLE");

extern int test1(void);


static int __init TEST(void){
    
    printk("i am the second mod\n");
    test1();
    return 0;
}

static void __exit TEST_out(void){
    printk("do nothing\n");
}

module_init(TEST);
module_exit(TEST_out);


