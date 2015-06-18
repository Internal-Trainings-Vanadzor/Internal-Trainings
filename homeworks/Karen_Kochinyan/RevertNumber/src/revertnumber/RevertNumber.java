/*
 TUDO
 */
package revertnumber;

public class RevertNumber {

    private Integer number = 123456789;

    public static void main(String[] args) {
        RevertNumber obj = new RevertNumber();
        System.out.println(obj.numberReverter());
        obj.setNumber(555566668);
        System.out.println(obj.numberReverter());
    }

    public void setNumber(Integer num) {
        this.number = num;
    }

    public Integer getNumber() {
        return this.number;
    }

    public Integer numberReverter() {
        Integer revertedNum = 0;
        int lengthNum = this.getNumber().toString().length();
        for (int i = 1; i <= lengthNum; ++i) {
            int point = (int) Math.floor(this.number % ((int) Math.pow(10, i)) / (int) Math.pow(10, i - 1));
            revertedNum += point * (int) Math.pow(10, lengthNum - i);
        }
        return revertedNum;
    }
}
