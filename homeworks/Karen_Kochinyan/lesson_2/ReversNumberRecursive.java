package reversnumberrecursive;

public class ReversNumberRecursive {

    private static int number;
    private int reversedNum = 0;

    public static void main(String[] args) {
        ReversNumberRecursive obj = new ReversNumberRecursive();
        System.out.println(obj.numberReverser(123456789));
    }

    public int numberReverser(int number) {
        if (number > 0) {
            reversedNum = number % 10 + reversedNum * 10;
            number = (int) Math.floor(number / 10);
            numberReverser(number);
        }
        return reversedNum;
    }
}
