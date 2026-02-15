import java.util.ArrayList;
import java.util.List;

public class Allergies {
    List<Allergen> allergies;
    Allergies(int allergiesIn) {
        allergies = new ArrayList<Allergen>();
        allergiesIn = allergiesIn % 256;
        if (allergiesIn%2 == 1) allergies.add(Allergen.EGGS);
        //System.out.println("allergiesIn="+allergiesIn);
        //System.out.println("allergies="+allergies);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.PEANUTS);
        //System.out.println("allergies="+allergies);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.SHELLFISH);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.STRAWBERRIES);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.TOMATOES);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.CHOCOLATE);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.POLLEN);
        allergiesIn = allergiesIn / 2;
        if (allergiesIn%2 == 1) allergies.add(Allergen.CATS);
    }
    Boolean isAllergicTo(Allergen allergenIn) {
        boolean allergicTo = false;
        for (Allergen allergen : allergies )
            if (allergen == allergenIn) allergicTo = true;
        return(allergicTo);
    }
    List<Allergen> getList () {
        return(allergies);
    }

    int size () {
        return (allergies.size());
    }
}