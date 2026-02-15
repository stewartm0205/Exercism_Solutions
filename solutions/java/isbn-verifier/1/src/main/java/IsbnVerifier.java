class IsbnVerifier {

    boolean isValid(String stringToVerify) {
        String digits = "0123456789";
        int[] isbnDigits = new int[10];



        int nd = 0;
        int di = -1;
        for (int i = 0; i < stringToVerify.length(); i++){
            if (stringToVerify.substring(i, i+1).equals("-")) {
                // ignore '-'
            } else {
                int d = digits.indexOf(stringToVerify.substring(i, i+1));
                if (d>=0){
                    di++;
                    if (di>9) return(false);
                    isbnDigits[di]=d;
                    //System.out.println("di="+di+",d="+d);
                } else if (stringToVerify.substring(i, i+1).equals("X")) {
                    di++;
                    if (di!=9) return(false);
                    isbnDigits[di]=10;
                } else {
                    return(false);
                }
            }

        }
        if (di != 9) return (false);
        int sum = 0;
        di = 0;
        for (int m = 10; m > 0; m--) {
            sum += m * isbnDigits[di];
            di++;
        }
        //System.out.println("sum="+sum);
        int cd = sum % 11;
        //System.out.println("cd="+cd);
        if (cd == 0) return (true);
        else return (false);
    }

}