# this program computes primitive root of any prime number
# 'a' is said to primitive root of prime number 'p' if [ a^1 mod p , a^2 mod p ........a^p-1 mod p ]
# are distinct
pr_values = []
def compute_primitive_root(x, y):
    for i in range(1, y):
       pr_values.append((x**i) % y)

a = int(input("Enter value for a= "))
p = int(input("Enter value for p= "))
compute_primitive_root(a, p)
print(pr_values)