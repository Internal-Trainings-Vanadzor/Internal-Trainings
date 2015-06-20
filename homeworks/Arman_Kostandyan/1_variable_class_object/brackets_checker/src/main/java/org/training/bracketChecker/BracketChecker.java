package org.training.bracketChecker;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.Stack;

/**
 * Created by Arman on 6/13/15.
 */
public class BracketChecker {

    Stack<Character> bracketsStack = new Stack<>();

    private JSONArray brackets = new JSONArray("[" +
            " {'begin': '{', 'end': '}'}, " +
            " {'begin': '[', 'end': ']'}, " +
            " {'begin': '(', 'end': ')'}, " +
            " {'begin': '\"'} " +
            "]");

    public JSONArray getBrackets() {
        return brackets;
    }

    public String check(String text) {

        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (isOpeningBracket(c)) {
                bracketsStack.push(c);
            } else if (isClosingBracket(c)) {
                if (!areBracketsPair(bracketsStack.pop(), c)) {
                    return "Oops, the text is wrong.";
                }
            }
        }
        if (bracketsStack.size() != 0) {
            return "Oops, there is unclosed bracket.";
        }
        return "Everything is successful!";
    }

    private boolean areBracketsPair(char openingBracket, char closingBracket) {
        for (int i = 0; i < brackets.length(); i++) {
            JSONObject bracket = brackets.getJSONObject(i);
            String begin = bracket.getString("begin");
            if (begin.equals(String.valueOf(openingBracket))) {
                if (bracket.has("end")) {
                    if (bracket.getString("end").equals(String.valueOf(closingBracket))) {
                        return true;
                    }
                } else {
                    if (begin.equals(String.valueOf(closingBracket))) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }

    private boolean isClosingBracket(char c) {
        for (int i = 0; i < brackets.length(); i++) {
            JSONObject bracket = brackets.getJSONObject(i);
            if (!bracket.has("end")) {
                if (String.valueOf(c).equals(bracket.getString("begin"))) {
                    return true;
                }
            } else { // if there is 'end' key
                if (String.valueOf(c).equals(bracket.getString("end"))) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean isOpeningBracket(char c) {
        for (int i = 0; i < brackets.length(); i++) {
            JSONObject bracket = brackets.getJSONObject(i);
            if (String.valueOf(c).equals(bracket.getString("begin"))) {
                if (!bracket.has("end")) {
                    if (!bracketsStack.isEmpty() && bracketsStack.peek() == c) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
}
