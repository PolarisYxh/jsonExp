// #include "pch.h"
#include <iostream>
#include "nlohmann/json.hpp"    // https://github.com/nlohmann/json/tree/develop/single_include/nlohmann/json.hpp
#include <fstream>              // ifstream, ofstream
#include <iomanip>              // std::setw()
#include <osg/MatrixTransform>
using json = nlohmann::json;
using namespace std;
struct modeldata
{
	string cate;
	string id;
	osg::Matrix t[6];
};
int main()
{
	
	// ���ļ���ȡ����
	std::ifstream fin("anatation1.json");   // ע��˴������·��
	json j,j1;
	fin >> j;	
	fin.close();
	int num=0;
	for (auto& element : j) 
	{
		element["n_aligned_models"]>> num;
		modeldata* my = new modeldata[num];
		for (auto& model : element["aligned_models"])
		{
			double x, y, z, h;
			fin >> my[i].cate >> my[i].id;
			model["trs"]["translation"] >> x >> y >> z;
			my[i].t[0] = osg::Matrix::translate(x, y, z);
			fin >> x >> y >> z >> h;
			my[i].t[1] = osg::Matrix::rotate(x, y, z, h);
			fin >> x >> y >> z;
			my[i].t[2] = osg::Matrix::scale(x, y, z);
			fin >> x >> y >> z;
			my[i].t[3] = osg::Matrix::scale(x, y, z);
			fin >> x >> y >> z;
			my[i].t[4] = osg::Matrix::translate(x, y, z);
		}
	}

	// д���ļ�
	std::ofstream fout("object.json");  // ע�� object.json �� config.json ����һ�£�����˳��ͬ
	fout << std::setw(4) << j << std::endl;
	fout.close();

	// ע�⣺
	// JSON��׼��������Ϊ������������� / ֵ�Ե����򼯺ϡ���
	// ���ϣ����������˳�򣬿���ʹ��tsl::ordered_map(integration)��nlohmann::fifo_map(integration)������ר�Ż��������͡�
	
	getchar();
}