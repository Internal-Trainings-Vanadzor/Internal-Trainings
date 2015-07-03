package introduction_functions;

import java.io.IOException;

public class main {
	public static void main(String args[]) throws IOException{
	RemoveComment remove = new RemoveComment();
	remove.rmooveCommentFromFile("input.txt", "//", "/*", "*/");
	ReversNumbers reverser = new ReversNumbers();
	int number = 12345;
	int reversedNumber = reverser.reverse(number);
	System.out.print("Reversed Number: " + reversedNumber);
}
}
