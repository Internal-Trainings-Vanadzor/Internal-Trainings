package org.training.bracketChecker;

import org.apache.commons.io.FileUtils;

import java.io.*;


/**
 * @author Arman Kostandyan
 */
public class App {

    public static void main(String[] args) {
        BracketChecker bracketChecker = new BracketChecker();
        String text = readFromFile("sample.txt");

        String result = bracketChecker.check(text);
        System.out.println("Result: " + result);

    }

    private static String readFromFile(String fileName) {
        String content = "";
        ClassLoader classLoader = App.class.getClassLoader();
        File file = new File(classLoader.getResource(fileName).getFile());
        try {
            content = FileUtils.readFileToString(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return content;
    }
}
