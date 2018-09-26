/*
 * Model.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: edgar
 */

#include "Model.h"
#include <direct.h>

Model::Model() : ObjectSize_(0), Processing_point_(0)
{
  n_correspondences_ = 0;
}

Model::~Model()
{
  // TODO Auto-generated destructor stub
}

void Model::add_ObjectSize(const cv::Point2f &ObjectSize)
{
	ObjectSize_.push_back(ObjectSize);
}

void Model::add_Processing_point(const cv::Point2f &processing_point)
{
	Processing_point_.push_back(processing_point);
}

void Model::add_use_number(const int &times)
{
  use_number_.push_back(times);
}

void Model::increase_use_time()
{
	use_number_[0]++;
}

void Model::add_Object_type(const int &Object_type)
{
  Object_type_.push_back(Object_type);
}


/** Save a CSV file and fill the object mesh */
void Model::save(const std::string path)
{
  /*cv::Mat Processing_points_matrix = cv::Mat(Processing_point_);*/

  cv::FileStorage storage(path, cv::FileStorage::WRITE);

  storage << "object_size" << ObjectSize_;
  storage << "use_times" << use_number_;
  storage << "object_type_number" << Object_type_;
  storage << "processing_point" << Processing_point_;

  storage.release();
}

/** Load a YAML file using OpenCv functions **/
void Model::load(const std::string path)
{
	//cv::Mat Processing_points_mat;

  cv::FileStorage storage (path, cv::FileStorage::READ);

  storage["object_size"] >> ObjectSize_;
  storage["use_times"] >> use_number_;
  storage["object_type_number"] >> Object_type_;
  storage["processing_point"] >> Processing_point_;

  //Processing_points_mat.copyTo(Processing_point_);

  storage.release();

}

void Model::GetQRnumber(std::string number)
{

	std::string file_path = "Data/";
	Model::load(file_path + "object_" + number + ".yml");
}

std::string IntToString(int Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}
