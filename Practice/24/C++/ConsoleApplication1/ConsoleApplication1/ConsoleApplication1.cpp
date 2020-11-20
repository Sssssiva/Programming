#include<fstream>
#include <iostream>
#include<iomanip>
#include "json.h"
using nlohmann::json;
using namespace std;
int main()
{
	ifstream data("in.json");
	json indata;
	data >> indata;
	size_t data_size = indata.size();
	int max_user = 0;
	for (int user = 0; user < data_size; user++) {
		if (indata[user]["userId"] > max_user) {
			max_user += 1;
		}
	}
	ofstream out("out.json");
	json outdata = json::array();
	int task_completed;
	for (int id = 1; id <= max_user; id++) {
		task_completed = 0;

		for (int task = 0; task <= data_size; task++) {
			if (indata[task]["userId"] == id && indata[task]["completed"]) {
				task_completed++;

			}

		}
	
		if (task_completed) {
			outdata.push_back(
				{
				{"task_completed",task_completed},
				{"userId",id},
				}
			);
		}
		}
	out << setw(4) << outdata << endl;
	}


