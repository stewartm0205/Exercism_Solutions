import java.util.ArrayList;
import java.util.List;

public class PascalsTriangleGenerator {
   int [][] pt;
    PascalsTriangleGenerator(){

    }

    int[][] generateTriangle(int order){
        if (order < 0) throw new IllegalArgumentException();
        pt = new int [order][];
        System.out.println("order="+order);
        if (order == 0) return(pt);
        for (int i = 0; i < order; i++) {
            pt[i] = new int[i+1];
            for (int j=0; j <= i; j++) {
                System.out.println("i="+i+",j="+j);
                if (j==0) pt[i][j] = 1;
                else if (j==i) pt[i][j] = 1;
                else pt[i][j] = pt[i-1][j-1]+pt[i-1][j];
            }
        }
        return (pt);
    }
}