class DifferenceOfSquaresCalculator {

    int computeSquareOfSumTo(int input) {
        int s=0;
        for (int i = 1; i <= input; i++){
            s += i;
        }
        return(s * s);
    }

    int computeSumOfSquaresTo(int input) {
        int s=0;
        for (int i = 1; i<= input; i++){
            s += i * i;
        }
        return(s );
    }

    int computeDifferenceOfSquares(int input) {
        return(computeSquareOfSumTo(input) - computeSumOfSquaresTo(input));
    }

}