void PortF_init(void){
	GPIO_PORTF_IS_R&=~0x11;  // make F0,F4 edge senstive        
	GPIO_PORTF_IBE_R&=~0x11; //single edge        
	GPIO_PORTF_IEV_R =~0x11; //falling edge 
	GPIO_PORTF_ICR_R |=0x11; //clear any prior interrupt       
	GPIO_PORTF_IM_R  |=0x11; // unmask interrupt
	NVIC_EN0_R|=0x40000000; //enable port f interrupt
	NVIC_PRI7_R=3<<21;; // set priorty 
}
