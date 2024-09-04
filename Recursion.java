public class Recursion {
    public static void main(String[] args) {
        // Example using countThree() function
        System.out.println("countThree(126) = " + countThree(126));
        System.out.println("countThree(123) = " + countThree(123));
        System.out.println("countThree(213) = " + countThree(132));
        System.out.println("countThree(30303) = " + countThree(30303));

        // Examples using multiply() function
        System.out.println("mutliples of 1, by 5 times = " + multiply(1, 5));
        System.out.println("mutliples of 18, by 8 times = " + multiply(18, 8));
        System.out.println("mutliples of 18, by 8 times = " + multiply(18, 8));

        // Examples using isPrime() function
        System.out.println("Checking if number 92 is prime: " + isPrime(919, 2));
        System.out.println("Checking if number 92 is prime: " + isPrime(50, 2));
        System.out.println("Checking if number 92 is prime: " + isPrime(2, 2));

        // Examples using isPrime() function
        System.out.println(dupVowel("hello"));
        System.out.println(dupVowel("xxyy"));
        System.out.println(dupVowel("abc"));

        // Example for array of ints problem
        int[] nums = {10, 20, 31};
        int count = array10(nums);
        System.out.println(count);

    }

    // Given a non-negative int n, recursively count the occurrences of 3 as a
    // digit.
    public static int countThree(int num) {
        // base case
        if (num == 0) {
            return num = 0;
        }

        // num is divided by 10 and if the last number is 3, then add one if not then it
        // is 0.
        return (num % 10 == 3 ? 1 : 0) + countThree(num / 10);
    }

    // Write a method that accepts two numbers and performs multiplication by
    // recursively adding the same number multiple times.
    public static int multiply(int num, int times) {
        // base case, if times equals 0, stop adding.
        if (times == 0) {
            return 0;
        } else {
            // recursive case: adding num by each other, while decreasing times by 1 until
            // it hits 0.
            return num + multiply(num, times - 1);
        }

    }

    // Write a boolean returning recursive method to determine if a number is prime.
    // Recursively determine if the any number less the number are divisible by the number.
    public static boolean isPrime(int numToCheck, int count) {
        // Base case: Numbers less than or equal to 1 are not prime
        if (numToCheck <= 1) {
            return false;
        }
        
        // Base case: If count reaches numToCheck, it means numToCheck is prime
        if (count >= numToCheck) {
            return true;
        }
    
        // Check if numToCheck is divisible by count
        if (numToCheck % count == 0) {
            return false;
        } else {
            // Continue checking with the next count
            return isPrime(numToCheck, count + 1);
        }
    }
    
    // Given a String, recursively build a new string where the vowels are duplicated
    public static String dupVowel(String str) {
        // Base case: if the string is empty, return an empty string
        if (str.isEmpty()) {
            return "";
        }

        // Checks if the first character is a vowel
        if (str.charAt(0) == 'a' || str.charAt(0) == 'e' || str.charAt(0) == 'i' || str.charAt(0) == 'o'
                || str.charAt(0) == 'u') {
            // If it's a vowel, adds it twice to the result and starts recurrsive process
            return str.charAt(0) + "" + str.charAt(0) + dupVowel(str.substring(1));
        } else {
            // If it's not a vowel, add it once to the result and recursively process the
            // rest of the string
            return str.charAt(0) + dupVowel(str.substring(1));
        }
    }

    // Given an array of ints, recursively compute the number of times that a multiple of 10
    // appears in the array. index is used to examine a specific element from the array. 
    // Use a helper function to incorporate an index to count through elements in the array 
    public static int array10(int[] nums) {
        return array10Helper(nums, 0);
    }

    // helper function to incorporate an index
    private static int array10Helper(int[] nums, int index) {
        // Basecase: Incase array reaches the end 
        if (index >= nums.length) {
            return 0;
        }
    
        //Directly return 1 if the current element is a multiple of 10,
        // otherwise, recursively count multiples in the remaining part
        return (nums[index] % 10 == 0 ? 1 : 0) + array10Helper(nums, index + 1);
    }
}
