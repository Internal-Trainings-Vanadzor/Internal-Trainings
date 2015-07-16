package number_reverser;

import java.util.Scanner;

/**
 * @author Arman Kostandyan
 *
 */
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Reverser reverser = new Reverser();

		System.out.print("Enter an integer number: ");
		
		int num = in.nextInt();
		int reversedNum = reverser.reverse(num);

		System.out.print("Result: " + reversedNum);
	}

}
