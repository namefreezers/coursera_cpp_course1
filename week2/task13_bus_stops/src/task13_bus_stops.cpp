#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, vector<string>> buses;
	map<string, vector<string>> stops;

	for (int i = 0; i < N; i++) {
		string op;
		cin >> op;

		if (op == "NEW_BUS") {

			string bus;
			int count;
			cin >> bus >> count;
			for (int i = 0; i < count; ++i) {
				string stop;
				cin >> stop;
				buses[bus].push_back(stop);
				stops[stop].push_back(bus);
			}
		} else if (op == "BUSES_FOR_STOP") {

			string stop;
			cin >> stop;
			if (stops.count(stop) == 0) {
				cout << "No stop" << endl;
			} else {
				for (const auto &bus : stops[stop]) {
					cout << bus << " ";
				}
				cout << endl;
			}
		} else if (op == "STOPS_FOR_BUS") {

			string bus;
			cin >> bus;
			if (buses.count(bus) == 0) {
				cout << "No bus" << endl;
			} else {
				for (const auto &stop : buses[bus]) {
					cout << "Stop " << stop << ":";
					if (stops[stop].size() == 1) {
						cout << " no interchange";
					} else {
						for (const auto &interchange_bus : stops[stop]) {
							if (bus != interchange_bus) {
								cout << " " << interchange_bus;
							}
						}
					}
					cout << endl;
				}
			}
		} else if (op == "ALL_BUSES") {
			if (buses.empty()) {
				cout << "No buses" << endl;
			} else {
				for (const auto& [bus, bus_stops] : buses) {
					cout << "Bus " << bus << ":";
					for (const auto& stop : bus_stops) {
						cout << " " << stop;
					}
					cout << endl;
				}
			}
		}
	}

	return 0;
}
