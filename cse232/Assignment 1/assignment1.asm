;our number (1011)
	ldaa #1
	ldab #0
	staa $100 ;100H=01
	stab $101 ;101H=00
	staa $102 ;102H=01
	staa $103 ;103H=01
	clra
	ldaa $100 ;a=1
	asla
	adda $101 ;a=10
	asla
	adda $102 ;a=101
	asla
	adda $103 ;a=1011
	staa $200 ;200H=1011=B
	.end