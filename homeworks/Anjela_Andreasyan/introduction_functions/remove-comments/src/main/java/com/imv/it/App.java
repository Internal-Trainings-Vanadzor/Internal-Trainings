package com.imv.it;


/**
 * Hello world!
 * 
 */
public class App {
	public static void main(String[] args) {
		CleanComments clearer = new CleanComments();
		String clearedText = clearer.readFileAndClearComments("file_with_comments.java", "//", "/*",
				"*/");
		System.out.println("Read and cleared text " + clearedText);
		clearer.writeClearedTextInFile("file_without_comments.java", clearedText);
	}

}
