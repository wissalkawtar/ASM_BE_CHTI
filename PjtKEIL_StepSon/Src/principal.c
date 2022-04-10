

#include "DriverJeuLaser.h"

#define periode 6552
#define Periode_ticks 720

extern void CallbackSon(void);

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
	Timer_1234_Init_ff( TIM4, periode);
	Active_IT_Debordement_Timer( TIM4, 2, CallbackSon );

// configuration de PortB.1 (PB1) en sortie push-pull
	GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);

//configuration fonction PMW
	PWM_Init_ff( TIM3,3, Periode_ticks );
	
	GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
//============================================================================	
	
	
while	(1)
	{
	}
}

