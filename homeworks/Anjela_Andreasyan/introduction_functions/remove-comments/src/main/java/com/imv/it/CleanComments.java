package com.imv.it;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CleanComments {
	private static final String QUOTE = "\"";
	private static final String SLASH = "\\";

	private String quoteRemainingTemp = "";
	private StringBuilder comments = new StringBuilder(""); // TODO add comments
															// to it
	private boolean isQuotFound = false;
	private boolean isStartBlockCommentFound = false;

	private String removeLineComments(String line, String commentSymbol) {
		if (line.contains(commentSymbol) && !line.contains(QUOTE)) {
			return removeLineComment(line, commentSymbol);
		} else if (line.contains(QUOTE) && line.contains(commentSymbol)) {
			int quoteIndex = line.indexOf(QUOTE);
			int commentIndex = line.indexOf(commentSymbol);
			if (commentIndex < quoteIndex) {
				return removeLineComment(line, commentSymbol);
			} else {
				line = separateComments(line, quoteIndex);
				if (!quoteRemainingTemp.isEmpty()) {
					line += removeLineComments(quoteRemainingTemp, commentSymbol);
					quoteRemainingTemp = "";
				}
			}
		}
		return line;
	}

	private String removeLineComment(String line, String commentSymbol) {
		int index = line.indexOf(commentSymbol);
		line = line.substring(0, index);
		return line;
	}

	private String removeBlockComments(String line, String startCommentSymbol, String endCommentSymbol) {
		if (!isStartBlockCommentFound) {
			if (line.contains(startCommentSymbol) && !line.contains(QUOTE)) {
				isStartBlockCommentFound = true;
				return deleteBlockComment(line, endCommentSymbol, startCommentSymbol);
			} else {
				if ((line.contains(startCommentSymbol) && line.contains(QUOTE))) {
					int quoteIndex = line.indexOf(QUOTE);
					int commentIndex = line.indexOf(startCommentSymbol);
					if (commentIndex < quoteIndex) {
						return deleteBlockComment(line, endCommentSymbol, startCommentSymbol);
					} else {
						line = separateComments(line, quoteIndex);
						if (!quoteRemainingTemp.isEmpty()) {
							line += removeBlockComments(quoteRemainingTemp, startCommentSymbol, endCommentSymbol);
							quoteRemainingTemp = "";
						}
						return line;
					}
				}
			}
		} else {
			line = checkForEndBlock(line, endCommentSymbol, startCommentSymbol);
		}
		return line;
	}

	private String separateComments(String line, int quoteIndex) {
		if (!isQuotFound) {
			isQuotFound = true;
			int secondQuotIndex = line.indexOf(QUOTE, quoteIndex + 1);
			if (secondQuotIndex != -1) {
				isQuotFound = false;
				String temp = line.substring(0, secondQuotIndex);
				if (line.length() > secondQuotIndex) {
					quoteRemainingTemp = line.substring(secondQuotIndex);
					return temp;
				}
			}
		} else {
			int secondQuotIndex = line.indexOf(QUOTE);
			if (secondQuotIndex == 0
					|| (secondQuotIndex >= 1 && !SLASH.equals(line.substring(secondQuotIndex - 1, secondQuotIndex)))) {
				isQuotFound = false;
				String temp = line.substring(0, secondQuotIndex);
				if (line.length() > secondQuotIndex) {
					quoteRemainingTemp = line.substring(secondQuotIndex);
					return temp;
				}
			}
		}
		return line;
	}

	private String deleteBlockComment(String line, String endCommentSymbol, String startCommentSymbol) {
		int index = line.indexOf(startCommentSymbol);
		String tempStr = line.substring(0, index);
		line = tempStr
				+ checkForEndBlock(line.substring(index + startCommentSymbol.length()), endCommentSymbol,
						startCommentSymbol);
		return line;
	}

	private String checkForEndBlock(String line, String endCommentSymbol, String startCommentSymbol) {
		if (line.contains(endCommentSymbol)) {
			isStartBlockCommentFound = false;
			int endBlockIndex = line.indexOf(endCommentSymbol);
			int nextIndex = endBlockIndex + endCommentSymbol.length() + 1;
			if (line.length() > nextIndex) {
				String tempLine = line.substring(nextIndex);
				line = tempLine + removeBlockComments(line.substring(nextIndex), startCommentSymbol, endCommentSymbol);
			} else {
				line = "";
			}
		} else {
			line = "";
		}
		return line;
	}

	public String readFileAndClearComments(String fileName, String lineComment, String startComment, String endComment) {
		StringBuilder result = new StringBuilder("");
		ClassLoader classLoader = getClass().getClassLoader();
		File file = new File(classLoader.getResource(fileName).getFile());
		try (Scanner scanner = new Scanner(file)) {
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				if (!line.isEmpty()) {
					line = removeBlockComments(line, startComment, endComment);
					line = removeLineComments(line, lineComment);
					if (!line.isEmpty()) {
						result.append(line).append("\n");
					}
				}
			}
			scanner.close();
		} catch (IOException e) {
			System.out.println("[Error] Could not read the string from the given file");
		}
		return result.toString();
	}

	public void writeClearedTextInFile(String path, String clearedText) {
		try {
			PrintWriter out = new PrintWriter(path);
			out.println(clearedText);
			out.close();
		} catch (FileNotFoundException e) {
			System.out.println("[Error] Could not write the string to the given file");
		}
	}
}
