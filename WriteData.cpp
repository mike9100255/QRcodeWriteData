#include <iostream>
#include <direct.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <Windows.h>

#include "Model.h"



void main()
{
	//Create Data File
	char ss[50], dirss[50];
	std::string file = "Data";
	std::string dirfile = "dir " + file;
	strcpy_s(ss, file.c_str());
	strcpy_s(dirss, dirfile.c_str());
	if (_mkdir(ss) == 0)
	{
		system(dirss);
	}

	while ((int)cv::waitKey(30) != VK_ESCAPE)
	{
		Model model;
		
		cv::Point2f ObjectSize, ProcessingPoint;
		int UseTimes, Type;
		char answer;

		std::string TIMES;
		std::cout << "object number : " ;
		std::cin >> TIMES;
		std::cout << "Enter object size : x = ";
		std::cin >> ObjectSize.x;
		std::cout << "Enter object size : y = ";
		std::cin >> ObjectSize.y;
		model.add_ObjectSize(ObjectSize);

		std::cout << "Enter using times : ";
		std::cin >> UseTimes;
		model.add_use_number(UseTimes);

		std::cout << "Enter object type (1)Rectangle (2)Trapezoid (3)Dome (4)Recurve : ";
		std::cin >> Type;
		model.add_Object_type(Type);

		while (true) {
			std::cout << "Do you want to add processing point ? (y or n) ";
			std::cin >> answer;
			if (answer == 'n') { break; }

			std::cout << "Enter processing point : x = ";
			std::cin >> ProcessingPoint.x;
			std::cout << "Enter processing point : y = ";
			std::cin >> ProcessingPoint.y;
			model.add_Processing_point(ProcessingPoint);

		}
		
		std::string save_path = "Data/object_" + TIMES + ".yml";

		model.save(save_path);

		system("pause");
	}
}