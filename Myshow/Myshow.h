#pragma once

//#include <vtkAutoInit.h> 
//VTK_MODULE_INIT(vtkRenderingOpenGL2);
//VTK_MODULE_INIT(vtkInteractionStyle);

#include <QtWidgets/QMainWindow>

#include <iostream>
#include <pcl/io/pcd_io.h>  
#include <pcl/point_types.h>  
#include <pcl/visualization/pcl_visualizer.h> 
#include <pcl/common/transforms.h>
#include <vtkPLYReader.h>
#include <vtkOBJReader.h>
#include <vtkPolyDataMapper.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/features/normal_3d.h>
#include <pcl/keypoints/harris_3d.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/common/io.h>
#include <pcl/keypoints/sift_keypoint.h>
#include <pcl/features/normal_3d.h>
#include <pcl/console/time.h>
#include <pcl/registration/icp.h>

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;
#include "ui_Myshow.h"



class Myshow : public QMainWindow
{
	Q_OBJECT

public:
	Myshow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MyshowClass ui;
	private slots:
	void myshow();
	int PcdShow();
//	int ObjToPcd();
	int HarrisKeypoints();
	int SiftKeypoints();
	int ICP();
};
