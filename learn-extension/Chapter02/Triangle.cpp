//// +++++++++++++++++++++++++++++++++++++++
//// ��OpenGL �������䡷 Chapter02 Triangle
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
//// GLTools ��װ�Ķ������δ�����
//GLBatch triangleBatch;
//// GLTools ��װ����ɫ��������
//GLShaderManager shaderManager;
//
//
//// +++++++++++
//// �Լ���չ����
//GLBatch triangle2Batch;
//GLBatch triangle3Batch;
//GLBatch triangle4Batch;
//// -----------
//
//
//// ���ڴ�С�ı䣬��Ӧ�ĸı��ӿڴ�С
//void ChangeSize(int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//// ��ʼ��
//void SetupRC()
//{
//	// ��ɫ����
//	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//
//	// ��ʼ�� GLTools  ����ɫ��������
//	shaderManager.InitializeStockShaders();
//
//	// ����һ�������ζ�������
//	GLfloat vVerts[] = {
//		0.5f,  -0.5f, 0.0f,
//		-0.5f, -0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//
//	// ���������ζ������鵽 GLTools �Ķ���������
//	// GL_TRIANGLES ��ʾΪ�����ζ���
//	triangleBatch.Begin(GL_TRIANGLES, 3);
//	triangleBatch.CopyVertexData3f(vVerts);
//	triangleBatch.End();
//
//
//	// +++++++++++
//	// �Լ���չ����
//
//	// ��ɫ�����ζ���
//	GLfloat vVerts2[] = {
//		0.5f,  -0.5f, 0.0f,
//		0.5f,  0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//	triangle2Batch.Begin(GL_TRIANGLES, 3);
//	triangle2Batch.CopyVertexData3f(vVerts2);
//	triangle2Batch.End();
//
//	// ��ɫ�����ζ���
//	GLfloat vVerts3[] = {
//		0.5f,  0.5f, 0.0f,
//		-0.5f,  0.5f, 0.0f,
//		0.0f,  0.0f, 0.0f,
//	};
//	triangle3Batch.Begin(GL_TRIANGLES, 3);
//	triangle3Batch.CopyVertexData3f(vVerts3);
//	triangle3Batch.End();
//
//	// ���ɫ�����ζ���
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
//// ��Ⱦ����
//void RenderScene(void)
//{
//	// ��� ��ɫ �� ��� �� ģ�� �Ļ���������
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//
//	// ��ɫ
//	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
//	// װ�غ�ɫ��ɫ��
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
//	// ����������
//	triangleBatch.Draw();
//
//
//	// +++++++++++
//	// �Լ���չ����
//
//	// ��ɫ
//	GLfloat vGreen[] = { 0.0f, 1.0f, 0.0f, 1.0f };
//	// װ�غ�ɫ��ɫ��
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vGreen);
//	// ����������
//	triangle2Batch.Draw();
//
//	// ��ɫ
//	GLfloat vYellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
//	// װ�غ�ɫ��ɫ��
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vYellow);
//	// ����������
//	triangle3Batch.Draw();
//
//	// ���ɫ
//	GLfloat vMagenta[] = { 1.0f, 0.0f, 1.0f, 1.0f };
//	// װ�غ�ɫ��ɫ��
//	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vMagenta);
//	// ����������
//	triangle4Batch.Draw();
//	// -----------
//
//
//	// ����̨�����������л���ǰ̨������
//	glutSwapBuffers();
//}
//
//int main(int argc, char * argv[])
//{
//	// ���ù���Ŀ¼
//	gltSetWorkingDirectory(argv[0]);
//
//	// ��ʼ�� GLUT
//	glutInit(&argc, argv);
//
//	// ��ʼ�� GLUT ��ʾģʽ
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
//
//	// ��ʼ�����ڴ�С
//	glutInitWindowSize(800, 600);
//
//	// ��ʼ�����ڱ���
//	glutCreateWindow("Triangle");
//
//	// ���ô��ڴ�С�ı�ص�����
//	glutReshapeFunc(ChangeSize);
//
//	// ���ô����ػ�ص�����
//	glutDisplayFunc(RenderScene);
//
//	// GLEW ��ʼ��
//	GLenum err = glewInit();
//	if (GLEW_OK != err) {
//		// ��ʼ��ʧ��
//		fprintf(stderr, "GLEW Init error: %s\n", glewGetErrorString(err));
//		return 1;
//	}
//
//	// ��ʼ�� RC
//	SetupRC();
//
//	// ��������Ϣѭ��
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
