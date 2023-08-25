for i in range(1, 100 + 1):
    out = "Fizz" if i % 3 == 0 else ""
    out += "Buzz" if i % 5 == 0 else ""
    print(out if out else i)