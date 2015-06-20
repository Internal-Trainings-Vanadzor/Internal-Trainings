package number_reverser;

public class Reverser {

	private int reversedNumber = 0;
	
	/**
	 * Reverses the given number(e.g. 147 -> 741)
	 * 
	 * @param number
	 * @return reversed number
	 */
	public int reverse(int number) {
		if(number <= 0) {
			return reversedNumber;
		}
		int remainder = number % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		
		return reverse(number / 10);
	}
}
