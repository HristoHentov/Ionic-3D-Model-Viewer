#include "Ionic.h"

namespace Ionic {
	namespace Application {

		using namespace Math;
		Ionic::Ionic()
		{
			_logger = &_cLogger;
			Initialize();
		}

		void Ionic::Initialize()
		{
			/// Initialize GLFW
			if (!glfwInit())
			{
				_logger->LogLine(GLFW_INIT_FAIL, TEXT_COLOR_RED);
				return;
			}

			/// Create GLFW Window
			_appWindow = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);


			/// Initialize GLEW
			if (glewInit() != GLEW_OK)
			{

				_logger->LogLine(GLEW_INIT_FAIL, TEXT_COLOR_RED);
				_logger->LogLine((char *)glewGetErrorString(glewInit()), TEXT_COLOR_RED);

				return;
			}
			glewExperimental = true;

			glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

			_shader = new Shader("src/Graphics/vShader.txt", "src/Graphics/fShader.txt");
			_shader->Build();
			_shader->Enable();

			_logger->LogLine(INIT_SUCCSESS, TEXT_COLOR_GREEN);
			_logger->Log(OPENGL_VERSION);
			_logger->LogLine((char*)glGetString(GL_VERSION), TEXT_COLOR_GREEN);
			_logger->Log(OPENGL_GPU);
			_logger->LogLine((char*)glGetString(GL_RENDERER), TEXT_COLOR_GREEN);
		}

		void Ionic::Run()
		{
			GLfloat meshVertecies[] =
			{ -0.5f, -0.5f,  0.0f,
				-0.5f,  0.5f,  0.0f,
				 0.5f,  0.5f,  0.0f,
				 0.5f, -0.5f,  0.0f
			};

			///Used for testing multiple buffers
			GLfloat meshColors[] =
			{
				0, 0, 1, 1,
				0, 1, 0, 1,
				1, 0, 0, 1,
				0, 0, 0, 1
			};

			GLushort meshIndecies[] =
			{
				0, 1, 2,
				2, 3, 0
			};

			VertexArray vao;
			Buffer * vbo = new Buffer(meshVertecies, 3, 4 * 3);
			Buffer * cbo = new Buffer(meshColors, 4, 4 * 4);
			IndexBuffer ibo(meshIndecies, 6);

			vao.Add(vbo, 0);
			vao.Add(cbo, 1);

			unsigned long ticks = 0;
			_shader->setUniformMat4("pMatrix", Math::mat4::Rotation(0, vec3(1, 0, 1)));
			while (!_appWindow->IsClosed())
			{
				ticks++;

				_shader->setUniformMat4("pMatrix", Math::mat4::Rotation((10 + (ticks / 20)), vec3(0, 0, 1)));
				_shader->setUniform2f("mouse_pos", InputManager::GetMousePosition());
				_appWindow->Clear();
				vao.Bind();
				ibo.Enable();
				glDrawElements(GL_TRIANGLES, ibo.GetSize(), GL_UNSIGNED_SHORT, 0);
				_appWindow->Update();
				ibo.Disable();
				vao.Unbind();

				if (InputManager::IsKeyPressed(GLFW_KEY_SPACE))
				{
					Math::vec4 x = Math::vec4(1.0f, 2.0f, 3.0f, 4.0f);
					Math::vec4 y = Math::vec4(1.0f, 2.0f, 3.0f, 4.0f);
					y += Math::vec4(1.0f, 1.0f, 1.0f, 1.0f);

					Math::vec4 z = x + y;
					std::cout << "=================" << std::endl;
					std::cout << "x: " << x << std::endl;
					std::cout << "y: " << y << std::endl;
					std::cout << "z: " << z << std::endl;
					std::cout << "-----------------" << std::endl;
					z -= Math::vec4(1.0f, 1.0f, 1.0f, 1.0f);
					std::cout << "x: " << x << std::endl;
					std::cout << "y: " << y << std::endl;
					std::cout << "z: " << z << std::endl;

					std::cout << "=================" << std::endl;

				}
				if (InputManager::IsMousePressed(GLFW_MOUSE_BUTTON_MIDDLE))
				{
					_logger->LogLine("Scroll pressed!", TEXT_COLOR_GREEN);
				}
				if (InputManager::GetScrollOffset() != 0)
				{
					_logger->Log("Scroll Offset: ", TEXT_COLOR_RED);
					_logger->LogLine(std::to_string(InputManager::GetScrollOffset()).c_str());
				}
				if (InputManager::IsKeyPressed(GLFW_KEY_M))
				{
					mat2 test2(1.0f);
					mat3 test3(1.0f);
					mat4 test(1.0f);
					test = mat4::Scale(vec3(2, 3, 4)) * mat4::Identity();
					test *= mat4(1.0f);
					_logger->LogLine(test.ToString(), TEXT_COLOR_YELLOW);
					_logger->LogLine(test2.ToString(), TEXT_COLOR_YELLOW);
					_logger->LogLine(test3.ToString(), TEXT_COLOR_YELLOW);

				}
				if (InputManager::IsKeyPressed(GLFW_KEY_T))
				{
					std::string result = FileLoader::ReadTextFile("test.txt");
					_logger->LogLine(result, TEXT_COLOR_GREEN);
				}
				if (InputManager::IsKeyPressed(GLFW_KEY_ESCAPE))
				{
					_appWindow->Close();
				}
			}
		}

		Ionic::~Ionic()
		{
			delete _appWindow;
		}
	}
}
