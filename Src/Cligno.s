	PRESERVE8
	THUMB   
	DriverJeuLaser.inc

; ====================== zone de r�servation de donn�es,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		

	
; ===============================================================================================
	


		
;section ROM code (read only) :		
	area    moncode,code,readonly
; �crire le code ici		
char FlagCligno;

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




		
		
	END	