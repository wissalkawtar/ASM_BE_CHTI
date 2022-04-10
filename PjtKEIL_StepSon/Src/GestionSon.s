	PRESERVE8
	THUMB   
	include DriverJeuLaser.inc
	import LongueurSon
	import Son	
	export CallbackSon
	export SortieSon
	export index
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
SortieSon dcd 0
index dcd 0
	
; ===============================================================================================
	


;callbackson algorithme 
;si(index<longueur)
;Rx=son[(indice+32767)/92]
;indice++


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
;fonction StartSon qui permet de lancer la séquence sonore
StartSon proc
	ldr r0,=index
	mov r1,#0
	str r1,[r0]
	ENDP

; écrire le code ici		
CallbackSon proc
	push {lr,r4,r5,r6}
	ldr r4,=LongueurSon
	ldr r3,[r4]   ; r1;val longueurSon
	ldr r4 , =index     ; r4 @index
	ldr r2,[r4]        ;r2 val index 
	cmp r3,r2       ; comparaison de index et LongueurSon 
	beq Next ; si index > longueurSonpsser a Next 
	
	ldr r1,= Son     ; recup de @ son
	ldrsh r0,[r1,r2,lsl #1]    ;echanti
	ldr r5,=SortieSon  
	; mise a l echelle
	add r0, #32768 
	mov r6, #720
	mul r0, r0, r6
	asr r0,#16
	str r0,[r5]
	;push {R2}
	bl PWM_Set_Value_TIM3_Ch3    ; mettre à jour le rapport cyclique  
	;pop {R2} 
	add r2,r2,#1   ;incrementation d'index
	str r2,[r4]
	;b Fin
	
Next
	
	
	pop{lr,r4,r5,r6}
	
	bx lr
		
	ENDP
	
	END