	PRESERVE8
	THUMB   

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
	
; ===============================================================================================
	


		
;section ROM code (read only) :		
	area    moncode,code,readonly
	include DriverJeuLaser.inc

; écrire le code ici
// variable globale

/*char FlagCligno;
void timer_callback(void)
{
	if (FlagCligno==1)
	{
		FlagCligno=0;
		GPIOB_Set(1);
	}
	
	else
	{
		FlagCligno=1;
		GPIOB_Clear(1);
	}
		
}
*/
;variable globale
import FlagCligno

timer_callback proc
	PUSH {lr,r4,r5}
	mov r0,#1
	ldr r4,=FlagCligno
	ldr r5,[r4]
	cmp r5,#1
	bne pegal
	
	bl GPIOB_Set
	mov r5,#0
	str r5,[r4]
	b continue
	pegal
	
	bl GPIOB_Set
	mov r5,#1
	str r5,[r4]
	continue
	POP {lr,r4,r5}
	BX lr 
	

		
		
	END	