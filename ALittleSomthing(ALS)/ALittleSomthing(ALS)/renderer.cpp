#include "renderer.h"

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}



renderer::renderer(bool* SeV)
{
	shallEnd = SeV;
}

//Initilizations and so on, called in mainGame constructor
void renderer::startStuff(){
	if (!glfwInit())
	{
		fatalError("GLFW couldn't initialize");
	}

	glfwSetErrorCallback(error_callback);

	window = glfwCreateWindow(640, 480, "somthingGoesHere",NULL,NULL);
	if (!window) { 
		fatalError("Window not initalized");
	}
	glfwMakeContextCurrent(window);

	VertexShader = glCreateShader(GL_VERTEX_SHADER);
	compileShader(".\\shader\\vertexShader.txt", VertexShader);

	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	compileShader(".\\shader\\fragmentShader.txt", FragmentShader);

	ShaderProgram = glCreateProgram();
	glAttachShader(ShaderProgram, VertexShader);
	glAttachShader(ShaderProgram, FragmentShader);

	glLinkProgram(ShaderProgram);

}

void renderer::render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
	glfwSwapBuffers(window);
	*shallEnd = !glfwWindowShouldClose(window);
}




void renderer::compileShader(const std::string& filePath, GLuint id) {

	//Textdateien aus Pfad oeffnen
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {
		perror(filePath.c_str());
	}

	std::string fileContents;
	std::string line;
	//Dateiinhalte in einen String kopieren
	while (std::getline(vertexFile, line)) {
		fileContents += line + "\n";
	}
	//Datei schliessen
	vertexFile.close();

	//mit Pointer zu dem String mit dem Inhalt der Shadertextdatei Shader kompilieren
	const char* contentsPtr = fileContents.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);

	glCompileShader(id);

	//moegliche Fehler ausgeben
	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		//Provide the infolog in whatever manor you deem best.
		//Exit with failure.
		glDeleteShader(id); //Don't leak the shader.

							//Print error log and quit
		std::printf("%s\n", &(errorLog[0]));
	}
}

renderer::~renderer()
{
}
