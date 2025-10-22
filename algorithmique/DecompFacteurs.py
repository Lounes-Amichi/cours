def decomp(n: int):
    # n = int(input("Quel nombre décomposer? \n\n >"))
    i = 2
    print("n = ", end="")
    while n > 1:
        while n % i == 0:
            n = n // i
            print(f"{i} * ", end="",)
        i += 1


def isPrime(n: int) -> bool:
    rep = True
    if n == 0 or n == 1:
        return False
    elif n >= 3:
        for i in range(2, n):
            if n % i == 0:
                return False
    return True
