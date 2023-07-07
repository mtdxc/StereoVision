#include "StdAfx.h"
#include "ParamServer.h"

ParamServer::ParamServer() 
{
	init();
}

ParamServer* ParamServer::instance() {
	static ParamServer* _instance = NULL;
	if (_instance == NULL) {
		_instance = new ParamServer();
	}
	return _instance;
}


void ParamServer::init()
{
	// Ĭ�ϴ򿪹̶�·���е� yml �ļ�
	bool isOpened = fs.open("D:\\Projects\\Kinect_NI\\Release\\params.yml", cv::FileStorage::READ);
	if (!isOpened)
	{// �����ʧ�ܣ���� release �ļ����е� yml �ļ�
		isOpened = fs.open("params.yml", cv::FileStorage::READ);
	}

	if ( isOpened )
	{// �� yml �ļ��ɹ�
		printf("[- Paramater Loading] Loaded data from File params.yml .");

		fs["image_width"]		>> image_width;
		fs["image_height"]		>> image_height;
	} 
	else
	{// �� yml �ļ�ʧ�ܣ���ʹ��Ĭ�ϲ���
		printf("[- Paramater Loading] File params.yml does not exist, load default values.");

		image_width		= 640;
		image_height	= 480;
	}
}


