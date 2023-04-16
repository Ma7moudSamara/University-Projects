// 1191602     MAHMOUD SAMARA   COMP231      SECTION 2

// This JAVA code shows the Nice numbers programming , we say the number is nice if its every digit is larger than the sum of digits which are on the right side of that digit

import java.util.Scanner; // importing a scanner 

public class Nice_num { // THE Main Method
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in); // Creating a Scanner object to read inputs (numbers that user will
												// enter)

		System.out.println(" *************************** Welcome to the program *************************** \n ");
		System.out.println(" <<This program prints all nice numbers in a given range that user will enter it >> \n ");
		System.out.println(" Please Enter left bound: \n "); // asking user to print the value of the left bound
		int left_bound = input.nextInt(); // Declare left_bound to be an integer variable and user will enter it's
											// value;
		System.out.println(" Please Enter right bound : \n "); // asking user to print the value of the right bound
		int right_bound = input.nextInt(); // Declare right_bound to be an integer variable and user will enter it's
											// value;
		System.out.println("Please Enter the arbitrary digit (m): \n "); // asking user to print the value of the
																			// arbitrary digit (m)
		int arbitrary_digit = input.nextInt(); // Declare arbitrary to be an integer variable and user will enter it's
												// value;
		if (left_bound >= right_bound || arbitrary_digit > 9) { // if statement to check if inputs right or not because
																// left must be less than right otherwise print wrong
																// for user and (m)must be [0...9] otherwise print wrong
																// for user.
			System.out.println(
					" **Sorry something went wrong because you have entered wrong numbers because left bound must be less than right bound , or you eneterd wrong excluding digit** \n ");
			System.exit(0);
		}
		System.out.println("\n[ So the numbers that the user entered is, the left bound is : (" + left_bound
				+ ") and right bound is : (" + right_bound + ") and excluding a given digit (m) is :  ("
				+ arbitrary_digit + ") ]\n");
		System.out.println(
				"                             ************************************************************************* \n ");
		System.out.println("[[ All Nice numbers between the left bound that is: ((" + left_bound
				+ ")) and right bound that is : ((" + right_bound + ")) with excluding digit that is :  (("
				+ arbitrary_digit + ")) ]] \n");
		niceNumbers(left_bound, right_bound, arbitrary_digit);
	}

// function to find all nice numbers in the given range that the user enterd;
	public static void niceNumbers(int left, int right, int digit) {

		for (int num = left; num <= right; num++) {
			int sign = num;
			int rest = num % 10; // to get the last digit of the number.
			int sum = rest; // storing the sum of digits that is at the right side of the number.
			int flag = 1; // boolean flag

			if (rest == digit) // checking if last digit of number equals the excluding digit if yes don't take
								// this number and continue.
				continue;

			sign /= 10; // to make the checking again for the remaining number and divide by 10.

			while (sign != 0) {

				rest = sign % 10; // to take the current digit because here we get the reminder

				if (rest == digit || rest <= sum) { // If rest equals digit or rest is less than or
													// equal to sum of digits on right side then this number is not nice
													// and don't take it.
					flag = 0;
					break;
				}

				else {
					sum = sum + rest;
					sign /= 10;
				}
			}
			if (flag == 1)
				System.out.println(num + "\n"); // printing all the nice numbers.
		}
	}
}