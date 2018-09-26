/*
 * Model.h
 *
 *  Created on: Apr 9, 2014
 *      Author: edgar
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <opencv2/core/core.hpp>

std::string IntToString(int Number);

class Model
{
public:
  Model();
  virtual ~Model();
  enum Mode
  {

	  Rectangle = 1,
	  Trapezoid = 2,
	  Dome      = 3,
	  Recurve   = 4,

  };

  std::vector<cv::Point2f> get_ObjectSize() const { return ObjectSize_; }
  std::vector<cv::Point2f> get_Processing_point() const { return Processing_point_; }
  std::vector<int> get_use_number() const { return use_number_; }
  std::vector<int> get_Object_type() const { return Object_type_; }


  void add_ObjectSize(const cv::Point2f &ObjectSize);
  void add_Processing_point(const cv::Point2f &processing_point);
  void add_use_number(const int &times);
  void increase_use_time();
  void add_Object_type(const int &Object_type);
  void GetQRnumber(std::string number);


  void save(const std::string path);
  void load(const std::string path);


private:
  /** The current number of correspondecnes */
  int n_correspondences_;
  /** The list of 2D points on the model surface */
  std::vector<cv::Point2f> ObjectSize_;
  /** The list of 2D points outside the model surface */
  std::vector<cv::Point2f> Processing_point_;
  /** The list of 3D points on the model surface */
  std::vector<int> use_number_;

  std::vector<int> Object_type_;

};

#endif /* OBJECTMODEL_H_ */
