class

LargestSeriesProductCalculator {
    String numbers;
    String digits="0123456789";
    LargestSeriesProductCalculator(String inputNumber) {
        numbers = inputNumber;
        for (int i = 0; i<numbers.length(); i++) {
            if (digits.indexOf(numbers.substring(i, i+1)) < 0)
                throw new IllegalArgumentException("String to search may only contain digits.");
        }


    }

    long calculateLargestProductForSeriesLength(int numberOfDigits) {
        System.out.println("numbers="+numbers);
        System.out.println("numberOfDigits="+numberOfDigits);
        if (numberOfDigits > numbers.length())
            throw new IllegalArgumentException("Series length must be less than or equal to the length of the string to search.");
        if (numberOfDigits < 0)
            throw new IllegalArgumentException("Series length must be non-negative.");
        int maxprod=0;
        for (int i = 0; i<numbers.length()-numberOfDigits+1; i++) {
            int prod = 1;
            for (int j = i; j < i + numberOfDigits; j++) {
                System.out.print("i="+i);
                System.out.print(",j="+j);
                System.out.println(",digit="+digits.indexOf(numbers.substring(j, j+1)));
                prod *= digits.indexOf(numbers.substring(j, j+1));
            }
            if (prod > maxprod) {
                maxprod = prod;
                System.out.println("newmaxprod="+maxprod);
            }
        }
        return(maxprod);


    }
}