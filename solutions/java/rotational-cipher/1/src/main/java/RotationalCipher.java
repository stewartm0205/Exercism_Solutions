class RotationalCipher {

    String alphabet = "abcdefghijklmnopqrstuvwxyz";
    String abrot;

    RotationalCipher(int shiftKey) {
        abrot="";
       for (int i = 0; i < 26; i++) {
            abrot += alphabet.substring((i + shiftKey) % 26, ((i + shiftKey) % 26) + 1);
        }
        //System.out.println("abrot="+abrot);
    }

    String rotate(String data) {
        String rot = "";
        for (int i = 0; i < data.length(); i++) {
            if (alphabet.indexOf(data.substring(i, i + 1).toLowerCase()) >= 0) {
                if (Character.isUpperCase(data.charAt(i))) {
                    rot += abrot.substring(alphabet.indexOf(data.substring(i, i + 1).toLowerCase()),
                            alphabet.indexOf(data.substring(i, i + 1).toLowerCase()) + 1).toUpperCase();
                } else {
                    rot += abrot.substring(alphabet.indexOf(data.substring(i, i + 1)),
                            alphabet.indexOf(data.substring(i, i + 1)) + 1);
                }
            } else {
                rot += data.substring(i, i + 1);
            }
            //System.out.println("rot="+rot);
        }
        return(rot);
    }

}