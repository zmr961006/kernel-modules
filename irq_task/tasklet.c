/*************************************************************************
	> File Name: tasklet.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月30日 星期一 20时01分22秒
 ************************************************************************/

#include<linux/module.h>
#include<linux/init.h>
#include<linux/interrupt.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("zmrlinux");
MODULE_DESCRIPTION("tasklet");

unsigned long dev = 1;
void my_tasklet_handler(unsigned long data);

//DECLARE_TASKLET(my_tasklet,my_tasklet_handler,dev);

void my_tasklet_handler(unsigned long data){
    int i = 10;
    while(i > 0){
        printk("hello   world\n");
        i--;
    }
}


 struct tasklet_struct my_tasklet;
static int __init test_task(void){

    //struct tasklet_struct my_tasklet;
    tasklet_init(&my_tasklet,my_tasklet_handler,dev);
    tasklet_schedule(&my_tasklet);
    printk("hello world\n");
    return 0;
}

static void __exit test_out(void){
    printk("ByBy\n");
}

module_init(test_task);
module_exit(test_out);
