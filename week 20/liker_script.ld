ENTRY (Reset_handler)

MEMORY
{
	Flash (xr) : ORIGIN = 0x08000000, length = 256k 
	SRAM (xwr) : ORIGIN = 0x20000000, length = 64k
}

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = . ;
	}AT>Flash
	.data :
	{
		_sdata = . ;
		*(.data)
		. = ALIGN(4);
		_edata = . ;
	}>SRAM AT> Flash
	.bss :
	{
		_sbss = . ;
		*(.bss)
		. = ALIGN(4);
		_ebss = . ;
	} >SRAM
}