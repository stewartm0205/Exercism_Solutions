public class PhoneNumber {
    private final static String wrongLengthExceptionMessage = "Number must be 10 or 11 digits";
    private final static String numberIs11DigitsButDoesNotStartWith1ExceptionMessage =
            "Can only have 11 digits if number starts with '1'";
    private final static String illegalCharacterExceptionMessage =
            "Illegal character in phone number. Only digits, spaces, parentheses, hyphens or dots accepted.";
    private final static String illegalAreaOrExchangeCodeMessage =
            "Illegal Area Or Exchange Code. Only 2-9 are valid digits";
    String enteredNumber;
    String actualNumber;

    PhoneNumber(String enteredNumber) {
        String numbers = "0123456789";
        String validphonenumberchars = numbers + " ()-.+";
        String areacodenumbers = numbers.substring(2,10);

        //System.out.println("enteredNumber="+enteredNumber);
        actualNumber = "";
        for (int i = 0; i < enteredNumber.length(); i++) {
            if (validphonenumberchars.indexOf(enteredNumber.substring(i,i+1))<0)
                throw new IllegalArgumentException(illegalCharacterExceptionMessage);
            if (numbers.indexOf(enteredNumber.substring(i,i+1))>=0){
                actualNumber += enteredNumber.substring(i,i+1);
            }
        }
        //System.out.println("actualNumber="+actualNumber);
        if (actualNumber.length() != 10 && actualNumber.length() != 11 )
            throw new IllegalArgumentException(wrongLengthExceptionMessage);
        if (actualNumber.length() == 11 && actualNumber.substring(0,1).equals("1") == false)
            throw new IllegalArgumentException(numberIs11DigitsButDoesNotStartWith1ExceptionMessage);
        if (actualNumber.length() == 11 && actualNumber.substring(0,1).equals("1"))
            actualNumber = actualNumber.substring(1,11);
        int j=0;
        if (actualNumber.length() == 11 && actualNumber.substring(0,1).equals("1")) j = 1;
        for (int i = 0; i < 3; i++) {
            //System.out.println("j="+j+",i="+i);
            //System.out.println(actualNumber.substring(j+i,j+i+1));
            //System.out.println(actualNumber.substring(j+i+3,j+i+1+3));
            if (areacodenumbers.indexOf(actualNumber.substring(j+i,j+i+1))<0)
                throw new IllegalArgumentException(illegalAreaOrExchangeCodeMessage);
            if (areacodenumbers.indexOf(actualNumber.substring(j+i+3,j+i+1+3))<0)
                throw new IllegalArgumentException(illegalAreaOrExchangeCodeMessage);
        }
    }

    String getNumber() {
        return(actualNumber);
    }
}