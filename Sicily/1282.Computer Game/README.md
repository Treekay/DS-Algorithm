# 1282. Computer Game

## Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

## Description



Brian is an enthusiast of computer games, especially those that simulate virtual reality. Now he is in front of the Star Gate. In order to open the gate he must break the protection as quickly as he can. Breaking the protection means to match a given code (a sequence of numbers) against the gate protection (a very long sequence of numbers). The starting position of the first occurrence of the code within the sequence opens the gate. Can you help him?

The code is a sequence of at most **60000** integer numbers between **0** and **255**. The gate protection contains integer numbers between **0** and **255**. Your program must find the first match if there is one, or report the absence of a match.



## Input



The text input file contains several data sets. Each data set has the following format:

l     the length of the code

l     the sequence of numbers representing the code

l     the number of integers in the gate protection

l     the sequence of numbers representing the gate protection 

 **code_dimension****integer1 integer2 … integercode_dimension** **protection_dimension****integer1 integer2 … integerprotection_dimension**

White spaces may occur freely in the input.



## Output



The results must be printed on the standard output. For each given data set, print the result on a separate line. The result is a number that represents the position (starting from zero) of the first occurrence of the code in the gate protection, or the message **no solution** if there is no match.



## Sample Input

```
3
0 1 2
7
2 3 4 0 1 2 5

2
1 4
6
4 1 4 1 4 4

3
1 2 3
7
3 2 1 3 2 255 7
```



## Sample Output

```
3
1
no solution
```



## Problem Source

ZSUACM Team Member