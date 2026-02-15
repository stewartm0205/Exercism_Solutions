class LuhnValidator {

    boolean isValid(String candidate) {
        int[] luhnDigits = new int[20];
        String digits = "0123456789";
        System.out.println("candidate="+candidate);

        int di = -1;
        for (int ci = 0; ci < candidate.length(); ci++){

            if (candidate.substring(ci, ci+1).equals(" ")) {
                // skip blanks
            } else if (digits.indexOf(candidate.substring(ci, ci+1)) < 0) {
                return (false);
            } else {
                di++;
                luhnDigits[di]=digits.indexOf(candidate.substring(ci, ci+1));
            }
        }
        if (di == 0 && luhnDigits[di]==0) return (false);
        // double every 2nd digit
        int lastd = di;
        System.out.println("lastd="+lastd);
        for (di = lastd-1; di >= 0; di -= 2) {
            luhnDigits[di] *= 2;
            if (luhnDigits[di] > 9) luhnDigits[di] -= 9;
            System.out.println("di="+di+",luhnDigits[di]="+luhnDigits[di]);
        }
        // sum up the digits
        int sum = 0;
        for (di = 0; di <= lastd; di++) {
            System.out.print(luhnDigits[di]);
            sum += luhnDigits[di];
        }
        System.out.println();
        System.out.println("sum="+sum);
        if (sum % 10 == 0) return (true);
        else return (false);
    }

}