

#include "DriverJeuLaser.h"

	int tab[64];
	extern int calcul_Reel(int);	


int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
	

		for (int k=0; k<64; k++){
				tab[k]=calcul_Reel(k);
}
	
	

//============================================================================	
	
	
while	(1)
	{
	}
}

