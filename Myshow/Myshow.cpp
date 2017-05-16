#include "Myshow.h"
#include <vtkRenderWindow.h>

Myshow::Myshow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(myshow()));
	connect(ui.pcdshowButton, SIGNAL(clicked()), this, SLOT(PcdShow()));
	connect(ui.HarrisButton, SIGNAL(clicked()), this, SLOT(HarrisKeypoints()));
	connect(ui.SiftButton, SIGNAL(clicked()), this, SLOT(SiftKeypoints()));
	connect(ui.IcpButton, SIGNAL(clicked()), this, SLOT(ICP()));
}

void Myshow::myshow()
{
	ui.label->setText("Succeed!");
	
}
int Myshow::PcdShow()
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	//	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);

	if (pcl::io::loadPCDFile<pcl::PointXYZ>("chair1.pcd", *cloud) == -1) //* load the file  
	{
		PCL_ERROR("Couldn't read file test_pcd.pcd \n");
		return (-1);
	}

	//if (pcl::io::loadPCDFile<pcl::PointXYZ>("7076.pcd", *cloud1) == -1) //* load the file1  
	//{
	//	PCL_ERROR("Couldn't read file test_pcd.pcd \n");
	//	return (-1);
	//}

	std::cout << "Loaded "
		<< cloud->width * cloud->height
		<< " data points from test_pcd.pcd with the following fields: "
		<< std::endl;
	//for (size_t i = 0; i < cloud->points.size(); ++i)
	//	std::cout << "    " << cloud->points[i].x
	//	<< " " << cloud->points[i].y
	//	<< " " << cloud->points[i].z << std::endl;
	/*for (size_t i = 0; i < cloud1->points.size(); ++i)
	std::cout << "    " << cloud->points[i].x
	<< " " << cloud1->points[i].y
	<< " " << cloud1->points[i].z << std::endl;
	*/
	pcl::visualization::PCLVisualizer viewer("Cloud viewer");
//	pcl::visualization::PCLVisualizer viewer;
	//	viewer.setCameraPosition(0, 0, -3.0, 0, -1, 0);
	//	viewer.addCoordinateSystem(0.3);

//	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
//	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));



	viewer.addPointCloud(cloud);

	//ui.qvtkWidget->SetRenderWindow(viewer.getRenderWindow());
	//viewer.setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	//ui.qvtkWidget->update();

	//viewer.updatePointCloud(cloud, "cloud");
	//viewer.resetCamera();
	//ui.qvtkWidget->update();


	//	pcl::visualization::PCLVisualizer viewer("PCL Viewer");
	//	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> keypoints_color_handler(cloud, 0, 255, 0);
	//	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_color_handler(cloud1, 255, 0, 0);
	//	viewer.setBackgroundColor(0.0, 0.0, 0.0);
	//	viewer.addPointCloud(cloud1, cloud_color_handler, "cloud");//add point cloud
	//	viewer.addPointCloud(cloud, keypoints_color_handler, "keypoints");//add the keypoints 
	//	viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "keypoints");

	//	viewer.addPointCloud(cloud1);
	while (!viewer.wasStopped())
		viewer.spinOnce(100);
	return (0);

}


//int Myshow::ObjToPcd()
//{
//	int default_tesselated_sphere_level = 2;
//	int default_resolution = 100;
//	float default_leaf_size = 0.025f;
//
//	int argc;
//	char **argv;
//
//
//	print_info("Convert a CAD model to a point cloud using ray tracing operations. For more information, use: %s -h\n",
//		argv[0]);
//
//	
//
//	// Parse command line arguments
//	int tesselated_sphere_level = default_tesselated_sphere_level;
//	parse_argument(argc, argv, "-level", tesselated_sphere_level);
//	int resolution = default_resolution;
//	parse_argument(argc, argv, "-resolution", resolution);
//	float leaf_size = default_leaf_size;
//	parse_argument(argc, argv, "-leaf_size", leaf_size);
//
//	// Parse the command line arguments for .ply and PCD files
//	std::vector<int> pcd_file_indices = parse_file_extension_argument(argc, argv, ".pcd");
//	if (pcd_file_indices.size() != 1)
//	{
//		print_error("Need a single output PCD file to continue.\n");
//		return (-1);
//	}
//	std::vector<int> ply_file_indices = parse_file_extension_argument(argc, argv, ".ply");
//	std::vector<int> obj_file_indices = parse_file_extension_argument(argc, argv, ".obj");
//	if (ply_file_indices.size() != 1 && obj_file_indices.size() != 1)
//	{
//		print_error("Need a single input PLY/OBJ file to continue.\n");
//		return (-1);
//	}
//
//	vtkSmartPointer<vtkPolyData> polydata1;
//	if (ply_file_indices.size() == 1)
//	{
//		vtkSmartPointer<vtkPLYReader> readerQuery = vtkSmartPointer<vtkPLYReader>::New();
//		readerQuery->SetFileName(argv[ply_file_indices[0]]);
//		readerQuery->Update();
//		polydata1 = readerQuery->GetOutput();
//	}
//	else if (obj_file_indices.size() == 1)
//	{
//		vtkSmartPointer<vtkOBJReader> readerQuery = vtkSmartPointer<vtkOBJReader>::New();
//		readerQuery->SetFileName(argv[obj_file_indices[0]]);
//		readerQuery->Update();
//		polydata1 = readerQuery->GetOutput();
//	}
//
//	bool INTER_VIS = false;
//	bool VIS = true;
//
//	visualization::PCLVisualizer vis;
//	vis.addModelFromPolyData(polydata1, "mesh1", 0);
//	vis.setRepresentationToSurfaceForAllActors();
//
//	PointCloud<PointXYZ>::CloudVectorType views_xyz;
//	std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f> > poses;
//	std::vector<float> enthropies;
//	vis.renderViewTesselatedSphere(resolution, resolution, views_xyz, poses, enthropies, tesselated_sphere_level);
//
//	//take views and fuse them together
//	std::vector<PointCloud<PointXYZ>::Ptr> aligned_clouds;
//
//	for (size_t i = 0; i < views_xyz.size(); i++)
//	{
//		PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>());
//		Eigen::Matrix4f pose_inverse;
//		pose_inverse = poses[i].inverse();
//		transformPointCloud(views_xyz[i], *cloud, pose_inverse);
//		aligned_clouds.push_back(cloud);
//	}
//
//	/* if (INTER_VIS)
//	{
//	visualization::PCLVisualizer vis2 ("visualize");
//
//	for (size_t i = 0; i < aligned_clouds.size (); i++)
//	{
//	std::stringstream name;
//	name << "cloud_" << i;
//	vis2.addPointCloud (aligned_clouds[i], name.str ());
//	vis2.spin ();
//	}
//	}*/
//
//	// Fuse clouds
//	PointCloud<PointXYZ>::Ptr big_boy(new PointCloud<PointXYZ>());
//	for (size_t i = 0; i < aligned_clouds.size(); i++)
//		*big_boy += *aligned_clouds[i];
//
//	//  savePCDFileASCII(argv[pcd_file_indices[0]], *big_boy);
//
//
//	std::cout << "done" << endl;
//
//	if (VIS)
//	{
//		visualization::PCLVisualizer vis2("visualize");
//		vis2.addPointCloud(big_boy);
//		vis2.spin();
//
//	}
//
//	// Voxelgrid
//	VoxelGrid<PointXYZ> grid_;
//	grid_.setInputCloud(big_boy);
//	grid_.setLeafSize(leaf_size, leaf_size, leaf_size);
//	grid_.filter(*big_boy);
//
//
//
//	if (VIS)
//	{
//		visualization::PCLVisualizer vis3("visualize");
//		vis3.addPointCloud(big_boy);
//		vis3.spin();
//	}
//
//	savePCDFileASCII(argv[pcd_file_indices[0]], *big_boy);
//	std::cout << "done1" << endl;
//}


int Myshow::HarrisKeypoints()
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudNonSubsample(new pcl::PointCloud<pcl::PointXYZ>);
	//	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	if (pcl::io::loadPCDFile<pcl::PointXYZ>("chair1.pcd", *cloudNonSubsample) == -1) //* load the file
	{
		PCL_ERROR("Couldn't read file test_pcd.pcd \n");
		return (-1);
	}

	pcl::VoxelGrid<pcl::PointXYZ> sor;
	//	sor.setInputCloud(cloudNonSubsample);
	//	sor.setLeafSize(0.1f, 0.1f, 0.1f);
	//	sor.filter(*cloud);

	std::cout << "input cloud counbt " << cloudNonSubsample->size() << "\n";
	//	std::cout << "input cloud filtered: " << cloud->size() << "\n";

	std::cout << "readed\n";
	pcl::visualization::PCLVisualizer viewer("PCL Viewer");



	pcl::HarrisKeypoint3D <pcl::PointXYZ, pcl::PointXYZI> detector;
	pcl::PointCloud<pcl::PointXYZI>::Ptr keypoints(new pcl::PointCloud<pcl::PointXYZI>);
	std::cout << "computed1\n";
	detector.setNonMaxSupression(true);
	detector.setRadius(0.04);                              //越小点越多
	detector.setInputCloud(cloudNonSubsample);
	detector.setThreshold(0.005);                         //越小点越多
	std::cout << "computed2\n";
	detector.compute(*keypoints);

	/*for (auto it = keypoints->begin(); it != keypoints->end(); it++)
	{
	if (fabs(it->x)> 100 || fabs(it->y)> 100 || fabs(it->z)> 100)
	{
	it->x = 0;
	it->y = 0;
	it->z = 0;

	}
	}*/

	std::cout << "computed " << keypoints->size() << "\n";

	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZI> keypoints_color_handler(keypoints, 0, 255, 0);
	viewer.addPointCloud(keypoints, keypoints_color_handler, "keypoints");
	viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "keypoints");
	viewer.addPointCloud(cloudNonSubsample, "inputCloud");

	cout << "done" << endl;


	while (!viewer.wasStopped())
	{
		viewer.spinOnce();
	}

	return (0);
}

namespace pcl
{
	template<>
	struct SIFTKeypointFieldSelector<PointXYZ>
	{
		inline float
			operator () (const PointXYZ &p) const
		{
			return p.z;
		}
	};
}
int Myshow::SiftKeypoints()
{
   
	
	/*int argc;
	char **argv;

	std::string filename = argv[1];
	std::cout << "Reading " << filename << std::endl;*/
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>);
	if (pcl::io::loadPCDFile<pcl::PointXYZ>("chair1.pcd", *cloud_xyz) == -1) // load the file
	{
		PCL_ERROR("Couldn't read file");
		return -1;
	}
	std::cout << "points: " << cloud_xyz->points.size() << std::endl;

	// Parameters for sift computation
	const float min_scale = 0.007f; //the standard deviation of the smallest scale in the scale space
	const int n_octaves = 6;//the number of octaves (i.e. doublings of scale) to compute
	const int n_scales_per_octave = 4;//the number of scales to compute within each octave
	const float min_contrast = 0.0045f;//the minimum contrast required for detection


	pcl::console::TicToc time;
	time.tic();
	// Estimate the sift interest points using z values from xyz as the Intensity variants
	pcl::SIFTKeypoint<pcl::PointXYZ, pcl::PointWithScale> sift;
	pcl::PointCloud<pcl::PointWithScale> result;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
	sift.setSearchMethod(tree);
	sift.setScales(min_scale, n_octaves, n_scales_per_octave);
	sift.setMinimumContrast(min_contrast);
	sift.setInputCloud(cloud_xyz);
	sift.compute(result);
	std::cout << "Computing the SIFT points takes " << time.toc() / 1000 << "seconds" << std::endl;
	std::cout << "No of SIFT points in the result are " << result.points.size() << std::endl;


	// Copying the pointwithscale to pointxyz so as visualize the cloud
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_temp(new pcl::PointCloud<pcl::PointXYZ>);
	copyPointCloud(result, *cloud_temp);
	std::cout << "SIFT points in the result are " << cloud_temp->points.size() << std::endl;
	// Visualization of keypoints along with the original cloud
	pcl::visualization::PCLVisualizer viewer("PCL Viewer");
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> keypoints_color_handler(cloud_temp, 0, 255, 0);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_color_handler(cloud_xyz, 255, 0, 0);
	viewer.setBackgroundColor(0.0, 0.0, 0.0);
	viewer.addPointCloud(cloud_xyz, cloud_color_handler, "cloud");//add point cloud
	viewer.addPointCloud(cloud_temp, keypoints_color_handler, "keypoints");//add the keypoints 
	viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "keypoints");

	while (!viewer.wasStopped())
	{
		viewer.spinOnce();
	}


	return 0;

}

int Myshow::ICP()
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_source(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_target(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_source_registration(new pcl::PointCloud<pcl::PointXYZ>);

	pcl::io::loadPCDFile("chair4.pcd", *cloud_source);
	pcl::io::loadPCDFile("chair5.pcd", *cloud_target);
	//	pcl::io::loadPCDFile("source.pcd", *cloud_in);
	//	pcl::io::loadPCDFile("source1.pcd", *cloud_icp);


	//argc = 3;
	//// check arguments
	//if(argc != 3) {
	//	std::cout << "ERROR: the number of arguments is illegal!" << std::endl;
	//	return -1;
	//}
	//
	//// load pcd file
	//if(pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud_source)==-1) {
	//	std::cout << "load source failed!" << std::endl;
	//	return -1;
	//}
	//std::cout << "source loaded!" << std::endl;

	//if(pcl::io::loadPCDFile<pcl::PointXYZ>(argv[2], *cloud_target)==-1) {
	//	std::cout << "load target failed!" << std::endl;
	//	return -1;
	//}
	//std::cout << "target loaded!" << std::endl;

	// ICP
	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree1(new pcl::search::KdTree<pcl::PointXYZ>);
	tree1->setInputCloud(cloud_source);
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZ>);
	tree2->setInputCloud(cloud_target);
	icp.setSearchMethodSource(tree1);
	icp.setSearchMethodTarget(tree2);
	icp.setInputSource(cloud_source);
	icp.setInputTarget(cloud_target);
	icp.setMaxCorrespondenceDistance(25);
	icp.setTransformationEpsilon(1e-10);
	icp.setEuclideanFitnessEpsilon(0.01);
	icp.setMaximumIterations(1050);
	icp.align(*cloud_source_registration);

	//	icp.align(*cloud_target);
	Eigen::Matrix4f transformation = icp.getFinalTransformation();
	std::cout << transformation << std::endl;

	// display
	pcl::visualization::PCLVisualizer p;
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> src_r_h(cloud_source_registration, 255, 0, 0);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> tgt_h(cloud_target, 0, 255, 0);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> src_h(cloud_source, 0, 0, 255);
	p.addPointCloud(cloud_source_registration, src_r_h, "source_r");
	p.addPointCloud(cloud_target, tgt_h, "target");
	//	p.addPointCloud(cloud_source, src_h, "source");
	p.spin();
	return 0;
}