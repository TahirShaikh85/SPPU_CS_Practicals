def linear_search(arr, key):
    for i in range(len(arr)):
        if (arr[i] == key):
            print("The element", key, "is present at index: ", i)
            break
    else:
        print("The element not present in the array")


def sanitel_search(arr, key):
    arr.append(key)
    i = 0
    while (arr[i] != key):
        i = i + 1
    if (i < len(arr)-1):
        print("The element", key, "is present at index: ", i)
    else:
        print("The element not present in the given array")


def binary_search(arr, key):
    start = 0
    end = len(arr) - 1
    while (start <= end):
        mid = int((start+end)/2)
        if (arr[mid] == key):
            print("The element is present at index: ", mid)
            break
        elif (key > arr[mid]):
            start = mid + 1
        elif (key < arr[mid]):
            end = mid - 1
    else:
        print("Element not found")


N = int(input("How many number of students attended the training program: "))
roll_numbers = []
for i in range(N):
    num = int(input("Enter the roll number: "))
    roll_numbers.append(num)

print("Roll numbers of students who attended the training trainig program", roll_numbers)

flag = True
while "no" not in input("Do you want to continue (yes/no) "):

    key = int(input("Enter the roll number of student to be searched: "))

    print("\n \t \t ************ Menu ************")
    print("Enter 1 to search the student using Linear Search")
    print("Enter 2 to search the student using Sentinel Search")
    print("Enter 3 to exit")

    choice = int(input("Enter your choice: "))

    match choice:
        case 1:
            linear_search(roll_numbers, key)
            break
        case 2:
            sanitel_search(roll_numbers, key)
            break
        case 3:
            print("Thanks for having me :) ")
            flag = False
            break
        case default:
            print("Entered wrong choice")
            break
    print("Thanks for having me :) ")
