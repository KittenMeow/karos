#include <stdint.h>
#include <stddef.h>
extern void PIC_sendEOI(unsigned char irq);
extern uint8_t keyboard_to_ascii(uint8_t key);
extern void terminal_writestring(const char* data);
extern size_t strlen(const char* str); 
#include "io.h"
#include "itos.h"

unsigned char kbdus[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};		

void _isr_0_handler(void){
    terminal_writestring("Hello!");
    __asm__ volatile ("iret"); 
}

void _isr_1_handler(void){
    terminal_writestring("Hi!\n");
    __asm__ volatile ("iret");
}

void _isr_2_handler(void){
    terminal_writestring("Other! 2");
   __asm__ volatile ("iret");
}

void _isr_3_handler(void){
    terminal_writestring("Other! 3");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_4_handler(void){
    terminal_writestring("Other! 4");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_5_handler(void){
    terminal_writestring("Other! 5");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_6_handler(void){
    terminal_writestring("Other!6");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_7_handler(void){
    terminal_writestring("Other!7");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_8_handler(void){
    terminal_writestring("Other!8");
    __asm__ volatile ("cli; hlt"); 
}
void _isr_9_handler(void){
    terminal_writestring("Other!9");
    //__asm__ volatile ("cli; hlt"); 
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
    //__asm__ volatile ("cli; hlt");  
}

void _isr_16_handler(void){
    terminal_writestring("Other!g");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_17_handler(void){
    terminal_writestring("Other!h");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_18_handler(void){
    terminal_writestring("Other!i");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_19_handler(void){
    terminal_writestring("Other!j");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_20_handler(void){
    terminal_writestring("Other!k");
    //__asm__ volatile ("cli; hlt"); 
}

void _isr_21_handler(void){
    terminal_writestring("Other!l");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_22_handler(void){
    terminal_writestring("Other!m");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_23_handler(void){
    terminal_writestring("Other!n");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_24_handler(void){
    terminal_writestring("Other!o");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_25_handler(void){
    terminal_writestring("Other!p");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_26_handler(void){
    terminal_writestring("Other!q");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_27_handler(void){
    terminal_writestring("Other!r");
    //__asm__ volatile ("cli; hlt"); 
}
void _isr_28_handler(void){
    terminal_writestring("Other!s");
    //__asm__ volatile ("cli; hlt");
}
void _isr_29_handler(void){
    terminal_writestring("Other!t");
    //__asm__ volatile ("cli; hlt");
}
void _isr_30_handler(void){
    terminal_writestring("Other!u");
    //__asm__ volatile ("cli; hlt");
}
void _isr_31_handler(void){
    terminal_writestring("Other!v");
    //__asm__ volatile ("cli; hlt");
}

void _irq_0_handler(void){
    //terminal_writestring("IRQ 0.");
    PIC_sendEOI(0);
}

void _irq_1_handler(void){
    unsigned char scancode;
    /* Read from the keyboard's data buffer */
    scancode = inb(0x60);
    

    /* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if (scancode & 0x80)
    {
        /* You can use this one to see if the user released the
        *  shift, alt, or control keys... */
    }
    else
    {
        /* Here, a key was just pressed. Please note that if you
        *  hold a key down, you will get repeated key press
        *  interrupts. */

        /* Just to show you how this works, we simply translate
        *  the keyboard scancode into an ASCII value, and then
        *  display it to the screen. You can get creative and
        *  use some flags to see if a shift is pressed and use a
        *  different layout, or you can add another 128 entries
        *  to the above layout to correspond to 'shift' being
        *  held. If shift is held using the larger lookup table,
        *  you would add 128 to the scancode when you look for it */
        if ((kbdus[scancode] == 0) | (kbdus[scancode] == 27)){
            
        }
        else{
            terminal_putchar(kbdus[scancode]);
        }

    }
    PIC_sendEOI(1);

}
void _irq_2_handler(void){
    terminal_writestring("IRQ 2.");
    PIC_sendEOI(2);
}

void _irq_3_handler(void){
    terminal_writestring("IRQ 3.");
    PIC_sendEOI(3);
}

void _irq_4_handler(void){
    terminal_writestring("IRQ 4.");
}


void _irq_5_handler(void){
    terminal_writestring("IRQ 5.");
}

void _irq_6_handler(void){
    terminal_writestring("IRQ 6.");
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