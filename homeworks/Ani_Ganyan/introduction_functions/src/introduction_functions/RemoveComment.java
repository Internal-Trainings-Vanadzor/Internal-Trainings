package introduction_functions;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

public class RemoveComment {
	private boolean checker = false;
	public void rmooveCommentFromFile(String fileName,
			String lineCommentSymbol, String openComment,
			String closeComment) throws FileNotFoundException,
			UnsupportedEncodingException {
		BufferedReader input = readFromFile(fileName);
		PrintWriter output = new PrintWriter("output.txt");
		String line;
		try {
			while ((line = input.readLine()) != null) {
				if (line.contains(openComment)
						|| line.contains(closeComment) || checker) {
					line = removeBlockComment(line, openComment,
							closeComment);
				}
				line = removeLineComment(line, lineCommentSymbol);
				if (!line.isEmpty()) {
					output.println(line);
				}
			}
		} catch (IOException e) {
			output.println("line not found");
		}
		output.close();
	}

	private BufferedReader readFromFile(String fileName) {
		BufferedReader input = null; 
		try {
			input = new BufferedReader(new FileReader(fileName));
		} catch (FileNotFoundException e) {
			System.out.println("file not found");
		}
		return input;
	}

	private String removeLineComment(String line, String lineComment) {
		int offset = line.indexOf(lineComment);
		if (-1 != offset) {
			line = line.substring(0, offset);
		}
		return line;
	}

	private String removeBlockComment(String line, String openComment,
			String closeComment) {
		if (line.contains(openComment)
				&& line.contains(closeComment)) {
			while (line.contains(closeComment)) {
				int startIndex = line.indexOf(openComment);
				int endIndex = line.indexOf(closeComment);
				String comment = line.substring(startIndex, endIndex + 2);
				line = line.replace(comment, "");
			}
		}
		if (line.contains(openComment)) {
			line = removeLineComment(line, openComment);
			checker = true;
			return line;
		}
		if (checker && line.contains(closeComment)) {
			int endIndex = line.indexOf(closeComment);
			line = line.substring(endIndex + 2);
			checker = false;
			return line;
		} else if (checker) {
			return "";
		}
		return line;
	}

}
