package example.am;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class DeleteComment {

	void getTextWithoutComments(String lineComment, String firstScopComment,String lastScopComment) throws IOException {
	
		BufferedReader readFile = new BufferedReader(new FileReader("file.txt"));
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		boolean check = false;
		
		try {
			String line = readFile.readLine();
	
			while (line != null) {

				int indexofChar;
				if (line.contains(lineComment)) {

					indexofChar = line.indexOf(lineComment);
					String lineText = line.substring(0, indexofChar);
					writer.println(lineText);

				} else if (line.contains(firstScopComment)) {

					indexofChar = line.indexOf(firstScopComment);
					String lineText = line.substring(0, indexofChar);
					writer.println(lineText);
					check = true;

				}

				if (line.contains(lastScopComment) && check) {

					check = false;
					indexofChar = line.indexOf(lastScopComment);
					String lineText = line.substring(indexofChar + lastScopComment.length(), line.length());
					writer.println(lineText);
					
				} else if (!check && !line.contains(lineComment)) {
					
					writer.println(line);
					
				}

				line = readFile.readLine();
			}
		} finally {
			readFile.close();
			writer.close();
		}
	}

}
