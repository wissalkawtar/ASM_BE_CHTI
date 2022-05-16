

#include "DriverJeuLaser.h"

	int tab[64];
	extern short int LeSignal[] ;
	extern int DFT_ModuleAuCarre(int ,short int *);	


int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
	

		for (int k=0; k<64; k++){
				tab[k]=DFT_ModuleAuCarre(k,&LeSignal[0]);
}
	
	

//============================================================================	
	
	
while	(1)
	{
	}
}

