class Hamming {
    String leftStrand;
    String rightStrand;

    Hamming(String leftStrand, String rightStrand) {

        this.leftStrand = leftStrand;
        this.rightStrand = rightStrand;

        if (this.leftStrand.length() != this.rightStrand.length()) {
            throw new IllegalArgumentException("leftStrand and rightStrand must be of equal length.");
        }
    }
        int getHammingDistance () {
            int h = 0;
            for (int i = 0; i < leftStrand.length(); i++) {
                if (leftStrand.substring(i, i + 1).equals(rightStrand.substring(i, i + 1))) {
                    // nothing
                }
                else {
                        //System.out.println("leftStrand.substring(i, i+1)=" + leftStrand.substring(i, i + 1));
                        //System.out.println("rightStrand.substring(i, i+1)=" + rightStrand.substring(i, i + 1));
                        h += 1;
                        //System.out.println("s=" + h);
                    }
                }
                return(h);
            }
        }