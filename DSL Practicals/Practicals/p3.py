# sort books according to price in ascending order
def sorted_books(books, N):
    for i in range(N):
        for j in range(i+1, N):
            if (books[i][1] > books[j][1]):
                temp1 = books[i][0]
                books[i][0] = books[j][0]
                books[j][0] = temp1

                temp2 = books[i][1]
                books[i][1] = books[j][1]
                books[j][1] = temp2

    return books

# remove duplicates


def remove_duplicate(books):
    new_list = []
    for value in books:
        if value not in new_list:
            new_list.append(value)
    print(new_list)

# more than Rs. 500


def more_than_500(books, N):
    count = 0
    for name_of_book in range(N):
        if (books[name_of_book][1] > 500):
            count = count + 1
    print(count)


N = int(input("\n Enter number of books in the library: "))

books = []
for value in range(N):
    row = []
    for cost in range(2):
        row.append(0)
    books.append(row)

for value in range(N):
    name_of_book = input("\nEnter name of the book: ")
    books[value][0] = name_of_book
    cost = int(input("Enter the cost of the book: "))
    books[value][1] = cost

print("\nThe name and the cost of the book respectively: ")
print(books)

while 'no' not in input("\n Do you want to continue? (yes/no) "):
    print("\n \t \t ************ Menu ************")
    print("\nEnter 1 to Delete the duplicate entries ")
    print("Enter 2 to Display books in ascending order based on cost of books ")
    print("Enter 3 to Count number of books with cost more than 500")

    ch = int(input("\nEnter your choice: "))
    match ch:
        case 1:
            print("\nThe list of books after removing the duplicate elements: ")
            remove_duplicate(books)
        case 2:
            print("\nThe list of books in ascending order based on the prices: ")
            print(sorted_books(books, N))
        case 3:
            print("\nNumber of books with cost more than 500 are: ")
            more_than_500(books, N)
        case 4:
            print("Thanks for using this program !")
        case default:
            print("\n sorry wrong choice :(")
