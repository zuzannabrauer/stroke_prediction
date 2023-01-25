#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

string lower(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;        
	}
	return str;
}

using vec = vector<string>;
using matrix = vector<vec>;

matrix readCSV(string filename)
{
	char separator = ',';
	matrix result;
	string row, item;

	ifstream in(filename);
	while (getline(in, row))
	{
		vec R;
		stringstream ss(row);
		while (getline(ss, item, separator)) R.push_back(item);
		result.push_back(R);
	}
	in.close();
	return result;
}

int main()
{
	matrix stroke_data = readCSV(R"(C:\Users\nimwy\OneDrive\Desktop\C\C++_obiektowe\stroke_prediction\heart_2020_cleaned.csv)");

	string sex;
	int weight;
	int height;
	string drinking;
	string smoking;

	cout << "Please enter your sex: Female or Male ?\n";
	cin >> sex;
	if (!(lower(sex) == "female" || lower(sex) == "male")) {
		cout << "Please write correct value\n";
		return 1;
	}
	cout << "Please enter your weight in kg\n";
	cin >> weight;
	if (weight < 20 || weight > 300) {
		cout << "Please write correct value\n";
		return 2;
	}
	cout << "Please enter your height in cm\n";
	cin >> height;
	if (height < 100 || height > 250) {
		cout << "Please write correct value\n";
		return 3;
	}
	cout << "If your a male having more than 14 drinks per week or female having more than 7 drinks per week please enter Yes, at any other case please type No\n";
	cin >> drinking;
	if (!(lower(drinking) == "yes" || lower(drinking) == "no")) {
		cout << "Please write correct value\n";
		return 1;
	}
	cout << "If you smoked at least 100 cigarettes in your entire life please enter Yes, at any other case please type No\n";
	cin >> smoking;
	if (!(lower(smoking) == "yes" || lower(smoking) == "no")) {
		cout << "Please write correct value\n";
		return 1;
	}

	if (lower(sex).find('f') != string::npos) {
		sex = "Female";
	}
	else {
		sex = "Male";
	}
	if (lower(drinking).find('y') != string::npos) {
		drinking = "Yes";
	}
	else {
		drinking = "No";
	}
	if (lower(smoking).find('y') != string::npos) {
		smoking = "Yes";
	}
	else {
		smoking = "No";
	}

    float f_weight = (float) weight;
    float f_height = (float) height;
	float bmi = f_weight / (f_height * f_height / 10000);

    ///the main part of code
    int all = 0;
    int all_stroke = 0;
    for (int i = 1 ; i<=319795;i++){
        if ((bmi - 1) <= stof(stroke_data[i][1]) and stof(stroke_data[i][1]) <= (bmi +1) and stroke_data[i][2] == smoking and stroke_data[i][3] == drinking and stroke_data[i][8] == sex){
            all++;
        }
        if((bmi - 1) <= stof(stroke_data[i][1]) and stof(stroke_data[i][1]) <= (bmi +1) and stroke_data[i][2] == smoking and stroke_data[i][3] == drinking and stroke_data[i][8] == sex and stroke_data[i][4] == "Yes") {
            all_stroke++;
        }
    }

    float output = float(all_stroke)/float(all) * 100;
    cout << "With accordance to your data and data about american citizens health and it connection to stroke and other hearts disease, you will have a stroke in the future with probability: " << output <<"%" << '\n';
    cout << "If your output is 0% is because the data probe doesn't contain cases matching your personal values, I'm so sorry for that :(";
	return 0;
}