	RORG
	NAME_deneme
	LDX	100H
	LDAB	#10H
	LDAA	30H, z
	INCA
	NAME_deneme
	asd_deneme
	STAA	40H, X
	LDAA	50H, x
LOOP:	CMPB	#0H
	BEQ	DONE
	LDAA	20H, z
	INCA
	NAME_deneme
	asd_deneme
	STAA	0H, X
	LDAA	-1H, x
	INX
	DECB
	BRA LOOP
	END
