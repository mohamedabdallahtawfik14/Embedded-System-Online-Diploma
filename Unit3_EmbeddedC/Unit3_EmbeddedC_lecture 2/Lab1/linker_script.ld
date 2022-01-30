ENTRY(reset)

MEMORY
{
    Mem(rwx): ORIGIN = 0x00000000, LENGTH = 64M 
}

SECTIONS
{
    . = 0x10000;
    .startup . :
    {
        /* take only .text part from startup.o and let it appear in new section name (.startup)*/
        startup.o(.text)
    }> Mem
    .text :
    {
        /* take all remain .text  from all other files and let it appear section name (.text)*/
        *(.text)
    }> Mem
    .data :
    {
        *(.data)
    }> Mem
    .bss :
    {
        *(.bss)
    }> Mem
    . = . + 0x1000;
    stack_top = .;
}