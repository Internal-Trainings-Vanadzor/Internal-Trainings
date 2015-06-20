package com.imv.it;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CleanComments {
	private static String quote = "\"";
	private static boolean isQuotFound = false;

	private static String removeLineComments(String line, String commentSymbol) {
		if (line.contains(commentSymbol) && !line.contains(quote)) {
			int index = line.indexOf(commentSymbol);
			line = line.substring(0, index);
			return line;
		} else if (line.contains(quote) && line.contains(commentSymbol)) {
			if (!isQuotFound) {
				isQuotFound = true;
				int quoteIndex = line.indexOf(quote);
				// line = line.substring(0, quoteIndex);
				int secondQuotIndex = line.indexOf(quote, quoteIndex);
				if (secondQuotIndex != -1) {
					isQuotFound = false;
					String temp = line.substring(0, secondQuotIndex);
					if (!line.substring(secondQuotIndex + 1).isEmpty()) {
						line = temp
								+ removeLineComments(
										line.substring(secondQuotIndex + 1),
										commentSymbol);
					}
				}
			} else {
				int secondQuotIndex = line.indexOf(quote);
				if (secondQuotIndex != -1) {
					isQuotFound = false;
					String temp = line.substring(0, secondQuotIndex);
					if (!line.substring(secondQuotIndex + 1).isEmpty()) {
						line = temp
								+ removeLineComments(
										line.substring(secondQuotIndex + 1),
										commentSymbol);
					}
				}
			}
		}
		return line;

	}

	private static String removeBlockComments(String line,
			String startCommentSymbol, String endCommentSymbol) {
		return line;
	}

	public String readFileAndClearComments(String fileName, String lineComment,
			String startCommentSymbol, String endCommentSymbol) {

		StringBuilder result = new StringBuilder("");

		// Get file from resources folder
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
