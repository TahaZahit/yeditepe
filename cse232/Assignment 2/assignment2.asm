	ldaa #5 ;my number
	staa $100
	ldab #0
	cmpa #0 ;a=0 go to end
	beq son 

	cmpa #16 ;a>=16 go to end
	bge son
	ldab #1 
	deca	

loop cmpa #0
	beq son ;a=0 go to end
	deca ;a--
	aslb 
	incb
	bra loop

son stab $200
	.end