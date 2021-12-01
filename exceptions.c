extern void PIC_sendEOI(unsigned char irq);
extern void terminal_writestring(const char* data);
#include "io.h"

void _isr_1_handler(void){
    terminal_writestring("Hi!\n");
    __asm__ volatile ("cli; hlt");
}
void _isr_0_handler(void){
    terminal_writestring("Hello!");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_2_handler(void){
    terminal_writestring("Other! 2");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_3_handler(void){
    terminal_writestring("Other! 3");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_4_handler(void){
    terminal_writestring("Other! 4");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_5_handler(void){
    terminal_writestring("Other! 5");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_6_handler(void){
    terminal_writestring("Other!6");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_7_handler(void){
    terminal_writestring("Other!7");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_8_handler(void){
    terminal_writestring("Other!8");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_9_handler(void){
    terminal_writestring("Other!9");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_10_handler(void){
    terminal_writestring("Other!a");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_11_handler(void){
    terminal_writestring("Other!b");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_12_handler(void){
    terminal_writestring("Other!c");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_13_handler(void){
    terminal_writestring("Other!d");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_14_handler(void){
    terminal_writestring("Other!e");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_15_handler(void){
    terminal_writestring("Other!f");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_16_handler(void){
    terminal_writestring("Other!g");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_17_handler(void){
    terminal_writestring("Other!h");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_18_handler(void){
    terminal_writestring("Other!i");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_19_handler(void){
    terminal_writestring("Other!j");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_20_handler(void){
    terminal_writestring("Other!k");
    __asm__ volatile ("cli; hlt"); 
}

void _isr_21_handler(void){
    terminal_writestring("Other!l");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_22_handler(void){
    terminal_writestring("Other!m");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_23_handler(void){
    terminal_writestring("Other!n");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_24_handler(void){
    terminal_writestring("Other!o");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_25_handler(void){
    terminal_writestring("Other!p");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_26_handler(void){
    terminal_writestring("Other!q");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_27_handler(void){
    terminal_writestring("Other!r");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_28_handler(void){
    terminal_writestring("Other!s");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_29_handler(void){
    terminal_writestring("Other!t");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_30_handler(void){
    terminal_writestring("Other!u");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_31_handler(void){
    terminal_writestring("Other!v");
    __asm__ volatile ("cli; hlt"); 
}

void _irq_0_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_1_handler(void){
    terminal_writestring("IRQ 1.");
}

void _irq_2_handler(void){
    terminal_writestring("IRQ 2.");
}

void _irq_3_handler(void){
    terminal_writestring("IRQ 3.");
}

void _irq_4_handler(void){
    terminal_writestring("IRQ 0.");
}


void _irq_5_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_6_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_7_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_8_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_9_handler(void){
    terminal_writestring("IRQ 0.");
}


void _irq_10_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_11_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_12_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_13_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_14_handler(void){
    terminal_writestring("IRQ 0.");
}

void _irq_15_handler(void){
    terminal_writestring("IRQ 15.");
}