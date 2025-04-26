#include <stdint.h>

void Reset_Handler(void);
void Default_Handler(void);
extern int main(void);

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void Reset_handler(void)
{
	uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint32_t* SRC = (uint32_t)&_etext;
	uint32_t* DEST = (uint32_t)&_sdata;
	for(uint32_t i = 0;i < data_size; i++)
	{
		*DEST = *SRC;
		DEST++;
		SRC++;
	}
	data_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	DEST = (uint32_t)&_sbss;
	for(uint32_t i = 0;i < data_size; i++)
	{
		*DEST = 0;
	}
	main();
	
	while(1);
}

void NMI_Handler(void)            _attribute_ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)      _attribute_ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)      _attribute_ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)       _attribute_ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)     _attribute_ ((weak, alias("Default_Handler")));
void SVC_Handler(void)            _attribute_ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)       _attribute_ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)         _attribute_ ((weak, alias("Default_Handler")));
void SysTick_Handler(void)        _attribute_ ((weak, alias("Default_Handler")));

_attribute_ ((section(".isr_vector")))
uint32_t *vector_table[] = {
    (uint32_t *)&_estack,           
    (uint32_t *)Reset_Handler,      
    (uint32_t *)NMI_Handler,       
    (uint32_t *)HardFault_Handler,  
    (uint32_t *)MemManage_Handler,  
    (uint32_t *)BusFault_Handler,   
    (uint32_t *)UsageFault_Handler, 
    0, 0, 0, 0,                     
    (uint32_t *)SVC_Handler,        
    (uint32_t *)DebugMon_Handler,  
    0,                             
    (uint32_t *)PendSV_Handler,     
    (uint32_t *)SysTick_Handler,   
};

void Default_Handler(void)
{
    while (1); 
}