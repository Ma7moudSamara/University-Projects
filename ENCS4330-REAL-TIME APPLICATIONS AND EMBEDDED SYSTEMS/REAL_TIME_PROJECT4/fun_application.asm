PROCESSOR 16F877A

	__CONFIG 0x3731

	#INCLUDE "P16F877A.INC" 	; standard labels 	
	TIME EQU 020
	CHAR EQU 021
	TIME_INT EQU 023
	TEMP EQU 022
	TEMP2 EQU 024
	POS EQU 025
	FLAG EQU 026
    POS1 EQU 027
	TIMET EQU 028

	CBLOCK 0X70
	PRE
	ONE
	TWO
	THREE

	ENDC

	COUNT EQU 0X27
	FOUR EQU 0X28
	FIVE EQU 0X29
	RESETINT EQU 0X30
; PROGRAM BEGINS ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	ORG		0		; Default start address 
	NOP			; required for ICD mode

	goto	init
	ORG		4
	GOTO	ISR
	

	ISR		NOP
			MOVFW RESETINT
			SUBLW D'1'
			BTFSC STATUS,Z
			CALL INT111
			
			MOVFW RESETINT
			SUBLW D'2'
			BTFSC STATUS,Z
			CALL INT222


			RETFIE	

	
; Port & display setup.....................................
INT111		
			BANKSEL PORTC
			BCF	Select,RS

			MOVLW POS
			MOVWF FSR
			MOVF INDF, W

			;MOVLW POS
			CALL send
			BSF	Select,RS

			MOVFW CHAR
			SUBLW D'32'
			BTFSC STATUS,Z
			CALL CHAR_A
	

			INCF CHAR
			MOVFW CHAR
			SUBLW D'91'
			BTFSC STATUS,Z
			CALL SPACE_CHAR

			MOVLW CHAR
			MOVWF FSR
			MOVF INDF, W
			CALL send
						
			BCF	Select,RS
			MOVLW 0X10
			CALL send
			BSF	Select,RS
			BCF INTCON,INTF

			MOVLW D'250' 
			MOVWF TIME_INT

			MOVLW D'3' 
			MOVWF TEMP

			MOVLW D'250' 
			MOVWF TEMP2
	RETURN

INT222		NOP
			CALL init
	RETURN

init	
		BANKSEL PORTB

		MOVLW D'250' 
		MOVWF TIME_INT

		MOVLW D'3' 
		MOVWF TEMP

		MOVLW D'250' 
		MOVWF TEMP2

		MOVLW H'C0' 
		MOVWF POS

		MOVLW D'0'
		MOVWF FLAG

		MOVLW D'1'
		MOVWF COUNT

		MOVLW D'1'
		MOVWF RESETINT

		BANKSEL PORTB
		BSF 	TRISB, 0

		BANKSEL	TRISD		; Select bank 1
    	CLRF	TRISD          	

		BANKSEL PORTD
		CLRF	PORTD		; Clear display outputs
		CALL	inid		; Initialise the display
		GOTO 	start 


; MAIN LOOP ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

start	CALL	putLCD		; display input
		BANKSEL TRISA
		CLRF TRISD
		BSF TRISB, RB0

		BSF OPTION_REG,INTEDG ; Set “Rising” Edge
		BCF INTCON,INTF ; Reset “Interrupt Flag” of INT
		BSF INTCON,INTE ; Set “Interrupt Enable Bit” of INT
		BSF INTCON,GIE ; Set “Global” Int Enable
		BANKSEL PORTC

		BCF	Select,RS	; set display command mode
		MOVLW	0XC0		; code to home cursor
		CALL	send	; output it to display
		BSF	Select,RS	; and restore data mode
		
		CALL SECOND_LINE


MAIN	CALL TIMINT			
		GOTO MAIN


TIMINT	NOP
		BANKSEL PORTC

		DECFSZ TIME_INT,F 
		RETURN

		CALL TIMINT2
		RETURN

TIMINT2	NOP
		BANKSEL PORTC

		MOVLW D'250' 
		MOVWF TIME_INT
		DECFSZ TEMP2,F 
		RETURN

		CALL TIMEROT
		RETURN

TIMEROT	NOP
		BANKSEL PORTC

		MOVLW D'250' 
		MOVWF TEMP2

		DECFSZ TEMP,F 
		RETURN



		MOVFW COUNT
		SUBLW D'1'
		BTFSC STATUS,Z
		CALL MAKEONE

		MOVFW COUNT
		SUBLW D'2'
		BTFSC STATUS,Z
		CALL MAKETWO

		MOVFW COUNT
		SUBLW D'3'
		BTFSC STATUS,Z
		CALL MAKETHREE

		MOVFW COUNT
		SUBLW D'4'
		BTFSC STATUS,Z
		CALL MAKEFOUR

		MOVFW COUNT
		SUBLW D'5'
		BTFSC STATUS,Z
		CALL MAKEFIVE

		INCF COUNT

		MOVLW CHAR
	
		MOVWF FSR
		MOVF INDF, W
		CALL send

		CALL CHAR_A
		INCF CHAR
		INCF POS

		MOVLW D'250' 
		MOVWF TIME_INT

		MOVLW D'3' 
		MOVWF TEMP

		MOVLW D'250' 
		MOVWF TEMP2

		MOVFW POS
		SUBLW H'C5' 
		BTFSC STATUS,Z
		CALL Equal

		MOVFW FLAG
		SUBLW D'1'
		BTFSC STATUS,Z
		CALL TESTSPACE

		MOVFW CHAR
		SUBLW D'32'
		BTFSC STATUS,Z
		CALL MAKEFLAG

		RETURN	

MAKEONE	NOP
		BANKSEL PORTC


		MOVF CHAR, W
		MOVWF ONE

		RETURN

MAKETWO	NOP
		BANKSEL PORTC



		MOVF CHAR, W
		MOVWF TWO

		RETURN

MAKETHREE	NOP
		BANKSEL PORTC


		MOVF CHAR, W
		MOVWF THREE

		RETURN

MAKEFOUR	NOP
		BANKSEL PORTC


	
		MOVF CHAR, W
		MOVWF FOUR
	
		RETURN

MAKEFIVE	NOP
		BANKSEL PORTC



		MOVF CHAR, W

		MOVWF FIVE

		RETURN
	

Equal	NOP
		BANKSEL PORTC

	
		CALL END_PROGRAM

		RETURN

TESTSPACE	NOP
			BANKSEL PORTC

			MOVFW CHAR
			SUBLW D'32'
			BTFSC STATUS,Z
			CALL Equal

			RETURN

MAKEFLAG	NOP
			BANKSEL PORTC

			MOVLW D'1'
			MOVWF FLAG

			RETURN

END_PROGRAM NOP
			BANKSEL PORTC
			BCF	Select,RS	; set display command mode
			MOVLW	0X01		
			CALL	send	; output it to display
		
			MOVLW	0X80		; code to home cursor
			CALL	send	; output it to display
			BSF	Select,RS	; and restore data mode

			MOVLW D'2'
			MOVWF RESETINT
			
            LOOP
			CALL PRINT_ARRAY

            MOVLW D'2'
			MOVWF RESETINT

			CALL DELAY_DD
			BCF	Select,RS
			MOVLW	0X80		
			CALL	send	
			MOVLW	0X1C		
			CALL	send
			BSF	Select,RS
				
			GOTO LOOP
			
			
			GOTO STUCK

			RETURN
STUCK GOTO STUCK

IN_ARRAY	NOP
			MOVF INDF, W
			CALL send
			
			INCF FSR
			BTFSS FSR, 2
			GOTO IN_ARRAY
			RETURN

; Output to display........................................

putLCD	BCF	Select,RS	; set display command mode
		MOVLW	0X80		; code to home cursor
		CALL	send	; output it to display
		BSF	Select,RS	; and restore data mode

; Convert digits to ASCII and display......................

        MOVLW	'E'			; load code
		CALL	send		; and output
		MOVLW	'n'			; load code
		CALL	send		; and output
		MOVLW	't'			; load code
		CALL	send		; and output
		MOVLW	'e'	    	; load code
		CALL	send		; and output
		MOVLW	'r'			; load code
		CALL	send		; and output

		MOVLW	' '			; load code
		CALL	send		; and output

		MOVLW	'S'			; load code
		CALL	send		; and output
		MOVLW	't'			; load code
		CALL	send		; and output
		MOVLW	'r'			; load code
		CALL	send		; and output
		MOVLW	'i'			; load code
		CALL	send		; and output
		MOVLW	'n'			; load code
		CALL	send		; and output
		MOVLW	'g'			; load code
		CALL	send		; and output

	RETURN				; done

SECOND_LINE	BCF	Select,RS
			MOVLW D'192'
			CALL send
			MOVLW 0X0F
			CALL send
			BSF	Select,RS
			CLRF CHAR

			
				
			MOVLW D'65'
			MOVWF CHAR

			MOVLW CHAR
			MOVWF FSR
			MOVF INDF, W
			
			CALL send
			BCF	Select,RS
			MOVLW 0X10
			CALL send
			BSF	Select,RS

			;INCF CHAR
			RETURN


SPACE_CHAR  NOP
			BANKSEL PORTC
			MOVLW D'32'
			MOVWF CHAR
			RETURN

CHAR_A		NOP
			BANKSEL PORTC
			MOVLW D'64'
			MOVWF CHAR
			RETURN

SHEFT_STR	NOP
			BCF	Select,RS	; set display command mode
			MOVLW 0X1C
			CALL	send	; output it to display
			BSF	Select,RS	; and restore data mode
			RETURN

START		NOP
			MOVLW D'255' 
			MOVWF TIMET
			RETURN

DELAY		NOP 
			DECFSZ TIMET,F 
			GOTO DELAY 
			RETURN

CLEAR_LCD	BCF	Select,RS	; set display command mode
			MOVLW 0X01
			CALL	send	; output it to display0X
			BSF	Select,RS	; and restore data mode
			RETURN

CHECK_END1	MOVWF FSR
			MOVF INDF, W
			SUBLW H'8F'
			BTFSC STATUS,Z
			CALL SHEFT_STR2
			RETURN

SHEFT_STR2 RETURN

PRINT_ARRAY	MOVLW ONE
			MOVWF FSR
			MOVF INDF,W
			CALL send

			MOVLW TWO
			MOVWF FSR
			MOVF INDF,W
			CALL send

			MOVLW THREE
			MOVWF FSR
			MOVF INDF,W
			CALL send

			MOVLW FOUR
			MOVWF FSR
			MOVF INDF,W
			CALL send

			MOVLW FIVE
			MOVWF FSR
			MOVF INDF,W
			CALL send
			RETURN

DELAY_D		CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			CALL START
			CALL DELAY
			RETURN
DELAY_DD	CALL DELAY_D
			CALL DELAY_D
			CALL DELAY_D
			CALL DELAY_D
			RETURN

; INCLUDED ROUTINES ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Include LCD driver routines
;
	#INCLUDE "LCDIS.INC"
	

	END	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;