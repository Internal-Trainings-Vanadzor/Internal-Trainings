package example.am;

import java.io.IOException;
import java.util.Scanner;

public class DeleteCommentMain {	
	static Scanner in=new Scanner(System.in);
	
	public static void main(String[] args) throws IOException{
		
		//get text without comments
		  System.out.println("....................<get text without comments>.................");
		  DeleteComment deleteComment=new DeleteComment();		
		  System.out.println("Please input the Line comment simbol ...");
		  String lineComment=in.nextLine();
		  System.out.println("Please input the block comment's first simbol ...");
		  String firstScopComment =in.nextLine();
		  System.out.println("Please input the block comment's first simbol ...");
		  String lastScopComment= in.nextLine();	
		  deleteComment.getTextWithoutComments(lineComment,firstScopComment,lastScopComment);
		  
		//get text inverting number
		  System.out.println("....................<get text inverting number>.................");
		  InvertNumber invertNumber=new InvertNumber();		 
		  System.out.println("Please input the number ..."+'\n');
		  String i_inputNumber1 =in.nextLine();
		  int y=invertNumber.getInvertNumber(Integer.parseInt(i_inputNumber1));
		  System.out.println("Results : " + y);
	}

}
