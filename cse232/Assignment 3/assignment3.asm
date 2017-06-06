	ldaa #0
	ldab #1
	stab $100
	staa $101
	stab $102
	stab $103
	staa $104
	ldx #$100
Loop adda 0,x
	inx
	asla
	cpx #$104
	bne loop
	adda 0,x
	staa $120
	.end