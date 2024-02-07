namespace RomanToNumbersAndReverse
{
    internal class RomanToInt(string s) {
        public int RomanToInt(string s) {
            int sum = 0;
            Dictionary<char, int> roman = new Dictionary<char, int>(){
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };

            for (int i = 0; i < s.Length; i++) {
                roman.TryGetValue(romanChar, out int num);
                if (i + 1 < s.Length && roman[s[i+1]] > roman[s[i]]) {
                    sum -= num;
                } else {
                    sum += num;
                }
            }
            return sum;
        }

        public static void Main(string[] args)
        {
            string s1 = "III"; 
            string s2 = "LVIII"; 
            string s3 = "MCMXCIV"; 
            int result1 = RomanToInt(s1);
            int result2 = RomanToInt(s2);
            int result3 = RomanToInt(s3);
            System.Console.WriteLine(result1);
            System.Console.WriteLine(result2);
            System.Console.WriteLine(result3);
        }
    }
}

