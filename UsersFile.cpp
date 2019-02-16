#include "UsersFile.h"

vector <User> UsersFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;

    xml.Load(USERS_FILE_NAME.c_str());

    //xml.FindElem();
    //xml.IntoElem();

    while (xml.FindElem("userId")) {
        user.setUserId(atoi(xml.GetData().c_str()));
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        xml.FindElem("name");
        user.setName(xml.GetData());
        xml.FindElem("surname");
        user.setSurname(xml.GetData());

        users.push_back(user);
    }

    return users;
}

void UsersFile::saveUserToFile(User user) {
    CMarkup xml;

    xml.Load(USERS_FILE_NAME.c_str());

    //xml.AddElem("user");
    //xml.IntoElem();
    //while (xml.FindElem("surname")) {};
    xml.AddElem("userId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());

    xml.Save(USERS_FILE_NAME.c_str());
}
