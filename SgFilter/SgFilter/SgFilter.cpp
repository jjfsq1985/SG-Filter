// SgFilter.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "SgFilter.h"
#include "savgol.h"

#include "Eigen/Dense"
#include "Eigen/LU"
#include "Eigen/Core"
#include "Eigen/QR"

using namespace Eigen;
using namespace std;

SF_FILTER_API bool sgFilter(double *pDataIn, int nDataLen, double *pDataOut)
{
	double Fd;
	double f_min, f_max;
	int Order = 5;
	int FrameSize = 17;
	double In_min = -1.0;
	double In_max = 1.0;

	auto s = vander(FrameSize);        //Compute vandermonde matrix

	auto B = sgdiff(Order, FrameSize, Fd);

	//To express as a real filtering operation, we shift x around the nth time instant
	auto x = VectorXf::LinSpaced(FrameSize, In_min, In_max);

	auto Filter = savgolfilt(x, Order, FrameSize);

	cout << "\n\nFiltered values in the range \n" << x.transpose().eval() << "\n are: \n" << Filter << endl;
}
