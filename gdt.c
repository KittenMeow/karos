#include <stdint.h>

struct gdt_entry{
    uint16_t lim0;
    uint16_t base0;
    uint8_t base1;
    uint8_t acc;
    uint8_t gran;
    uint8_t base2;
}__attribute__((packed));

struct gdt_ptr{
    uint16_t lim;
    uint32_t base;
}__attribute__((packed));

extern void gdt_flush();

struct gdt_entry gdt[3];
struct gdt_ptr gp;

void gdt_set_gate(uint16_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran){
    /* Setup the descriptor base address */
    gdt[num].base0 = (base & 0xFFFF);
    gdt[num].base1 = (base >> 16) & 0xFF;
    gdt[num].base2 = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].lim0 = (limit & 0xFFFF);
    gdt[num].gran = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].gran |= (gran & 0xF0);
    gdt[num].acc = access;

}

void gdt_install(){
    /* Setup the GDT pointer and limit */
    gp.lim = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = &gdt;

    /* Our NULL descriptor */
    gdt_set_gate(0, 0, 0, 0, 0);

    /* The second entry is our Code Segment. The base address
    *  is 0, the limit is 4GBytes, it uses 4KByte granularity,
    *  uses 32-bit opcodes, and is a Code Segment descriptor.
    *  Please check the table above in the tutorial in order
    *  to see exactly what each value means */
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /* The third entry is our Data Segment. It's EXACTLY the
    *  same as our code segment, but the descriptor type in
    *  this entry's access byte says it's a Data Segment */
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    /* Flush out the old GDT and install the new changes! */
    gdt_flush();
}