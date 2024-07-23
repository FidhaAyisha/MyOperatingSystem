[bits 32]

; void __attribute__((cdecl)) i686_IDT_Load(IDTDescriptor* idtDescriptor);
global i686_GDT_Load
i686_GDT_Load:

    ; make new call frame
    push ebp             ; save old call frame
    mov ebp, esp         ; initialize new call frame
    
    ; load idt
    mov eax, [ebp + 8]
    lgdt [eax]

    mov eax, [ebp + 12]
    push eax
    push .reload_cs
    retf

.reload_cs:

    mov ax, [ebp + 16]
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov esp, ebp
    pop ebp 
    ret


    ; restore old call frame
    mov esp, ebp
    pop ebp
    ret