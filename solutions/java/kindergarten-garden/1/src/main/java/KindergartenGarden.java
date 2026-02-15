import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class KindergartenGarden {

    String[] students = {"Alice", "Bob", "Charlie", "David",
            "Eve", "Fred", "Ginny", "Harriet",
            "Ileana", "Joseph", "Kincaid", "Larry"};
    enum Plant {GRASS, CLOVER, RADISHES, VIOLETS};
    Plant[][] studentsPlants = new Plant[12][4];


    //KindergartenGarden(String garden, String[] students) {
   //
   //     this.students = students;
   // }

    KindergartenGarden(String garden) {
        String[][] sg = new String[12][4];
        int sl = garden.indexOf("\n");
        for (int si = 0 ; si < sl / 2; si++){
                sg[si][0] = garden.substring(2*si,2*si+1);
                sg[si][1] = garden.substring(2*si+1,2*si+2);
                sg[si][2] = garden.substring(sl+2*si+1,sl+2*si+2);
                sg[si][3] = garden.substring(sl+2*si+2,sl+2*si+3);
                for (int i = 0; i < 4; i++) {
                    if (sg[si][i].equals("V")) studentsPlants[si][i] = Plant.VIOLETS;
                    if (sg[si][i].equals("R")) studentsPlants[si][i] = Plant.RADISHES;
                    if (sg[si][i].equals("C")) studentsPlants[si][i] = Plant.CLOVER;
                    if (sg[si][i].equals("G")) studentsPlants[si][i] = Plant.GRASS;
                }
        }

    }

    List<Plant> getPlantsOfStudent(String student) {

        for (int si = 0; si < students.length; si++ ) {
            if (students[si].equals(student)) {
                return(Arrays.asList(studentsPlants[si]));
            }
        }
        return(Arrays.asList(studentsPlants[0]));

    }

}