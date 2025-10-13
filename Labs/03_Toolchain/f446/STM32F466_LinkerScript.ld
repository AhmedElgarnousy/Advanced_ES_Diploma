/*entry point*/
ENTRY(Reset_Handler)

/*memory command for stm32f446re*/
MEMORY
{
  FLASH(rx) : ORIGIN = 0x08000000 , LENGTH = 512K
  /* u can divide it to SRAM1, SRAM2 */
  SRAM (rwx) : ORIGIN = 0x20000000 , LENGTH = 128K
}

SECTIONS
{
   .text :
   {
    *(.isr_vector)
    *(.text)
    *(.rodata)
    . = ALIGN(4); /*for readability, gcc by default align by word size (4 byte)*/
    _etext = . ;

   } > FLASH

   .data :
   {
     _sdata = . ; /*ORIGIN Of SRAM as VMA of this memory*/
    *(.data)
    . = ALIGN(4);
    _edata = .;
   }>SRAM AT>FLASH

   .bss :
   {
    _sbss = .;
     *(.bss)
    . = ALIGN(4);
    _ebss = .;
   }>SRAM
}



