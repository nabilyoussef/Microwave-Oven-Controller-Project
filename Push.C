void SW3Init (void)
{
	SYSCTL_RCGCGPIO_R |= 0X1; //Port B
	while((SYSCTL_PRGPIO_R&0x1) == 0){}
	GPIO_PORTA_LOCK_R=0x4C4F434B;
	GPIO_PORTA_CR_R |= 0X03; //Pin 3
    GPIO_PORTA_AFSEL_R &= ~0X03;
	GPIO_PORTA_PCTL_R &= ~0X0000F000;
	GPIO_PORTA_AMSEL_R &=~0X03;
	GPIO_PORTA_DIR_R &=~0X03; //Pin 3 designated as input
	GPIO_PORTA_DEN_R |= 0X03;
	GPIO_PORTA_DATA_R |= 0X03; // initial value is not pressed
}

unsigned char SW3Input(void)
{
	return (GPIO_PORTA_DATA_R&=0X03);

}
