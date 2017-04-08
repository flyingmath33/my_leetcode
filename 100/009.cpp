/*
  Determine whether an integer is a palindrome. Do this without extra space.
  Could negative integers be palindromes? (ie, -1)
  If you are thinking of converting the integer to string, 
  note the restriction of using extra space.
  You could also try reversing an integer. 
  However, if you have solved the problem "Reverse Integer", 
  you know that the reversed integer might overflow. How would you handle such case?
  There is a more generic way of solving this problem.
*/


bool isPalindrome(int x) {
        if(x < 0 || (x && x % 10 == 0))
            return false;
            
        int stackForReverseDigits = 0;
        while(x > stackForReverseDigits)
        {
            const int tailDigit = x % 10;
            x /= 10;
            if(x == stackForReverseDigits || x == 10 * stackForReverseDigits + tailDigit)
                return true; 

            stackForReverseDigits = 10 * stackForReverseDigits + tailDigit;
        }
        
        return x == 0;
    }
