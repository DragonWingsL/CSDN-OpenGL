//// +++++++++++++++++++++++++++++++++++++++
//// 《OpenGL 超级宝典》 Chapter02 Bounce
//// ---------------------------------------


#include <GLTools.h>
#include <GLShaderManager.h>

#ifdef __APPLE__
#include <gl/glut.h>
#else
#define FREEGULT_STATIC
#include <GL/glut.h>
#endif

GLBatch squareBatch;
GLShaderManager shaderManager;

GLfloat blockSize = 0.1f;
GLfloat vVerts[] = {
	-blockSize - 0.5f, -blockSize, 0.0f,
	 blockSize - 0.5f, -blockSize, 0.0f,
	 blockSize - 0.5f,  blockSize, 0.0f,
	-blockSize - 0.5f,  blockSize, 0.0f
};
// ==
GLBatch leftFootTriangleBatch;
GLBatch leftShankTriangleBatch;
GLBatch leftThighTriangleBatch;
GLBatch leftUpperArmTriangleBatch;
GLBatch leftForeArmTriangleBatch;
GLBatch leftFinger1TriangleBatch;
GLBatch leftFinger2TriangleBatch;

GLBatch rightFootTriangleBatch;
GLBatch rightShankTriangleBatch;
GLBatch rightThighTriangleBatch;
GLBatch rightUpperArmTriangleBatch;
GLBatch rightForeArmTriangleBatch;
GLBatch rightFinger1TriangleBatch;
GLBatch rightFinger2TriangleBatch;

GLBatch neckTriangleBatch;

GLBatch bodySquareBatch;
GLBatch headSquareBatch;

GLfloat fStartX = 0.0f, fStartY = 0.0f;

// Left-Foot
GLfloat vLeftFootVerts[] = {
	fStartX - 0.02f - 0.1f, fStartY, 0.0f,
	fStartX - 0.02f, fStartY, 0.0f,
	fStartX - 0.07f, fStartY + 0.05f, 0.0f
};

// Left-Shank
GLfloat vLeftShankVerts[] = {
	fStartX - 0.07f, fStartY + 0.05f, 0.0f,
	fStartX - 0.02f - 0.02f, fStartY + 0.05f + 0.1f, 0.0f,
	fStartX - 0.02f - 0.08f, fStartY + 0.05f + 0.1f, 0.0f,
};

// Left-Thigh
GLfloat vLeftThightVerts[] = {
	fStartX - 0.02f - 0.08f, fStartY + 0.05f + 0.1f, 0.0f,
	fStartX - 0.02f - 0.02f, fStartY + 0.05f + 0.1f, 0.0f,
	fStartX - 0.07f, fStartY + 0.05f + 0.1f + 0.08f, 0.0f,
};

// Right-Foot
GLfloat vRightFootVerts[] = {
	fStartX + 0.02f + 0.1f, fStartY, 0.0f,
	fStartX + 0.02f, fStartY, 0.0f,
	fStartX + 0.07f, fStartY + 0.05f, 0.0f
};

// Right-Shank
GLfloat vRightShankVerts[] = {
	fStartX + 0.07f, fStartY + 0.05f, 0.0f,
	fStartX + 0.02f + 0.02f, fStartY + 0.05f + 0.1f, 0.0f,
	fStartX + 0.02f + 0.08f, fStartY + 0.05f + 0.1f, 0.0f,
};

// Right-Thigh
GLfloat vRightThightVerts[] = {
	fStartX + 0.02f + 0.08f, fStartY + 0.05f + 0.1f, 0.0f,
	fStartX + 0.02f + 0.02f, fStartY + 0.05f + 0.1f, 0.0f,
	fStartX + 0.07f, fStartY + 0.05f + 0.1f + 0.08f, 0.0f,
};

// Body
GLfloat vBodyVerts[] = {
	fStartX - 0.1f, fStartY + 0.05f + 0.1f + 0.08f, 0.0f,
	fStartX + 0.1f, fStartY + 0.05f + 0.1f + 0.08f, 0.0f,
	fStartX + 0.1f, fStartY + 0.05f + 0.1f + 0.08f + 0.15f, 0.0f,
	fStartX - 0.1f, fStartY + 0.05f + 0.1f + 0.08f + 0.15f, 0.0f,
};

// Neck
GLfloat vNeckVerts[] = {
	fStartX - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.15f, 0.0f,
	fStartX + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.15f, 0.0f,
	fStartX,         fStartY + 0.05f + 0.1f + 0.08f + 0.15f + 0.05f, 0.0f,

};

// Head
GLfloat vHeadVerts[] = {
	fStartX,         fStartY + 0.05f + 0.1f + 0.08f + 0.15f + 0.05f, 0.0f,
	fStartX + 0.05f, fStartY + 0.05f + 0.1f + 0.08f + 0.15f + 0.05f + 0.05f, 0.0f,
	fStartX,         fStartY + 0.05f + 0.1f + 0.08f + 0.15f + 0.05f + 0.05f + 0.1f, 0.0f,
	fStartX - 0.05f, fStartY + 0.05f + 0.1f + 0.08f + 0.15f + 0.05f + 0.05f, 0.0f,

};

// Left-UpperArm
GLfloat vLeftUpperArmVerts[] = {
	fStartX - 0.1f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f - 0.03f, 0.0f,
	fStartX - 0.1f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f, 0.0f,
	fStartX - 0.1f - 0.05f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f, 0.0f,

};

// Right-UpperArm
GLfloat vRightUpperArmVerts[] = {
	fStartX + 0.1f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f - 0.03f, 0.0f,
	fStartX + 0.1f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f, 0.0f,
	fStartX + 0.1f + 0.05f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f, 0.0f,

};

// Left-ForeArm
GLfloat vLeftForeArmVerts[] = {
	fStartX - 0.1f - 0.05f,         fStartY + 0.05f + 0.1f + 0.08f + 0.075f, 0.0f,
	fStartX - 0.1f - 0.05f - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f, 0.0f,
	fStartX - 0.1f - 0.05f - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f - 0.03f, 0.0f,
};

// Right-ForeArm
GLfloat vRightForeArmVerts[] = {
	fStartX + 0.1f + 0.05f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f, 0.0f,
	fStartX + 0.1f + 0.05f + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f, 0.0f,
	fStartX + 0.1f + 0.05f + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f - 0.03f, 0.0f,
};

// Left-Finger-1
GLfloat vLeftFinger1Verts[] = {
	fStartX - 0.1f - 0.05f - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f, 0.0f,
	fStartX - 0.1f - 0.05f - 0.07f - 0.02f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.015f, 0.0f,
	fStartX - 0.1f - 0.05f - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.03f, 0.0f,
};

// Left-Finger-2
GLfloat vLeftFinger2Verts[] = {
	fStartX - 0.1f - 0.05f - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.03f, 0.0f,
	fStartX - 0.1f - 0.05f - 0.07f - 0.02f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.015f - 0.03f, 0.0f,
	fStartX - 0.1f - 0.05f - 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.03f - 0.03f, 0.0f,
};

// Right-Finger-1
GLfloat vRightFinger1Verts[] = {
	fStartX + 0.1f + 0.05f + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f, 0.0f,
	fStartX + 0.1f + 0.05f + 0.07f + 0.02f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.015f, 0.0f,
	fStartX + 0.1f + 0.05f + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.03f, 0.0f,
};

// Right-Finger-2
GLfloat vRightFinger2Verts[] = {
	fStartX + 0.1f + 0.05f + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.03f, 0.0f,
	fStartX + 0.1f + 0.05f + 0.07f + 0.02f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.015f - 0.03f, 0.0f,
	fStartX + 0.1f + 0.05f + 0.07f, fStartY + 0.05f + 0.1f + 0.08f + 0.075f + 0.03f - 0.03f - 0.03f, 0.0f,
};


void Rotate(GLfloat fOriginX, GLfloat fOriginY, GLfloat fRadius, GLfloat angle, GLfloat *pX, GLfloat *pY)
{
	static GLfloat fPi = 3.1415926f, fRad = fPi / 180.0f;
	*pX = fOriginX + fRadius * cos(angle * fRad);
	*pY = fOriginY + fRadius * sin(angle * fRad);
}

// 获取两点之间的距离
GLfloat GetDistanceBetweenTwoPoint(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	// 根据勾股定理计算两点距离
	GLfloat a = x1 - x2;
	GLfloat b = y1 - y2;
	return sqrt(a * a + b * b);
}

// 挥舞手臂
void WaringArm()
{
	static GLint counter = 1;
	static GLfloat fMinAngle = 180.0f - 30.0f, fMaxAngle = 180.0f + 30.0f, fAngle = fMinAngle, fAngleInc = 1.0f;

	if (++counter > 30)
		counter = 0;
	else
		return;

	fAngle += fAngleInc;

	if (fAngle <= fMinAngle) {
		fAngle = fMinAngle;
		fAngleInc = 1;
	}
	else if (fAngle >= fMaxAngle) {
		fAngle = fMaxAngle;
		fAngleInc = -1;
	}

	// 肘关节的坐标点(x, y)
	GLfloat fLeftElbowX = vLeftForeArmVerts[0], fLeftElbowY = vLeftForeArmVerts[1];

	// 旋转点1
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftForeArmVerts[3], vLeftForeArmVerts[4]),
		fAngle - 20, &vLeftForeArmVerts[3], &vLeftForeArmVerts[4]
	);
	// 旋转点2
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftForeArmVerts[6], vLeftForeArmVerts[7]),
		fAngle + 20, &vLeftForeArmVerts[6], &vLeftForeArmVerts[7]
	);
	leftForeArmTriangleBatch.CopyVertexData3f(vLeftForeArmVerts);

	vRightForeArmVerts[3] = -vLeftForeArmVerts[3];
	vRightForeArmVerts[4] = vLeftForeArmVerts[4];

	vRightForeArmVerts[6] = -vLeftForeArmVerts[6];
	vRightForeArmVerts[7] = vLeftForeArmVerts[7];
	rightForeArmTriangleBatch.CopyVertexData3f(vRightForeArmVerts);

	// 旋转 Finger1 点1
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftFinger1Verts[0], vLeftFinger1Verts[1]),
		fAngle - 6 - 11, &vLeftFinger1Verts[0], &vLeftFinger1Verts[1]
	);
	// 旋转 Finger1 点2
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftFinger1Verts[3], vLeftFinger1Verts[4]),
		fAngle - 6, &vLeftFinger1Verts[3], &vLeftFinger1Verts[4]
	);
	// 旋转 Finger1 点3
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftFinger1Verts[6], vLeftFinger1Verts[7]),
		fAngle - 6 + 11, &vLeftFinger1Verts[6], &vLeftFinger1Verts[7]
	);
	leftFinger1TriangleBatch.CopyVertexData3f(vLeftFinger1Verts);

	vRightFinger1Verts[0] = -vLeftFinger1Verts[0];
	vRightFinger1Verts[1] = vLeftFinger1Verts[1];

	vRightFinger1Verts[3] = -vLeftFinger1Verts[3];
	vRightFinger1Verts[4] = vLeftFinger1Verts[4];

	vRightFinger1Verts[6] = -vLeftFinger1Verts[6];
	vRightFinger1Verts[7] = vLeftFinger1Verts[7];
	rightFinger1TriangleBatch.CopyVertexData3f(vRightFinger1Verts);

	// 旋转 Finger2 点1
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftFinger2Verts[0], vLeftFinger2Verts[1]),
		fAngle + 6 - 11, &vLeftFinger2Verts[0], &vLeftFinger2Verts[1]
	);
	// 旋转 Finger2 点2
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftFinger2Verts[3], vLeftFinger2Verts[4]),
		fAngle + 6, &vLeftFinger2Verts[3], &vLeftFinger2Verts[4]
	);
	// 旋转 Finger2 点3
	Rotate(
		fLeftElbowX, fLeftElbowY,
		GetDistanceBetweenTwoPoint(fLeftElbowX, fLeftElbowY, vLeftFinger2Verts[6], vLeftFinger2Verts[7]),
		fAngle + 6 + 11, &vLeftFinger2Verts[6], &vLeftFinger2Verts[7]
	);
	leftFinger2TriangleBatch.CopyVertexData3f(vLeftFinger2Verts);

	vRightFinger2Verts[0] = -vLeftFinger2Verts[0];
	vRightFinger2Verts[1] = vLeftFinger2Verts[1];

	vRightFinger2Verts[3] = -vLeftFinger2Verts[3];
	vRightFinger2Verts[4] = vLeftFinger2Verts[4];

	vRightFinger2Verts[6] = -vLeftFinger2Verts[6];
	vRightFinger2Verts[7] = vLeftFinger2Verts[7];
	rightFinger2TriangleBatch.CopyVertexData3f(vRightFinger2Verts);
}

void AutoTriangleCopyVertexData3f(GLBatch *pTriangleBatch, GLfloat *vVerts)
{
	pTriangleBatch->Begin(GL_TRIANGLES, 3);
	pTriangleBatch->CopyVertexData3f(vVerts);
	pTriangleBatch->End();
}

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	shaderManager.InitializeStockShaders();

	/*squareBatch.Begin(GL_TRIANGLE_FAN, 4);
	squareBatch.CopyVertexData3f(vVerts);
	squareBatch.End();*/
	
	//==
	AutoTriangleCopyVertexData3f(&leftFootTriangleBatch, vLeftFootVerts);
	AutoTriangleCopyVertexData3f(&leftShankTriangleBatch, vLeftShankVerts);
	AutoTriangleCopyVertexData3f(&leftThighTriangleBatch, vLeftThightVerts);

	AutoTriangleCopyVertexData3f(&rightFootTriangleBatch, vRightFootVerts);
	AutoTriangleCopyVertexData3f(&rightShankTriangleBatch, vRightShankVerts);
	AutoTriangleCopyVertexData3f(&rightThighTriangleBatch, vRightThightVerts);

	bodySquareBatch.Begin(GL_TRIANGLE_FAN, 4);
	bodySquareBatch.CopyVertexData3f(vBodyVerts);
	bodySquareBatch.End();

	AutoTriangleCopyVertexData3f(&neckTriangleBatch, vNeckVerts);

	headSquareBatch.Begin(GL_TRIANGLE_FAN, 4);
	headSquareBatch.CopyVertexData3f(vHeadVerts);
	headSquareBatch.End();

	AutoTriangleCopyVertexData3f(&leftUpperArmTriangleBatch, vLeftUpperArmVerts);
	AutoTriangleCopyVertexData3f(&leftForeArmTriangleBatch, vLeftForeArmVerts);
	AutoTriangleCopyVertexData3f(&leftFinger1TriangleBatch, vLeftFinger1Verts);
	AutoTriangleCopyVertexData3f(&leftFinger2TriangleBatch, vLeftFinger2Verts);

	AutoTriangleCopyVertexData3f(&rightUpperArmTriangleBatch, vRightUpperArmVerts);
	AutoTriangleCopyVertexData3f(&rightForeArmTriangleBatch, vRightForeArmVerts);

	AutoTriangleCopyVertexData3f(&rightFinger1TriangleBatch, vRightFinger1Verts);
	AutoTriangleCopyVertexData3f(&rightFinger2TriangleBatch, vRightFinger2Verts);
}

void BounceFunction(void)
{
	static GLfloat xDir = 1.0f;
	static GLfloat yDir = 1.0f;

	GLfloat stepSize = 0.005;

	GLfloat blockX = vVerts[0];
	GLfloat blockY = vVerts[7];

	blockX += stepSize * xDir;
	blockY += stepSize * yDir;

	if (blockX < -1.0f) { blockX = -1.0f; xDir *= -1.0f; }
	if (blockX > (1.0f - blockSize * 2)) { blockX = 1.0f - blockSize * 2; xDir *= -1.0f; }
	if (blockY < -1.0f + blockSize * 2) { blockY = -1.0f + blockSize * 2; yDir *= -1.0f; }
	if (blockY > 1.0f) { blockY = 1.0f; yDir *= -1.0f; }

	vVerts[0] = blockX;
	vVerts[1] = blockY - blockSize * 2;

	vVerts[3] = blockX + blockSize * 2;
	vVerts[4] = blockY - blockSize * 2;

	vVerts[6] = blockX + blockSize * 2;
	vVerts[7] = blockY;

	vVerts[9] = blockX;
	vVerts[10] = blockY;

	squareBatch.CopyVertexData3f(vVerts);
}

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	/*GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
	squareBatch.Draw();*/

	//BounceFunction();

	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
	leftFootTriangleBatch.Draw();
	rightFootTriangleBatch.Draw();

	GLfloat vGreen[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vGreen);
	leftShankTriangleBatch.Draw();
	rightShankTriangleBatch.Draw();


	GLfloat vYellow[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vYellow);
	leftThighTriangleBatch.Draw();
	rightThighTriangleBatch.Draw();


	GLfloat vMagenta[] = { 1.0f, 0.0f, 1.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vMagenta);
	bodySquareBatch.Draw();


	GLfloat vCyan[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vCyan);
	neckTriangleBatch.Draw();


	GLfloat vPumpkinOrange[] = { 0.98f, 0.625f, 0.12f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vPumpkinOrange);
	headSquareBatch.Draw();


	GLfloat vPastelPink[] = { 0.98f, 0.04f, 0.70f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vPastelPink);
	leftUpperArmTriangleBatch.Draw();
	rightUpperArmTriangleBatch.Draw();

	GLfloat vPlum1[] = {  0.67f, 0.50f, 1.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vPlum1);
	leftForeArmTriangleBatch.Draw();
	rightForeArmTriangleBatch.Draw();

	GLfloat vOrchid1[] = { 1.0f, 0.51f, 0.98f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vOrchid1);
	leftFinger1TriangleBatch.Draw();
	leftFinger2TriangleBatch.Draw();
	rightFinger1TriangleBatch.Draw();
	rightFinger2TriangleBatch.Draw();

	WaringArm();

	glutSwapBuffers();
	glutPostRedisplay();
}

void ChangeSize(int w, int h)
{
	glViewport(0, 0, w, h);
}

int main(int argc, char* argv[])
{
	gltSetWorkingDirectory(argv[0]);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Bouncing Block");

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW init err: %s\n", glewGetErrorString(err));
		return 1;
	}

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);

	SetupRC();

	glutMainLoop();
	return 0;
}







