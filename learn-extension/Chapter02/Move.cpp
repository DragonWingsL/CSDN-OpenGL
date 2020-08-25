////// +++++++++++++++++++++++++++++++++++++++
////// 《OpenGL 超级宝典》 Chapter02 Move
////// ---------------------------------------
//
//#include <GLTools.h>
//#include <GLShaderManager.h>
//
//#ifdef __APPLE__
//#include <glut/glut.h>
//#else
//#define FREEGULT_STATIC
//#include <GL/glut.h>
//#endif
//
//GLBatch squareBatch;
//GLShaderManager shaderManager;
//
//GLfloat blockSize = 0.1f;
//GLfloat vVerts[] = {
//	-blockSize, -blockSize, 0.0f,
//	 blockSize, -blockSize, 0.0f,
//	 blockSize,  blockSize, 0.0f,
//	-blockSize,  blockSize, 0.0f,
//};
//
////// +++++++++++
////// 自己扩展部分
//GLBatch triangleBatch;
//
//GLfloat fPi = 3.1415926f;
//GLfloat fRad = fPi / 180.0f;
//GLfloat fTriangleX = 0.0f, fTriangleY = 0.0f;
//GLfloat fCurAngle = 0.0f;
//// 创建一个三角形顶点数组
//GLfloat fScale = 0.8f;
//GLfloat vTriangleVerts[] = {
//	-blockSize * fScale, 0.0f, 0.0f,
//	blockSize * fScale,  0.0f, 0.0f,
//	0.0f,  blockSize * fScale, 0.0f,
//};
//
//void Rotate(GLfloat angle, GLfloat *pX, GLfloat *pY)
//{
//	*pX = fTriangleX + (blockSize * fScale) * cos(angle * fRad);
//	*pY = fTriangleY + (blockSize * fScale) * sin(angle * fRad);
//}
//
//void RotateTriangleArrow(GLfloat angle)
//{
//	Rotate(angle, &vTriangleVerts[0], &vTriangleVerts[1]);
//	Rotate(angle + 90.0f, &vTriangleVerts[3], &vTriangleVerts[4]);
//	Rotate(angle + 180.0f, &vTriangleVerts[6], &vTriangleVerts[7]);
//}
//// -----------
//
//void SetupRC()
//{
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//	shaderManager.InitializeStockShaders();
//
//	squareBatch.Begin(GL_TRIANGLE_FAN, 4);
//	squareBatch.CopyVertexData3f(vVerts);
//	squareBatch.End();
//
//	triangleBatch.Begin(GL_TRIANGLES, 3);
//	triangleBatch.CopyVertexData3f(vTriangleVerts);
//	triangleBatch.End();
//}
//
//void SpecialKeys(int key, int x, int y)
//{
//	GLfloat stepSize = 0.025f;
//
//	GLfloat blockX = vVerts[0];
//	GLfloat blockY = vVerts[7];
//
//	if (key == GLUT_KEY_UP) {
//		fCurAngle = 0.0f;
//		blockY += stepSize;
//	}
//
//	if (key == GLUT_KEY_DOWN) {
//		fCurAngle = 180.0f;
//		blockY -= stepSize;
//	}
//
//	if (key == GLUT_KEY_LEFT) {
//		fCurAngle = 90.0f;
//		blockX -= stepSize;
//	}
//
//	if (key == GLUT_KEY_RIGHT) {
//		fCurAngle = 270.0f;
//		blockX += stepSize;
//	}
//
//	if (blockX < -1.0f) blockX = -1.0f;
//	if (blockX > (1.0 - blockSize * 2)) blockX = 1.0f - blockSize * 2;
//	if (blockY < -1.0f + blockSize * 2) blockY = -1.0f + blockSize * 2;
//	if (blockY > 1.0f) blockY = 1.0f;
//
//	fTriangleX += blockX - vVerts[0];
//	fTriangleY += blockY - vVerts[7];
//
//	vVerts[0] = blockX;
//	vVerts[1] = blockY - blockSize * 2;
//
//	vVerts[3] = blockX + blockSize * 2;
//	vVerts[4] = blockY - blockSize * 2;
//
//	vVerts[6] = blockX + blockSize * 2;
//	vVerts[7] = blockY;
//
//	vVerts[9] = blockX;
//	vVerts[10] = blockY;
//
//	squareBatch.CopyVertexData3f(vVerts);
//
//	RotateTriangleArrow(fCurAngle);
//	triangleBatch.CopyVertexData3f(vTriangleVerts);
//
//	glutPostRedisplay();
//}
//
//void RenderScene(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//
//	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
//	squareBatch.Draw();
//
//	// 南瓜橙色
//	GLfloat vPumpkinOrange[] = { 0.98f, 0.625f, 0.12f, 1.0f };
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vPumpkinOrange);
//	triangleBatch.Draw();
//
//	glutSwapBuffers();
//}
//
//void ChangeSize(int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//int main(int argc, char * argv[])
//{
//	gltSetWorkingDirectory(argv[0]);
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Move Block with Arrow Keys");
//
//	GLenum err = glewInit();
//	if (GLEW_OK != err) {
//		fprintf(stderr, "GLEW init err: %s\n", glewGetErrorString(err));
//		return 1;
//	}
//
//	glutDisplayFunc(RenderScene);
//	glutReshapeFunc(ChangeSize);
//	glutSpecialFunc(SpecialKeys);
//
//	SetupRC();
//
//	glutMainLoop();
//	return 0;
//}
//
