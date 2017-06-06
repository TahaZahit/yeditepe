	ldaa #12
	cmpa #4
	bgt xy ;if x>y jump to "xy" label
	bra son ;else jump to son
xy	asla
son	staa $100
	.end
