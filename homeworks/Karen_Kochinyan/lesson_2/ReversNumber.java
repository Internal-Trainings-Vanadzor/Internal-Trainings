/*
 TUDO
 */
package reversnumber;

public class ReversNumber {

    private Integer number = 123456789;

    public static void main(String[] args) {
        ReversNumber obj = new ReversNumber();
        System.out.println(obj.numberReverser());
        obj.setNumber(555566668);
        System.out.println(obj.numberReverser());
    }

    public void setNumber(Integer num) {
        this.number = num;
    }

    public Integer getNumber() {
        return this.number;
    }

    public Integer numberReverser() {
        Integer reversedNum = 0;
        int lengthNum = this.getNumber().toString().length();
        for (int i = 1; i <= lengthNum; ++i) {
            int point = (int) Math.floor(this.number % ((int) Math.pow(10, i)) / (int) Math.pow(10, i - 1));
            reversedNum += point * (int) Math.pow(10, lengthNum - i);
        }
        return reversedNum;
    }
}
