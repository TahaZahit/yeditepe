	.org $100
	LDAA #5
	STAA $20
	LDAA #3
	STAA $21
	LDAA #8
	STAA $22
	LDAA #18
	STAA $23
	LDAA #2
	STAA $24
	LDX #0
	CLRA

L1 LDAB $20,X
	JSR LABEL
	INX
	CPX #5
	BNE L1
	STAA $30
	BRA LAST

LABEL ANDB #1
	BNE BACK
	ADDA $20,X
BACK RTS

LAST .END
