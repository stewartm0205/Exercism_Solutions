class ReverseString {

    String reverse(String inputString) {
        String s = "";
        int l = inputString.length();
        for (int j = 0; j<l; j++ ) {
                s = s + inputString.substring((l - j) - 1, l - j);
        }
        return (s);
    }
  
}