class ArmstrongNumbers {

	boolean isArmstrongNumber(int numberToCheck) {

		int n = numberToCheck;
		//System.out.println("numberToCheck="+numberToCheck);
		String digits = Integer.toString(numberToCheck);
		int e = digits.length();
		//System.out.println("e="+e);
		int s = 0;
		for (int i = 0; i < e; i++){
			int d = Integer.parseInt(digits.substring(i,i+1));
			s += (int) Math.pow(d,e);
			//System.out.println("d^e="+Math.pow(d,e));
			//System.out.println("s="+s);
		}
		if (s == numberToCheck) return (true);
		else return (false);
	}
	//public void ArmstrongNumbers ()
}