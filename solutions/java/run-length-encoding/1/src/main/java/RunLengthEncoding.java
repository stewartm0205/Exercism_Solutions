import static java.lang.Integer.parseInt;

public class RunLengthEncoding {
    RunLengthEncoding() {
    }

    String encode (String toEncodeStr) {
        String encodeStr = "";
        int i = 0;
        while (i < toEncodeStr.length()) {
            int c = 0;
            String ch = toEncodeStr.substring(i,i+1);
            int nc = 1;
            for (int j=i+1; j < toEncodeStr.length() && ch.equals(toEncodeStr.substring(j, j+1)); j++ ) {
                nc += 1;
                i++;
            }
            if (nc > 1) encodeStr +=  Integer.toString(nc) + ch;
            else encodeStr +=  ch;
            i++;
        }
        return (encodeStr);
    }

    String decode (String toDecodeStr) {
        String decodeStr = "";
        String numbers = "0123456789";
        int i = 0;
        while (i < toDecodeStr.length()) {
            // check for integer
            String cStr = "";
            for (int j = i; j <= toDecodeStr.length() && numbers.indexOf(toDecodeStr.substring(j,j+1))>=0; j++) cStr += toDecodeStr.substring(j,j+1);
            if (cStr.length()>0) {
                i += cStr.length();
                int nc = parseInt(cStr);
                String ch = toDecodeStr.substring(i,i+1);
                for (int j = 0; j < nc; j++) decodeStr += ch;
            } else {
                decodeStr += toDecodeStr.substring(i,i+1);
            }
            i++;
        }
        return (decodeStr);
    }
}