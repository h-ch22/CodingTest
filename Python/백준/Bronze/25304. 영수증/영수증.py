total_price = int(input())
count = int(input())
products = []

for i in range(count):
    products.append(input())

sum = 0

for product in products:
    info = list(map(int, product.split(" ")))
    sum += info[0] * info[1]

print("Yes" if sum == total_price else "No")
