def selection_sort(array, n):
    for i in range(0, n-1):
        for j in range(i+1, n):
            if (array[i] > array[j]):
                temp = array[i]
                array[i] = array[j]
                array[j] = temp
    print("Sorted array using selection sort: ", array)


def bubble_sort(array, n):
    for j in range(n):
        i = 0
        while (i < n-1):
            if (array[i] > array[i+1]):
                array[i], array[i+1] = array[i+1], array[i]
            i = i+1
    print("Sort array using bubble sort: ", array)


def topFive(array):
    print("Top Five: ", array[-5:])


num = int(input("Enter number of students: "))
percentage = []
for i in range(num):
    per = float(input("Enter percentage: "))
    percentage.append(per)

print("Percentage of students are(unsorted): ", percentage)


while "no" not in input("Do you want to continue (yes/no) "):
    print("\n \t \t *************** Menu ***************")
    print("Enter 1 to sort Percentages using selection sort")
    print("Enter 2 to sort Percentages using bubble sort")
    print("Enter 3 to display top five scores")
    print("Enter 4 to exit")

    choice = int(input("Enter your choice: "))

    match choice:
        case 1:
            selection_sort(percentage, num)
        case 2:
            bubble_sort(percentage, num)
        case 3:
            topFive(percentage)
        case 4:
            print("\n Thanks for having me")
            break
        case default:
            print("Wrong choice!!")
            break
