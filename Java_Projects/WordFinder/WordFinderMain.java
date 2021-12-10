package WordFinder;

import java.util.*;
public class WordFinder {
	public static Scanner scanner = new Scanner(System.in);
	public static Word word;
	public static String output;
	public static int input;
	
	public static void main(String[] args) {
		while(true)
		{
			System.out.print("Enter a four digit number: ");
			String input = scanner.nextLine();
				if(!(Word.errorMessage(input)[0] || Word.errorMessage(input)[1]))
				{
					word = new Word(input);
					output = word.toString();
					System.out.println(output);
					System.out.println("Combinations: " +Word.combos);
					System.out.println();
				}
				else if(Word.errorMessage(input)[0])//IF LENGTH IS LESS THAN 4
				{
					System.out.println("Mismatch error caught.\nOnly four digits. Please enter a four digit number.");	
					System.out.println();
				}
				else if(Word.errorMessage(input)[1])//IF THERE IS A CHARACTER THAT IS NOT A NUMBER
				{
					System.out.println("Mismatch error caught.\nThere was a character that was not a letter. Please enter a four digit number.");	
					System.out.println();
				}
			}
		}
	}
