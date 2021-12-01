global load_page_dir
load_page_dir:
    push ebp
    mov ebp, esp
    mov eax, [esp + 8]
    mov cr3, eax
    mov esp, ebp
    pop ebp
    ret

global enable_paging
extern page_directory

enable_paging:
    push ebp
    mov esp, ebp
    mov eax, cr0
    or eax, 0x80000000
    mov eax, cr0
    mov esp, ebp
    pop ebp
    ret