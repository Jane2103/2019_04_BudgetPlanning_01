#include "UserManager.h"

void UserManager::registerUser() {
    User user = setNewUserData();

    users.push_back(user);
    usersFile.saveUserToFile(user);
    cout << endl << "User has been registered" << endl << endl;
    system("pause");
}

User UserManager::setNewUserData() {
    User user;
    string login, password, name, surname;

    user.setUserId(getNewUserId());

    cout << "Enter name: ";
    cin >> name;
    user.setName(name);

    cout << "Enter surname: ";
    cin >> surname;
    user.setSurname(surname);

    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (userLoginExists(user.getLogin()));

    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::userLoginExists(string login) {
    int usersVectorSize = users.size();
    for (int i = 0; i < usersVectorSize; i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Entered user login already exists" << endl << endl;
            system("pause");
            return true;
        }
    }
    return false;
}

//development only!
void UserManager::displayUsers() {
    vector <User> :: iterator it;
    for (it = users.begin(); it != users.end(); it++) {
        cout << "Id: " << it -> getUserId() << endl;
        cout << "Name: " << it -> getName() << endl;
        cout << "Surname: " << it -> getSurname() << endl;
        cout << "Login: " << it -> getLogin() << endl;
        cout << "Password: " << it -> getPassword() << endl;
        cout << endl;
    }
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

bool UserManager::userLogged() {
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::logOnUser() {
    if (!users.empty()) {
        vector <User> :: iterator it;
        string login, password;

        cout << "Login: ";
        cin >> login;
        cout << "Password: ";
        cin >> password;

        for (it = users.begin(); it != users.end(); it++) {
            if (login == it -> getLogin()) {
                if (password == it -> getPassword()) {
                    loggedUserId = it -> getUserId();
                    loggedUserName = it -> getName();
                    loggedUserSurname = it -> getSurname();
                    break;
                } else
                    loggedUserId = 0;
            } else
                loggedUserId = 0;
        }

        if (loggedUserId > 0)
            cout << endl << "User logged in" << endl;
        else
            cout << endl << "Incorrect login or password" << endl;

        cout << endl;
        system("pause");
    } else {
        cout << "No register user" << endl;
        Sleep(1000);
        loggedUserId = 0;
    }
}

string UserManager::getUserName() {
    return loggedUserName;
}
string UserManager::getUserSurname() {
    return loggedUserSurname;
}
