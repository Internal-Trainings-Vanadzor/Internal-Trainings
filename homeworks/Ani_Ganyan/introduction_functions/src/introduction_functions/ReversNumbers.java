package introduction_functions;

public class ReversNumbers {
	private int reversedNumber = 0;

	public int reverse(int number) {
		if (number <= 0) {
			return reversedNumber;
		}
		reversedNumber = reversedNumber * 10 + number % 10;
		return reverse(number / 10);
	}
}