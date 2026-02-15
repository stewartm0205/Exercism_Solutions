import java.util.ArrayList;
import java.util.List;

class PrimeCalculator {
    Sieve sieve = new Sieve(105000);

    int nth(int nth) {
        if (nth <= 0) throw new IllegalArgumentException();
        List<Integer> primes = sieve.getPrimes();
        return(primes.get(nth-1));
    }

    class Sieve {
        List<Integer> primes = new ArrayList<Integer>();

        Sieve(int maxPrime) {

            if (maxPrime == 1) return;
            primes.add(2);
            for (int i = 3; i < maxPrime; i+=2) primes.add(i);
            for (int j = 1; j < primes.size(); j++) {
                int k = j+1;
                while(k < primes.size()){
                    //System.out.println("j="+j+",k="+k);
                    if (primes.get(k) % primes.get(j) == 0) primes.remove(k);
                    else k++;
                }
            }
        }

        public List<Integer> getPrimes() {
            return(primes);
        }
    }
}