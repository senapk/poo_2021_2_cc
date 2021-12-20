#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <memory>

using namespace std;

template <typename T>
using ptr = shared_ptr<T>;

//interface
class IMsg {
public:
    virtual string getSender() = 0;
    virtual string getText() = 0;
    virtual ~IMsg(){};
    friend ostream& operator<<(ostream& os, IMsg& msg);
};

ostream& operator<<(ostream& os, IMsg& msg) {
    os << msg.getSender() << ": " << msg.getText();
    return os;
}

class Msg : public IMsg {
    string sender;
protected:
    string text;
public:
    Msg(string sender, string text) : sender(sender), text(text) {}
    string getSender() override { return sender; }
    string getText() override { return text; }
};

class MsgGaiata : public Msg {
public:
    MsgGaiata(string text): Msg("vsf", text) {}
    string getText() override {
        return exchange(text, text + ":lido");
    }
};

class User {
    string username; //chave
    vector<ptr<IMsg>> inbox;
    vector<ptr<IMsg>> sent;
public:
    User(string username) : username(username) {}

    void sendMsg(ptr<IMsg> msg, User& receiver) {
        receiver.inbox.push_back(msg);
        this->sent.push_back(msg);
    }

    string getInbox() {
        stringstream ss;
        for (auto msg : inbox) {
            ss << *msg << endl;
        }
        inbox.clear();
        return ss.str();
    }

    string getSent() {
        stringstream ss;
        for (auto msg : sent) {
            ss << *msg << endl;
        }
        return ss.str();
    }
};


class Manager {
    map<string, ptr<User>> users;
    vector<ptr<IMsg>> messages;

public:
    Manager() {
    }
    ~Manager() {
    }
    
    string getUsernames() {
        stringstream ss;
        for (auto user : users) {
            ss << user.first << " ";
        }
        return ss.str();
    }

    void addUser(string nome) {
        auto it = users.find(nome);

        if (it == users.end()) {
            users[nome] = make_shared<User>(nome);
        } else {
            throw runtime_error("User already exists");
        }
    }

    ptr<User> getUser(string nome) {
        auto it = users.find(nome);

        if (it == users.end()) {
            throw runtime_error("User not found");
        } else {
            return it->second;
        }
    }

    void sendMsg(string sender, string receiver, ptr<IMsg> msg) {
        auto senderUser = getUser(sender);
        auto receiverUser = getUser(receiver);
        senderUser->sendMsg(msg, *receiverUser);
    }

};

#include <tuple>
#include <algorithm>

template <typename T>
T read(stringstream& ss) {
    T t;
    ss >> t;
    return t;
}

template <typename... Args>
auto parse(istream& is) {
    tuple<Args...> t;
    apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}

int main(){
    Manager manager;
    while(true) {
        string line{}, cmd{};
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
//        cout << "$" << line << '\n';
        try {
            if (cmd == "end") {
                break;
            } else if (cmd == "add") {
                manager.addUser(read<string>(ss));
            } else if (cmd == "show") {
                cout << manager.getUsernames() << '\n';
            } else if (cmd == "send") {
                auto sender = read<string>(ss);
                auto receiver = read<string>(ss);
                string text;
                getline(ss, text);
                manager.sendMsg(sender, receiver, make_shared<Msg>(sender, text));
            } else if (cmd == "gaiata") {
                auto sender = read<string>(ss);
                auto receiver = read<string>(ss);
                string text;
                getline(ss, text);
                manager.sendMsg(sender, receiver, make_shared<MsgGaiata>(text));
            } else if (cmd == "inbox") { //david
                cout << manager.getUser(read<string>(ss))->getInbox();
            }else if (cmd == "sent") { //david
                cout << manager.getUser(read<string>(ss))->getSent();
            } else {
                cout << "Unknown command\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << '\n';
        }
    }
    return 0;
}