import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Matrix {
    List<List<Integer>> matrix;
    Matrix(List<List<Integer>> values) {
        matrix = values;
    }

    Set<MatrixCoordinate> getSaddlePoints() {
        Set<MatrixCoordinate> sp = new HashSet<MatrixCoordinate>();
        int nr = matrix.size();
        System.out.println("nr="+nr);
        if (nr == 0) return(sp);
        int nc = matrix.get(0).size();
        System.out.println("nc="+nc);
        for (int i = 0; i < nr; i++){
            for (int j = 0; j < nc; j++){
                System.out.println("i="+i+", j="+j+", m[i,j]="+matrix.get(i).get(j));
                // check if M(i,j) a saddle point
                boolean issp = true;
                for (int ii = 0; ii < nr && issp; ii++) {
                    System.out.println("ii="+ii+", m[ii,j]="+matrix.get(ii).get(j));
                    if (ii != i & (matrix.get(i).get(j) > matrix.get(ii).get(j))) issp = false;
                }
                System.out.println("issp="+issp);
                for (int jj = 0; jj < nc && issp; jj++) {
                    System.out.println("jj="+jj+", m[i,jj]="+matrix.get(i).get(jj));
                    if (jj != j & (matrix.get(i).get(j) < matrix.get(i).get(jj))) issp = false;
                }
                System.out.println("issp="+issp);
                if (issp) sp.add(new MatrixCoordinate(i,j));
            }
       }

        return(sp);
    }
}