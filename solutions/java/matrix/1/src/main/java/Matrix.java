class Matrix {

    int [][] matrix = new int[10][10];
    int maxr;
    int maxc;

    Matrix(String matrixAsString) {
        String digits = "0123456789";
        int r = 0;
        int c = -1;

        for (int i = 0; i < matrixAsString.length(); i++){
            if (digits.indexOf(matrixAsString.substring(i, i+1))>=0){
                c++;
                matrix[r][c]=digits.indexOf(matrixAsString.substring(i, i+1));
            } else if (matrixAsString.substring(i, i+1).equals("\n")) {
                r++;
            } else {
                // nothing
            }
        }
        maxr = r;
        maxc = c;
    }

    int[] getRow(int rowNumber) {
        int[] row = new int[10];
        for (int c = 0; c < maxc; c++) {
            row[c] = matrix[rowNumber][c];
        }
        return(row);
    }

    int[] getColumn(int columnNumber) {
        int[] col = new int[10];
        for (int r = 0; r < maxr; r++) {
            col[r] = matrix[r][columnNumber];
        }
        return(col);
    }

    int getRowsCount() {
        return (maxr + 1);
    }

    int getColumnsCount() {
        return (maxc + 1);
    }
}