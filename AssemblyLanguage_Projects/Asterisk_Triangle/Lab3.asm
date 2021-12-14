.data

space: .asciiz "\t"
newline: .asciiz "\n"
entryMessage: .asciiz "Enter the height of the pattern (must be greater than 0):\n"
star: .asciiz "*"
invalid: .asciiz "Invalid Entry!\n"

.text
check:
	li $v0, 4		#prepares to print a string
	la $a0, entryMessage	#entry message to be printed
	syscall		#prints the entryMessage
	
	li $v0, 5	#gets user input
	syscall		#calls for user input
	move $t0, $v0	#moves user input into a register
					#$t0 is the exit number
	bgt $t0, 0, main	#if (input > 0): go to main, else check agian
	li $v0, 4
	la $a0, invalid	#prints invalid message
	syscall
	j check 		#jumps back to check branch
	
main:	
	li $t1, 0	#value being iterated
	li $t2, 0	#loads 0 into $t2
	while:
		bge $t1, $t0, exit	#exits the program if user input is equal to the final result
						#initially, $t1 = 0 and $t0 = <userInput>
		jal insertNumber	#calls insert number to print the number to the left side of the screen
		
		move $t2, $t1	#moves the value from $t1 into $t2 as a counter
		for:		#a for loop for the number of stars in the current row
			ble $t2, $zero, next	#our conditional statement to check
			jal tab		#jumps to make a tab by the star
						#go to next line if ($t2 > 0) else stay at current line
			li $v0, 4	#gets system ready to print a string
			la $a0, star	#assigns $a0 to print a string	
			syscall		#prints the star to the string
			sub $t2, $t2, 1#decrements $t2 register by 1 ($t2--)
			j for	#jump to the next iteration in the for loop
		next:		#function to move onto a new line for the next iteration
			jal nl	#adds a new line
			addi $t1, $t1, 1	#increments $t1 by one. i++		
			j while		#jump to the next iteration in the while loop
		
insertNumber:			#function that inserts the current line number
	li $v0, 1			#prepares to print an int
	la $a0, ($t1)		#stores int value to print
	addi $a0, $a0, 1	#prints the number to the screen ($t1 +1)
	syscall			#prints
	jr $ra			#returns to the previous address
	
nl:		#function to make a new line
	li $v0, 4
	la $a0, newline
	syscall
	jr $ra
	
tab:		#creates a tab
	li $v0, 4
	la $a0, space
	syscall
	jr $ra

exit:		#function that executes the program
	li $v0, 10	#code to exit
	syscall		#exits
	


	
		
