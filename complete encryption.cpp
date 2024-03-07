#include<iostream>
#include<string>
#include<cctype>
#include<list>
#include<iterator>
using namespace std;

// Function to check if all characters in the key are alphabetic
int check_alpha_word(string key) {
    int count = 0;
    for(int i = 0 ; i < 5 ; i++) {
        if(!(isalpha(key[i]))) {
            count++;
        }
    }
    if(count != 0) {
        return 0; // Return 0 if the key contains non-alphabetic characters
    }
    return 1; // Return 1 if the key is valid
}

int main() {
        bool Flag = true; // Flag to control the loop
        string valid_string = "abcdefghijklmnopqrstuvwxyz"; // String containing valid characters
        string cipher_string = ""; // String for storing the cipher alphapet
        string text; // Input text that will cipher or decipher
        string cipher_text = ""; // Encrypted text
        string decipher_text = ""; // Decrypted text
        string key; // Key for encryption or decryption
        auto found = 0; // Variable to store the index of found characters
        int check1; // Variable to store the result of key validation
        int choice; // Variable for user choice
        string reversed_key = ""; // Reversed key for add them to the  the alphabet
        //valid list that will be used to add the key to the start of the list and then put them in the cipher string to be more easy to deal with
        list<char> valid_list = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        // Display the welcome message and menu
        cout << "\"Welcome to Simple Substitution Cipher program\"\n";
        cout << "What do you want to do?\n";
        cout <<"1) Cipher a message\n2) Decipher a message\n3) End";
        cout << "\nchoose from 1 to 3 : ";

        // Loop until the user provides a valid choice
        while(Flag == true) {
            cin >> choice; // Read user choice
            cin.ignore();

            // If the choice is to cipher a message
            if(choice == 1) {
                cout<<"enter the key : ";
                cin >> key;

                // Validate the key
                while(true) {
                    check1 = check_alpha_word(key);
                    if(key.size() != 5) {
                        cout << "Invalid Input. Please enter 5 letters : ";
                        cin >> key;
                        continue;
                    } else if(check1 == 0) {
                        cout << "Invalid Input. Please enter key from English alphabet : ";
                        cin >> key;
                        continue;
                    } else {
                        break;
                    }
                }

                // Convert the key to lowercase
                for(char& c : key) {
                    c = tolower(c);
                }

                // reverse the key to add it to the list in the right order
                for(int i = 4; i >= 0; i--) {
                    reversed_key += key[i];
                }
                //remove the letter from the list and add it to the start of the list and keep the order
                for(int i = 0; i < 5; i++) {
                    valid_list.remove(reversed_key[i]);
                    valid_list.push_front(reversed_key[i]);
                }
                cin.ignore();//clear the cin from the key to can receive the text
                cout << "Please enter the message to cipher: ";
                getline(cin, text);

                // Convert text to lowercase and prepare the cipher string
                for(char& c : text) {
                    if(isalpha(c)) {
                        c = tolower(c);
                    }
                }
                for(char c : valid_list) {
                    cipher_string += c;
                }

                // Encrypt the text
                for(int i = 0; i < text.size(); i++) {
                    if(isalpha(text[i])) {
                        found = valid_string.find(text[i]);
                        cipher_text += cipher_string[found];
                    } else {
                        cipher_text += text[i];
                    }
                }
                cout << "Your Text After Encryption = " << cipher_text << endl;
                Flag = false; // Set the flag to exit the loop
            }
            // If the choice is to decipher a message
            else if(choice == 2) {
                cout<<"enter the key : ";
                cin >> key;

                // Validate the key
                while(true) {
                    check1 = check_alpha_word(key);
                    if(key.size() != 5) {
                        cout << "Invalid Input. Please enter 5 letters : ";
                        cin >> key;
                        continue;
                    } else if(check1 == 0) {
                        cout << "Invalid Input. Please enter key from English alphabet : ";
                        cin >> key;
                        continue;
                    } else {
                        break;
                    }
                }

                // Convert the key to lowercase
                for(char& c : key) {
                    c = tolower(c);
                }

                // reverse the key to add it to the list in the right order
                for(int i = 4; i >= 0; i--) {
                    reversed_key += key[i];
                }
                //remove the letter from the list and add it to the start of the list and keep the order
                for(int i = 0; i < 5; i++) {
                    valid_list.remove(reversed_key[i]);
                    valid_list.push_front(reversed_key[i]);
                }

                cin.ignore();
                cout << "Please enter the message to decipher: ";
                getline(cin, text);

                // Convert text to lowercase and prepare the cipher string
                for(char& c : text) {
                    if(isalpha(c)) {
                        c = tolower(c);
                    }
                }
                for(char c : valid_list) {
                    cipher_string += c;
                }

                // Decrypt the text
                for(int i = 0; i < text.size(); i++) {
                    if(isalpha(text[i])) {
                        found = cipher_string.find(text[i]);
                        decipher_text += valid_string[found];
                    } else {
                        decipher_text += text[i];
                    }
                }
                cout << "Your Text After Decryption: " << decipher_text << endl;
                Flag = false; // Set the flag to exit the loop
            }
            // If the choice is to end the program
            else if(choice == 3) {
                cout << "\"Thanks For Using Our Program\"";
                break; // Exit the loop and end the program
            }
            // If the choice is invalid
            else {
                cout << "Invalid Input. Please Choose From 1 to 3: ";
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                continue;
            }
        }

    return 0;
}
