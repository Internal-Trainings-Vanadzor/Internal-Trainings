package example.am;

public class InvertNumber {
	
	static int i_invertNumber = 0;
	int getInvertNumber(int i_tiv){
		
		if (i_tiv==0){return i_invertNumber;}
		i_invertNumber = i_invertNumber * 10 + i_tiv % 10;
		return getInvertNumber(i_tiv/10);
		
	}

}
