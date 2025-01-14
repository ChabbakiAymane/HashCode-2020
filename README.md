# **HashCode-2020**
Google Books is a project that embraces the value books bring to our daily lives. It aspires to bring the world's books online and make them accessible to everyone. In the last 15 years, Google Books has collected digital copies of 40 million books in more than 400 languages, partly by scanning books from libraries and publishers all around the world.
In this competition problem, we will explore the challenges of setting up a scanning process for millions of books stored in libraries around the world and having them scanned at a scanning facility.

---
## **Task**
Given a description of libraries and books available, plan which books to scan from which library to maximize the total score of all scanned books, taking into account that each library needs to be signed up before it can ship books.
Given a description of libraries and books available, plan which books to scan from which library to maximize the total score of all scanned books, taking into account that each library needs to be signed up before it can ship books.

## Problem description
### **Books**
There are B different books with IDs from 0 to B–1. Many libraries can have a copy of the same book, but we only need to scan each book once. Each book is described by one parameter: the score that is awarded when the book is scanned.

### **Libraries**
There are L different libraries with IDs from 0 to L–1. Each library is described by the following parameters:
  - the set of books in the library,
  - the time in days that it takes to sign the library up for scanning,
  - the number of books that can be scanned each day from the library once the library is signed up.
  
### Time
There are D days from day 0 to day D–1. The first library signup can start on day 0.
D–1 is the last day during which books can be shipped to the scanning facility.

### **Library signup**
Each library has to go through a signup process before books from that library can be shipped. Only one library at a time can be going through this process (because it involves lots of planning and on-site visits at the library by logistics experts): the signup process for a library can sta  only when no other signup processes are running. The libraries can be signed up in any order.
Books in a library can be scanned as soon as the signup process for that library completes (that is, on the first day immediately after the signup process). Books can be scanned in parallel from multiple libraries.

### **Scanning**
All books are scanned in the scanning facility. The entire process of sending the books, scanning them, and returning them to the library happens in one day (note that each library has a maximum number of books that can be scanned from this library per day). The scanning facility is big and can scan any number of books per day.

## Input data set
### **File format**
Each input data set is provided in a plain text file. The file contains only ASCII characters with lines ending with a single '\n' character (also called “UNIX-style” line endings). When multiple numbers are given in one line, they are separated by a single space between each two numbers.
The first line of the data set contains:
  - an integer B (1 ≤ B ≤ 10^5) – the number of different books, 
  - an integer L (1 ≤ L ≤ 10^5) – the number of libraries,
  - an integer D (1 ≤ D ≤ 10^5) – the number of days.

This is followed by one line containing B integers: S_0, …, S_{B-1}, (0 ≤ S_i ≤ 10^3), describing the score of individual books, from book 0 to book B–1.
This is followed by L sections describing individual libraries from library 0 to library L–1. Each such section contains two lines:
  - the first line, which contains:
    - N_j (1 ≤ N_j ≤ 10^5) – the number of books in library j, ○ T_j (1 ≤ T_j ≤ 10^5) – the number of days it takes to  nish the library signup process for library j,
    - M_j (1 ≤ M_j ≤ 10^5) – the number of books that can be shipped from library j to the scanning facility per day, once the library is signed up.
  - the second line, which contains N_j integers, describing the IDs of the books in the library. Each book ID is listed at most once per library.

The total number of books in all libraries does not exceed 10^6.

---
For more info, see: [hashcode_2020_online_qualification_round.pdf](https://github.com/ChabbakiAymane/HashCode-2020/blob/main/hashcode_2020_online_qualification_round.pdf)
