#include <iostream>
#include <exception>
#include <string>
using namespace std;

//string AskTimeServer() {
//	throw system_error(error_code());
//	return "";
//}

string AskTimeServer() {
	return "";
}

class TimeServer {
public:
    string GetCurrentTime() {
    	try {
    		last_fetched_time = AskTimeServer();
    	} catch (const system_error& ex) {

    	}

    	return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

//int main() {
//    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
//    TimeServer ts;
//    try {
//        cout << ts.GetCurrentTime() << endl;
//    } catch (exception& e) {
//        cout << "Exception got: " << e.what() << endl;
//    }
//    return 0;
//}
