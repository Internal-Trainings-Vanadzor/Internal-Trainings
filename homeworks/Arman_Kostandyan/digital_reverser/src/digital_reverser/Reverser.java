package digital_reverser;

public class Reverser {

	private int reversedDigit = 0;
	
	/**
	 * Reverses the given digit(e.g. 147 -> 741)
	 * 
	 * @param digit
	 * @return reversed digit
	 */
	public int reverse(int digit) {
		if(digit <= 0) {
			return reversedDigit;
		}
		int remainder = digit % 10;
		reversedDigit = reversedDigit * 10 + remainder;
		
		return reverse(digit / 10);
	}
}
