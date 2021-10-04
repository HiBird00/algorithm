a, b = input().split()
print(max(int("".join(list(reversed(list(a))))), int("".join(list(reversed(list(b)))))))
