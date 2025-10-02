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
   .text:
   {
    *(.isr_vector)
    *(.text)
    *(.rodata)
   } > FLASH

   .data:
   {
    *(.data)
   }>SRAM AT>FLASH

   .bss:
   {
    *(.bss)
   }>SRAM
}