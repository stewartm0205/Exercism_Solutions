class RnaTranscription {

    String dnaTemplate = "GCTA";
    String rnaTemplate = "CGAU";
    String transcribe(String dnaStrand) {
        //System.out.println("dnaStrand=" + dnaStrand);
        String rnaStrand = "";
        for (int i = 0; i < dnaStrand.length(); i++) {
            int di = dnaTemplate.indexOf(dnaStrand.substring(i, i + 1));
            String rl = rnaTemplate.substring(di, di + 1);
            //System.out.println("dl=" + dnaStrand.substring(i, i + 1));
            //System.out.println("di=" + di);
            //System.out.println("rl=" + rl);
            rnaStrand += rl;
        }
        //System.out.println("rnaStrand=" + rnaStrand);

        return(rnaStrand);

    }
    public void RnaTranscription (){

    };
}