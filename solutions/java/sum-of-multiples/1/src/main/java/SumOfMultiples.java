class SumOfMultiples {
    int number;
    int[] set;

    SumOfMultiples(int number, int[] set) {
        this.number = number;
        this.set = set;

    }

    int getSum() {
        int s = 0;
        int n = 1;
        while( n < number) {

            for (int i = 0; i < set.length && n < number; i++) {
                if (n % set[i] == 0){
                    //System.out.println("n,set[i]="+n+","+set[i]);
                    s += n;
                    break;
                }
            }
            n++;
        }
        return(s);
    }

}