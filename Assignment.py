import sys
import math
import bisect
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right as br
from collections import Counter

test_cases = int(input())

user_name = []


class user:
 def __init__(self,Player_names): 
    self.Player_names = Player_names
    counter = Counter(self.Player_names)   
    self.max_user = counter.most_common()
    print(self.max_user)
  
    
for x in range(0,test_cases):
    tweets_cnt = int(input())
  
    for y in range(0,tweets_cnt) :
        tweets = str(input())
        dum = list(tweets.split(" "))
      
        user_name.append(dum[0])

us = user(user_name)
