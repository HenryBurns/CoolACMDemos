public class StringDemo {
	public static void main(String[] args) {
		String s1 = "Hi", s2 = "Hi", s3 = s1;
		String s4 = s1 + " Dad", s5 = "Hi Dad";

		String s6 = s2 + s5;
		String s7 = s2 + s5;

		String s8 = "Hi " + "Dad";

		if(s1 == s2) { // True or false
			System.out.println("s1 == s2");
		}

		if(s1 == s3) { // True or false
			System.out.println("s1 == s3");
		}

		if(s4 == s5) { // True or false
			System.out.println("s4 == s5");
		}

		if(s6 == s7) { // True or false
			System.out.println("s6 == s7");
		}

		if(s5 == s8) { // True or false
			System.out.println("s5 == s8");
		}
	}
}
