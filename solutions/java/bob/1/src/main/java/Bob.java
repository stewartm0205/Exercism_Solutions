import java.util.regex.Pattern;

public class Bob {

    Bob () {}

    String hey(String phrase) {
        String response = "";

        boolean lc = Pattern.matches("^(.|\n)*[a-z]+(.|\n)*$",phrase);
        boolean e = Pattern.matches(".+! *$",phrase);
        boolean q = Pattern.matches(".+\\? *$",phrase);
        boolean caps = Pattern.matches(".*[A-Z]+.*",phrase);
        boolean och = Pattern.matches(".*[0-9,:{}]+.*",phrase);
        System.out.println(Pattern.matches("^(.|\n)*[a-z]+(.|\n)*$","\nDoes this cryogenic chamber make me look fat?\nno"));
        System.out.println("lc="+lc+",e="+e+",q="+q+",caps="+caps+",och="+och);

        if ((lc || och) && q)response="Sure.";
        else if (!lc && e)response="Whoa, chill out!";
        else if (!lc && caps & !q)response="Whoa, chill out!";
        else if (!lc && caps & q)response = "Calm down, I know what I'm doing!";
        else if (!lc && !e && !q && !caps && !och)response = "Fine. Be that way!";
        else response = "Whatever.";
        return(response);
    }

}