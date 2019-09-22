#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

void main(int argc, char* argv[])
{
	std::string fileName = argv[1];

	std::ifstream fin1;
	std::ifstream fin2;
	std::ifstream fin3;
	std::ifstream fin4;
	std::ifstream fin5;

	fin1.open((fileName + "Cash1.txt").c_str());
	fin2.open((fileName + "Cash2.txt").c_str());
	fin3.open((fileName + "Cash3.txt").c_str());
	fin4.open((fileName + "Cash4.txt").c_str());
	fin5.open((fileName + "Cash5.txt").c_str());

	std::vector<float> v;
	float val;
	float sum = 0;

	while (!fin1.eof()) {
		fin1 >> val;
		sum += val;

		fin2 >> val;
		sum += val;

		fin3 >> val;
		sum += val;

		fin4 >> val;
		sum += val;

		fin5 >> val;
		sum += val;

		v.push_back(sum);
		sum = 0;
	}

	int maxInter = std::max_element(v.begin(), v.end()) - v.begin() + 1;

	std::cout << maxInter << std::endl;
}
