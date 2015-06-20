package com.imv.it;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CleanComments {
	private static String quote = "\"";
	private static String quoteRemainingTemp = "";
	private static boolean isQuotFound = false;
	private static boolean isStartBlockCommentFound = false;

	private static String removeLineComments(String line, String commentSymbol) {
		if (line.contains(commentSymbol) && !line.contains(quote)) {
			return removeLineComment(line, commentSymbol);
		} else if (line.contains(quote) && line.contains(commentSymbol)) {
			int quoteIndex = line.indexOf(quote);
			int commentIndex = line.indexOf(commentSymbol);
			if (commentIndex < quoteIndex) {
				return removeLineComment(line, commentSymbol);
			} else {
				line = separateComments(line, quoteIndex);
				if (!quoteRemainingTemp.isEmpty()) {
					line += removeLineComments(quoteRemainingTemp,
							commentSymbol);
					quoteRemainingTemp = "";
				}
			}
		}
		return line;

	}

	private static String removeLineComment(String line, String commentSymbol) {
		int index = line.indexOf(commentSymbol);
		line = line.substring(0, index);
		return line;
	}

	private static String removeBlockComments(String line,
			String startCommentSymbol, String endCommentSymbol) {
		if (!isStartBlockCommentFound) {
			if (line.contains(startCommentSymbol) && !line.contains(quote)) {
				isStartBlockCommentFound = true;
				return deleteBlockComment(line, endCommentSymbol,
						startCommentSymbol);
			} else {
				if ((line.contains(startCommentSymbol) && line.contains(quote))) {
					int quoteIndex = line.indexOf(quote);
					int commentIndex = line.indexOf(startCommentSymbol);
					if (commentIndex < quoteIndex) {
						return deleteBlockComment(line, endCommentSymbol,
								startCommentSymbol);
					} else {
						line = separateComments(line, quoteIndex);
						if (!quoteRemainingTemp.isEmpty()) {
							line += removeBlockComments(quoteRemainingTemp,
									startCommentSymbol, endCommentSymbol);
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

	private static String separateComments(String line, int quoteIndex) {
		if (!isQuotFound) {
			isQuotFound = true;
			int secondQuotIndex = line.indexOf(quote, quoteIndex + 1);
			if (secondQuotIndex != -1) {
				isQuotFound = false;
				String temp = line.substring(0, secondQuotIndex);
				if (line.length() > secondQuotIndex) {
					quoteRemainingTemp = line.substring(secondQuotIndex);
					return temp;
				}
			}
		} else {
			int secondQuotIndex = line.indexOf(quote);
			if (secondQuotIndex != -1) {
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

	private static String deleteBlockComment(String line,
			String endCommentSymbol, String startCommentSymbol) {
		int index = line.indexOf(startCommentSymbol);
		String tempStr = line.substring(0, index);
		line = tempStr
				+ checkForEndBlock(
						line.substring(index + startCommentSymbol.length()),
						endCommentSymbol, startCommentSymbol);
		return line;

	}

	private static String checkForEndBlock(String line,
			String endCommentSymbol, String startCommentSymbol) {
		if (line.contains(endCommentSymbol)) {
			isStartBlockCommentFound = false;
			int endBlockIndex = line.indexOf(endCommentSymbol);
			String tempLine = line.substring(endBlockIndex
					+ endCommentSymbol.length());
			if (line.length() > endBlockIndex + endCommentSymbol.length()) {
				line = tempLine
						+ removeBlockComments(
								line.substring(endBlockIndex
										+ endCommentSymbol.length()),
								startCommentSymbol, endCommentSymbol);
			}
		} else {
			line = "";
		}
		return line;
	}

	public String readFileAndClearComments(String fileName, String lineComment,
			String startCommentSymbol, String endCommentSymbol) {

		StringBuilder result = new StringBuilder("");

		ClassLoader classLoader = getClass().getClassLoader();
		File file = new File(classLoader.getResource(fileName).getFile());

		try (Scanner scanner = new Scanner(file)) {

			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				line = removeLineComments(line, lineComment);
				line = removeBlockComments(line, startCommentSymbol,
						endCommentSymbol);
				result.append(line).append("\n");
			}
			scanner.close();

		} catch (IOException e) {
			e.printStackTrace();
			System.out
					.println("[Error] Could not read the string from the given file");
		}
		return result.toString();

	}

	public void writeClearedTextInFile(String path, String clearedText) {
		try {
			PrintWriter out = new PrintWriter(path);
			out.println(clearedText);
			out.close();
		} catch (FileNotFoundException e) {
			System.out
					.println("[Error] Could not write the string to the given file");
		}
	}
}
