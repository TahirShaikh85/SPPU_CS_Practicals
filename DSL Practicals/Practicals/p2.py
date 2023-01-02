
# a) The average score of class
# avg = total marks / no of students
def avg(studentsList):
    total_marks = sum(studentsList)
    total_students = len(studentsList)

    avg = total_marks / total_students
    return avg

# b) Highest score and lowest score of class


def compare(studentsList):
    high = max(studentsList)
    low = min(studentsList)

    return [high, low]

# c) Count of students who were absent for the test


def absent(studentsList):
    absent_count = 0
    for m in studentsList:
        if m == 0:
            absent_count += 1
    return absent_count

# main ------------------------------

# get how many students (number)
# enter marks for each student


studentsList = []
n = int(input("How many students in the class? "))
count = 1
for i in range(n):
    marks = int(input(f"Enter marks for student {count}: "))
    studentsList.append(marks)
    count += 1

print("\n", studentsList)

loop = True
while loop:
    print("\n \t \t --------------------Select Your Choice From Following list-----------------")
    print("Enter 1 for Average")
    print("Enter 2 for Maximum")
    print("Enter 3 for Minimum")
    print("Enter 4 for Count of absent student")
    print("Enter 5 to exit")

    choice = int(input("Enter your choice: "))
    if choice == 1:
        print("Average marks obtained by student is: ", avg(studentsList))
    elif choice == 2:
        print("Highest score of the class is: ", compare(studentsList)[0])
    elif choice == 3:
        print("Lowest score of the class is: ", compare(studentsList)[1])
    elif choice == 4:
        print("Number of absent students are: ", absent(studentsList))
    elif choice == 5:
        print("Thanks for having me :)")
        loop = False
    else:
        print("You entered invalid choice!")
        loop = False
