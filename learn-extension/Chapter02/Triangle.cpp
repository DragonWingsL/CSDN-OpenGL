//// +++++++++++++++++++++++++++++++++++++++
//// 《OpenGL 超级宝典》 Chapter02 Triangle
//// ---------------------------------------
//
//#include <GLTools.h>
//#include <GLShaderManager.h>
//
//#ifdef __APPLE__
//#include <glut/glut.h>
//#else
//#define FREEGLUT_STATIC
//#include <GL/glut.h>
//#endif
//
//// GLTools 封装的顶点批次处理类
//GLBatch triangleBatch;
//// GLTools 封装的着色器管理器
//GLShaderManager shaderManager;
//
//
//// +++++++++++
//// 自己扩展部分
//GLBatch triangle2Batch;
//GLBatch triangle3Batch;
//GLBatch triangle4Batch;
//// -----------
//
//
//// 窗口大小改变，对应的改变视口大小
//void ChangeSize(int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//// 初始化
//void SetupRC()
//{
//	// 蓝色背景
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//
//	// 初始化 GLTools  的着色器管理器
//	shaderManager.InitializeStockShaders();
//
//	// 创建一个三角形顶点数组
//	GLfloat vVerts[] = {
//		0.5f,  -0.5f, 0.0f,
//		-0.5f, -0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//
//	// 拷贝三角形顶点数组到 GLTools 的顶点批次中
//	// GL_TRIANGLES 表示为三角形顶点
//	triangleBatch.Begin(GL_TRIANGLES, 3);
//	triangleBatch.CopyVertexData3f(vVerts);
//	triangleBatch.End();
//
//
//	// +++++++++++
//	// 自己扩展部分
//
//	// 绿色三角形顶点
//	GLfloat vVerts2[] = {
//		0.5f,  -0.5f, 0.0f,
//		0.5f,  0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//	triangle2Batch.Begin(GL_TRIANGLES, 3);
//	triangle2Batch.CopyVertexData3f(vVerts2);
//	triangle2Batch.End();
//
//	// 黄色三角形顶点
//	GLfloat vVerts3[] = {
//		0.5f,  0.5f, 0.0f,
//		-0.5f,  0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//	triangle3Batch.Begin(GL_TRIANGLES, 3);
//	triangle3Batch.CopyVertexData3f(vVerts3);
//	triangle3Batch.End();
//
//	// 洋红色三角形顶点
//	GLfloat vVerts4[] = {
//		-0.5f,  0.5f, 0.0f,
//		-0.5f,  -0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//	triangle4Batch.Begin(GL_TRIANGLES, 3);
//	triangle4Batch.CopyVertexData3f(vVerts4);
//	triangle4Batch.End();
//	// -----------
//}
//
//// 渲染场景
//void RenderScene(void)
//{
//	// 清除 颜色 和 深度 和 模板 的缓冲区数据
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//
//	// 红色
//	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	// 装载红色着色器
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
//	// 绘制三角形
//	triangleBatch.Draw();
//
//
//	// +++++++++++
//	// 自己扩展部分
//
//	// 绿色
//	GLfloat vGreen[] = { 0.0f, 1.0f, 0.0f, 1.0f };
//	// 装载红色着色器
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vGreen);
//	// 绘制三角形
//	triangle2Batch.Draw();
//
//	// 黄色
//	GLfloat vYellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
//	// 装载红色着色器
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vYellow);
//	// 绘制三角形
//	triangle3Batch.Draw();
//
//	// 洋红色
//	GLfloat vMagenta[] = { 1.0f, 0.0f, 1.0f, 1.0f };
//	// 装载红色着色器
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vMagenta);
//	// 绘制三角形
//	triangle4Batch.Draw();
//	// -----------
//
//
//	// 将后台缓冲区内容切换到前台缓冲区
//	glutSwapBuffers();
//}
//
//int main(int argc, char * argv[])
//{
//	// 设置工作目录
//	gltSetWorkingDirectory(argv[0]);
//
//	// 初始化 GLUT
//	glutInit(&argc, argv);
//
//	// 初始化 GLUT 显示模式
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
//
//	// 初始化窗口大小
//	glutInitWindowSize(800, 600);
//
//	// 初始化窗口标题
//	glutCreateWindow("Triangle");
//
//	// 设置窗口大小改变回调函数
//	glutReshapeFunc(ChangeSize);
//
//	// 设置窗口重绘回调函数
//	glutDisplayFunc(RenderScene);
//
//	// GLEW 初始化
//	GLenum err = glewInit();
//	if (GLEW_OK != err) {
//		// 初始化失败
//		fprintf(stderr, "GLEW Init error: %s\n", glewGetErrorString(err));
//		return 1;
//	}
//
//	// 初始化 RC
//	SetupRC();
//
//	// 进入主消息循环
//	glutMainLoop();
//	return 0;
//}
//
//
//
//
//
//
//
