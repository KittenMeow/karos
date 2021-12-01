#include <stdint.h>
#include <stdbool.h>
/* 
struct PDE{
    uint32_t addr : 20;
    uint8_t avail0 : 3;
    bool size;
    bool avail1;
    bool acc;
    bool cachedis;
    bool wt;
    bool us;
    bool rw;
    bool pres;
};

struct PTE{
    uint32_t addr : 20;
    uint8_t avail : 3;
    bool global;
    bool pat;
    bool dirty;
    bool acc;
    bool cachedis;
    bool wt;
    bool us;
    bool rw;
    bool pres;
};
 */

void map_page(void *physaddr, void *virtualaddr, uint32_t flags){
    uint32_t pdindex = (uint32_t)virtualaddr >> 22;
    uint32_t ptindex = (uint32_t)virtualaddr >> 12 & 0xC003FF;

    uint32_t *pd = (uint32_t*)0xFFFFF000;

    uint32_t *pt = ((uint32_t*)0xFFC00000) + (0x400 * pdindex);
    pt[ptindex] = ((uint32_t)physaddr) | (flags & 0xFFF) | 0x01;
}

void unmap_page(void *virtualaddr){
    uint32_t pdindex = (uint32_t)virtualaddr >> 22;
    uint32_t ptindex = (uint32_t)virtualaddr >> 12 & 0xC003FF;

    uint32_t *pt = ((uint32_t*)0xFFC00000) + (0x400 * pdindex);
    pt[ptindex] = 0x00000000;
}