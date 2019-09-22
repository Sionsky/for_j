#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iomanip>

void main(int argc, char* argv[])
{
	std::string fileName = argv[1];

	std::vector<float> v;
	std::ifstream fin;
	float val;

	fin.open(fileName.c_str());

	while (!fin.eof())  {
		fin >> val;
		v.push_back(val);
	}
	
	std::sort(v.begin(), v.end());

	float cel;
	float const med = (*(v.begin() + (v.size() - 1) / 2) + *(v.begin() + (v.size() - 1) / 2)) / 2;
	float const min = v.front();
	float const max = v.back();
	float const sr = std::accumulate(v.begin(), v.end(), 0.0) / v.size();
	float const drob = modf(0.9 * (v.size() - 1) + 1, &cel);
	float const proc = *(v.begin() + cel - 1) + drob * (*(v.begin() + cel - 1) - *((v.begin() + cel - 1) - 1));

	std::cout << std::setprecision(2) << std::fixed << proc << std::endl;
	std::cout << std::setprecision(2) << std::fixed << med << std::endl;
	std::cout << std::setprecision(2) << std::fixed << max << std::endl;
	std::cout << std::setprecision(2) << std::fixed << min << std::endl;
	std::cout << std::setprecision(2) << std::fixed << sr << std::endl;
}
