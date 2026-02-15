import java.util.List;
import java.util.ArrayList;

class HandshakeCalculator {
   // enum Signal {
   //     WINK, DOUBLE_BLINK, CLOSE_YOUR_EYES, JUMP
   // };

    HandshakeCalculator(){

    }

    List<Signal> calculateHandshake(int number) {
        int n = number;
        String bits = "";
        List<Signal> signals = new ArrayList<Signal>();
        while(n>0){
            int b = n % 2;
            if (b == 1) bits = "1" + bits;
            else bits = "0" + bits;
            System.out.println("bits="+bits);
            n = n / 2;
        }
        System.out.println("bits="+bits);
        System.out.println("bits.length()="+bits.length());
        if (bits.length()>=1 && bits.substring(bits.length()-1,bits.length()).equals("1")){
            signals.add(Signal.WINK);
        }
        if (bits.length()>=2 && bits.substring(bits.length()-2,bits.length()-1).equals("1")){
            signals.add(Signal.DOUBLE_BLINK);
        }
        if (bits.length()>=3 && bits.substring(bits.length()-3,bits.length()-2).equals("1")){
            signals.add(Signal.CLOSE_YOUR_EYES);
        }
        if (bits.length()>=4 && bits.substring(bits.length()-4,bits.length()-3).equals("1")){
            signals.add(Signal.JUMP);
        }
        if (bits.length()>=5 && bits.substring(bits.length()-5,bits.length()-4).equals("1")){
            List<Signal> reversesignals = new ArrayList<Signal>();
            for (int i = 0; i < signals.size(); i++) {

                reversesignals.add(signals.get(signals.size() - i - 1));
            }
            signals = reversesignals;
        }
        return (signals);
    }

}