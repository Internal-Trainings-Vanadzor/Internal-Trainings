package com.imv.it;

/**
 * A simple app which removes comments from a file using CleanComments class
 * 
 */
public class App {
	public static void main(String[] args) {
		CleanComments clearer = new CleanComments();
		String clearedText = clearer.readFileAndClearComments(
				"file_with_comments.java", "//", "/*", "*/");
		System.out.println("[Info] Read and cleared from comment text "
				+ clearedText);
		clearer.writeClearedTextInFile("file_without_comments.java",
				clearedText);
	}

}
