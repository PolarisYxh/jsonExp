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
	
	// 从文件读取配置
	std::ifstream fin("anatation1.json");   // 注意此处是相对路径
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

	// 写入文件
	std::ofstream fout("object.json");  // 注意 object.json 和 config.json 内容一致，但是顺序不同
	fout << std::setw(4) << j << std::endl;
	fout.close();

	// 注意：
	// JSON标准将对象定义为“零个或多个名称 / 值对的无序集合”。
	// 如果希望保留插入顺序，可以使用tsl::ordered_map(integration)或nlohmann::fifo_map(integration)等容器专门化对象类型。
	
	getchar();
}