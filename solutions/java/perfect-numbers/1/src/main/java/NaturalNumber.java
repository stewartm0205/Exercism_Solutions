class NaturalNumber {
    int number;
    Classification numberClassification;

    public Classification getClassification() {

        this.number = number;
        int s = 1;

        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) s += i;
        }
        //System.out.println("s="+s);
        if (s == number && number != 1) numberClassification = Classification.PERFECT;
        else if (s > number) numberClassification = Classification.ABUNDANT;
        else  numberClassification = Classification.DEFICIENT;
        return (numberClassification);
    }

    NaturalNumber(int number) {

        if (number < 1){
            throw new IllegalArgumentException("You must supply a natural number (positive integer)");
        }
        this.number = number;
    }

}