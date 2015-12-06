/*************************************************************************
	> File Name: slab_creat.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月09日 星期一 18时58分36秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/slab.h>
#include<linux/mm.h>
#include<linux/gfp.h>
#include<linux/mm_types.h>
#include<linux/list.h>
#include<linux/types.h>
#include<linux/sched.h>
#include<linux/test.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("something about slab_create");


static struct kmem_cache *test;

static int __init slab_create(void){
    struct TEST *pos;
    struct TEST *temp;
    struct TEST *p;

    
    printk("\n\n");
    test = kmem_cache_create("TEST",sizeof(struct TEST),8,SLAB_RED_ZONE,((void *) 0));
    if(!test){
        printk("create failed ");
        return -1;
    }else{
        printk("I create a kmem_cache is ok ,i feel good\n");
    }
    printk("create a test slab of test\n");


    pos = kmem_cache_alloc(test,GFP_KERNEL);
    if(NULL == pos){
        printk("alloc new slab is failed\n");
        return -1;
    }else{
        printk("create pos is ok\n");
        printk("pos :%p\n",pos);
    }
    temp = kmem_cache_alloc(test,GFP_KERNEL);
    if(NULL == temp){
        printk("alloc new slab is failed\n");
        return -1;
    }else{
        printk("create temp is ok \n");
        printk("temp :%p\n",temp);
    }
    p = kmem_cache_alloc(test,GFP_KERNEL);
    if(NULL == p){
        printk("alloc new slab is failed\n");
        return -1;
    }else{
        printk("create temp is ok\n");
        printk("p :%p\n",p);
    }

 
    printk("betewn size is %ld\n",(temp-pos));
    
    
    kmem_cache_free(test,pos);
    kmem_cache_free(test,temp);
    
    return 0;
}

static void __exit slab_out(void){
 
    printk("BYBY :)\n");

}

module_init(slab_create);
module_exit(slab_out);



