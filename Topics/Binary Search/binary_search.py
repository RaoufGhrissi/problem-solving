def search(arr, e):
    operation = 0
    for i in arr:
        operation += 1
        if i == e:
            print(f"3malt {operation} operation")
            return True
    return False


def main():     
    arr = [1, 5, 8, 9 ,10]
    e = 10
    print(search(arr, e))

main()
