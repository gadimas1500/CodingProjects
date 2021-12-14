# Spring 2021 CSE12 Lab 4 Template
######################################################
# Macros made for you (you will need to use these)
######################################################

# Macro that stores the value in %reg on the stack 
#	and moves the stack pointer.
.macro push(%reg)
	subi $sp $sp 4
	sw %reg 0($sp)
.end_macro 

# Macro takes the value on the top of the stack and 
#	loads it into %reg then moves the stack pointer.
.macro pop(%reg)
	lw %reg 0($sp)
	addi $sp $sp 4	
.end_macro

#################################################
# Macros for you to fill in (you will need these)
#################################################

# Macro that takes as input coordinates in the format
#	(0x00XX00YY) and returns x and y separately.
# args: 
#	%input: register containing 0x00XX00YY
#	%x: register to store 0x000000XX in
#	%y: register to store 0x000000YY in
.macro getCoordinates(%input %x %y)	#DONE
	# YOUR CODE HERE	
	la $t6, ($zero)		#ENSURES THAT $t6 IS ZERO
	srl %x, %input, 16	#%x = 0x000000XX
	sll $t6, %x, 16		#A LEFT LOGICAL SHIFT BY 4 BYTES
	sub %y, %input, $t6	#%y = 0x000000YY
	la $t6, ($zero)		#RESETS $t6 REGISTER


.end_macro

# Macro that takes Coordinates in (%x,%y) where
#	%x = 0x000000XX and %y= 0x000000YY and
#	returns %output = (0x00XX00YY)
# args: 
#	%x: register containing 0x000000XX
#	%y: register containing 0x000000YY
#	%output: register to store 0x00XX00YY in
.macro formatCoordinates(%output %x %y)	#DONE
	# YOUR CODE HERE
	li %output, 0x00000000			#ENSURES THAT THE POINTER IS RESET
	add %output, %output, %x		#ADDS X COORD TO THE ADDRESS
	sll %output, %output, 16		#SHIFTS TO PREPARE TO ADD Y COORD
	add %output, %output, %y		#ADDS Y COORD TO THE ADDRESS
	
 .end_macro 

# Macro that converts pixel coordinate to address
# 	  output = origin + 4 * (x + 128 * y)
# 	where origin = 0xFFFF0000 is the memory address
# 	corresponding to the point (0, 0), i.e. the memory
# 	address storing the color of the the top left pixel.
# args: 
#	%x: register containing 0x000000XX
#	%y: register containing 0x000000YY
#	%output: register to store memory address in
.macro getPixelAddress(%output %x %y)	#DONE
	# YOUR CODE HERE
	la %output, ($zero)	#ENSURES THAT OUR OUTPUT POINTER IS RESET
	la $t6, ($zero)		#RESETS THE $t6 REGISTER TO ZERO
	mul $t6, %y, 128  	#MULTIPLICATION 128*Y
	add $t6, $t6, %x	#ADDIDTION X + (128*Y)
	mul $t6, $t6, 4		#MULTIPLY 4*(X + (128*Y))
	addi $t6, $t6, 0xffff0000	#ADD ORIGIN + (4*(X + (128*Y)))
	la %output, ($t6)	#LOADS THE RESULT TO THE REGISTER AT THE POINTER
	la $t6, ($zero)		#RESETS THE $t6 REGISTER
.end_macro


.text
# prevent this file from being run as main
li $v0 10 
syscall

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#  Subroutines defined below
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#*****************************************************
# Clear_bitmap: Given a color, will fill the bitmap 
#	display with that color.
# -----------------------------------------------------
# Inputs:
#	$a0 = Color in format (0x00RRGGBB) 
# Outputs:
#	No register outputs
#*****************************************************
clear_bitmap: nop	#DONE
	# YOUR CODE HERE, only use t registers (and a, v where appropriate)
	#INPUT IS $a0 OUTPUT IS $v0
	li $t0, 0x00000000		#RESETS THE X COORD
	
	x_loop:	#FIRST PART OF THE LOOP
		bgt $t0, 0x0000007f, next #BRANCHES IF X VALUE IS AT ITS MAX
		li $t1, 0x00000000	#RESETS THE Y COORDINATE
		y_loop:	#INNER LOOP
			bgt $t1, 0x0000007f, nextXIteration	#if ($s1 (aka Y) > 127) exit
			getPixelAddress($t3, $t0, $t1)	#STORES ADDRESS OF PIXEL INTO $t3
			sw $a0, ($t3)	#STORES THE COLOR INTO THE ADDRESS OF THE PIXEL
			addi $t1, $t1, 1		#ITERATES Y COORD +1
			j y_loop #GO BACK TO THE INNER LOOP
		nextXIteration: #BRANCH OF THE INNER LOOP
			addi $t0, $t0, 1
			
			j x_loop
	next:
 		jr $ra

#*****************************************************
# draw_pixel: Given a coordinate in $a0, sets corresponding 
#	value in memory to the color given by $a1
# -----------------------------------------------------
#	Inputs:
#		$a0 = coordinates of pixel in format (0x00XX00YY)
#		$a1 = color of pixel in format (0x00RRGGBB)
#	Outputs:
#		No register outputs
#*****************************************************
draw_pixel: nop	#DONE
	# YOUR CODE HERE, only use t registers (and a, v where appropriate)
	getCoordinates($a0, $t0, $t1)  #WE NEED TO FORMAT THE $t0 & $t1 REGISTERS
	getPixelAddress($a0, $t0, $t1)	#WE GET THE ADDRESS OF THE PIXEL AT THE XY COORDINATES
	sw $a1, ($a0)	#STORES THE GIVEN COLOR AT THE GIVEN ADDRESS
	jr $ra
	
#*****************************************************
# get_pixel:
#  Given a coordinate, returns the color of that pixel	
#-----------------------------------------------------
#	Inputs:
#		$a0 = coordinates of pixel in format (0x00XX00YY)
#	Outputs:
#		Returns pixel color in $v0 in format (0x00RRGGBB)
#*****************************************************
get_pixel: nop		#DONE
	# YOUR CODE HERE, only use t registers (and a, v where appropriate)
	#INPUT IS $a0
	getCoordinates($a0, $t0, $t1)  #WE NEED TO FORMAT THE $t0 & $t1 REGISTERS
	getPixelAddress($a0, $t0, $t1) #WE GET THE ADDRESS OF THE PIXEL AT THE XY COORDINATES
	lw $v0, ($a0) #LOADS $v0 WITH THE COLOR AT THE XY CORRDINATE PIXEL
	#FINAL OUTPUT SHOULD BE STORED IN $v0
	jr $ra

#*****************************************************
# draw_horizontal_line: Draws a horizontal line
# ----------------------------------------------------
# Inputs:
#	$a0 = y-coordinate in format (0x000000YY)
#	$a1 = color in format (0x00RRGGBB) 
# Outputs:
#	No register outputs
#*****************************************************
draw_horizontal_line: nop
	# YOUR CODE HERE, only use t registers (and a, v where appropriate)
 	li $t0, 0x00000000	#RESETS THE X COORD
 	move $t1, $a0		#MOVES $t1 INTO $a0
	
	x_HorzLoop:
		bgt $t0, 0x0000007f, next1	#if ($t1 (aka Y) > 127) exit
		getPixelAddress($t3, $t0, $t1)	#STORES ADDRESS OF PIXEL INTO $t3
		sw $a1, ($t3)	#STORES THE COLOR INTO THE ADDRESS OF THE PIXEL
		addi $t0, $t0, 1	#ITERATES x COORD +1
		j x_HorzLoop	#JUMPS BACK TO THE LOOP TO ITERATE AGAIN
	next1:
 		jr $ra


#*****************************************************
# draw_vertical_line: Draws a vertical line
# ----------------------------------------------------
# Inputs:
#	$a0 = x-coordinate in format (0x000000XX)
#	$a1 = color in format (0x00RRGGBB) 
# Outputs:
#	No register outputs
#*****************************************************
draw_vertical_line: nop
	# YOUR CODE HERE, only use t registers (and a, v where appropriate)
 	li $t1, 0x00000000		#RESETS THE Y COORD
 	move $t0, $a0			#MOVES $t1 INTO $a0
	
	y_VertLoop:
		bgt $t1, 0x0000007f, next2	#if ($s1 (aka Y) > 127) exit
		getPixelAddress($t3, $t0, $t1)	#STORES ADDRESS OF PIXEL INTO $t3
		sw $a1, ($t3)	#STORES THE COLOR INTO THE ADDRESS OF THE PIXEL
		addi $t1, $t1, 1				#ITERATES Y COORD +1
		j y_VertLoop	#JUMPS BACK TO THE LOOP TO ITERATE AGAIN
	next2:
 		jr $ra


#*****************************************************
# draw_crosshair: Draws a horizontal and a vertical 
#	line of given color which intersect at given (x, y).
#	The pixel at (x, y) should be the same color before 
#	and after running this function.
# -----------------------------------------------------
# Inputs:
#	$a0 = (x, y) coords of intersection in format (0x00XX00YY)
#	$a1 = color in format (0x00RRGGBB) 
# Outputs:
#	No register outputs
#*****************************************************
draw_crosshair: nop
	push($ra)
		
	
	# HINT: Store the pixel color at $a0 before drawing the horizontal and 
	# vertical lines, then afterwards, restore the color of the pixel at $a0 to 
	# give the appearance of the center being transparent.
	
	# Note: Remember to use push and pop in this function to save your t-registers
	# before calling any of the above subroutines.  Otherwise your t-registers 
	# may be overwritten.  
	
	# YOUR CODE HERE, only use t0-t7 registers (and a, v where appropriate)
	move $t5, $a0	#MAKES A LOCAL COPY OF THE XY COORDINATE
	push($a0)	#ADDS THE XY COORDINATE TO THE STACK
	jal get_pixel	#GETS THE CURRENT RGB VALUE OF THE INTERSECTION
	push($v0)	#PUSHES THE CURRENT RGB VALUE OF THE INTERSECTION TO THE STACK

	#DRAW A HORIZONTAL LINE
	move $a0, $t1	#MOVES THE Y COORDINATE INTO $a0
	jal draw_horizontal_line	#CREATES THE HORIZONTAL LINE OF THE GIVEN COLOR
	
	
	#DRAW A VERTICAL LINE.
	getCoordinates($t5, $t0, $t1) #FORMAT COORDINATES TO DRAW HORZ AND VERT LINES (A RESET)			
	move $a0, $t0		#USES $a0 AS OUR PARAMETER
	jal draw_vertical_line	#DRAWS THE VERTICAL LINE
	


	#UNDO THE INTERSECTION
	pop($a1)	#REINSTATES THE ORIGINAL $a1 VALUE
	pop($a0)	#REINSTATES THE ORIGINAL $a1 VALUE
	jal draw_pixel	#DRAWS THE ORIGINAL PIXEL TO THE SCREEN INTERSECTION
	
	
	#POP THE STACK
	pop($ra)	#RETURNS TO THE CORRECT ADDRESS
	
	
	# HINT: at this point, $ra has changed (and you're likely stuck in an infinite loop). 
	# Add a pop before the below jump return (and push somewhere above) to fix this.
	jr $ra
