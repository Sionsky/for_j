#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// 0 - �� ������
// 1 - ������
// 2 - ����


struct Data
{
	int status = 0;

	int in;
	int out;
};


void main(int argc, char* argv[])
{
	std::string fileName = argv[1];

	Data data;
	std::ifstream fin;
	std::vector<Data> vData;
	std::vector<Data> vCount;
	std::vector<Data> vMax;
	// std::multiset
	// std::pair

	fin.open(fileName.c_str());

	std::string str1;
	std::string str2;
	
	while (!fin.eof()) {
		fin >> str1;
		fin >> str2;

		str1.erase(std::remove(str1.begin(), str1.end(), ':'));
		str2.erase(std::remove(str2.begin(), str2.end(), ':'));

		data.in = atol(str1.c_str());
		data.out = atol(str2.c_str());

		vData.push_back(data);
	}

	int time;
	int timeMin = 800;
	int timeMax = 2000;
	int count = 0;
	int tIn = 0;
	int tOut = 0;

	int maxCount = 0;

	bool combo = false; // ������ �����

	// �������� �� ������������ ���������� ����� � ����
	///////////////////////////////////////////////////////////////////////////
	for (time = timeMin; time <= timeMax;) {
		for (size_t i = 0; i < vData.size(); i++) {
			if (vData[i].in <= time && vData[i].status == 0)
				vData[i].status = 1;

			if (vData[i].out <= time && vData[i].status == 1)
				vData[i].status = 2;

			for (size_t j = 0; j < vData.size(); j++)
				if (vData[j].status == 1)
					count++;

			if (count > maxCount)
				maxCount = count;

			count = 0;
		}

		time++;

		if ((time % 100) == 60)
			time = (time / 100 + 1) * 100;
		
	}

	for (time = timeMin; time <= timeMax;) {
		// ���������� � ������� ��������� �����
		///////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < vData.size(); i++) {
			if (vData[i].in == time)  {
				vCount.push_back(vData[i]);
				vData.erase(vData.begin() + i);
				i--;
			}
		}
		///////////////////////////////////////////////////////////////////////////
		
		// �������� �� �������� �������
		///////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < vCount.size(); i++) { 
			if (vCount[i].out == time) {
				vCount.erase(vCount.begin() + i);
				i--;
			}
		}
		///////////////////////////////////////////////////////////////////////////

		if (vCount.size() == maxCount) {
			int left;
			int right;

			for (int i = 0; i < vCount.size(); i++) {
				if (i == 0) {
					left = vCount[0].in;
					right = vCount[0].out;
					continue;
				}

				if (vCount[i].in > left)
					left = vCount[i].in;

				if (vCount[i].out < right)
					right = vCount[i].out;
			}

			if (!combo)
				tIn = left;
			
			tOut = right;

			combo = true;
		}
		else if (vCount.size() < maxCount && combo) {
			combo = false;

			data.in = tIn;
			data.out = tOut;

			vMax.push_back(data);
		}
		
		time++;
		
		if ((time % 100) == 60)
			time = (time / 100 + 1) * 100;

	}
	
	for (size_t i = 0; i < vMax.size(); i++) {
		std::string s = std::to_string(vMax[i].in);
		std::string s1 = std::to_string(vMax[i].out);
		if (s.size() < 4)
			s.insert(1, ":");
		else 
			s.insert(2, ":");

		if (s1.size() < 4)
			s1.insert(1, ":");
		else
			s1.insert(2, ":");
		
		std::cout << s << " " << s1 << std::endl;
	}
}
