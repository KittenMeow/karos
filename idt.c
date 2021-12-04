#include <stdint.h>
#include <stdbool.h>

extern void _isr0(void);
extern void _isr1(void);
extern void _isr2(void);
extern void _isr3(void);
extern void _isr4(void);
extern void _isr5(void);
extern void _isr6(void);
extern void _isr7(void);
extern void _isr8(void);
extern void _isr9(void);
extern void _isr10(void);
extern void _isr11(void);
extern void _isr12(void);
extern void _isr13(void);
extern void _isr14(void);
extern void _isr15(void);
extern void _isr16(void);
extern void _isr17(void);
extern void _isr18(void);
extern void _isr19(void);
extern void _isr20(void);
extern void _isr21(void);
extern void _isr22(void);
extern void _isr23(void);
extern void _isr24(void);
extern void _isr25(void);
extern void _isr26(void);
extern void _isr27(void);
extern void _isr28(void);
extern void _isr29(void);
extern void _isr30(void);
extern void _isr31(void);

extern void _irq0(void);
extern void _irq1(void);
extern void _irq2(void);
extern void _irq3(void);
extern void _irq4(void);
extern void _irq5(void);
extern void _irq6(void);
extern void _irq7(void);
extern void _irq8(void);
extern void _irq9(void);
extern void _irq10(void);
extern void _irq11(void);
extern void _irq12(void);
extern void _irq13(void);
extern void _irq14(void);
extern void _irq15(void);

typedef struct {
	uint16_t    isr_low;      // The lower 16 bits of the ISR's address
	uint16_t    kernel_cs;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t     reserved;     // Set to zero
	uint8_t     attributes;   // Type and attributes; see the IDT page
	uint16_t    isr_high;     // The higher 16 bits of the ISR's address
} __attribute__((packed)) idt_entry_t;

typedef struct {
	uint16_t	limit;
	uint32_t	base;
} __attribute__((packed)) idtr_t;

static idt_entry_t idt[256]; // Create an array of IDT entries; aligned for performance
static idtr_t idtr;

void idt_set_gate(uint8_t vector, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[vector].isr_low = (base & 0xFFFF);
    idt[vector].isr_high = (base >> 16) & 0xFFFF;
    idt[vector].kernel_cs = sel;
    idt[vector].reserved = 0;
    idt[vector].attributes = flags | 0x60;
}
void idt_init() {
    idtr.base = (uintptr_t)&idt[0];
    idtr.limit = (uint16_t)sizeof(idt_entry_t) * 256 - 1;
    
    idt_set_gate(0,  _isr0,  0x08, 0x8E);
	idt_set_gate(1,  _isr1,  0x08, 0x8E);
	idt_set_gate(2,  _isr2,  0x08, 0x8E);
	idt_set_gate(3,  _isr3,  0x08, 0x8E);
 	idt_set_gate(4,  _isr4,  0x08, 0x8E);
	idt_set_gate(5,  _isr5,  0x08, 0x8E);
	idt_set_gate(6,  _isr6,  0x08, 0x8E);
	idt_set_gate(7,  _isr7,  0x08, 0x8E);
	idt_set_gate(8,  _isr8,  0x08, 0x8E);
	idt_set_gate(9,  _isr9,  0x08, 0x8E);
	idt_set_gate(10, _isr10, 0x08, 0x8E);
	idt_set_gate(11, _isr11, 0x08, 0x8E);
	idt_set_gate(12, _isr12, 0x08, 0x8E);
	idt_set_gate(13, _isr13, 0x08, 0x8E);
	idt_set_gate(14, _isr14, 0x08, 0x8E);
	idt_set_gate(15, _isr15, 0x08, 0x8E);
	idt_set_gate(16, _isr16, 0x08, 0x8E);
	idt_set_gate(17, _isr17, 0x08, 0x8E);
	idt_set_gate(18, _isr18, 0x08, 0x8E);
	idt_set_gate(19, _isr19, 0x08, 0x8E);
	idt_set_gate(20, _isr20, 0x08, 0x8E);
	idt_set_gate(21, _isr21, 0x08, 0x8E);
	idt_set_gate(22, _isr22, 0x08, 0x8E);
	idt_set_gate(23, _isr23, 0x08, 0x8E);
	idt_set_gate(24, _isr24, 0x08, 0x8E);
	idt_set_gate(25, _isr25, 0x08, 0x8E);
	idt_set_gate(26, _isr26, 0x08, 0x8E);
	idt_set_gate(27, _isr27, 0x08, 0x8E);
	idt_set_gate(28, _isr28, 0x08, 0x8E);
	idt_set_gate(29, _isr29, 0x08, 0x8E);
	idt_set_gate(30, _isr30, 0x08, 0x8E);
	idt_set_gate(31, _isr31, 0x08, 0x8E); 
	idt_set_gate(32, _irq0,  0x08, 0x8E);
    idt_set_gate(33, _irq1,  0x08, 0x8E);
	idt_set_gate(34, _irq2,  0x08, 0x8E);
	idt_set_gate(35, _irq3,  0x08, 0x8E);
 	idt_set_gate(36, _irq4,  0x08, 0x8E);
	idt_set_gate(37, _irq5,  0x08, 0x8E);
	idt_set_gate(38, _irq6,  0x08, 0x8E);
	idt_set_gate(39, _irq7,  0x08, 0x8E);
	idt_set_gate(40, _irq8,  0x08, 0x8E);
	idt_set_gate(41, _irq9,  0x08, 0x8E);
	idt_set_gate(42, _irq10, 0x08, 0x8E);
	idt_set_gate(43, _irq11, 0x08, 0x8E);
	idt_set_gate(44, _irq12, 0x08, 0x8E);
	idt_set_gate(45, _irq13, 0x08, 0x8E);
	idt_set_gate(46, _irq14, 0x08, 0x8E);
	idt_set_gate(47, _irq15, 0x08, 0x8E); 

    __asm__ volatile ("lidt %0" : : "m"(idtr)); // load the new IDT
    __asm__ volatile ("sti"); // set the interrupt flag
}
