

#include "DriverJeuLaser.h"
#include "GestionSon.s"
# define Periode_ticks 360000 //72 MHz *5 ms
	int tab[64];
	int score[4]={0,0,0,0};
	int compteur={0,0,0,0};
  short int dma_buf[64];
	extern short int LeSignal[] ;
	extern int DFT_ModuleAuCarre(int ,short int *);	




void Callback_systick(void)
{
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	for (int k=0; k<64; k++){
				tab[k]=DFT_ModuleAuCarre(k,&dma_buf[0]);
}
	for (int j=0,j<4,j++){
		if(tab[j+17] > 0X9999A){
			compteur[j]++;
			if(compteur[j] ==20){
				score[j]++;
				compteur[j]=0;
				callbackSon();
				
				
			}
		}
}
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
		CLOCK_Configure();
	

		
	
		 Systick_Period_ff( 360000 ); 
		 Systick_Prio_IT( 2, Callback_systick );
		 SysTick_On;


		 Init_TimingADC_ActiveADC_ff( ADC1, 72 );
		 Single_Channel_ADC( ADC1, 2 );
		 Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
		 Init_ADC1_DMA1( 0, dma_buf);
	
		 SysTick_Enable_IT;  

//============================================================================	
	
	
while	(1)
	{
	}
}

