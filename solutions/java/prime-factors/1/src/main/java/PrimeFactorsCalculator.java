import java.util.ArrayList;
import java.util.List;

public class PrimeFactorsCalculator {

    PrimeFactorsCalculator (){}

     List<Long> calculatePrimeFactorsOf(Long input) {
        List<Long> primeFactors = new ArrayList<Long>();
        Long n = input;
        for (Long i = 2L; i <= n; i++) {
            while (n % i == 0) {
                //System.out.println("i="+i);
                primeFactors.add(i);
                n = n / i;
                //System.out.println("n="+n);
            }
        }
        return (primeFactors);
    }
}