import java.util.Random;

public class Robot {
    String name;
    Random rand = new Random();

    Robot() {
        generateName();
    }

    void generateName() {
        String alphabet = "abcdefghijklmnopqrstuvwxyz".toUpperCase();
        String number = "0123456789";
        name = "";
    int i = rand.nextInt(26);
    name =alphabet.substring(i,i+1);
    i =rand.nextInt(26);
    name +=alphabet.substring(i,i+1);
    i =rand.nextInt(10);
    name +=number.substring(i,i+1);
    i =rand.nextInt(10);
    name +=number.substring(i,i+1);
    i =rand.nextInt(10);
    name +=number.substring(i,i+1);
}

    String getName () {
        return(name);
    }

    void reset () {
        generateName();
    }

}