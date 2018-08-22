import random
import math

exp = 6
union = random.sample(range(1, 5000), int((math.pow(2, exp))))
party_1 = union[0:(int(math.pow(2, (exp-1))))]
party_2 = union[int(math.pow(2, (exp-1))):(int(math.pow(2, exp)))]

union.sort()
known_median = union[int(math.pow(2, exp-1)) - 1]

print party_1
print party_2
print known_median
