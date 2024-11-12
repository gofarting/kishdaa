#include <iostream>

using namespace std;

class Binary
{

public:
    int BinaryIterative(int arr[], int key, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (key > arr[mid])
            {
                low = mid + 1;
            }
            else if (key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                cout << "Number found :" << arr[mid] << endl;
                return mid;
            }
        }
        cout << "Number not Found";
        return -1;
    }

    int BinaryRecursive(int arr[], int key, int low, int high)
    {
        if(low <= high)
        {
            int mid = low + (high-low) / 2;
            if (key == arr[mid])
            {
                cout << "Number found :" << arr[mid] << endl;
                return mid;
            }
            else if (key > arr[mid])
            {
                return BinaryRecursive(arr, key, mid + 1, high);
            }
            else
            {
                return BinaryRecursive(arr, key, low, mid - 1);
            }
        }
        return -1;
    }
};

int main()
{
    Binary b;

    int n;

    cout << "Enter the size of array :";
    cin >> n;

    int arr[n];

    cout << "Enter the elments in the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        cout << "\t";
    }
    cout << "\n";

    int key;

    cout << "Enter the number to Find :";
    cin >> key;

    int low = 0;
    int high = n - 1;

    int ch;

    do
    {
        cout << "\n**********menu**********\n";
        cout << "\n1.Iterative" << endl;
        cout << "2.Recursive" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter the choice : ";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
        {
            int result = b.BinaryIterative(arr, key, low, high);
            cout << "\nIndex of Key is :" << result;
        }
        break;
        case 2:
        {
            int result = b.BinaryRecursive(arr, key, low, high);
            cout << "\nIndex of key is :" << result;
        }
        break;
        case 3:
            exit(0);
            break;
        }
    } while (ch < 3 && ch > 0);

    return 0;
}