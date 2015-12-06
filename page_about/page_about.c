/*************************************************************************
	> File Name: page_about.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月04日 星期三 16时29分33秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/sched.h>
#include<linux/mm_types.h>
#include<linux/gfp.h>
#include<linux/mm.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("something about page");

static int __init page_size(void){
    
    struct page * pos;
    char *temp;


    pos = alloc_pages(GFP_KERNEL,2);
    if(NULL == pos){

        printk("alloc failed\n");
        return -1;

    }else{
        printk("First page is %p\n",pos);
        printk("The temp is %p\n",temp);
        temp = (char *)page_address(pos);
        printk("the page address is %p\n",temp);
        
    }
   
    return 0;
}

static void __exit page_size_out(void)
{
    printk("GOODBYE \n");
}

module_init(page_size);
module_exit(page_size_out);

