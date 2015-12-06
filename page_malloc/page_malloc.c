/*************************************************************************
	> File Name: page_malloc.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月06日 星期五 18时01分44秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/mm_types.h>
#include<linux/gfp.h>
#include<linux/mm.h>
#include<linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("something about kmalloc");

static int __init KMALLOC(void){
    char *temp;
    printk("I want to malloc \n");
    temp = (char *)kmalloc(sizeof(char) * 100,GFP_KERNEL);
    if(NULL == temp){
        printk("ERROR:alloc failed\n");
        return -1;
    }else{
        printk("I malloc is OK\n");
    }
    kfree(temp);
    return 0;
}

static void __exit KMALLOC_out(void){

    printk("GOODBYE \n");

}

module_init(KMALLOC);
module_exit(KMALLOC_out);

