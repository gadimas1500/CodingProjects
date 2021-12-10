package WordFinder;


public class Word
{
	private static int intNum;
	private static String stringNum;
	private static String[] charAt;
	private static boolean two, three, four, five, six, seven, eight, nine;
	private static String returnString;
	private static String[][][][][] arr;
	public static int combos = 1;
	

	
	public Word(String x)
	{
		//intNum = x;
		arr = new String[3][3][3][3][4];
		stringNum = x;//Integer.toString(x);
		charAt = new String[stringNum.length()];
		returnString = "0. ";
		for(int i = 0; i < charAt.length; i++)//USED FOR 2C
		{
			charAt[i] = Character.toString(stringNum.charAt(i));
		}
		for(int j = 0; j < stringNum.length(); j++)
		{
			if(charAt[j].equals("2"))
			{
				two = true;
				combos *= 3;
			}
			if(charAt[j].equals("3"))
			{
				three = true;
				combos *= 3;
			}
			if(charAt[j].equals("4"))
			{
				four = true;
				combos *= 3;
			}
			if(charAt[j].equals("5"))
			{
				five = true;
				combos *= 3;
			}
			if(charAt[j].equals("6"))
			{
				six = true;
				combos *= 3;
			}
			if(charAt[j].equals("7"))
			{
				seven = true;
				combos *= 4;
			}
			if(charAt[j].equals("8"))
			{
				eight = true;
				combos *= 3;
			}
			if(charAt[j].equals("9"))
			{
				nine = true;
				combos *= 4;
			}
		}
		
		for(int a = 0; a < 3; a++)//TAKES THE NULL AWAY
		{
			for(int b = 0; b < 3; b++)
			{				
				for(int c = 0; c < 3; c++)
				{
					for(int d = 0; d < 3; d++)
					{
						for(int e = 0; e < 4; e++)					
						{
							arr[a][b][c][d][e] = new String();
						}
					}
				}
			}
		}	
		decoder();
	}
	
	private static void decoder()
	{
		firstLetter();		//THE FIRST LETTER TO GIVE TO THE 5D ARRAY
		restOfLetters();	//THE REST OF THE LETTERS TO GIVE TO THE 5D ARRAY
	}
	
	
	private static void firstLetter()
	{
			for(int b = 0; b < 3; b++)//SECOND LETTER
			{				
				for(int c = 0; c < 3; c++)//THIRD LETTER
				{
					for(int d = 0; d < 3; d++)//FOURTH LETTER
					{
						for(int e = 0; e < 3; e++)//FIFTH INDEX
						{
							if(charAt[0].equals("2") && two)//FIRST NUMBER
							{
								arr[0][b][c][d][e] = "a";
								arr[1][b][c][d][e] = "b";
								arr[2][b][c][d][e] = "c";
							}
							if(charAt[0].equals("3") && three)
							{
								arr[0][b][c][d][e] = "d";
								arr[1][b][c][d][e] = "e";
								arr[2][b][c][d][e] = "f";
							}
							if(charAt[0].equals("4") && four)
							{
								arr[0][b][c][d][e] = "g";
								arr[1][b][c][d][e] = "h";
								arr[2][b][c][d][e] = "i";
							}
							if(charAt[0].equals("5") && five)
							{
								arr[0][b][c][d][e] = "j";
								arr[1][b][c][d][e] = "k";
								arr[2][b][c][d][e] = "l";
							}
							if(charAt[0].equals("6") && six)
							{
								arr[0][b][c][d][e] = "m";
								arr[1][b][c][d][e] = "n";
								arr[2][b][c][d][e] = "o";
							}
							if(charAt[0].equals("7") && seven)
							{
								arr[0][b][c][d][e] = "p";
								arr[1][b][c][d][e] = "q";
								arr[2][b][c][d][e] = "r";
								arr[3][b][c][d][e] = "s";
							}
							if(charAt[0].equals("8") && eight)
							{
								arr[0][b][c][d][e] = "t";
								arr[1][b][c][d][e] = "u";
								arr[2][b][c][d][e] = "v";
							}
							if(charAt[0].equals("9") && nine)
							{
								arr[0][b][c][d][e] = "w";
								arr[1][b][c][d][e] = "x";
								arr[2][b][c][d][e] = "y";
								arr[3][b][c][d][e] = "z";
							}
						}
					}
				}
			}		
	}
	
	private static void restOfLetters()
	{
		for(int b = 0; b < 3; b++)//SECOND LETTER
		{				
			for(int c = 0; c < 3; c++)//THIRD LETTER
			{
				for(int d = 0; d < 3; d++)//FOURTH LETTER
				{
					for(int e = 0; e < 4; e++)//FIFTH INDEX
					{
						if(charAt[1].equals("2") && two)//SECOND NUMBER
						{
							arr[d][0][c][b][1] = "a";
							arr[d][1][c][b][1] = "b";
							arr[d][2][c][b][1] = "c";
						}
						
						if(charAt[1].equals("3") && three)
						{
							arr[d][0][c][b][1] = "d";
							arr[d][1][c][b][1] = "e";
							arr[d][2][c][b][1] = "f";
						}
						
						if(charAt[1].equals("4") && four)
						{
							arr[d][0][c][b][1] = "g";
							arr[d][1][c][b][1] = "h";
							arr[d][2][c][b][1] = "i";
						}
						
						if(charAt[1].equals("5") && five)
						{
							arr[d][0][c][b][1] = "j";
							arr[d][1][c][b][1] = "k";
							arr[d][2][c][b][1] = "l";
						}
						
						if(charAt[1].equals("6") && six)
						{
							arr[d][0][c][b][1] = "m";
							arr[d][1][c][b][1] = "n";
							arr[d][2][c][b][1] = "o";
						}
						
						if(charAt[1].equals("7") && seven)
						{
							arr[d][0][c][b][1] = "p";
							arr[d][1][c][b][1] = "q";
							arr[d][2][c][b][1] = "r";
						}
						
						if(charAt[1].equals("8") && eight)
						{
							arr[d][0][c][b][1] = "t";
							arr[d][1][c][b][1] = "u";
							arr[d][2][c][b][1] = "v";
						}
						
						if(charAt[1].equals("9") && nine)
						{
							arr[d][0][c][b][1] = "w";
							arr[d][1][c][b][1] = "x";
							arr[d][2][c][b][1] = "y";
						}
						
						
						if(charAt.length > 2)	//IF THE NUMBER IS GREATER THATN 2 DIGITS (completes the rest of the loops)
						{
							if(charAt[2].equals("2") && two)//THIRD NUMBER
							{
								arr[d][c][0][b][2] = "a";
								arr[d][c][1][b][2] = "b";
								arr[d][c][2][b][2] = "c";
							}
							if(charAt[2].equals("3") && three)
							{
								arr[d][c][0][b][2] = "d";
								arr[d][c][1][b][2] = "e";
								arr[d][c][2][b][2] = "f";
							}
							if(charAt[2].equals("4") && four)
							{
								arr[d][c][0][b][2] = "g";
								arr[d][c][1][b][2] = "h";
								arr[d][c][2][b][2] = "i";
							}
							if(charAt[2].equals("5") && five)
							{
								arr[d][c][0][b][2] = "j";
								arr[d][c][1][b][2] = "k";
								arr[d][c][2][b][2] = "l";
							}
							if(charAt[2].equals("6") && six)
							{
								arr[d][c][0][b][2] = "m";
								arr[d][c][1][b][2] = "n";
								arr[d][c][2][b][2] = "o";
							}
							if(charAt[2].equals("7") && seven)
							{
								arr[d][c][0][b][2] = "p";
								arr[d][c][1][b][2] = "q";
								arr[d][c][2][b][2] = "r";
							}
							if(charAt[2].equals("8") && eight)
							{
								arr[d][c][0][b][2] = "t";
								arr[d][c][1][b][2] = "u";
								arr[d][c][2][b][2] = "v";
							}
							if(charAt[2].equals("9") && nine)
							{
								arr[d][c][0][b][2] = "w";
								arr[d][c][1][b][2] = "x";
								arr[d][c][2][b][2] = "y";
							}
							
							
							
							if(charAt[3].equals("2") && two)//FOURTH NUMBER
							{
								arr[d][c][b][0][3] = "a";
								arr[d][c][b][1][3] = "b";
								arr[d][c][b][2][3] = "c";
							}
							if(charAt[3].equals("3") && three)
							{
								arr[d][c][b][0][3] = "d";
								arr[d][c][b][1][3] = "e";
								arr[d][c][b][2][3] = "f";
							}
							if(charAt[3].equals("4") && four)
							{
								arr[d][c][b][0][3] = "g";
								arr[d][c][b][1][3] = "h";
								arr[d][c][b][2][3] = "i";
							}
							if(charAt[3].equals("5") && five)
							{
								arr[d][c][b][0][3] = "j";
								arr[d][c][b][1][3] = "k";
								arr[d][c][b][2][3] = "l";
							}
							if(charAt[3].equals("6") && six)
							{
								arr[d][c][b][0][3] = "m";
								arr[d][c][b][1][3] = "n";
								arr[d][c][b][2][3] = "o";
							}
							if(charAt[3].equals("7") && seven)
							{
								arr[d][c][b][0][3] = "p";
								arr[d][c][b][1][3] = "q";
								arr[d][c][b][2][3] = "r";
							}
							if(charAt[3].equals("8") && eight)
							{
								arr[d][c][b][0][3] = "t";
								arr[d][c][b][1][3] = "u";
								arr[d][c][b][2][3] = "v";
							}
							if(charAt[3].equals("9") && nine)
							{
								arr[d][c][b][0][3] = "w";
								arr[d][c][b][1][3] = "x";
								arr[d][c][b][2][3] = "y";
							}
						}
						
					}
				}
			}
		}
	}
	
	public static boolean[] errorMessage(String number)
	{
		boolean[] errorKind = new boolean[2];//0 INDEX IS SHORTLENGTH, 1 INDEX IS !LETTER
		String intString = number; 
		
		if(intString.length() < 4 || intString.length() > 4) //NORMAL OPERATION IS FALSE
		{
			errorKind[0] = true; //WOULD CREATE AN ERROR IN THE CODE
		}
		else
		{
			errorKind[0] = false; //NORMAL OPERATION
		}
		for(int i = 0; i < intString.length(); i++)//NORMAL OPERATION IS FALSE
		{
			String temp = Character.toString(intString.charAt(i));
			if(temp.equals("2") || temp.equals("3")|| temp.equals("4")
			|| temp.equals("5") || temp.equals("6") || temp.equals("7")
			|| temp.equals("8") || temp.equals("9"))
			{
				errorKind[1] = false; //WOULD CREATE AN ERROR IN THE CODE
			}
			else
			{
				errorKind[1] = true; //NORMAL OPERATION
				break;
			}
		}
		
		return errorKind;

	}
	
	public String toString()
	{
		int temp = 0;
		for(int a = 0; a < 3; a++)
		{
			for(int b = 0; b < 3; b++)
			{
				for(int c = 0; c < 3; c++)
				{
					for(int d = 0; d < 3; d++)
					{
						for(int e = 0; e < 4; e++)
						{
							returnString += arr[a][b][c][d][e];
							temp++;
							if(temp % 4 == 0)
							{
								if(temp == 81*4)
								{
									break;
								}
								returnString +=  "\n" +temp/4 + ". ";
							}	
						}
					}	
				}	
			}
		}
		return returnString;
	}
}






