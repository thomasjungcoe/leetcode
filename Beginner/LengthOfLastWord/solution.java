class Solution {
    public int lengthOfLastWord(String s) {
        int end = s.length() - 1;

        while (end >= 0 && s.charAt(end) == ' ') {
            end--;
        }

        int newEnd = end;

        while (newEnd >= 0 && s.charAt(newEnd) != ' ') {
            newEnd--;
        }

        return end - newEnd;
    }
}