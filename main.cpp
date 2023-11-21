/*
s1.Given a sequence of n numbers, and k queries indicating which elements of the sequence must be removed, what will the sequence look like when these requests are fulfilled? Note that after each query the sequence is shortened and the position of some elements changes.


 #include <iostream>
 #include <vector>
 using namespace std;

 int main()
 {
     int count1, count2;
     cin >> count1 >> count2;

     vector<int> v(count1);
     for (int i = 0; i < count1; i++)
         cin >> v[i];
     for (int i = 0; i < count2; i++)
     {
         int removeIndex;
         cin >> removeIndex;
         v.erase(v.begin() + removeIndex - 1);
     }
     for (int i = 0; i < v.size() - 1; i++)
         cout << v[i] << " ";
     cout << *v.rbegin();
     return 0;

 }
 
2.Given an array of size n and k queries. There are 3 types of requests to support:
 a. sum m - Find the sum of the first m elements and print it
 b. del m - delete the mth element of the array
 c. pap m - insert 2m after the mth element
 It is guaranteed that m will not exceed the current array size.

 #include <iostream>
 #include <vector>
 #include <string>
 using namespace std;

 int main()
 {
     int num1, num2, num, sum; // defining variables
     cin >> num1 >> num2; // input first line of numbers

     vector<int> v(num1); // defining original vector
     vector<int> sumsum;

     for (int i = 0; i < num1; i++) // inputting original vector
         cin >> v[i];

     // loop dependent on functions
     for (int i = 0; i < num2; i++)
     {
         string com; // defining commands
         cin >> com; // input command

         if (com == "sum") // if command = sum, do sum function
         {
             sum = 0;
             cin >> num; // input number

             
             for (int i = 0; i < num; i++) // sum function
                 sum += v[i];
             
             
             cout << sum << '\n'; // PRINT SUM OUTSIDE FUNCTION
         }
         
         else if (com == "pap") // if command = pap, insert 2m at [n]
             {
                 cin >> num; // input number
                 v.insert(v.begin() + num, num * 2);
             }

         else if (com == "del") // if command = del, delete nth number
         {
             cin >> num; // input number place
             v.erase(v.begin() + num - 1);
         }
     }
     return 0;
 }
 
 3.
 Initially, pile A contains n cards numbered from 1 to n (top card number is 1, last cards number is n). The cards are stacked in a pile B as follows:
 a. We take the top card of pile A and place it on pile B.
 b. In each pile, we take the first card from the top and place it on the back of corresponding pile.
 c. If there are no cards left in the pile A, the shuffle is complete, otherwise we return to step 1.
 Print the order (top to bottom) of cards in pile B.

#include <iostream>
 #include <vector>

 using namespace std;

 int main()
 {
     int n;
     cin >> n;
     vector<int> a(n);
     vector<int> b;
     
     for(int i=0; i<a.size(); i++)
         a[i]=i+1;
     
     while (!a.empty()) {
         int card = a.front();
         a.erase(a.begin());
         b.insert(b.begin(),card);
             
         
         if (!a.empty()) {
             int first_card = b.front();
             b.erase(b.begin());
             b.push_back(first_card);
             int second_card = a.front();
             a.erase(a.begin());
             a.push_back(second_card);
         }
     }
     
     b.push_back(b.front());
     b.erase(b.begin());
     
     for (int i = 0; i < n-1; i++)
         cout << b[i] << ",";
     cout << *b.rbegin();
         
     return 0;
 }
 
 
4.
 The restaurant has a row of n dishes on the festive table. There were m customers who dreamed of eating a particular dish. How many clients will fulfill their dreams?
 #include <iostream>
 #include <unordered_map>
 using namespace std;

 int main() {
     int n, m;
     cin >> n;
     unordered_map<string, int> dishes;
     for(int i=0; i<n; i++) {
         string dish;
         cin >> dish;
         dishes[dish]++;
     }
     cin >> m;
     unordered_map<string, int> customers;
     for(int i=0; i<m; i++) {
         string customer, dream_dish;
         cin >> customer >> dream_dish;
         customers[dream_dish]++;
     }
     int count = 0;
     for(const auto& dish_count : dishes) {
         string dish = dish_count.first;
         int times = dish_count.second;
         if(customers.count(dish) > 0) {
             count += min(customers[dish], times);
         }
     }
     cout << count << endl;
     return 0;
 }
 
 5.Given a sequence of n numbers, how many different numbers are in the sequence?
 
 #include <iostream>
 #include <unordered_set>

 using namespace std;

 int main() {
     int n;
     cin >> n;

     unordered_set<int> unique_nums;

     for (int i = 0; i < n; i++) {
         int num;
         cin >> num;
         unique_nums.insert(num);
     }

     cout << unique_nums.size() << endl;

     return 0;
 }
 
 
 6.Given a sequence of n numbers and two constants C1, C2. How many different numbers fall within the interval [C1, C2)?
 
 
 #include <iostream>
 #include <set>
 using namespace std;

 int main() {
     int n, a, b;
     cin >> n >> a >> b;
     set<int> numbers;
     for (int i = 0; i < n; i++) {
         int num;
         cin >> num;
         if (num >= a && num < b) {
             numbers.insert(num);
         }
     }
     cout << numbers.size() << endl;
     return 0;
 }
 
 7.A two-dimensional array of numbers is given. How many different elements are in the outline of the array?


 #include <iostream>
 #include <set>
 using namespace std;

 int main() {
     int n, m;
     cin >> n >> m;

     int a[n][m];

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             cin >> a[i][j];
         }
     }

     set<int> outline;

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                 outline.insert(a[i][j]);
             }
         }
     }

     cout << outline.size() << endl;

     return 0;
 }
 
 
 8.A character string is given. How many characters needs to be changed to make the resulting string a word of different letters?
 A string is considered a word if all characters are letters.

 #include <iostream>
 #include <string>
 #include <unordered_set>

 using namespace std;

 int main() {
     string str;
     cin >> str;

     unordered_set<char> letters;

     for (char c : str) {
         if (isalpha(c)) {
             letters.insert(tolower(c));
         }
     }

     int num_changes = str.size() - letters.size();

     cout << num_changes << endl;

     return 0;
 }
 
 
 9.A two-dimensional array of numbers is given. What is the minimum number of elements to replace so that all elements in the array are different?
 

 
 #include <iostream>
  #include <unordered_set>
  
  using namespace std;
  
  int main() {
  int n, m;
  cin >> n >> m;
  
  int arr[n][m];
  
  for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
         cin >> arr[i][j];
     }
  }
  
  unordered_set<int> unique_elems;
  
  int replace_count = 0;
  
  for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             if (unique_elems.find(arr[i][j]) == unique_elems.end()) {
                 unique_elems.insert(arr[i][j]);
         }
  
             else {
              
              
                 while (unique_elems.find(arr[i][j]) != unique_elems.end()) {
                     arr[i][j]++;
                 }
                 
                 replace_count++;
          
             }
         }
  }
  
  cout << replace_count << endl;
  
  return 0;
  }
 
 10.The Mars bars firm employs n staff. The firm’s working week consists of k days. Every employee in the firm has a personal schedule [a, b), that is, working from day a to b (a <b). Help determine if there will be at least one employee working on the firm every working day?
 
 
 #include <iostream>
  #include <vector>
  #include <algorithm>
  
  using namespace std;
  
  int main() {
  int n, k;
  cin >> n >> k;
  
  vector<pair<int, int>> schedules(n);
  for (int i = 0; i < n; i++) {
  int a, b;
  cin >> a >> b;
  schedules[i] = make_pair(a, b);
  }
  
  sort(schedules.begin(), schedules.end());
  
  int currDay = 0;
  for (int i = 0; i < n; i++) {
  if (schedules[i].first > currDay) {
  cout << "NO" << endl;
  return 0;
  }
  currDay = max(currDay, schedules[i].second);
  if (currDay >= k) {
  cout << "YES" << endl;
  return 0;
  }
  }
  
  //cout << "NO" << endl;
  return 0;
  
  }
 
 11.Given a sequence of n numbers, after each number is entered, check whether number is already in the sequence.
 

 
 #include <iostream>
 #include <set>

 using namespace std;

 int main(){
     
     set<int>s;
     int count;
     cin>>count;
     for (int i=0; i < count; i ++)
     {
         int num;
         cin>>num;
         
         if (s.find(num) != s.end()){
             cout << "YES"<<endl;
         }
         else
             cout << "NO"<<endl;
         
         s.insert(num);
     }
     
     
     return 0;
    
 }
 
 12.Peter wrote down his test marks on the wall throughout the semester. At the end of the semester, there were m friends coming to Peter and everyone was asking: how many times did you get the mark x? Help Peter to respond to any requests from his friends.
 

 #include <iostream>
 #include <map>

 using namespace std;

 int main()
 {
     map<int, int> marks;
     int mCount, qCount;
     cin >> mCount;
     for (int i = 0; i < mCount; i++)
     {
         int temp;
         cin >> temp;
         marks[temp]++;
     }
     cin>> qCount;
     for (int i = 0; i < qCount; i++)
     {
         int temp;
         cin >> temp;
         if ( i == 0)
             cout << marks[temp];
         else
            cout << " " << marks[temp];
     }
     return 0;
 }
 
 13.A character string is given. Calculate how many characters are used more than twice.
 

 #include <iostream>
 #include <string>
 #include <map>

 using namespace std;

 int main() {
     string s;
     getline(cin, s);

     map<char, int> counts;
     for (char c : s) {
         counts[c]++;
     }

     int count = 0;
     for (auto p : counts) {
         if (p.second > 2) {
             count++;
         }
     }

     cout << count << endl;

     return 0;
 }
 
 14.Given a sequence of n numbers, find the maximum number that is repeated more than twice.
 

 #include <iostream>
 #include <unordered_map>
 #include <vector>
 #include <limits>

 using namespace std;

 int main() {
     int n;
     cin >> n;

     unordered_map<long long, int> freq;
     vector<int> nums(n);
     long long num;
     for (int i = 0; i < n; i++) {
         cin >> num;
         nums[i] = num;
         freq[num]++;
     }

     int max_num = numeric_limits<int>::min();
     for (auto p : freq) {
         if (p.second > 2 && p.first > max_num) {
             max_num = p.first;
         }
     }

     if (max_num == numeric_limits<int>::min()) {
         cout << "NO" << endl;
     } else {
         cout << max_num << endl;
     }

     return 0;
 }
 
15.
 Given a sequence of n numbers find the most recurring odd number.


 #include <iostream>
 #include <map>
 using namespace std;

 int main() {
     int n;
     map<int, int> freq;

     
     cin >> n;

     int num;
     for (int i = 0; i < n; i++) {
         cin >> num;
         if (num % 2 != 0) {
             freq[num]++;
         }
     }

     int max_freq = 0, most_recurring_odd = 0;
     for (auto it = freq.begin(); it != freq.end(); it++) {
         if (it->second > max_freq) { // update most recurring odd number if frequency is higher
             max_freq = it->second;
             most_recurring_odd = it->first;
         }
     }

     if (most_recurring_odd == 0) {
         cout << "NO" << endl;
     } else {
         cout << most_recurring_odd << endl;
     }

     return 0;
 }
 
 16.Given a sequence of n numbers, is there a number in the sequence that repeats more than k times?
 

 
 #include <iostream>
 #include <unordered_map>

 using namespace std;

 int main() {
     int n, k;
     cin >> n >> k;

     unordered_map<int, int> freq;
     int num;
     for (int i = 0; i < n; i++) {
         cin >> num;
         freq[num]++;
     }

     bool found = false;
     for (auto p : freq) {
         if (p.second > k) {
             found = true;
             cout << "YES" << endl;
             break;
         }
     }

     if (!found) {
         cout << "NO" << endl;
     }

     return 0;
 }
 
 */
