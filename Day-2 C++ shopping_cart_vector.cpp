#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> cart;
    string item;
    int choice;

    do {
        cout << endl;
        cout << "===== Shopping Cart =====" << endl;
        cout << "1. Add item" << endl;
        cout << "2. View cart" << endl;
        cout << "3. Remove last item" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter item name: ";
            cin >> item;

            cart.push_back(item);
            cout << item << " added to cart" << endl;

        } else if (choice == 2) {
            if (cart.size() == 0) {
                cout << "Cart is empty" << endl;
            } else {
                cout << "Your cart:" << endl;

                for (int i = 0; i < cart.size(); i++) {
                    cout << i + 1 << ". " << cart[i] << endl;
                }
            }

        } else if (choice == 3) {
            if (cart.size() == 0) {
                cout << "Cart is already empty" << endl;
            } else {
                cout << cart[cart.size() - 1] << " removed" << endl;
                cart.pop_back();
            }

        } else if (choice == 4) {
            cout << "Thank you" << endl;

        } else {
            cout << "Wrong choice" << endl;
        }

    } while (choice != 4);

    return 0;
}
